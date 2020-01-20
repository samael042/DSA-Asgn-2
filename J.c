#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 10005

long long isprime(long long n){
 	for(long long i = 2; i*i <= n; i++){
 	 	if(n%i == 0){
 	 	    return 0;
 	 	}	
 	}
 	return 1;
}

int main()
{
	long long n, x = 0LL;
	scanf("%lld", &n);
	if(isprime(n)){
	 	printf("%lld", n);
	 	return 0;
	}
	for(long long i = 2; i*i <= n; i++){
		int been = 0;
		while(n%i == 0){
		 	n /= i;
		 	been = 1;
		}
		if(been)
			x = x^i;
	}
	x ^= n;
	printf("%lld", x);
 	return 0;
}