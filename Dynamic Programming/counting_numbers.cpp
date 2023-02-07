#include<iostream>
#include<cmath>
using namespace std;


 unsigned long long int  xpow(long long int x, unsigned int y){
    unsigned long long  int res=1;
    while(y>0){
        if (y&1) res= (res*x); y=y>>1; x=(x*x);
    }
    return res;
}



long long int solve(long long int b){


    if (b < 0) return 0;
	if (b == 0) return 1;
	
    long long int n=0;
    long long int temp=b;
    
    while (temp){
        n+=1;
        temp/=10;
    }


    long long int flag = 1;        
	while(flag) {
		flag = 0;
		for (long long int i = n - 2; i >= 0; i--) {
			long long int m = xpow(10,i);
			if (b/(m*10)%10 == b/m%10) {
				b = (b/m - 1)*m + (m-1);  // if b itself has adjacent same numbers , answer is same for a-b and  a-(b-1)
				flag = 1;
			}
		}
	}
    unsigned long long int dp[n+1][2] ; //dp[n][0] = free, dp[n][1] = contrained
    for(long long int i=0;i<=n;i++){
        for(int j=0;j<2;j++){
            dp[i][j]=0;
        }
    }
	dp[0][0] = 1, dp[0][1] = 1;
	unsigned long long int ans = 1;
	long long int m = 1;
	for (long long int i = 1; i < n; i++, m *= 10) {
		dp[i][0] = xpow(9, i);                               // unconstrained is just 9^ number of digits 
		dp[i][1] = (b/m%10)*dp[i-1][0] + dp[i-1][1];        // constrained is easy to see recurrence 
		if (b/m%10 > b/(m*10)%10) dp[i][1] -= dp[i-1][0];   // cant use unconstrained if we have a higher number in lower signifant bit than the previous higher significant bit
		ans += dp[i][0];
	}
	dp[n][1] = (b/m%10 - 1)*dp[n-1][0] + dp[n-1][1]; 
   	return ans + dp[n][1];

}

int main(){
    long long int a,b;
    cin>>a>>b;
    cout<<solve(b)-solve(a-1);
    return 0;
}