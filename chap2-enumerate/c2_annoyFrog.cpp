#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//恼人的青蛙

typedef struct
{
    int x;
    int y;
}plants;

bool comp(plants a, plants b)
{
    if(a.x == b.x) return a.y < b.y;
    else return a.x < b.x;
}

int search_path(const vector<plants> &v_plants, plants p2, int dx, int dy, int R, int C)
{
    int steps = 2; //已包含p1,p2两个点
    p2.x += dx;
    p2.y += dy;
    while( p2.x>=1 && p2.x<=R && p2.y>=1 && p2.y <=C )
    {
        if( !binary_search(v_plants.begin(), v_plants.end(), p2, comp) ) //二分查找函数也需要比较函数
        {
            steps=0;
            break;
        }
        p2.x += dx;
        p2.y += dy;
        steps++;
    }
    return steps;
}

int main()
{
    int R, C, N;
    cin>>R>>C;
    cin>>N;
    vector<plants> v_plants(N);
    for(int i=0; i<N; i++)
    {
        cin>>v_plants[i].x>>v_plants[i].y;
    }
    sort(v_plants.begin(), v_plants.end(), comp);

    int max = 2;
    for(int i=0; i<N-2; i++)
    {
        for(int j=i+1; j<N-1; j++)
        {
            plants p1 = v_plants[i], p2 = v_plants[j];
            int dx = p2.x - p1.x, dy = p2.y - p1.y;
            if( p1.x-dx>=1 && p1.x-dx<=R && p1.y-dy>=1 && p1.y-dy<=C ) continue; //前一个点在稻田内
            if( p1.x + (max-1)*dx > R ) break; //这条路径上没有max个点
            if( p1.y + (max-1)*dy > C || p1.y + (max-1)*dy < 1 ) continue; //y向上过早越界。

            int steps = search_path(v_plants, p2, dx, dy, R, C);
            if( steps > max ) max = steps;
        }
    }
    if(max == 2) max=0;
    cout<<max<<endl;

    return 0;
}
