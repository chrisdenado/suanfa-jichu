#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool find_num(const vector<vector<int>> &color, vector<vector<int>> &press, int &temp, int n)
{
    int press_num=0;
    for(int j=1; j<n+1; j++)
    {
        if(press[1][j] == 1) press_num++;
    }

    for(int i=1; i<n; i++)
    {
        for(int j=1; j<n+1; j++)
        {
            press[i+1][j] = (press[i][j] + color[i][j] + press[i-1][j] + press[i][j-1] + press[i][j+1])%2;
            if(press[i+1][j] == 1) press_num++;
        }
    }
    for(int j=1; j<n+1; j++)
    {
        if( press[n][j] != (color[n][j] + press[n-1][j] + press[n][j-1] + press[n][j+1])%2 ) return false;
    }
    temp = press_num;
    return true;
}

bool brush(int &num, int n)
{
    vector<vector<int>> color(n+1, vector<int>(n+2, 0)), press(n+1, vector<int>(n+2, 0)); //0代表黄色，1代表白色
    string str;
    num = 0x7fffffff;
    int cnt = 1<<n;
    for(int i=0; i<n; i++)
    {
        cin>>str;
        for(int j=0; j<n; j++)
        {
            if(str[j] == 'w') color[i+1][j+1] = 1;
        }
    }
    for(int i=0; i<cnt; i++)
    {
        int c=1, temp=-1;
        if( find_num(color, press, temp, n) && temp < num ) num=temp;

        press[1][c]++;
        while (press[1][c] > 1) {
            press[1][c]=0;
            c++;
            press[1][c]++;
        }
    }
    if(num!= 0x7fffffff) return true;
    else return false;
}

int main()
{
//    int t, n;
//    int num;
//    vector<string> result;
//    cin>>t;
//    for(int i=0; i<t; i++)
//    {
//        cin>>n;
//        if( brush(num, n) ) result.push_back(to_string(num));
//        else result.push_back("inf");
//    }
//    for(size_t i=0; i<result.size(); i++)
//        cout<<result[i]<<endl;
    int n, num;
    cin>>n;
    if( brush(num, n) ) cout<<num<<endl;
    else cout<<"inf"<<endl;;
    return 0;
}
