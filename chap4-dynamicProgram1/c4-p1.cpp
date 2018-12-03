#include<iostream>
#include<memory.h>
#include<vector>
#include<algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;
#define MAX 500
//OJ2792:集合加法
int main()
{
    int n; cin>>n;
    while(n-- > 0)
    {
        int s, a, b;
        cin>>s;
        cin>>a;
        vector<int> A(a);
        for(int i=0; i<a; i++) cin>>A[i];
        cin>>b;
        vector<int> B(b);
        for(int i=0; i<b; i++) cin>>B[i];

        sort(A.begin(), A.end());
        sort(B.begin(), B.end());

        int num=0;
        for(int i=0; i<a; i++)
        {
            int cnt = 1;
            while( (i+1<a) && (A[i+1] == A[i])) {i++; cnt++;}

            for(int j=0; j<b; j++)
            {
                if( A[i] + B[j] == s ) num += cnt;
                if( A[i] + B[j] > s ) break;
            }
        }
        cout<<num<<endl;
    }
    return 0;
}
