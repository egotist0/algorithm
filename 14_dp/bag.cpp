//dp[i][v]表示前i件物品恰好装进容量为v的背包中所能获得的最大价值
//dp[i][v]=max{dp[i-1][v],dp[i-1][v-w[i]]+c[i]}

//dp[i][v]只与dp[i-1][]有关
//边界dp[0][v]=0

#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn=100; //物品最大件数
const int maxv=1000; //v的上限

int w[maxn],c[maxn],dp[maxv];

int main(){
    int n,v;
    scanf("%d%d",&n,&v);
    for(int i=1;i<=n;i++){
        scanf("%d",&w[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&c[i]);
    }

    //边界
    for(int i=0;i<=v;i++){
        dp[i]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=v;j>=w[i];j--){
            //状态转移方程
            dp[j]=max(dp[j],dp[j-w[i]]+c[i]);
        }
    }

    //寻找dp[0...v]中最大的即为答案
    int max=0;
    for(int i=0;i<=v;i++){
        if(dp[i]>max){
            max=dp[i];
        }
    }

    printf("%d\n",max);
    return 0;
}