```c
#include<iostream>
#include<cstdio>
#include<windows.h>
using namespace std;

int k[5], p[5];
int n, m;
int ans;
long long poww(int x, int y) {
	long long ret = 1;
	for (int i = 0; i < y; i++) {
		ret *= x;
	}
	return ret;
}

void dfs(int x, long long  s) {
	if (x == n) {
		if (s ==0) {
			ans++;
		}
		return;
	}
	for (int i = 1; i <= m; i++) {
		dfs(x + 1, s + k[x] * poww(i, p[x]));
	}

}

int main() {
	scanf("%d", &n);
	scanf("%d", &m);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &k[i], &p[i]);
	}
	dfs(0, 0);
	printf("%d\n", ans);
	system("pause");
	return 0;
}

```
