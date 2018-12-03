#include<iostream>
#include<memory.h>
#include<vector>
#include<queue>
#include<algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;
//OJ2757, 最长上升子序列
int main()
{
    int N, MAX=1;
    cin>>N;
    vector<int> num(N), max_len(N,1);
    for(int i=0; i<N; i++) cin>>num[i];
    for(int i=1; i<N; i++)
    {
        for(int j=0; j<i; j++)
        {
            if(num[j] < num[i])
            {
                max_len[i] = max(max_len[i], max_len[j]+1);
            }
        }
        if(max_len[i] > MAX) MAX = max_len[i];
    }
    cout<<MAX<<endl;
    return 0;
}
