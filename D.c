#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 1005
int a[N][N], n, m;
int sz[N], c, vis[N];

int max(int a, int b)
{
 	return a > b ? a : b;
}

void dfs(int node)
{
	c++;
 	vis[node] = 1;
 	for(int i = 1; i <= n; i++){
 	 	if(a[i][node] && !vis[i]){
 	 	 	dfs(i);
 	 	}
 	}
}
int main()
{
	scanf("%d %d", &n, &m);
	memset(sz, -1, sizeof(sz));
	for(int i = 0; i < m; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		a[u][v] = 1;
		a[v][u] = 1;
	}
	int t  = -1;
	for(int i = 1; i <= n; i++){
		c = 0;
		if(!vis[i])
			dfs(i);		 	
		for(int i = 1; i <= n; i++){
		    if(sz[i] == -1 && vis[i])
		    	sz[i] = c;
		}	    
		t = max(t, c);
	}
	for(int i = 1; i <= n; i++){
		if(sz[i] != t){
		 	printf("%d ",i);
		}
	}
 	return 0;
}