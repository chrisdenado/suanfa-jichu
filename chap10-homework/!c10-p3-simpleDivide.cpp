#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
//POJ4117, 简单整数划分. (后续可尝试POJ4119，复杂得整数划分)
//解析参考(整数划分及变种):https://www.cnblogs.com/jinhong123/p/7909689.html
int GetNum(int n, int m, vector<vector<int>> &dp)
{
    if(dp[n][m] != 0) return dp[n][m];
    else {
        if(n == 1 || m == 1) dp[n][m] = 1;
        else if(n == m) dp[n][m] = GetNum(n, n-1, dp) + 1;
        else if(m > n) dp[n][m] = GetNum(n, n, dp);
        else if(n > m) dp[n][m] = GetNum(n-m, m, dp) + GetNum(n, m-1, dp);
    }
    return dp[n][m];
}

int main()
{
    int N;
    while(cin>>N)
    {
        vector<vector<int>> dp(N+1, vector<int>(N+1, 0));
        cout<<GetNum(N,N,dp)<<endl;
    }
    return 0;
}
