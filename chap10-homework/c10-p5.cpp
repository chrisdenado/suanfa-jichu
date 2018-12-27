#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
//猴子吃桃，找规律
int main()
{
    int n;
    cin>>n;
    while(n!=0)
    {
        if(n==2) cout<<7<<endl;
        else
        {
            int temp=1;
            for(int i=0; i<n; i++)
                temp *= n;
            cout<<(temp - n + 1)<<endl;
        }
        cin>>n;
    }
    return 0;
}
