#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

struct room
{
    int i,j;
    room() {}
    room(int ii, int jj):i(ii),j(jj) {}
};

int main()
{
    int m,n;
    cin>>m>>n;
    vector<vector<int>> wall(m+5, vector<int>(n+5, 0)), flag(m+5, vector<int>(n+5, 0));
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>wall[i][j];
        }
    }
    int roomNum=0, roomArea=0, maxNum=0;
    stack<room> sta;
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(!flag[i][j])
            {
                roomNum += 1;
                roomArea = 0;
                sta.push(room(i,j));

                while (!sta.empty()) {
                    room temp = sta.top();
                    sta.pop();
                    int x=temp.i, y=temp.j;
                    if( x<0 || x>=m || y<0 || y>=n) continue;
                    if(flag[x][y]) continue;

                    roomArea += 1;
                    flag[x][y] = roomNum;
                    if( (wall[x][y] & 1) == 0 ) sta.push(room(x,y-1));
                    if( (wall[x][y] & 2) == 0 ) sta.push(room(x-1,y));
                    if( (wall[x][y] & 4) == 0 ) sta.push(room(x,y+1));
                    if( (wall[x][y] & 8) == 0 ) sta.push(room(x+1,y));
                }
                maxNum = max(maxNum, roomArea);
            }
        }
    }
    cout<<roomNum<<endl;
    cout<<maxNum<<endl;
    return 0;
}
