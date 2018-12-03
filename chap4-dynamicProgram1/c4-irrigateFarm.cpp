#include<iostream>
#include<memory.h>
#include<vector>
#include<queue>
#include<algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;
//OJ2373, 灌溉草场
struct Fx
{
    int x, f;
    bool operator <(const Fx &a)const { return f > a.f;}
    Fx(int xx, int ff):x(xx),f(ff){}
};

priority_queue<Fx> qFx;

int main()
{
    int N, L, A, B;
    cin>>N>>L;
    cin>>A>>B;
    A*=2; B*=2;
    vector<int> cows_point(L+5, 0), F(L+5, 0x7fffffff);
    for(int i=0; i<N; i++)
    {
        int s,e;
        cin>>s>>e;
        ++cows_point[s+1];
        --cows_point[e];
    }
    int inCows = 0;
    for(int i=0; i<L; i++)
    {
        inCows += cows_point[i];
        cows_point[i] = inCows>0;
    }
    for(int i=A; i<=B; i+=2)
    {
        if(!cows_point[i])
        {
            F[i] = 1;
            if(i <= B+2-A)
                qFx.push(Fx(i, 1));
        }
    }
    for(int i=B+2; i<=L; i+=2)
    {
        if(!cows_point[i])
        {
            Fx fx(0,0);
            while (!qFx.empty()) {
                fx = qFx.top();
                if( fx.x < i-B) qFx.pop();
                else break;
            }
            if(!qFx.empty())
                F[i] = fx.f + 1;
        }
        if(F[i-A+2] != 0x7fffffff) qFx.push(Fx(i-A+2, F[i-A+2]));
    }
    if(F[L] == 0x7fffffff) cout<<-1;
    else cout<<F[L];
    return 0;
}
