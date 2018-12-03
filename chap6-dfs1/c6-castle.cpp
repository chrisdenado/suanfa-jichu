#include<iostream>
#include<memory.h>
#include<vector>
#include<queue>
#include<algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;

void dfs( int i, int j,const int &m, const int &n, int &roomNum, int &roomArea, const vector<vector<int>> &wall, vector<vector<int>> &flag)
{
    if((i<0||i>=m) || (j<0||j>=n)) return;
    if(flag[i][j]) return;

    flag[i][j] = roomNum;
    roomArea++;
    if((wall[i][j] & 1) == 0) dfs(i, j-1, m, n, roomNum, roomArea, wall, flag);
    if((wall[i][j] & 2) == 0) dfs(i-1, j, m, n, roomNum, roomArea, wall, flag);
    if((wall[i][j] & 4) == 0) dfs(i, j+1, m, n, roomNum, roomArea, wall, flag);
    if((wall[i][j] & 8) == 0) dfs(i+1, j, m, n, roomNum, roomArea, wall, flag);
}

int main()
{
    int m,n;
    cin>>m>>n;
    vector<vector<int>> wall(m+5, vector<int>(n+5, 0)), flag(m+5, vector<int>(n+5, 0));
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>wall[i][j];
        }
    }
    int roomNum=0, roomArea=0, maxNum=0;
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(!flag[i][j])
            {
                roomNum += 1;
                roomArea = 0;
                dfs(i, j, m, n, roomNum, roomArea, wall, flag);
                maxNum = max(maxNum, roomArea);
            }
        }
    }
    cout<<roomNum<<endl;
    cout<<maxNum<<endl;
    return 0;
}
