#include<iostream>
#include<memory.h>
#include<vector>
#include<algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;
//OJ2978 help jimmy
#define LEFT 0
#define RIGHT 1

struct board
{
    int l, r, h;
    board(int a,int b,int c):l(a),r(b),h(c){}
    board():l(0),r(0),h(0){}
};

bool comp(board a, board b)
{
    return a.h > b.h; //高度由大到小
}

int findNext( int cur_id, const vector<board> &b, int flag)
{
    int x = b[cur_id].l;
    if(flag == RIGHT) x = b[cur_id].r;
    for(int i=cur_id+1; i<b.size(); i++)
    {
        if( b[i].l <= x && b[i].r >= x )
            return i;
    }
}

int findFirst(int x, int h, const vector<board> &b)
{
    for(int i=0; i<b.size(); i++)
    {
        if(b[i].h < h && b[i].l <= x && b[i].r >= x)
            return i;
    }
}

int getMin( int cur_id, int x, int MAX, const vector<board> &b, vector<vector<int>> &array )
{
    if( b[cur_id].h == 0 ) return 0;
    int left_id, right_id, left_num, right_num, min_num;

    left_id = findNext(cur_id, b, LEFT);
    if( b[cur_id].h - b[left_id].h > MAX ) left_num = 10000000;
    else
    {
        int temp = array[cur_id][LEFT];
        if(temp == -1)
        {
            temp = (b[cur_id].h - b[left_id].h) + getMin(left_id, b[cur_id].l, MAX, b, array);
            array[cur_id][LEFT] = temp;
        }
        left_num = (x - b[cur_id].l) + temp;

    }

    right_id = findNext(cur_id, b, RIGHT);
    if( b[cur_id].h - b[right_id].h > MAX ) right_num = 10000000;
    else
    {
        int temp = array[cur_id][RIGHT];
        if(temp == -1)
        {
            temp = (b[cur_id].h - b[right_id].h) + getMin(right_id, b[cur_id].r, MAX, b, array);
            array[cur_id][RIGHT] = temp;
        }
        right_num = (b[cur_id].r - x) + temp;
    }
    min_num = min(left_num, right_num);

    return min_num;
}

int main()
{
    int num;
    cin>>num;
    for(int i=0; i<num; i++)
    {
        int board_num, x0, h0, MAX;
        cin>>board_num>>x0>>h0>>MAX;
        vector<board> b(board_num);
        vector<vector<int>> array(board_num+1, vector<int>(2, -1)); //每个板子的左边最短路径和右边最短路径。
        board ground(-20000, 20000, 0);

        for(int j=0; j<board_num; j++)
            cin>>b[j].l>>b[j].r>>b[j].h;
        b.push_back(ground);
        sort(b.begin(), b.end(), comp);

        int cur_id = findFirst(x0, h0, b);
        int MIN = h0 - b[cur_id].h + getMin(cur_id, x0, MAX, b, array);
        cout<<MIN<<endl;
    }
    return 0;
}

