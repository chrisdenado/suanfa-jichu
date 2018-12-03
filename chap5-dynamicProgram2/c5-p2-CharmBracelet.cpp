#include<iostream>
#include<memory.h>
#include<vector>
#include<queue>
#include<algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;
//OJ4131, 典型01背包问题
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> w(n), d(n);
    for(int i=0; i<n; i++)
        cin>>w[i]>>d[i];

    vector<int> dp(13000);
    for(int i=0; i<n; i++)
    {
        for(int j=m; j>=w[i]; j--)
            dp[j] = max(dp[j], dp[j-w[i]] + d[i]);
    }
    cout<<dp[m]<<endl;
    return 0;
}