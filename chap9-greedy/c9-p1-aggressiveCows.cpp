#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<memory.h>
using namespace std;
//POJ2456, Aggressive Cows
int binSearch(int a, const vector<int> &stall, int l, int r)
{
//    int mid=0, l=0, r=stall.size()-1;
    int mid=0;
    int MAX = stall.size()-1;
    r = min(r, MAX);
    while (l<=r) {
        mid = (l+r)/2;
        if(stall[mid] == a) return mid;
        if(stall[mid] < a) l = mid + 1;
        if(stall[mid] > a) r = mid - 1;
    }
    return l; //若a不存在，则返回第一个比a大的数的位置
}

bool check(int itval, int C, const vector<int> &stall)
{
    int temp, id=0;
    int MAX = stall[stall.size()-1];
    for(int i=1; i<C; i++)
    {
        temp = stall[id] + itval;
        if(temp > MAX) return false;
//        id = binSearch(temp, stall);
        id = binSearch(temp, stall, id, id+itval); //添加左右搜索边界，节省30ms的查找时间
    }
    return true;
}

int main()
{
    int N, C;
    cin>>N>>C;
    vector<int> stall(N);
    for(int i=0; i<N; i++)
        cin>>stall[i];
    sort(stall.begin(), stall.end());
    int r = stall[N-1]/C + 1, l = 1, mid=0;
    while (l<=r) {
        mid = (l+r)/2;
        if(check(mid, C, stall)) l=mid+1;
        else r=mid-1;
    }
    cout<<r<<endl; //注意此处选择r而不是l的逻辑
    return 0;
}

