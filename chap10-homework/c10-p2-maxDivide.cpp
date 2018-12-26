#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <iomanip>
using namespace std;
//POJ3248, 最大公约数
int find(int x, int y)
{
    if(x == 0) return y;
    else return find(min(x, y%x), max(x, y%x));
}

int main()
{
    int x,y;
    while (cin>>x>>y) {
        cout<<find(min(x, y), max(x, y))<<endl;
    }
    return 0;
}
