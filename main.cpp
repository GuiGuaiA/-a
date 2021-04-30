#include<cstdio>
#include<stdlib.h>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#define MaxVertexNum 750    //最大顶点数

// file path
#define FILE_PATH "../data.txt"
using namespace std;

// 这个？你把int重新命名为vertex？
typedef int Vertex; //顶点类型
//typedef int WeightType; //边的权重
typedef char DataType;  //顶点存储数据类型

// 这个？
// 记住现在的结构体，马上要用了。看见扣1
typedef struct AdjVNode // 定义点结构
{
      // 这个vertex是啥类型？
      //Vertex AdjV;    //邻接点下标
    string node_name; // 这个就用来存放字符串
    vector<string> ad_nodes; // 这个就用来存放与本节点直接相连的节点。
      //WeightType Weight;  //边权重
      //AdjVNode *Next;  //指向下一个邻接点的指针
} AdjVNode,*PtrToAdjVNode;


// 这个是边的结构体？
typedef struct ENode //定义边结构
{
    // 因为一条边连接两个节点，所以我们边的成员变量弄两个节点类型的变量就好了。分别表示这个线相连的两个节点。
    // 这里不能用，因为AdjVNode在边struct后面声明的，所以系统现在还不认识他
    // 你看，现在就好了。牛逼吧。
    AdjVNode node1;
    AdjVNode node2;
    //这俩节点就是一条线直接相连的节点。现在去初始化节点.
    //Vertex V1,V2;
    //WeightType Weight;
} ENode,*PtrToENode;
typedef PtrToENode Edge;



typedef struct VNode //定义表头结构
{
    PtrToAdjVNode FirstEdge;    //第一条边的地址（一个指针变量）
    DataType Data;  //存顶点的数据

} VNode,*PtrToVNode, AdjList[MaxVertexNum];


// 这个是你的节点？哈喽？
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

/*void InsertEdge(LGraph Graph,Edge E) // 差入边，规定改图的所有边的集合为 E
{
    PtrToAdjVNode NewNode;

    NewNode = (PtrToAdjVNode)malloc(sizeof(AdjVNode));
    NewNode->AdjV = E->V2;
    //NewNode->Weight = E->Weight; // 新的节点的权重就是下一条边的权重。
    NewNode->Next = Graph->G[E->V1].FirstEdge; // 新节点的后继是图第一条边的后继。
    Graph->G[E->V1].FirstEdge = NewNode;

    //  这里指图的节点通过 有方向的边线 首尾连在一起。 （有向图)

    NewNode = (PtrToAdjVNode)malloc(sizeof(AdjVNode));
    NewNode->AdjV = E->V1;
    //NewNode->Weight = E->Weight;
    NewNode->Next = Graph->G[E->V2].FirstEdge;
    Graph->G[E->V2].FirstEdge = NewNode;

    // 这个也是指图的节点通过 有方向的边线 首尾连在一起，和上面的结合，就是v1，v2两点都可以互通 （无向图）
}*/

/*LGraph BuildGraph() // 构建以邻接表存储的类型的图。
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
           // scanf("%d %d %d", &E->V1, &E->V2, &E->Weight); // 输入，因为是无向图所有边可以指向两个节点。
            printf(" V1 V2 Weight \n "); //输出两个节点和权重。
            InsertEdge(Graph, E); // 插入图的边。
        }
    }
    for (V = 0; V < Graph->vexnum; V++)
    {
        scanf(" %c", &(Graph->G[V].Data));
    }
}*/



/*void Print(LGraph Graph)
{
    for(int i=0; i<Graph->vexnum; i++) //循环节点。
    {
        printf("G[%d]->",i); // 输出图的边取整数，和节点i的编号。
        PtrToAdjVNode p;
        p = Graph->G[i].FirstEdge; // p为图的第一条边。

        while(p!=NULL) // 循环图的所有边。
        {
           // printf("%d(%d)->",p->AdjV,p->Weight); //输出p连接的节点，和p这条边的权重。
            p = p->Next; // 一条接一条的探索

        }
        if(p==NULL)  // 若p什么也不是，直接输出。
        {
            printf("NULL");
        }
        printf("\n");  // 换行码。
    }
}*/

  // here are some util function which used to do some trick works.（这里有一些实用函数，用来做一些特技。神特么特技。）
  // data extract （数据提取）
vector<string> data_extract(string file_path);  //  file path (文件路径) vector（可变大小的数组）
  //std::string是标准C++的字符串实现 (如果我们使用名空间std中的类，为了防止和其他的类库名称冲突，就需要在程序中加入语句：using namespace std )
  // hanming
int hanming_distance(string string1, string string2);  //定义汉明距离，字符串1，字符串2.


