#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int To[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};

bool isIn(int x, int y, int w, int h)
{
    return ( x>-1 && x<h+2 && y>-1 && y<w+2 );
}

void search(const vector<vector<int>> &card, vector<vector<int>> &mark, int &min_step, int step, int forward, \
            int cur_x, int cur_y, int end_x, int end_y, int w, int h)
{
    if(step >= min_step) return;
    if(cur_x==end_x && cur_y==end_y)
    {
        if(min_step > step) min_step = step;
        return;
    }
    for(int i=0; i<4; i++)
    {
        int x = cur_x + To[i][0];
        int y = cur_y + To[i][1];
        if( isIn(x,y,w,h) && ( (card[x][y] != 1 && mark[x][y] != 1) || (x==end_x && y==end_y) )) //mark的作用避免在i 和i+1之间产生死循环
        {
            mark[x][y] = 1;
            if(i == forward) search(card, mark, min_step, step, i, x, y, end_x, end_y, w, h);
            else search(card, mark, min_step, step+1, i, x, y, end_x, end_y, w, h);
            mark[x][y] = 0;
        }
    }

}

int main()
{
    int w,h;
    cin>>w>>h;
    int board_num=0;
    char in;

    while( w!=0 && h!=0 )
    {
        vector<vector<int>> card(h+2, vector<int>(w+2, 0)), mark(h+2, vector<int>(w+2, 0));
        for(int i=1; i<h+1; i++)
        {
            getchar();
            for(int j=1; j<w+1; j++)
            {
                in = getchar();
                if(in == 'X') card[i][j] = 1;
            }
        }

        int begin_x, begin_y, end_x, end_y;
        cin>>begin_y>>begin_x>>end_y>>end_x;
        vector<int> temp;
        while( begin_x!=0 &&begin_y!=0 && end_x!=0 && end_y!=0 )
        {
            int min_step = 0x7fffffff, step = 0;
            search(card, mark, min_step, step, -1, begin_x, begin_y, end_x, end_y, w, h);
            temp.push_back(min_step);
            cin>>begin_y>>begin_x>>end_y>>end_x;
        }
        cin>>w>>h;

        cout<<"Board #"<<++board_num<<":"<<endl;
        for(int i=0; i<temp.size(); i++)
        {
            if(temp[i] != 0x7fffffff) cout<<"Pair "<<i+1<<": "<<temp[i]<<" segments."<<endl;
            else cout<<"Pair "<<i+1<<": "<<"impossible."<<endl;
        }
        cout<<endl;
    }

    return 0;
}
