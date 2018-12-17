#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<memory.h>
using namespace std;
//POJ1505 copy books. 自定义判断方式进行二分查找，递归输出的思路。
bool check(long long ans, int k, const vector<int> &pages)
{
    int num=0, cnt=0;
    for(int i=0; i<pages.size(); i++)
    {
        if(pages[i] > ans) return false;
        if( cnt+pages[i] <= ans ) cnt += pages[i];
        else
        {
            num++;
            cnt = pages[i];
        }
    }
    if(cnt > 0) num++;

    return num<=k;
}

void print(int bookNum, int maxPage, int person, int nowPage, const vector<int> &pages)
{
    bool sepa=false;
    if(bookNum < 0) return;
    if( bookNum == person-1 || nowPage+pages[bookNum] > maxPage )
    {
        sepa = true;
        print(bookNum-1, maxPage, person-1, pages[bookNum], pages);
    }
    else print(bookNum-1, maxPage, person, nowPage+pages[bookNum], pages);

    if(bookNum > 0) cout<<" ";
    cout<<pages[bookNum];
    if(sepa) cout<<" /"; //递归输出，仔细体会
}
int main()
{
    int n;
    cin>>n;
    while(n-- > 0)
    {
        int m,k;
        cin>>m>>k;
        vector<int> pages(m);
        long long l=0, r=0, mid=0;
        for(int i=0; i<m; i++)
        {
            cin>>pages[i];
            r += pages[i];
            if(pages[i] > l) l = pages[i];
        }

        while( l<=r )
        {
            mid = (l+r)/2;
            if(check(mid, k, pages)) r = mid-1;
            else l = mid+1;
        }//最后选l作为临界值，仔细思考是为什么？
        print(m-1, l, k-1, 0, pages);
        cout<<endl;
    }

    return 0;
}

