#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
//POJ1753, Flip Games, with BFS
int MAX=70000; // > 2^16
int b=0, w=1; //黑色为0,白色为1

int strToInt(string s)
{
    int res = 0;
    for(int i=15; i>=0; i--) //以输入的右下角为最高为，左上角为最低位
    {
        res *= 2;
        if( s[i] == 'w' ) res += 1; //白色记为1
    }
    return res;
}
int xor_n(int n, int dig) //对指定位取反
{
    return n^=(1<<dig);
}
struct pos
{
    int n, step;
    pos() {}
    pos(int nn, int s):n(nn), step(s){}
};

int main()
{
    vector<int> visited(MAX, 0);
    string s, temp;
    for(int i=0; i<4; i++)
    {
        cin>>temp;
        s += temp;
    }
    queue<pos> bfs;
    int n = strToInt(s);
    bfs.push(pos(n, 0));
    visited[n] = 1;

    while (!bfs.empty()) {
        pos cur = bfs.front();
        n = cur.n;
        if(n == 0 || n == 65535)
        {
            cout<<cur.step<<endl;
            return 0;
        }
        for(int i=0; i<16; i++)
        {
            int n1 = xor_n(n, i);
            if(!visited[n1]) { visited[n1] = 1; bfs.push(pos(n1, cur.step+1)); }
            int row = i/4, col = i%4;
            if( col-1 >= 0 ) n1 = xor_n(n1, i-1);
            if( col+1 < 4 ) n1 = xor_n(n1, i+1);
            if( row-1 >= 0 ) n1 = xor_n(n1, i-4);
            if( row+1 < 4) n1 = xor_n(n1, i+4);
            if(!visited[n1]) { visited[n1] = 1; bfs.push(pos(n1, cur.step+1)); }
        }
        bfs.pop();
    }
    cout<<"Impossible"<<endl;
    return 0;
}
