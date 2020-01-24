#include<stdio.h>

int main()
{
	long long n, x = 0LL;
	scanf("%lld", &n);
	for(long long i = 2; i*i <= n; i++){
		int been = 0;
		while(n%i == 0){
		 	n /= i;
		 	been = 1;
		}
		if(been)
			x = x^i;
	}
	if(n > 1)
		x ^= n;
	printf("%lld", x);
 	return 0;
}
