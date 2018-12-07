#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//POJ1724, 寻路问题。 注意剪枝
struct Road
{
    int toD,len,cost;
    Road() {}
    Road(int d, int l, int c):toD(d),len(l),cost(c){}
};

void dfs(int id, int N, int K, int &totalLen, int &totalCost, int &minLen, vector<int> &visit, vector<vector<int>> &minCost_Len, const vector<vector<Road>> &road)
{
    if(id == N)
    {
        minLen = min(minLen, totalLen);
        return;
    }
    for(int i=0; i<road[id].size(); i++)
    {
        int d = road[id][i].toD;
        if(!visit[d])//未走到该城市
        {
            int cost = road[id][i].cost + totalCost;
            int len = totalLen + road[id][i].len;
            if( cost > K ) continue;
            if( len>=minLen || len>=minCost_Len[d][cost] ) continue;//如果当前长度已大于最优长度，或在当前位置，有性价比更高的路径，则剪枝

            totalLen += road[id][i].len;
            totalCost += road[id][i].cost;
            visit[d] = 1;
            minCost_Len[id][cost] = len; //前面已经判断len<minCost_Len[id][cost],所以不需要再做比较。不加上此处剪枝会超时.
            dfs(d, N, K, totalLen, totalCost, minLen, visit, minCost_Len, road);
            totalLen -= road[id][i].len; //恢复
            totalCost -= road[id][i].cost;
            visit[d] = 0;
        }
    }

}
int main()
{
    int K,N,R;
    cin>>K>>N>>R;
    vector<vector<Road>> road(N+5);

    for(int i=0;i<R;i++)
    {
        int s,d,l,t;
        cin>>s>>d>>l>>t;
        if(s!=d)
            road[s].push_back(Road(d,l,t));
    }
    int totalLen=0, totalCost=0, minLen=1<<30;
    vector<vector<int>> minCost_Len(N+5, vector<int>(K+5, 1<<30));
    vector<int> visit(N+5, 0);
    dfs(1, N, K, totalLen, totalCost, minLen, visit, minCost_Len, road);
    if(minLen < (1<<30)) cout<<minLen<<endl;
    else cout<<-1<<endl;
    return 0;
}
