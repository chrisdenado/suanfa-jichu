#include<iostream>
#include<memory.h>
#include<vector>
#include<algorithm>
using namespace std;

int res[15][9][9][9][9], sum[9][9] = {0};

int calSum(int x1, int y1, int x2, int y2)
{
    return sum[x2][y2] - sum[x1-1][y2] - sum[x2][y1-1] + sum[x1-1][y1-1];
}

int fun_pow2(int n, int x1, int y1, int x2, int y2)
{
    if(res[n][x1][y1][x2][y2] != -1) return res[n][x1][y1][x2][y2];
    if(n == 1)
    {
        int t = calSum(x1,y1,x2,y2);
        res[n][x1][y1][x2][y2] = t*t;
        return t*t;
    }
    int MIN = 0x7fffffff;
    for(int i=x1; i<x2; i++)
    {
        int p1 = calSum(i+1, y1, x2, y2);
        int p2 = calSum(x1, y1, i, y2);
        int t = min(fun_pow2(n-1,x1,y1,i, y2) + p1*p1, fun_pow2(n-1, i+1, y1, x2,y2) + p2*p2);
        if(MIN > t)  MIN = t;
    }
    for(int i=y1; i<y2; i++)
    {
        int p1 = calSum(x1, i+1, x2, y2);
        int p2 = calSum(x1, y1, x2, i);
        int t = min(fun_pow2(n-1,x1,y1,x2, i) + p1*p1, fun_pow2(n-1, x1, i+1, x2,y2) + p2*p2);
        if(MIN > t)  MIN = t;
    }
    res[n][x1][y1][x2][y2] = MIN;
    return MIN;
}

int main()
{
    memset(res, -1, sizeof(res));
    int n;
    cin>>n;

    for(int i=1;i<9;i++)
    {
        for(int j=1; j<9; j++)
        {
            int tmp;
            cin>>tmp;
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + tmp;
        }
    }
    double result = n*fun_pow2(n, 1,1,8,8);
    result -= sum[8][8]*sum[8][8];
    cout.precision(3);
    cout.flags(ios::fixed);
    cout<<sqrt(result/(n*n))<<endl;
    return 0;
}
