#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>

#define N 100005
char a[N], b[N], c[N];
int f[10], n;

void sub(int i, int c)
{
 	if(i < 0)
 	 	return;
 	int x = a[i]-b[i]-c, nc = 0;
 	if(x < 0)
 	{
 		x += 10;
 		nc = 1;
 	}
 	sub(i-1, nc);
 	printf("%d", x);
}

int main()
{
	scanf("%s", c);
	n = strlen(c);
	for(int i = 0; i < n; i++){
		f[c[i]-'0']++;
	}
	int ptr = 0, small = 10;
	for(int i = 9; i >= 0; i--){
		int now = f[i];
		if((i > 0) && (now != 0))
			small = i;
		while(now--){
			a[ptr++] = i + '0';	 	
		}
	}
	assert(ptr == n);
	ptr = 0;
	if(f[0]){
	 	b[ptr++] = '0'+small;
	 	f[small]--;
	}
	for(int i = 0; i <= 9; i++){
	 	int now = f[i];
	 	while(now--){
	 	 	b[ptr++] = i + '0';
		}
	}
	sub(n-1, 0);
}