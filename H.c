#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define N 1005
int a[N][N], c = 0, h, n;
int vis[N], f[N];

void dfs(int node, int parent, int height)
{
 	if(height == h){
 	 	f[node]++;
 	 	c++;
 	}
 	for(int i = 0; i < n; i++){
 	 	if(parent != i && a[node][i] == 1){
 	 	  	dfs(i, node, height+1);
 	 	}
 	}
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n-1; i++){
	 	int cur; scanf("%d ", &cur);
	 	a[i][cur] = 1;
	 	a[cur][i] = 1;
	}
	scanf("%d ", &h);
	dfs(0,-1, 0);
	if(c == 0){
	 	return printf("-1"), 0;
	}
	printf("%d\n", c); 
	for(int i = 0; i < n; i++){
	 	if(f[i]){
	 	 	printf("%d ", i);
	 	}
	}
}          