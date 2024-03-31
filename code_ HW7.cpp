#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct EdgeNode //单链表节点
{
    int tgtIdx;
    EdgeNode* link;
};
struct GraphInAdjList
{
    int NumOfVertex;
    EdgeNode** adjLists;
};
GraphInAdjList* createGraph(int NumOfVer)
{
    GraphInAdjList* graph = (GraphInAdjList*)malloc(sizeof(GraphInAdjList));
    if (graph == NULL)
        return NULL;
    graph->NumOfVertex = NumOfVer;
    graph->adjLists = (EdgeNode**)malloc(sizeof(EdgeNode*) * NumOfVer);
    for (int i = 0; i < NumOfVer; i++)
        graph->adjLists[i] = NULL;
    return graph;
};
bool checkTopoOrder(int* topoArray, GraphInAdjList* graph)
{
    //这里申请了一个数组的内存作为检查过程临时使用，因此必须在函数返回之前free掉，
    //否则会有内存泄漏。为此我们需要在所有可能的返回路径上退出。
    int* topoOrder = (int*)malloc(sizeof(int) * graph->NumOfVertex);

    //这里的突破order实际上记录了顶点i排在第topoOrder[i]个位置上。
    for (int i = 0; i < graph->NumOfVertex; i++)
        topoOrder[topoArray[i]] = i;
    for (int v = 0; v < graph->NumOfVertex; v++) //遍历所有顶点
    {
        int topoOrderOfV = topoOrder[v];    //顶点v的排列位置。
        //遍历v的所有出边
        for (EdgeNode* cur = graph->adjLists[v]; cur != NULL; cur = cur->link)
        {
            int topoOrderOfTgt = topoOrder[cur->tgtIdx]; //目标顶点的排列位置
            if (topoOrderOfTgt < topoOrderOfV)
            {    //如果目标顶点的排列位置小于v的排列位置,则不满足要求。
                free(topoOrder);        //返回前是否内存，否则会有内存泄漏
                return false;
            }
        }
    }
    free(topoOrder);    //返回前释放内存，否则会有内存泄漏
    cout << "YES";
    return true;
}
int main()
{
    int n;
    cin >> n;
    GraphInAdjList* graph = createGraph(n);
    int* preNum = new int[n];
    for (int i = 0;i < n; i++) {
        preNum[i] = 0;
    }
    for (int i = 0;i < n;i++) {
        int num;
        cin >> num;
        while (num--) {
            int index;
            cin >> index;
            preNum[index]++;
            EdgeNode* temp = new EdgeNode;
            temp->tgtIdx = index;
            temp->link = graph->adjLists[i];
            graph->adjLists[i] = temp;
        }
    }
    int* topoArray = new int[n];
    int sortedNum = 0;
    queue<int> q0;
    for (int i = 0;i < n;i++) {
        if (preNum[i] == 0) q0.push(i);
    }
    while (!q0.empty()) {
        int curNum = q0.front();
        q0.pop();
        topoArray[sortedNum++] = curNum;
        for (EdgeNode* cur = graph->adjLists[curNum];cur != NULL;cur = cur->link) {
            preNum[cur->tgtIdx]--;
            if (preNum[cur->tgtIdx] == 0) {
                q0.push(cur->tgtIdx);
            }
        }
    }
    checkTopoOrder(topoArray, graph);
    return 0;
}
