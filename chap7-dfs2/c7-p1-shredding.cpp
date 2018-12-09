#include<iostream>
#include<vector>
#include<algorithm>
#include<memory.h>
using namespace std;
//POJ1416, shredding company
int vectorToNum(int start, int end, const vector<int> &v)
{
    int num=0;
    for(int i=start; i<=end; i++)
        num = num*10 + v[i];
    return num;
}

int minSum(int start, const vector<int> &v)
{
    int sum = 0;
    for(int i=start; i<v.size(); i++)
        sum += v[i];
    return sum;
}

void dfs(int sum, int &minDelta, int &number, int id, const vector<int> &v, vector<int> &res, int target, vector<vector<int>> &array)
{
    if(id == v.size())
    {
        int delta = target - sum;
        if( delta >= 0 )
        {
            if(delta < minDelta)
            {
                minDelta = delta;
                number = 1;
                array.clear();
                array.push_back(res);
            }
            else if(delta == minDelta)
            {
                number++;
                array.push_back(res);
            }
        }
        return;
    }
    if( sum + minSum(id, v) > target ) return; //当前和+剩下值的最小和 仍大于目标值
    if( sum + vectorToNum(id, v.size()-1, v) < target - minDelta ) return; //当前和+剩下值的最大和 仍小于已有的最佳值

    for(int i=id; i<v.size(); i++)
    {
        int temp = vectorToNum(id, i, v);
        res.push_back(temp);
        dfs(sum+temp, minDelta, number, i+1, v, res, target, array);
        res.pop_back();
    }

}
int main()
{
    int target;
    string str;
    cin>>target;
    cin>>str;
    while (target !=0) {
        vector<int> v, res;
        vector<vector<int>> array;
        for(int i=0; i<str.size(); i++)
            v.push_back(str[i]-'0');

        int minDleta = 1<<30, number = 0;
        dfs(0, minDleta, number, 0, v, res, target, array);
        if( minDleta == 1<<30 ) cout<<"error"<<endl;
        else if( number > 1 ) cout<<"rejected"<<endl;
        else
        {
            cout<<(target-minDleta)<<" ";
            for(int i=0; i<array[0].size(); i++) cout<<array[0][i]<<" ";
            cout<<endl;
        }
        cin>>target;
        cin>>str;
    }
    return 0;
}
