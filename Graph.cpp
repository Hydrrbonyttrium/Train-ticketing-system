#include "Public1.h"
#include "Graph.h"
#include "LinkQueue.h"

Boolean visited[MAX_VERTEX_NUM]; /* ���ʱ�־����(ȫ����) */
void (*VisitFunc)(char v); /* ��������(ȫ����) */
void print(char i)
{
    printf("%c ",i);
}

int LocateVex(ALGraph G,VertexType u)
{ /* ��ʼ����: ͼ G ����,u �� G �ж�������ͬ���� */
/* �������: �� G �д��ڶ��� u,�򷵻ظö�����ͼ��λ��;���򷵻�-1 */
 int i;
 for(i=0;i<G.vexnum;++i)
   if(u==G.vertices[i].data)
     return i;
 return -1;
}

Status CreateGraph(ALGraph &G)
{ /* �����ڽӱ�洢�ṹ,����û�������Ϣ��ͼ G(��һ���������� 4 ��ͼ) */
  int i,j,k;
  int w; /* Ȩֵ */
  VertexType va,vb;
  ArcNode *p;
  printf("������ͼ������(����ͼ:0,������:1,����ͼ:2,������:3): ");
  scanf("%d",&(G.kind));
  printf("������ͼ�Ķ�����,����: ");
  scanf("%d,%d",&(G.vexnum),&(G.arcnum));
  getchar();
  printf("������%d �������ֵ(%d ���ַ���ʾ�����ÿո���):\n",G.vexnum,MAX_NAME);
  for(i=0;i<G.vexnum;++i) /* ���춥������ */  
  {
	scanf("%c",&G.vertices[i].data);
	G.vertices[i].firstarc=NULL;
  }
  getchar();
  if(G.kind==1||G.kind==3) /* �� */
      printf("��˳������ÿ����(��)��Ȩֵ����β�ͻ�ͷ(��,��Ϊ���):\n");
  else /* ͼ */
      printf("��˳������ÿ����(��)�Ļ�β�ͻ�ͷ(��,��Ϊ���):\n");
  for(k=0;k<G.arcnum;++k) /* ����������� */
  {
	if(G.kind==1||G.kind==3) /* �� */
		scanf("%d,%c,%c",&w,&va,&vb);
	else /* ͼ */
		scanf("%c,%c",&va,&vb);
    getchar();
	i=LocateVex(G,va); /* ��β */
	j=LocateVex(G,vb); /* ��ͷ */
	p=(ArcNode*)malloc(sizeof(ArcNode));
	p->adjvex=j;
	if(G.kind==1||G.kind==3) /* �� */
	{
		p->info=(int *)malloc(sizeof(int));
		*(p->info)=w;
	}
	else
		p->info=NULL; /* ͼ */
	p->nextarc=G.vertices[i].firstarc; /* ���ڱ�ͷ */
	G.vertices[i].firstarc=p;
	if(G.kind>=2) /* ����ͼ����,�����ڶ������� */
	{
		p=(ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex=i;
		if(G.kind==3) /* ������ */
		{
			p->info=(int*)malloc(sizeof(int));
			*(p->info)=w;
		}
		else
			p->info=NULL; /* ����ͼ */
		p->nextarc=G.vertices[j].firstarc; /* ���ڱ�ͷ */
		G.vertices[j].firstarc=p;
	}
  }
  return OK;
}

void DestroyGraph(ALGraph &G)
{ /* ��ʼ����: ͼ G ���ڡ��������: ����ͼ G */
  int i;
  ArcNode *p,*q;
  G.vexnum=0;
  G.arcnum=0;
  for(i=0;i<G.vexnum;++i)
  {
	p=G.vertices[i].firstarc;
	while(p)
	{
		q=p->nextarc;
		if(G.kind%2) /* ��*/
			free(p->info);
		free(p);
		p=q;
	}
  }	
}

VertexType* GetVex(ALGraph G,int v)
{ /* ��ʼ����: ͼ G ����,v �� G ��ĳ���������š��������: ���� v ��ֵ */
   if(v>=G.vexnum||v<0)
	exit(ERROR);
   return &G.vertices[v].data;
}

int FirstAdjVex(ALGraph G,VertexType v)
{ /* ��ʼ����: ͼ G ����,v �� G ��ĳ������ */
/* �������: ���� v �ĵ�һ���ڽӶ������š��������� G ��û���ڽӶ���,�򷵻�-1 */
  ArcNode *p;
  int v1;
  v1=LocateVex(G,v); /* v1 Ϊ����v ��ͼG �е����*/
  p=G.vertices[v1].firstarc;
  if(p)
	return p->adjvex;
  else
	return -1;
}

int NextAdjVex(ALGraph G,VertexType v,VertexType w)
{ /* ��ʼ����: ͼ G ����,v �� G ��ĳ������,w �� v ���ڽӶ��� */
/* �������: ���� v ��(����� w ��)��һ���ڽӶ������š� */
/*
�� w �� v �����һ���ڽӵ�,�򷵻�-1 */
  ArcNode *p;
  int v1,w1;
  v1=LocateVex(G,v); /* v1 Ϊ����v ��ͼG �е����*/
  w1=LocateVex(G,w); /* w1 Ϊ����w ��ͼG �е����*/
  p=G.vertices[v1].firstarc;
  while(p&&p->adjvex!=w1) /* ָ��p ��������ָ���㲻��w */
	p=p->nextarc;
  if(!p||!p->nextarc) /* û�ҵ�w ��w �����һ���ڽӵ�*/
	return -1;
  else /* p->adjvex==w */
	return p->nextarc->adjvex; /* ����v ��(�����w ��)��һ���ڽӶ�������*/
}


void DFS(ALGraph G,int v)
{ /* �ӵ� v ����������ݹ��������ȱ���ͼ G���㷨 7.5 */
  int w;
  VertexType v1,w1;
  v1=*GetVex(G,v);
  visited[v]=TRUE; /* ���÷��ʱ�־ΪTRUE(�ѷ���) */
  VisitFunc(G.vertices[v].data); /* ���ʵ�v ������*/
  for(w=FirstAdjVex(G,v1);w>=0;w=NextAdjVex(G,v1,w1=*GetVex(G,w)))
  if(!visited[w])
	DFS(G,w); /* ��v ����δ���ʵ��ڽӵ�w �ݹ����DFS */
}

void DFSTraverse(ALGraph G,void(*Visit)(char))
{ /* ��ͼ G ��������ȱ������㷨 7.4 */
  int v;
  VisitFunc=Visit; /* ʹ��ȫ�ֱ���VisitFunc,ʹDFS �����躯��ָ�����*/
  for(v=0;v<G.vexnum;v++)
	visited[v]=FALSE; /* ���ʱ�־�����ʼ��*/
  for(v=0;v<G.vexnum;v++)
	if(!visited[v])
	   DFS(G,v); /* ����δ���ʵĶ������DFS */
    printf("\n");
}

void BFSTraverse(ALGraph G,void(*Visit)(char))
{
	int v,u,w;
    VertexType u1,w1;
	LinkQueue Q;
	for(v=0;v<G.vexnum;++v)
		visited[v]=FALSE; /* �ó�ֵ*/
	InitQueue(Q); /* �ÿյĸ�������Q */
	for(v=0;v<G.vexnum;v++) /* �������ͨͼ,ֻv=0 �ͱ���ȫͼ*/
		if(!visited[v]) /* v ��δ����*/
		{
			visited[v]=TRUE;
			Visit(G.vertices[v].data);
			EnQueue(Q,v); /* v �����*/
			while(!QueueEmpty(Q)) /* ���в���*/
			{
				DeQueue(Q,u); /* ��ͷԪ�س��Ӳ���Ϊu */
				u1=*GetVex(G,u);
				for(w=FirstAdjVex(G,u1);w>=0;w=NextAdjVex(G,u1,w1=*GetVex(G,w)))
				if(!visited[w]) /* w Ϊu ����δ���ʵ��ڽӶ���*/
				{
					visited[w]=TRUE;
					Visit(G.vertices[w].data);
					EnQueue(Q,w); /* w ���*/
				}
			}
		}
		printf("\n");
}

void Display(ALGraph G)
{ /* ���ͼ���ڽӾ��� G */
	int i;
	ArcNode *p;
	switch(G.kind)
	{ case DG: printf("����ͼ\n");
	  break;
      case DN: printf("������\n");
      break;
      case AG: printf("����ͼ\n");
      break;
      case AN: printf("������\n");
	}
 printf("%d �����㣺\n",G.vexnum);
 for(i=0;i<G.vexnum;++i)
	printf("%c ",G.vertices[i].data);
 printf("\n%d ����(��):\n",G.arcnum);
 for(i=0;i<G.vexnum;i++)
 {
	p=G.vertices[i].firstarc;
    while(p)
	{ 
		if(G.kind<=1) /* ���� */
		{
			printf("%c��%c ",G.vertices[i].data,G.vertices[p->adjvex].data);
			if(G.kind==DN) /* �� */
				printf(":%d ",*(p->info));
		}
		else /* ����(�����������) */
		{
			if(i<p->adjvex)
			{
				printf("%c��%c ",G.vertices[i].data,G.vertices[p->adjvex].data);
				if(G.kind==AN) /* �� */
					printf(":%d ",*(p->info));
			}
		}
		p=p->nextarc;
	}
	printf("\n");
 }
}
