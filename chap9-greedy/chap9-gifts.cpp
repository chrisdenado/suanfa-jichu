#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <iomanip>
using namespace std;
//POJ4110, 圣诞老人的礼物
struct candy
{
    int v,w;
    double v_w;
    candy() {}
    candy(int vv, int ww):v(vv), w(ww) {}
};

bool comp(candy a, candy b)
{
    return a.v_w < b.v_w;
}

int main()
{
    int N,W;
    cin>>N>>W;
    vector<candy> c(N);
    for(int i=0; i<N; i++)
    {
        cin>>c[i].v>>c[i].w;
        c[i].v_w = (1.0 * c[i].v) / c[i].w;
    }
    sort(c.begin(), c.end(), comp);

    int cur_w = 0;
    double cur_v = 0.0;
    for(int i=c.size()-1; i>=0; i--)
    {
        if(cur_w + c[i].w < W)
        {
            cur_w += c[i].w;
            cur_v += c[i].v;
        }
        else {
            cur_v += c[i].v_w * (W - cur_w);
            break;
        }
    }
    cout<<setiosflags(ios::fixed)<<setprecision(1);
    cout<<cur_v<<endl;
}
