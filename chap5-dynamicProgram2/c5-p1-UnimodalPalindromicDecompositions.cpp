#include<iostream>
#include<memory.h>
#include<vector>
#include<queue>
#include<algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;
//OJ1221, 参考https://blog.csdn.net/daniel_csdn/article/details/52027206
long long dp(int n, int k, vector<vector<long long>> &array)
{
    if(n==0 || k==0) return 1;
    if(n==k) return 1;
    if(n<k) return 0;

    if(array[n][k] > 0) return array[n][k];
    long long ret=1;
    for(int i=k; 2*i<=n; i++)
        ret += dp(n-2*i, i, array);
    array[n][k] = ret;
    return ret;
}

int main()
{
    int n;
    cin>>n;
    vector<vector<long long>> array(255, vector<long long>(255,0));
    while (n!=0) {
        long long ans=0;
        for(int i=0; 2*i<=n; i++)
            ans += dp(n-2*i, i, array);
        cout<<n<<" "<<ans<<endl;
        cin>>n;
    }
    return 0;
}