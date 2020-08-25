#include<bits/stdc++.h>
using namespace std;
#define maxn 1000
int n, m;
int dp[maxn][maxn];
int main(){
	int dp[maxn][maxn] = {0};
	int n, m, tmp;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
	    for (int j = 1; j <= m; j++) {
	        scanf("%d", &tmp);
	        dp[i][j] = dp[i-1][j] + tmp;
	    }
	}
	int tmp_sum = 0, max_sum = -999999;
	for (int i = 1; i <= n; i++) {
	    for (int j = i; j <= n; j++) {
	        tmp_sum = 0;
	        for (int k = 1; k <= m; k++) {
	            tmp_sum += dp[j][k] - dp[i-1][k];
	            if(tmp_sum > max_sum)
	                max_sum = tmp_sum;
	            if(tmp_sum < 0)
	                tmp_sum = 0;
	        }
	    }
	}
	cout<<max_sum<<endl;
    system("pause");
    return 0;
}