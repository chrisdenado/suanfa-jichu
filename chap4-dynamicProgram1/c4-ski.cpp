#include<iostream>
#include<memory.h>
#include<vector>
#include<algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;
//OJ1088, 滑雪
typedef struct
{
    int i, j, h;
}loc_height;

bool comp(loc_height a, loc_height b)
{
    return a.h < b.h;
}

int main()
{
    int m,n;
    cin>>m>>n;
    vector<loc_height> height_str(m*n);
    vector<vector<int>> height_2d(m+2, vector<int>(n+2, -1));
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            int h;
            cin>>h;
            height_str[i*n+j].i = i+1;
            height_str[i*n+j].j = j+1;
            height_str[i*n+j].h = h;
            height_2d[i+1][j+1] = h;
        }
    }
    sort(height_str.begin(), height_str.end(), comp);
    vector<vector<int>> array(m+2, vector<int>(n+2, 1));
    int MAX=0;
    for(int k=0; k<m*n; k++)
    {
        int i=height_str[k].i, j=height_str[k].j, h=height_str[k].h;
        if(height_2d[i-1][j] > h) array[i-1][j] = max(array[i-1][j], array[i][j]+1);
        if(height_2d[i+1][j] > h) array[i+1][j] = max(array[i+1][j], array[i][j]+1);
        if(height_2d[i][j-1] > h) array[i][j-1] = max(array[i][j-1], array[i][j]+1);
        if(height_2d[i][j+1] > h) array[i][j+1] = max(array[i][j+1], array[i][j]+1);
    }
    for(int k=0; k<m*n; k++)
    {
        int i=height_str[k].i, j=height_str[k].j;
        if(MAX < array[i][j]) MAX = array[i][j];
    }
    cout<<MAX<<endl;
    return 0;
}


