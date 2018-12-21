#include <iostream>
#include <stdio.h>
#include <queue>
#include <cmath>
#include <string.h>
#include <algorithm>
 //POJ1042， 巧妙运用优先队列进行贪心搜索。奇怪的是，自己写的程序总是wrong anwser
using namespace std;
struct lake
{
    int f;//鱼量
    int d;//减少量
    int id;//湖的编号
};
lake a[100];
int dist[100],tmp[100],best[100];
bool operator<(const lake &a,const lake &b)//贪心思想，每次都找最多，利用最少时间的
{
    if(a.f==b.f)
        return a.id>b.id;//如果两个湖鱼量相同，则直接按湖的编号顺序进行扑鱼
    else
        return a.f<b.f;//如果鱼量不同，则选择鱼量最大的先进行扑鱼
}
priority_queue<lake> q;
int main()
{
    int n,i,j,k;
    scanf("%d",&n);
    while(n!=0)
    {
        int time,ans=-100;
        scanf("%d",&time);
        time*=12;//以五为单位进行划分
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i].f);
            a[i].id=i;
        }
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i].d);
        }
        dist[0]=0;//默认在第一个湖，所以距离设置为0
        for(i=1;i<n;i++)
        {
            scanf("%d",&dist[i]);
            dist[i]+=dist[i-1];//distance[i]表示从0到i的距离
        }
        for(i=0;i<n;i++)
        {
            int now=0;
            while(q.empty()==0)
            {
                q.pop();//清空队列
            }
            for(j=0;j<=i;j++)
            {
                q.push(a[j]);//全部入队
            }
            memset(tmp,0,sizeof(tmp));
            int tt=time-dist[i];
            while(tt>0)//按优先级一次进行扑鱼
            {
                lake node=q.top();
                q.pop();
                tt--;
                now+=node.f;
                node.f-=node.d;
                tmp[node.id]++;
                if(node.f<0)
                    node.f=0;
                q.push(node);//每次扑鱼后，都进行一次优先级的比较
            }
            if(now>ans)
            {
                ans=now;
                for(j=0;j<n;j++)
                {
                    best[j]=tmp[j];
                }
            }
 
        }
        for(i=0;i<n-1;i++)
            printf("%d, ",5*best[i]);
        printf("%d\n",5*best[n-1]);
        printf("Number of fish expected: %d\n",ans);
        scanf("%d",&n);
        if(n>0)
            printf("\n");
 
    }
    return 0;
}