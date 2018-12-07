#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//POJ1321, 棋盘问题
struct chass
{
    int x,y;
    chass() {}
    chass(int xx, int yy):x(xx),y(yy) {}
};

void dfs(int k, int id, int N, int K, int &totalNum, vector<int> &col_flag, vector<int> &row_flag, const vector<chass> &chassMap)
{
    if(k >= K) {totalNum++; return;}
    if(id >= chassMap.size()) return;

    for(int i= id; i<chassMap.size(); i++)
    {
        int x = chassMap[i].x, y = chassMap[i].y;
        if( N-x < K-k ) return; //剩余的行数小于待放置的棋子，剪枝

        if( (!col_flag[x]) && (!row_flag[y]) )
        {
            col_flag[x] = 1;
            row_flag[y] = 1;
            dfs(k+1, i+1, N, K, totalNum, col_flag, row_flag, chassMap);
            col_flag[x] = 0;
            row_flag[y] = 0;
        }
    }
}

int main()
{
    int N,K;
    cin>>N>>K;
    while ( N!=-1 ) {
        vector<chass> chassMap;
        char c;
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<N; j++)
            {
               cin>>c;
               if(c == '#') chassMap.push_back(chass(i,j)); //已经按x,y排好序了
            }
        }
        int totalNum = 0;
        vector<int> row_flag(N, 0), col_flag(N, 0);
        dfs(0, 0, N, K, totalNum, col_flag, row_flag, chassMap);
        cout<<totalNum<<endl;
        cin>>N>>K;
    }

    return 0;
}
