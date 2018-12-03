#include<iostream>
#include<memory.h>
#include<vector>
#include<queue>
#include<algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;
//OJ1390, 方盒游戏
struct sec
{
    int type, len;
    sec() {}
    sec(int t, int l): type(t), len(l) {}
};

int click_box(vector<vector<vector<int>>> &array, const vector<sec> &sec_vec, int start, int end, int ex_len)
{
    if(array[start][end][ex_len] != -1) return array[start][end][ex_len];

    int len = sec_vec[end].len, type = sec_vec[end].type;
    if(start == end)
        return (len + ex_len) * (len + ex_len);

    int t1 = click_box(array, sec_vec, start, end-1, 0) + (len + ex_len) * (len + ex_len);
    for(int k=end-1; k>=start; k--)
    {
        if(sec_vec[k].type == type)
            t1 = max(t1, click_box(array, sec_vec, start, k, len+ex_len) + click_box(array, sec_vec, k+1, end-1, 0) );
    }
    array[start][end][ex_len] = t1;
    return t1;
}

int main()
{
    int t, c=0;
    cin>>t;
    while (c++ < t) {
        int N; cin>>N;
        vector<sec> sec_vec(N, sec(0,0));
        int end=0, temp;
        cin>>sec_vec[0].type;
        sec_vec[0].len++;
        for(int i=1; i<N; i++)
        {
            cin>>temp;
            if(temp == sec_vec[end].type) sec_vec[end].len++;
            else {
                end++;
                sec_vec[end].type = temp;
                sec_vec[end].len++;
            }
        }
        if(N == 1) {cout<<"Case "<<c<<": "<<1<<endl; continue;}

        vector<vector<vector<int>>> array(200, vector<vector<int>>(200, vector<int>(200, -1)));
        cout<<"Case "<<c<<": "<<click_box(array, sec_vec, 0, end, 0)<<endl;
    }
    return 0;
}
