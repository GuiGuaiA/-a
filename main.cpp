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

 oooo

