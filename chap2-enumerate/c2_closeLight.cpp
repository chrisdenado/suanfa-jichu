#include<iostream>
#include<vector>
using namespace std;
//熄灯问题
bool guess(vector<vector<int>> &press, const vector<vector<int>> &puzzle)
{
    for(int i=1; i<5; i++)
    {
        for(int j=1; j<7; j++)
        {
            press[i+1][j] = (press[i][j] + puzzle[i][j] + press[i-1][j] + press[i][j-1] + press[i][j+1])%2;
        }
    }
    for(int j=1; j<7; j++)
    {
        if( (press[5][j] + press[5][j-1] + press[5][j+1] + press[4][j])%2 != puzzle[5][j] )
            return false;
    }
    return true;
}

int main()
{
    vector<vector<int>> puzzle(6, vector<int>(8, 0)), press(6, vector<int>(8, 0));
    for(int i=1; i<6; i++)
    {
        for(int j=1; j<7; j++)
        {
            cin>>puzzle[i][j];
        }
    }

    int c=1;
    while( guess(press,puzzle) == false )
    {
        c=1;
        press[1][c]++;
        while(press[1][c] > 1) //模拟二进制
        {
            press[1][c] = 0;
            c++;
            press[1][c]++;
        }
    }

    for(int i=1; i<6; i++)
    {
        for(int j=1; j<7; j++)
        {
            cout<<press[i][j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}
