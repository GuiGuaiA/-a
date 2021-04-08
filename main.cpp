#include<cstdlib>
#include<cstdio>

#define MaxVertexNum 750;
typedef int Vertex;
typedef int WeightType;
typedef char DataType;

typedef  struct  ENode //定义边结构
{
    Vertex v1,v2;
    WeightType Weight;
} ENode,*PtrtoENode;
typedef PtrtoENode Edge;

typedef  struct  ADjVNode // 定义点结构
{
    Vertex ADjV;
    WeightType Weight;
    ADjVNode *Next;
}ADjVNode,*PtrToAdjVNode;

typedef struct  VNode // 顶点表头节点
{
    PtrToAdjVNode FirstEdge; // 第一条边的地址 （一指针变量）
}VNode,*PTRtoVNode,AdjList[MaxVertexNum];

typedef struct GNode  //图节点
{
    int vexnum;  //顶点数
    int arcnum;  //边数
    AdjList G; // 顶点表
} GNode,*PtrToGNode;

typedef PtrToGNode LGraph;

LGraph CreateGraph;
int VertexNum;  // 创建个图，并且定义顶点的编号。
{
    Vertex  V; // 定义图的最顶点节点V。
    LGraph Grapg; // 此图的存储方式为邻接表的存储图的图类型。

    Graph->vexnum = VertexNum; // 所有的节点都连在一起。
    Graph->arcnum = 0; // 图的最外边的边数是0，也就是说所有的边都在图内。

    for(V=0,V<Graph->Nvevnum,V++) // 从最顶点节点开始循环探索，若小于图的的节点的数量，每次循环后编码加一。
    {
        Graph->G[V].FirstEdge=NULL; //循环到最后一个节点的边和最顶点节点的边连在一起是结束，也就是围成一个圈。
    }
    return Graph;
}
