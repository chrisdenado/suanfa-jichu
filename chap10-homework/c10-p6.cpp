#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
//献给阿尔吉侬的花束, 典型广搜问题

struct point
{
    int r,c, s;
    point() {}
    point(int rr, int cc, int step):r(rr), c(cc), s(step) {}
};

int main()
{
    int n;
    cin>>n;
    while(n-- > 0)
    {
        int r,c;
        cin>>r>>c;
        vector<vector<char>> situ(r, vector<char>(c, '.'));
        vector<vector<int>> flag(r, vector<int>(c, 0));
        point start;
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                cin>>situ[i][j];
                if(situ[i][j] == 'S')
                {
                    start.r = i;
                    start.c = j;
                    start.s = 0;
                }
            }
        }
        queue<point> bfs;
        int step=0, success=0;
        bfs.push(start);
        while (!bfs.empty()) {
            point temp = bfs.front();
            bfs.pop();
            int x=temp.r, y=temp.c, s=temp.s;
            if(situ[x][y] == 'E')
            {
                success = 1;
                step = s;
                break;
            }
            flag[x][y] = 1;
            if(x-1 >= 0 && flag[x-1][y] == 0 && situ[x-1][y] != '#') bfs.push(point(x-1,y, s+1));
            if(x+1 < r && flag[x+1][y] == 0 && situ[x+1][y] != '#') bfs.push(point(x+1,y, s+1));
            if(y-1 >= 0 && flag[x][y-1] == 0 && situ[x][y-1] != '#') bfs.push(point(x,y-1, s+1));
            if(y+1 < c && flag[x][y+1] == 0 && situ[x][y+1] != '#') bfs.push(point(x,y+1, s+1));
        }
        if(success) cout<<step<<endl;
        else cout<<"oop!"<<endl;
    }
    return 0;
}
