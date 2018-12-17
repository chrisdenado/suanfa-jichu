#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<memory.h>
using namespace std;
//POJ2393, Yogurt factory
int main()
{
    int N, S;
    cin>>N>>S;
    vector<int> C(N), Y(N);
    cin>>C[0]>>Y[0];
    long long price = C[0] * Y[0];
    for(int i=1; i<N; i++)
    {
        cin>>C[i]>>Y[i];
        C[i] = min(C[i], C[i-1]+S);
        price += C[i] * Y[i];
    }
    cout<<price<<endl;
    return 0;
}
