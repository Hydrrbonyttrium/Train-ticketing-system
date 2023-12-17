#include "Public1.h"
#include "Graph.h"
#include "LinkQueue.h"

Boolean visited[MAX_VERTEX_NUM]; /* 访问标志数组(全局量) */
void (*VisitFunc)(char v); /* 函数变量(全局量) */
void print(char i)
{
    printf("%c ",i);
}

int LocateVex(ALGraph G,VertexType u)
{ /* 初始条件: 图 G 存在,u 和 G 中顶点有相同特征 */
/* 操作结果: 若 G 中存在顶点 u,则返回该顶点在图中位置;否则返回-1 */
 int i;
 for(i=0;i<G.vexnum;++i)
   if(u==G.vertices[i].data)
     return i;
 return -1;
}

Status CreateGraph(ALGraph &G)
{ /* 采用邻接表存储结构,构造没有相关信息的图 G(用一个函数构造 4 种图) */
  int i,j,k;
  int w; /* 权值 */
  VertexType va,vb;
  ArcNode *p;
  printf("请输入图的类型(有向图:0,有向网:1,无向图:2,无向网:3): ");
  scanf("%d",&(G.kind));
  printf("请输入图的顶点数,边数: ");
  scanf("%d,%d",&(G.vexnum),&(G.arcnum));
  getchar();
  printf("请输入%d 个顶点的值(%d 个字符表示，不用空格间隔):\n",G.vexnum,MAX_NAME);
  for(i=0;i<G.vexnum;++i) /* 构造顶点向量 */  
  {
	scanf("%c",&G.vertices[i].data);
	G.vertices[i].firstarc=NULL;
  }
  getchar();
  if(G.kind==1||G.kind==3) /* 网 */
      printf("请顺序输入每条弧(边)的权值、弧尾和弧头(以,作为间隔):\n");
  else /* 图 */
      printf("请顺序输入每条弧(边)的弧尾和弧头(以,作为间隔):\n");
  for(k=0;k<G.arcnum;++k) /* 构造表结点链表 */
  {
	if(G.kind==1||G.kind==3) /* 网 */
		scanf("%d,%c,%c",&w,&va,&vb);
	else /* 图 */
		scanf("%c,%c",&va,&vb);
    getchar();
	i=LocateVex(G,va); /* 弧尾 */
	j=LocateVex(G,vb); /* 弧头 */
	p=(ArcNode*)malloc(sizeof(ArcNode));
	p->adjvex=j;
	if(G.kind==1||G.kind==3) /* 网 */
	{
		p->info=(int *)malloc(sizeof(int));
		*(p->info)=w;
	}
	else
		p->info=NULL; /* 图 */
	p->nextarc=G.vertices[i].firstarc; /* 插在表头 */
	G.vertices[i].firstarc=p;
	if(G.kind>=2) /* 无向图或网,产生第二个表结点 */
	{
		p=(ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex=i;
		if(G.kind==3) /* 无向网 */
		{
			p->info=(int*)malloc(sizeof(int));
			*(p->info)=w;
		}
		else
			p->info=NULL; /* 无向图 */
		p->nextarc=G.vertices[j].firstarc; /* 插在表头 */
		G.vertices[j].firstarc=p;
	}
  }
  return OK;
}

void DestroyGraph(ALGraph &G)
{ /* 初始条件: 图 G 存在。操作结果: 销毁图 G */
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
		if(G.kind%2) /* 网*/
			free(p->info);
		free(p);
		p=q;
	}
  }	
}

VertexType* GetVex(ALGraph G,int v)
{ /* 初始条件: 图 G 存在,v 是 G 中某个顶点的序号。操作结果: 返回 v 的值 */
   if(v>=G.vexnum||v<0)
	exit(ERROR);
   return &G.vertices[v].data;
}

int FirstAdjVex(ALGraph G,VertexType v)
{ /* 初始条件: 图 G 存在,v 是 G 中某个顶点 */
/* 操作结果: 返回 v 的第一个邻接顶点的序号。若顶点在 G 中没有邻接顶点,则返回-1 */
  ArcNode *p;
  int v1;
  v1=LocateVex(G,v); /* v1 为顶点v 在图G 中的序号*/
  p=G.vertices[v1].firstarc;
  if(p)
	return p->adjvex;
  else
	return -1;
}

