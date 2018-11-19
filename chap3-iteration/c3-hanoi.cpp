#include<iostream>
#include<memory.h>
#include<vector>
#include<algorithm>
using namespace std;

void hanoi(int n, char src, char mid, char dst)
{
    if(n == 1)
    {
        cout<<n<<":"<<src<<"->"<<dst<<endl;
        return;
    }
    hanoi(n-1, src, dst, mid);
    cout<<n<<":"<<src<<"->"<<dst<<endl;
    hanoi(n-1, mid, src, dst);
}

int main()
{
    int n;
    char src, mid, dst;
    cin>>n;
    cin>>src>>mid>>dst;
    hanoi(n, src, mid, dst);
    return 0;
}
