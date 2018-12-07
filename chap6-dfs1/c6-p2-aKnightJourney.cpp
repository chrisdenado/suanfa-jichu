#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//POJ2488: A Knight's Journey
struct chass
{
    int x, y;
    chass() {}
    chass(int xx, int yy):x(xx), y(yy) {}
};

bool dfs(int cur_id, int x, int y, int p, int q, vector<chass> &path, vector<vector<int>> &visited)
{
    if(cur_id == p*q) return true;
    if( x<0 || x>=p || y<0 || y>=q ) return false;
    if( visited[x][y] ) return false;

    path.push_back(chass(x, y));
    visited[x][y]=1;
    if( dfs(cur_id+1, x-1, y-2, p, q, path, visited) ) return true;
    if( dfs(cur_id+1, x+1, y-2, p, q, path, visited) ) return true;
    if( dfs(cur_id+1, x-2, y-1, p, q, path, visited) ) return true;
    if( dfs(cur_id+1, x+2, y-1, p, q, path, visited) ) return true;
    if( dfs(cur_id+1, x-2, y+1, p, q, path, visited) ) return true;
    if( dfs(cur_id+1, x+2, y+1, p, q, path, visited) ) return true;
    if( dfs(cur_id+1, x-1, y+2, p, q, path, visited) ) return true;
    if( dfs(cur_id+1, x+1, y+2, p, q, path, visited) ) return true;
    visited[x][y]=0;
    path.pop_back();
    return false;
}

int main()
{
    int t;
    cin>>t;
    for(int i=1; i<=t; i++)
    {
        int p, q;
        cin>>p>>q;
        vector<vector<int>> visited(p, vector<int>(q,0));
        vector<chass> path;
        cout<<"Scenario #"<<i<<":"<<endl;
        if( dfs(0, 0, 0, p, q, path, visited) )
        {
            string res;
            for(int i=0; i<path.size(); i++)
            {
                res += path[i].y + 'A';
                res += path[i].x + '1';
            }
            cout<<res<<endl;
        }
        else cout<<"impossible"<<endl;
        cout<<endl;
    }

    return 0;
}
