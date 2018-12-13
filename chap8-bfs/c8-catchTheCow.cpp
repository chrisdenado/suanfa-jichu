#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
//POJ4001， 抓住那头牛
struct point
{
    int loc, preloc, step;
    point() {}
    point(int l, int pl, int s): loc(l),preloc(pl),step(s) {}
};

int main()
{
    int N,K;
    cin>>N>>K;
    queue<point> bfs;
    vector<int> visited(100010,0);
    bfs.push(point(N,0,0));
    while (!bfs.empty()) {
        point p = bfs.front();
        int l=p.loc, pl=p.preloc, s=p.step;
        if( l == K )
        {
            cout<<s<<endl;
            break;
        }
        if( l-1>=0 && !visited[l-1] )
        {
            bfs.push(point(l-1, l, s+1));
            visited[l-1] = 1;
        }
        if( l+1<=100000 && !visited[l+1])
        {
            bfs.push(point(l+1, l, s+1));
            visited[l+1] = 1;
        }
        if( 2*l <= 100000 && !visited[2*l])
        {
            bfs.push(point(2*l, l, s+1));
            visited[2*l] = 1;
        }
        bfs.pop();
    }
    return 0;
}
