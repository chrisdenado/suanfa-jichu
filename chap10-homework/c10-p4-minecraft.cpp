#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
//Minecraft, 枚举, 注意转换

int main()
{
    int n;
    cin>>n;
    while(n-- > 0)
    {
        int m;
        cin>>m;
        int min_num=1<<30;
        for(int l=1; l<=m; l++)
        {
            for(int w=1; w<=m; w++)
            {
                for(int h=1; h<=m; h++)
                {
                    int V = l*w*h;
                    if( V > m ) break;
                    else if(V == m)
                    {
                        int A = 2*l*w + 2*l*h + 2*w*h;
                        if(A < min_num) min_num = A;
                    }
                }
            }
        }
        cout<<min_num<<endl;
    }
}
