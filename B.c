#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 1000005
int dp[N];

int min(int a, int b)
{
 	return a > b ? b : a;
}

int main()
{
	for(int i = 1; i <= 1e6; i++)
		dp[i] = (int)2e9;
	int a, b, c, d, e, f;
	scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);
	dp[0] = 0;
	dp[b] = 1;
	dp[d] = 1;
	dp[f] = 1;
	for(int i = 1; i <= (int)1e6; i++)
	{
	 	if(dp[i] != (int)2e9)
	 	{
	 		if(a*i+b <= (int)1e6)
	 	 		dp[a*i+b] = min(dp[a*i+b], dp[i]+1);
	 	 	if(c*i+d <= (int)1e6)
	 	 		dp[c*i+d] = min(dp[c*i+d], dp[i]+1);
	 	 	if(e*i+f <= (int)1e6)
	 	 		dp[e*i+f] = min(dp[e*i+f], dp[i]+1);
	 	}
	}
	int q;
	scanf("%d", &q);
	for(int i = 0; i < q; i++){
	 	int x;
	 	scanf("%d", &x);
	 	int temp = dp[x];
	 	temp = (temp == 2e9) ? -1 : temp;
	 	printf("%d\n", temp);
	}
 	return 0;
}