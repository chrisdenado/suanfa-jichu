#include<iostream>
#include<vector>
#include<algorithm>
#include<memory.h>
using namespace std;
//POJ1190, 生日蛋糕
int minVal[25] = {0}, minA[25] = {0};
int minArea = 1<<30;
int N,M;

int maxVNRH(int n, int r, int h)
{
    int v=0;
    for(int i=0; i<n; i++)
    {
        v += (r-i)*(r-i)*(h-i);
    }
    return v;
}

void dfs(int v, int m, int r, int h, int area)
{
    if( m == 0)
    {
        if( v == 0 ) minArea = min(minArea, area);
        return;
    }
    if( v < minVal[m] ) return; //最小体积大于v
    if( area + minA[m] > minArea ) return; //总面积已超过最小值
    if( h<m || r<m ) return; //无法依次递减到第1层
    if( maxVNRH(m, r, h) < v ) return; //最大体积小于v
    for(int rr=r; rr>=m; rr--)
    {
        if(m==M) area = rr*rr;
        for(int hh=h; hh>=m; hh--)
        {
            dfs(v-rr*rr*hh, m-1, rr-1, hh-1, area+2*rr*hh);
        }
    }
}

int main()
{
    cin>>N>>M;
    minVal[0] = 0;
    minA[0] = 0;
    for(int i=1; i<=M; i++)
    {
        minVal[i] = minVal[i-1] + i*i*i;
        minA[i] = minA[i-1] + 2*i*i;
    }
    if( minVal[M] > N ) //剪枝1:当前层数的最小体积都大于N,则不可能
    {
        cout<<0<<endl;
        return 0;
    }
    int rMax = sqrt(double(N-minVal[M-1])/M) +1, hMax = (N-minVal[M-1])/(M*M) +1;
    dfs(N, M, rMax, hMax, 0);
    if(minArea == 1<<30) cout<<0<<endl;
    else cout<<minArea<<endl;

    return 0;
}
