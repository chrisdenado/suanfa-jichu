#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isRightMethod(const vector<int> &state, const vector<int> &press)
{
    if( (state[0] + press[0] + press[1] + press[3]) % 4 != 0 ) return false;
    if( (state[1] + press[0] + press[1] + press[2] + press[4]) % 4 != 0 ) return false;
    if( (state[2] + press[1] + press[2] + press[5]) % 4 != 0 ) return false;
    if( (state[3] + press[0] + press[3] + press[4] + press[6]) % 4 != 0 ) return false;
    if( (state[4] + press[0] + press[2] + press[4] + press[6] + press[8]) % 4 != 0 ) return false;
    if( (state[5] + press[2] + press[4] + press[5] + press[8]) % 4 != 0 ) return false;
    if( (state[6] + press[3] + press[6] + press[7]) % 4 != 0 ) return false;
    if( (state[7] + press[4] + press[6] + press[7] + press[8]) % 4 != 0 ) return false;
    if( (state[8] + press[5] + press[7] + press[8]) % 4 != 0 ) return false;
    return true;
}

int sum(vector<int> a)
{
    int temp=0;
    for(int i=0; i<a.size(); i++) temp += a[i];
    return temp;
}

int main()
{
    vector<int> state(9, 0), press(9,0), res(9,0);
    for(int i=0; i<9; i++)
        cin>>state[i];
    int min=0x7fffffff;

    int cnt = 2<<17;
    for(int i=0; i<cnt; i++)
    {
        if( isRightMethod(state, press) && sum(press) < min)
        {
            min = sum(press);
            res = press;
        }

        int c=0;
        press[c]++;
        while(press[c] > 3)
        {
            press[c] = 0;
            if(++c == 9) break;
            press[c]++;
        }

    }

    for(int i=0; i<res.size(); i++)
    {
        for(int j=0; j<res[i]; j++)
            cout<<i+1<<" ";
    }
    cout<<endl;

    return 0;
}
