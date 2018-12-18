#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <iomanip>
using namespace std;
vector<int> fi(30), di(30), ti(30,0);

void GetFishNum(int cur_id, int id, int fish_num, int left_T, vector<int> &res, vector<int> &cur_travel, vector<vector<int>> &travel, const vector<int> &pTime)
{
    if( cur_id == id )
    {
        if( left_T <pTime[id] )
            fish_num += (2*fi[id]-di[id]*(left_T-1))*left_T/2;
//        else fish_num += (fi[id]+0)
        if(fish_num > res[id])
        {
            res[id] = fish_num;
            cur_travel.push_back(left_T);
            travel[id] = cur_travel;
            cur_travel.pop_back();
        }
        return ;
    }
    if( left_T<0 ) return;//提前用完钓鱼时间，返回
    for(int i=0; i<=pTime[cur_id]; i++)
    {
        if(left_T <= i) return;
        int temp = (2*fi[cur_id]-di[cur_id]*(i-1))*i/2;
        fish_num += temp;
        cur_travel.push_back(i);
        GetFishNum(cur_id+1, id, fish_num, left_T-i, res, cur_travel, travel, pTime);
        cur_travel.pop_back();
        fish_num -= temp;
    }
}

int findMaxID(int n, const vector<int> &res)
{
    int MaxID=0, maxNum=0;
    for(int i=0; i<n; i++)
    {
        if(res[i] > maxNum)
        {
            maxNum = res[i];
            MaxID = i;
        }
    }
    return MaxID;
}

int main()
{
    int n,h;
    cin>>n;
    while(1)
    {
        cin>>h;
        int temp, T=h*12;

        for(int i=0; i<n; i++)
            cin>>fi[i];
        for(int i=0; i<n; i++)
            cin>>di[i];
        for(int i=1; i<n; i++)
        {
            cin>>temp;
            ti[i] = ti[i-1]+temp; //从0点到i点的总耗时
        }
        vector<int> res(n,0), pTime(n,0);
        vector<vector<int>> travel;
        for(int i=0; i<n; i++)
        {
            if(di[i] == 0) pTime[i] = T - ti[i];
            else pTime[i] = min(T - ti[i], (fi[i]-1)/di[i] + 1);//后者保证值向上取整
        }
        for(int i=0; i<n; i++)
        {
            int left_T = T - ti[i];
            vector<int> cur_travel;
            GetFishNum(0, i, 0, left_T, res, cur_travel, travel, pTime);
        }
        int id = findMaxID(n, res);
        for(int i=0; i<n; i++)
        {
            if(i < travel[id].size()) cout<<travel[id][i]*5;
            else cout<<0;
            if(i == n-1)cout<<endl;
            else cout<<", ";
        }
        cout<<"Number of fish expected: "<<res[id]<<endl;
        cin>>n;
        if(n!=0) cout<<endl;
        else break;
    }

    return 0;
}
