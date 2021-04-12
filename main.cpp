#include<cstdlib>
#include<cstdio>
#include<iostream>
#include<string.h>

#define MaxVertexNum 750
typedef int Vertex;
typedef int WeightType;
typedef char DataType;

{
int hanmingDistance(int v1, int v2); {
    {
        {
            int hanming = v1 ^v2;
            int count = 0;
            while (hanming != 0) {
                hanming = hanming & (hanming - 1);
                count++;
            }
            return count;
        }  //计算汉明距离。
        typedef struct ENode; //定义边结构
        {
            Vertex v1, v2;
            WeightType Weight;
        } ENode, *PtrtoENode;
        typedef PtrtoENode Edge;

        typedef struct ADjVNode; // 定义点结构
        {
            Vertex ADjV;
            WeightType Weight;
            ADjVNode *Next;
        } ADjVNode, *PtrToAdjVNode;

        typedef struct VNode; // 顶点表头节点
        {
            PtrToAdjVNode FirstEdge; // 第一条边的地址 （一指针变量）
            DataType Data;
        } VNode, PtrToVNode, ADjList[MaxVertexNum];

        typedef struct GNode;  //图节点
        {
            int vexnum;  //顶点数
            int arcnum;  //边数
            ADjList G; // 顶点表
        } GNode, *PtrToGNode;

        typedef PtrToGNode LGraph;

        LGraph CreateGraph(int VexNum) // 创建个图，并且定义顶点的编号。
        {
            Vertex V; // 定义图的最顶点节点V。
            LGraph Graph; // 此图的存储方式为邻接表的存储图的图类型。

            Graph->vexnum = VexNum; // 所有的节点都连在一起。
            Graph->arcnum = 0; // 图的最外边的边数是0，也就是说所有的边都在图内。

            for (V = 0; V < Graph->vexnum; V++) // 从最顶点节点开始循环探索，若小于图的的节点的数量，每次循环后编码加一。
            {
                Graph->G[V].FirstEdge = NULL; //循环到最后一个节点的边和最顶点节点的边连在一起是结束，也就是围成一个圈。
            }

            return Graph;

        }

        void InsertEdge(LGraph Graph, Edge E);// 插入边，规定该图所有的边为集合 E 。
        {
            PtrToAdjVNode NewNode;
            {
                NewNode = (PtrToAdjVNode) malloc(sizeof(ADjVNode));
                NewNode->ADjV = E->v2;
                NewNode->Weight = E->Weight; // 新节点的权重就是下一条边的权重
                NewNode->Next = Graph->G[E->v1].FirstEdge; // 新节点的后继是图第一条边的后继。
                Graph->G[E->v1].FirstEdge = NewNode;
            }

            // 这里指图的节点通过 有方向的边线 首尾连在一起。 （有向图）

            {
                NewNode = (PtrToAdjVNode) malloc(sizeof(ADjVNode));
                NewNode->ADjV = E->v1;
                NewNode->Weight = E->Weight;
                NewNode->Next = Graph->G[E->v2].FirstEdge;
                Graph->G[E->v2].FirstEdge = NewNode;

                // 这个也是指图的节点通过 有方向的边线 首尾连在一起，和上面的结合，就是v1，v2两点都可以互通 （无向图）

            }
        }

        LGraph BuildGraph(); // 构建以邻接表存储图的类型的图。
        {
            LGraph Graph; // 构建图。
            Edge E;  //边
            Vertex V;   //节点
            int vexnum;  // 定义的节点。

            scanf("%d", &vexnum); // 输入节点。
            printf("number of the vexter\n");  // 输出节点的数量。
            Graph = CreateGraph(vexnum);// 最后得到的图包含所有节点。

            scanf("%d", &(Graph->arcnum));  // 输入图的边的数量。
            printf("number of the Edge\n");

            if (Graph->arcnum != 0)  // -> 指的是图中的边的数量。
            {
                E = (PtrtoENode) malloc(sizeof(ENode)); // 输入边这条边的信息 比如是哪个点到哪个点，边的的权重什么的。
                for (int i = 0; i < Graph->arcnum; ++i)  // 定义i从0开始循环，i的编码数小于该图的边数，每次循环加一。
                {
                    scanf("%d %d %d", &E->v1, &E->v2, &E->Weight); // 输入，因为是无向图所有边可以指向两个节点。
                    printf(" v1 v2 Weight \n"); // 输出两个节点和权重。
                    InsertEdge(Graph, E); // 插入图的边
                }
                for (V=0;V<Graph->vexnum; V++)
               {
                scanf("%c",&(Graph->G[V].Data));
               }
            }
        }

            return Graph;
        };


        void Print(LGraph Graph);
        {
            for (int i = 0; i < Graph->vexnum; i++) // 循环节点。
            {
                int i;
                printf("Graph[%d]->", i); // 输出图的边取整数，和节点i的编号。
                PtrToAdjVNode p, q;
                p = Graph->G[i].FirstEdge; // p为图的第一条边。

                while (p != NULL) // 循环图的所有边。
                {
                    printf("%d%d", p->ADjV, p->Weight); //输出p连接的节点，和p这条边的权重。
                    p = p->Next; // 一条接一条的探索。
                }
                if (p == NULL) {
                    printf("NULL"); // 若p什么也不是，直接输出。
                }
                printf("\n");  // 换行码。
            }
        }

        int main();
        {
            LGraph Graph;
            Graph = BuildGraph();
            print(Graph);
            Edge E;
            E = (PtrtoENode) malloc(sizeof(ENode));

            return 0;  //
        }

    }

}

