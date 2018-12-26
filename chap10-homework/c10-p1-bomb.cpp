#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <iomanip>
using namespace std;
//POJ4133, 垃圾炸弹
struct rubbish
{
    int x,y,num;
    rubbish() {}
    rubbish(int xx, int yy, int nn):x(xx), y(yy), num(nn) {}
};

int main()
{
   int n,d;
   cin>>d>>n;
   vector<rubbish> r(n);
   for(int i=0; i<n; i++)
        cin>>r[i].x>>r[i].y>>r[i].num;

   vector<vector<int>> deal(1025, vector<int>(1025, 0));
   int max_num=0, max_cnt=0;
   for(int i=0; i<n; i++)
   {
        for(int m=-d; m<=d; m++)
        {
            for(int n=-d; n<=d; n++)
            {
                int x=r[i].x + m, y=r[i].y + n;
                if(x>=0 && x<=1024 && y>=0 && y<=1024)
                {
                    deal[x][y] += r[i].num;
                    if(deal[x][y] > max_num)
                    {
                        max_num = deal[x][y];
                        max_cnt = 1;
                    }
                    else if(deal[x][y] == max_num)
                        max_cnt++;
                }
            }
        }
   }
   cout<<max_cnt<<" "<<max_num<<endl;
    return 0;
}
