#include<iostream>
#include<memory.h>
#include<vector>
#include<algorithm>
using namespace std;

void maxSum(int i, int j, int n, vector<int> &temp, const vector<vector<int>> &array)
{
    for(int t=n-1; t>=i; t--)
    {
        for(int k=1; k<=t; k++)
        {
            temp[k] = max(temp[k], temp[k+1]);
            temp[k] = max(temp[k], array[t][k]);
        }
    }
}

int main()
{
    int n;
    cin>>n;
    while(n!=0)
    {
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
        int end_i, end_j;
        cin>>end_i>>end_j;
        maxSum(end_j,end_j,n, temp,array);
        cout<<temp[end_j]<<endl;
        cin>>n;
    }
    return 0;
}