int NextAdjVex(ALGraph G,VertexType v,VertexType w)
{ /* 初始条件: 图 G 存在,v 是 G 中某个顶点,w 是 v 的邻接顶点 */
/* 操作结果: 返回 v 的(相对于 w 的)下一个邻接顶点的序号。 */
/*
若 w 是 v 的最后一个邻接点,则返回-1 */
  ArcNode *p;
  int v1,w1;
  v1=LocateVex(G,v); /* v1 为顶点v 在图G 中的序号*/
  w1=LocateVex(G,w); /* w1 为顶点w 在图G 中的序号*/
  p=G.vertices[v1].firstarc;
  while(p&&p->adjvex!=w1) /* 指针p 不空且所指表结点不是w */
	p=p->nextarc;
  if(!p||!p->nextarc) /* 没找到w 或w 是最后一个邻接点*/
	return -1;
  else /* p->adjvex==w */
	return p->nextarc->adjvex; /* 返回v 的(相对于w 的)下一个邻接顶点的序号*/
}


void DFS(ALGraph G,int v)
{ /* 从第 v 个顶点出发递归地深度优先遍历图 G。算法 7.5 */
  int w;
  VertexType v1,w1;
  v1=*GetVex(G,v);
  visited[v]=TRUE; /* 设置访问标志为TRUE(已访问) */
  VisitFunc(G.vertices[v].data); /* 访问第v 个顶点*/
  for(w=FirstAdjVex(G,v1);w>=0;w=NextAdjVex(G,v1,w1=*GetVex(G,w)))
  if(!visited[w])
	DFS(G,w); /* 对v 的尚未访问的邻接点w 递归调用DFS */
}

void DFSTraverse(ALGraph G,void(*Visit)(char))
{ /* 对图 G 作深度优先遍历。算法 7.4 */
  int v;
  VisitFunc=Visit; /* 使用全局变量VisitFunc,使DFS 不必设函数指针参数*/
  for(v=0;v<G.vexnum;v++)
	visited[v]=FALSE; /* 访问标志数组初始化*/
  for(v=0;v<G.vexnum;v++)
	if(!visited[v])
	   DFS(G,v); /* 对尚未访问的顶点调用DFS */
    printf("\n");
}

void BFSTraverse(ALGraph G,void(*Visit)(char))
{
	int v,u,w;
    VertexType u1,w1;
	LinkQueue Q;
	for(v=0;v<G.vexnum;++v)
		visited[v]=FALSE; /* 置初值*/
	InitQueue(Q); /* 置空的辅助队列Q */
	for(v=0;v<G.vexnum;v++) /* 如果是连通图,只v=0 就遍历全图*/
		if(!visited[v]) /* v 尚未访问*/
		{
			visited[v]=TRUE;
			Visit(G.vertices[v].data);
			EnQueue(Q,v); /* v 入队列*/
			while(!QueueEmpty(Q)) /* 队列不空*/
			{
				DeQueue(Q,u); /* 队头元素出队并置为u */
				u1=*GetVex(G,u);
				for(w=FirstAdjVex(G,u1);w>=0;w=NextAdjVex(G,u1,w1=*GetVex(G,w)))
				if(!visited[w]) /* w 为u 的尚未访问的邻接顶点*/
				{
					visited[w]=TRUE;
					Visit(G.vertices[w].data);
					EnQueue(Q,w); /* w 入队*/
				}
			}
		}
		printf("\n");
}

void Display(ALGraph G)
{ /* 输出图的邻接矩阵 G */
	int i;
	ArcNode *p;
	switch(G.kind)
	{ case DG: printf("有向图\n");
	  break;
      case DN: printf("有向网\n");
      break;
      case AG: printf("无向图\n");
      break;
      case AN: printf("无向网\n");
	}
 printf("%d 个顶点：\n",G.vexnum);
 for(i=0;i<G.vexnum;++i)
	printf("%c ",G.vertices[i].data);
 printf("\n%d 条弧(边):\n",G.arcnum);
 for(i=0;i<G.vexnum;i++)
 {
	p=G.vertices[i].firstarc;
    while(p)
	{ 
		if(G.kind<=1) /* 有向 */
		{
			printf("%c→%c ",G.vertices[i].data,G.vertices[p->adjvex].data);
			if(G.kind==DN) /* 网 */
				printf(":%d ",*(p->info));
		}
		else /* 无向(避免输出两次) */
		{
			if(i<p->adjvex)
			{
				printf("%c－%c ",G.vertices[i].data,G.vertices[p->adjvex].data);
				if(G.kind==AN) /* 网 */
					printf(":%d ",*(p->info));
			}
		}
		p=p->nextarc;
	}
	printf("\n");
 }
}
