#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <iomanip>
using namespace std;
//POJ1328, 雷达安装问题。将覆盖雷达的安装点转换成区间，注意对应的逻辑
struct point
{
    int x,y;
    point() {}
    point(int xx, int yy):x(xx), y(yy) {}
};
struct interval
{
    double left, right;
    interval() {}
    interval(double l, double r): left(l), right(r) {}
};

bool comp(interval a, interval b)
{
    return a.left < b.left;
}

int getMinNum(const vector<interval> &itval)
{
    int num = 1;
    double now = itval[0].right;
    for(int i=1; i<itval.size(); i++)
    {
        if( itval[i].left <= now )
            now = min(now, itval[i].right);
        else {
            num++;
            now = itval[i].right;
        }
    }
    return num;
}

int main()
{
    int n, d;
    cout<<(1.0==1.000)<<endl;
    cin>>n>>d;
    int cnt = 1;
    while(n != 0)
    {
        vector<point> p(n);
        vector<interval> itval(n);
        bool flag = false;
        for(int i=0; i<n; i++)
        {
            cin>>p[i].x>>p[i].y;
            if(p[i].y > d) flag=true;
            else
            {
                double temp = sqrt(1.0*d*d - p[i].y*p[i].y);
                itval[i].left = p[i].x - temp;
                itval[i].right = p[i].x + temp;
            }
        }
        if(flag) cout<<"Case "<<cnt++<<": "<<-1<<endl;
        else
        {
            sort(itval.begin(), itval.end(), comp);
            cout<<"Case "<<cnt++<<": "<<getMinNum(itval)<<endl;
        }
        cin>>n>>d;
    }
    return 0;
}
