#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
 
using namespace std;
long long a[550][550];
int main()
{
    int N,M,t;
    long long sum,ans=0;
    scanf("%d %d",&N,&M);
    memset(a,0,sizeof(a));
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            scanf("%d",&t);
            a[i][j]=a[i-1][j]+t;
        }
    }
    for(int i=1;i<=N;i++){
        for(int j=i;j<=N;j++){
            sum=0;
            for(int k=1;k<=M;k++){
                sum=sum+(a[j][k]-a[i-1][k]);
                if(sum<0) sum=0;
                if(sum>ans) ans=sum;
            }
        }
    }
    printf("%lld\n",ans);
    system("pause");
    return 0;
}