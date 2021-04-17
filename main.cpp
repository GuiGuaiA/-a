#include<stdio.h>
#include<stdlib.h>
#include <fstream>
#include <iostream>
#include "string"
#include "vector"

#define MaxVertexNum 750    //最大顶点数

// file path
#define FILE_PATH "../data.txt"

typedef int Vertex; //顶点类型
typedef int WeightType; //边的权重
typedef char DataType;  //顶点存储数据类型


typedef struct ENode //定义边结构
{
    Vertex V1,V2;
    WeightType Weight;
} ENode,*PtrToENode;
typedef PtrToENode Edge;


typedef struct AdjVNode // 定以点结构
{
    Vertex AdjV;    //邻接点下标
    WeightType Weight;  //边权重
    AdjVNode *Next;  //指向下一个邻接点的指针
} AdjVNode,*PtrToAdjVNode;


typedef struct VNode //定义表头结构
{
    PtrToAdjVNode FirstEdge;    //第一条边的地址（一个指针变量）
    DataType Data;  //存顶点的数据
} VNode,*PtrToVNode, AdjList[MaxVertexNum];


typedef struct GNode // 图节点
{
    int vexnum; //顶点数
    int arcnum; //边数
    AdjList G;  //顶点表
} GNode,*PtrToGNode;

typedef PtrToGNode LGraph;   //图的结构

LGraph CreateGraph(int VertexNum) // 创建个图，并且定义顶点的编号。
{
    Vertex V; // 定义图的最顶点节点为v。
    LGraph Graph; // 此图的存储方式为邻接表的存储图的图类型。

    Graph = (PtrToGNode)malloc(sizeof(GNode));
    Graph->vexnum = VertexNum; // 所有的节点都连在一起。
    Graph->arcnum = 0; //图的最外边是 0 ，也就是说所有的边在图内。

    for(V=0; V<Graph->vexnum; V++) //从最顶点节点开始循环探索，若小于图的的节点的数量，每次循环后编码加一
    {
        Graph->G[V].FirstEdge = NULL;  // 循环到最后一个节点的边和最顶点节点的边连在一起是结束，也就是围成一个圈。
    }
    return Graph;
}

void InsertEdge(LGraph Graph,Edge E) // 差入边，规定改图的所有边的集合为 E
{
    PtrToAdjVNode NewNode;

    NewNode = (PtrToAdjVNode)malloc(sizeof(AdjVNode));
    NewNode->AdjV = E->V2;
    NewNode->Weight = E->Weight; // 新的节点的权重就是下一条边的权重。
    NewNode->Next = Graph->G[E->V1].FirstEdge; // 新节点的后继是图第一条边的后继。
    Graph->G[E->V1].FirstEdge = NewNode;

    //  这里指图的节点通过 有方向的边线 首尾连在一起。 （有向图)

    NewNode = (PtrToAdjVNode)malloc(sizeof(AdjVNode));
    NewNode->AdjV = E->V1;
    NewNode->Weight = E->Weight;
    NewNode->Next = Graph->G[E->V2].FirstEdge;
    Graph->G[E->V2].FirstEdge = NewNode;

    // 这个也是指图的节点通过 有方向的边线 首尾连在一起，和上面的结合，就是v1，v2两点都可以互通 （无向图）
}

LGraph BuildGraph() // 构建以邻接表存储的类型的图。
{
    LGraph Graph; // 构建图。
    Edge E;  // 边
    Vertex V;  //节点
    int Nv;  //定义的节点

    scanf("%d", &Nv); // 输入节点。
    printf("Please input the number of Vertex\n"); // 输出节点的数量。
    Graph = CreateGraph(Nv); //最后得到的图包含所有的节点。

    scanf("%d", &(Graph->arcnum)); //输入图的边的数量。
    printf("Please input the number of Edge\n");

    if (Graph->arcnum != 0)  // -> 指的是图中边的数量。
    {
        E = (PtrToENode) malloc(sizeof(ENode)); // 输入边这条边的信息 比如是哪个点到哪个点，边的的权重什么的。
        for (int i = 0; i < Graph->arcnum; i++)  // 定义i从0开始循环，i的编码数小于该图的边数，每次循环加一。
        {
            scanf("%d %d %d", &E->V1, &E->V2, &E->Weight); // 输入，因为是无向图所有边可以指向两个节点。
            printf(" V1 V2 Weight \n "); //输出两个节点和权重。
            InsertEdge(Graph, E); // 插入图的边。
        }
    }
    for (V = 0; V < Graph->vexnum; V++)
    {
        scanf(" %c", &(Graph->G[V].Data));
    }
}



void Print(LGraph Graph)
{
    for(int i=0; i<Graph->vexnum; i++) //循环节点。
    {
        printf("G[%d]->",i); // 输出图的边取整数，和节点i的编号。
        PtrToAdjVNode p,q;
        p = Graph->G[i].FirstEdge; // p为图的第一条边。

        while(p!=NULL) // 循环图的所有边。
        {
            printf("%d(%d)->",p->AdjV,p->Weight); //输出p连接的节点，和p这条边的权重。
            p = p->Next; // 一条接一条的探索

        }
        if(p==NULL)  // 若p什么也不是，直接输出。
        {
            printf("NULL");
        }
        printf("\n");  // 换行码。
    }
}

// here are some util function which used to do some trick works.
// data extract
std::vector<std::string> data_extract(std::string file_path);
// hanming
int hanming_distance(std::string string1, std::string string2);

int main()
{
    //data extract
    std::vector<std::string> data = data_extract(FILE_PATH);

    // test output
    std::string test1 = data[0];
    std::string test2 = data[1];
    int index = 1;
    for (auto & i : data){
        std::cout << index << " " << i << std::endl;
        index ++;
    }

    std::cout << "the hanming distance of the test1 and test2 is: " << hanming_distance(test1, test2) << std::endl;

    LGraph Graph;

    Graph = BuildGraph();

    Print(Graph);

    Edge E;
    E = (PtrToENode)malloc(sizeof(ENode));

    return 0;
}

std::vector<std::string> data_extract(std::string file_path) {
    std::string temp;
    std::vector<std::string> data;
    std::ifstream file(file_path);
    while (getline(file, temp)){
        data.push_back(temp);
    }
    return data;
}

int hanming_distance(std::string string1, std::string string2)
{
    int sum = 0,n = 0;
    if  (string1.length() == string2.length())
    {
        for (int i = 0; i < string1.length(); i++)
        {
            if (string1.substr(i,n+1) != string2.substr(i,n+1))
                ++ sum;
        }
        return sum;
    }
    else{
        std::cout<< string1.length() << std::endl << string2.length() << std::endl;
        std::cout<< "The length of the strings are not equivalence." << std::endl;
        return 0;
    }
}