int main() {
    // data extract
    vector<string> data = data_extract(FILE_PATH);  //  取值操作。
    // 这个node_list用来存放所有的节点
    vector<AdjVNode> node_list;  // 存储点
    vector<ENode> arc_list;  // 存储边
    // 164行报错了，temp_list报错了，因为node_list没有初始化，你就给它赋值了。哦不对，也好象是我改了以后类型不统一了。不过不重要
    // vector<VNode> temp_list = node_list;

    // test output (测试输出)
    // 这个是不是我之前写的数据读取？ok 那就直接用了。现在要初始化所有节点了，你看好。
    string test1 = data[0];
    string test2 = data[1];
    int index = 1;
    for (auto &i : data) {  // 此份为两部分，冒号前部分是，i的适应性变量类型，eg--若i=1 ，则auto的类型就是整型变量，冒号后部分是i的变化的范围
        //cout << index << " " << i << endl;  //输出 指数 和 i 。
        index++;

        AdjVNode adjVNode;
        adjVNode.node_name = i;
        node_list.push_back(adjVNode);
        // 好了 初始化完了。输出一下看看效果
    }

    cout << "all node are as follow: " << endl;
    // 看 好了。但是还没好，因为我们发现每个节点的node name 后面都多了一个1.需要去掉。  我忘记了 我看看我之前咋写的。
    // 哦 上次都没有管1，这个确实也不影响，那就不管了。先跑起来再说。我们现在初始化边。但是现在需要把边的结构体搞好
    for (int i = 0; i < node_list.size(); i++) {  // 此份为两部分，冒号前部分是，i的适应性变量类型，eg--若i=1 ，则auto的类型就是整型变量，冒号后部分是i的变化的范围
        cout << i << " " << node_list[i].node_name << endl;  //输出   这个是我们输出的，看好
    }

    // 初始化所有的线
    // 需要复制一个noede list
    vector<AdjVNode> temp_list = node_list;
    for (int i = 0; i < node_list.size(); i++) {
        for (int j = 0; j < temp_list.size(); j++) {
            //hanming距离为1，连线
            //kanhao 这里是你不会的。
            if (hanming_distance(node_list[i].node_name, temp_list[j].node_name) == 1) {
                ENode eNode;
                eNode.node1 = node_list[i];
                eNode.node2 = temp_list[j];
                arc_list.push_back(eNode);
                // 然后现在所有的线都初始化好了 有不懂的码？
            }
        }
    }

    //这里开始构建邻接表
    for (int i = 0; i < node_list.size(); i++){
        // 因为你要判断任意两个节点之间都有没有边，所以，你就需要有两层循环，每一层循环都是所有的节点，这样就可以枚举出，所有的节点对的所有情况。
        // 明白了吗？
        // 现在这里的 node_list[i]就是图中的 A。即node_list中的任意一个节点。

        // 需要一个存放临时相邻节点的vector
        // buyongyekeyi
        //vector<AdjVNode>
        for (int j = 0; j < arc_list.size(); j++) {
            // 现在这里的 arc_list[j].node1 和 arc_list[j].node2 就是 B C 懂了吗？
            // 这里就是对 任意两个节点对，判断汉明距离是不是为1，是1的话，就新建一个 边arc对象，并且把这两个节点对存储下来。
            // 然后把这个对象加到arc_list


            // 然后，若arc_list[j].node1 和 arc_list[j].node2 ，即B C 中的任何一个和A相同，那么，另外一个点，就是A直接相连的点。有问题吗？
            // 我们怎么判断B C 中的任何一个和A相同？ 用字符串相等判断  string1 == string2 刚才给你说过，你看好
            if (arc_list[j].node1.node_name == node_list[i].node_name){
                node_list[i].ad_nodes.push_back(arc_list[j].node2.node_name);
            }
            // 另外一个也是相同的写法
            if (arc_list[j].node2.node_name == node_list[i].node_name){
                node_list[i].ad_nodes.push_back(arc_list[j].node1.node_name);
            }
        }
    }

    //现在就构造好邻接表了。 输出看看
    cout << "the ad list is here : " << endl;
    for (int i = 0; i < node_list.size(); ++i) {
        cout << node_list[i].node_name << endl;
        for (int j = 0; j < node_list[i].ad_nodes.size(); ++j) {
            cout << " -> " << node_list[i].ad_nodes[j];
        }
        cout << endl; //刚才输出的太丑了。再调整一下输出格式
    }

    cout << "the hanming distance of the test1 and test2 is: " << hanming_distance(test1, test2) << endl;
    //输出测试1和测试2的汉明距离
  /*  {
        for (int k,i = 0; i < node_list.size(); i++)
            // 因为你要判断任意两个节点之间都有没有边，所以，你就需要有两层循环，每一层循环都是所有的节点，这样就可以枚举出，所有的节点对的所有情况。
            // 明白了吗？
            for (int j = 0; j < node_list.size(); j++) {
                // 这里就是对 任意两个节点对，判断汉明距离是不是为1，是1的话，就新建一个 边arc对象，并且把这两个节点对存储下来。然后把这个对象加到arc_list
                if (hanming_distance(node_list[i](), temp_list[j]()) == 1) {
                    Edge k (node_list[i], temp_list[j]);
                    arc_list.push_back(k);
                }

            }

        LGraph Graph;

        Graph = BuildGraph();

        Print(Graph);

        Edge E;
        E = (PtrToENode) malloc(sizeof(ENode));
*/
        return 0;
    }

    vector<string> data_extract(string file_path)
    {  //数据提取。
        string temp;  //定义临时变量 （换数思想）
        vector<string> data;   // 提取数据。
        ifstream file(file_path);   // 已输入的方式打开文件
        while (getline(file, temp)) {  // 获取文件中的字符串和定义temp的字符串。
            data.push_back(temp); // 数据返回。
        }
        return data;
    }

    int hanming_distance(string string1, string string2) // 定义汉明距离 字符串1，字符串2.
    {
        int sum = 0, n = 0;
        if (string1.length() == string2.length())  //若字符串1的长度等于字符串2的长度，
        {
            for (int i = 0; i < string1.length(); i++) //定义i，循环字符串1的长度，
            {
                if (string1.substr(i, n + 1) != string2.substr(i, n + 1))
                    ++sum;  // 若字符串1和字符串2每有一个字符不同，则sum数值加一。
            }
            return sum;
        } else {
            cout << string1.length() << endl << string2.length() << endl; // 输出字符串1 然后换行输出字符串2.
            cout << "The length of the strings are not equivalence." << endl; //  输出长度不等的字符串。
            return 0;
        }
    }


