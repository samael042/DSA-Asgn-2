#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 505
char a[N];

typedef struct node
{
	struct node* next;
	int data;
}node;

int dp[N][N];

int max(int a, int b){
 	return a > b ? a : b;
}
int main()
{
	scanf("%s", a);
	int n = strlen(a);
	for(int i = 0; i < n; i++){
	    for(int j = 0; j < n; j++){
	        dp[i][j] = 0;
	    }	
	}	
	for(int i = 0; i < n; i++)
		dp[i][i] = 1;
	for(int i = 0; i + 1 < n; i++){
		if(a[i] == a[i+1]){
		 	dp[i][i+1] = 1;
		}
	}
	for(int len = 3; len <= n; len++){
	 	for(int i = 0; i + len <= n; i++){
	 	 	int j = i+len-1;
	 	 	if(a[i] == a[j] && dp[i+1][j-1]){
	 	 	 	dp[i][j] = 1;
	 	 	}
	 	}
	}
	int l = -1;
	for(int i = 0; i < n; i++){
	 	for(int j = i; j < n; j++){
	 	  	if(dp[i][j]){
	 	  	 	l = max(l, j-i+1);
	 	  	}
	 	}	
	}
	int x = -1, y = -1;
	for(int i = 0; i < n; i++){
		for(int j = i; j < n; j++){
		   	if(j-i+1 == l && dp[i][j]){
		   	 	x = i;
		   	 	y = j;
		   	 	break;
		   	}
	 	}	
	}
	printf("%d\n",l);
	for(int i = x; i <= y; i++){
	 	printf("%c",a[i]);
	}
 	return 0;
}