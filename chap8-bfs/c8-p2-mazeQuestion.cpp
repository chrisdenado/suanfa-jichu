#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<memory.h>
using namespace std;
//POJ4127, 迷宫问题. 带回溯路径, 用vector加head,tail模拟队列
struct point
{
    int x,y;
    point() {x=0; y=0;}
    point(int xx, int yy): x(xx), y(yy) {}
};

struct step
{
    point cur_p;
    int num, last_id;
    step() {}
    step(point cp, int lid, int s):cur_p(cp), last_id(lid), num(s) {}
};

int main()
{
    vector<vector<int>> wall(5, vector<int>(5, 0)), visited(5, vector<int>(5, 0));
    int tmp = 0;
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            cin>>tmp;
            if(tmp) wall[i][j] = 1;
        }
    }
    vector<step> bfs; //vector 和head, tail模拟队列
    bfs.push_back(step(point(), 0, 0));
    visited[0][0] = 1;

    vector<point> res;
    int head=0, tail=1; //队列的队尾和队头
    while(head != tail)
    {
        step s = bfs[head];
        point cp = s.cur_p;
        int x = cp.x, y = cp.y, n = s.num;
        if( x == 4 && y == 4 )
        {
            res.push_back(cp);
            while (n-- > 0) {
                s = bfs[s.last_id];
                res.push_back(s.cur_p);
            }
            break;
        }

        if( y-1>=0 && !wall[x][y-1] && !visited[x][y-1]) { visited[x][y-1] = 1; bfs.push_back(step(point(x,y-1), head, n+1));}
        if( y+1<=4 && !wall[x][y+1] && !visited[x][y+1]) { visited[x][y+1] = 1; bfs.push_back(step(point(x,y+1), head, n+1));}
        if( x-1>=0 && !wall[x-1][y] && !visited[x-1][y]) { visited[x-1][y] = 1; bfs.push_back(step(point(x-1,y), head, n+1));}
        if( x+1<=4 && !wall[x+1][y] && !visited[x+1][y]) { visited[x+1][y] = 1; bfs.push_back(step(point(x+1,y), head, n+1));}
        head++;
        tail = bfs.size();
    }
    for(int i=res.size()-1; i>=0; i--)
    {
        cout<<"("<<res[i].x<<", "<<res[i].y<<")"<<endl;
    }

    return 0;
}

