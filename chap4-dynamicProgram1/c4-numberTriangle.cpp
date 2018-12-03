#include<iostream>
#include<memory.h>
#include<vector>
#include<algorithm>
using namespace std;
//OJ2760:数字三角形
void maxSum(int i, int j, int n, vector<int> &temp, const vector<vector<int>> &array)
{
    for(int t=n-1; t>0; t--)
    {
        for(int k=1; k<=t; k++)
        {
            temp[k] = max(temp[k], temp[k+1]) + array[t][k];
        }
    }
}

int main()
{
    int n;
    cin>>n;
    vector<vector<int>> array(n+1, vector<int>(101));
    vector<int> temp(n+1, -1);
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=i; j++)
        {
            cin>>array[i][j];
            if(i == n) temp[j] = array[i][j];
        }
    }

    maxSum(1,1,n, temp,array);
    cout<<temp[1];
    return 0;
}
