#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 1005
int a[N][N];

int n, m, c;
int deg[N], vis[N];

void dfs(int node)
{
	vis[node] = 1;
	c++;
	for(int i = 1; i <= n; i++){
	 	if(a[node][i] && !vis[i]){
	 		dfs(i); 	
	 	}
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= m; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		a[x][y] = 1;
		deg[y]++;
	}
	for(int i = 1; i <= n; i++){
		memset(vis, 0, sizeof(vis));
	 	if(deg[i] == 0){
	 		c = 0;
	 		dfs(i);
	 		if(c == n){
	 		 	return printf("%d ", i), 0;
		 	}
	 	}
	}
	printf("Bad luck\n");

 	return 0;
}