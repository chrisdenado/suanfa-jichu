#include<iostream>
#include<memory.h>
#include<vector>
#include<algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;
#define MAX 500
//OJ1458, 最长子字符串
int main()
{
    char str1[MAX], str2[MAX];
    int len1, len2;
    while (scanf("%s %s", str1, str2) != EOF) {
        len1 = strlen(str1);
        len2 = strlen(str2);
        vector<vector<int>> max_num(len1+1, vector<int>(len2+1, 0));
        for(int i=1; i<=len1; i++)
        {
            for(int j=1; j<=len2; j++)
            {
                if(str1[i-1] == str2[j-1])
                    max_num[i][j] = max_num[i-1][j-1]+1;
                else
                    max_num[i][j] = max(max_num[i-1][j], max_num[i][j-1]);
            }
        }
        cout<<max_num[len1][len2]<<endl;
    }
    return 0;
}

