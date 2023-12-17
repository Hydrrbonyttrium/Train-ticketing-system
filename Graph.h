#define MAX_VERTEX_NUM 20
typedef enum {DG,DN,AG,AN} GraphKind; /* {����ͼ,������,����ͼ,������} */
#define MAX_NAME 1 /* �����ַ�������󳤶�+1 */
typedef int InfoType; /* �������Ȩֵ */
//typedef char VertexType[MAX_NAME]; /* �ַ������� */
typedef char VertexType;

typedef int InfoType;

typedef struct ArcNode
{
 int adjvex; /* �û���ָ��Ķ����λ�� */
 struct ArcNode *nextarc; /* ָ����һ������ָ�� */
 InfoType *info; /* ����Ȩֵָ�룩 */
}ArcNode; /* ���� */

typedef struct
{
 VertexType data; /* ������Ϣ */
 ArcNode *firstarc; /* ��һ������ĵ�ַ,ָ���һ�������ö���Ļ���ָ�� */
}VNode,AdjList[MAX_VERTEX_NUM]; /* ͷ��� */

typedef struct
{
 AdjList vertices;
 int vexnum,arcnum; /* ͼ�ĵ�ǰ�������ͻ��� */
 int kind; /* ͼ�������־ */
}ALGraph;

int LocateVex(ALGraph G,VertexType u);
Status CreateGraph(ALGraph &G);
void DestroyGraph(ALGraph &G);
VertexType* GetVex(ALGraph G,int v);
int FirstAdjVex(ALGraph G,VertexType v);
int NextAdjVex(ALGraph G,VertexType v,VertexType w);

void DFSTraverse(ALGraph G,void(*Visit)(char));
void BFSTraverse(ALGraph G,void(*Visit)(char));
void DFS(ALGraph G,int v);
void Display(ALGraph G);
void print(char i);