#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//数学推导见 https://blog.csdn.net/tp7309/article/details/53142265
int main()
{
    int res[31] = {0};
    res[0] = 1;
    res[2] = 3;
    for(int i=2; i<=15; i++)
    {
        res[2*i] = 4*res[2*i-2] - res[2*i-4];
    }
    int n;
    cin>>n;
    while (n!=-1) {
        cout<<res[n]<<endl;
        cin>>n;
    }
    return 0;
}
