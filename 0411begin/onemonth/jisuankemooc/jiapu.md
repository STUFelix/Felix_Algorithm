![image](https://github.com/STUFelix/Felix_Algorithm/blob/master/image/jiapu.jpg)

```cpp
#include <cstdio>
#include <vector>
#include <windows.h>
int n, m;
using namespace std;
vector<int>  son[100005];
bool f[100005];
int ans[100005];
int dfs(int u) {
	int ret = 0;
	for (int i = 0; i < son[u].size(); i++) {
		ret += dfs(son[u][i]);
	}

	ans[u] = ret;
	return ret + 1;
}

int main() {
	int n,x,y,u;
	scanf_s("%d",& n);
	for (int i = 0; i < n-1; i++) {
		scanf_s("%d%d",&x,&y);
		son[x].push_back(y);
		f[y] = true;
	}
	for (int i = 1; i <= n; i++) {
		if(!f[i]){
			u = i;
			break;
		}
	}
	dfs(u);
	for (int i = 1; i <= n; i++) {
		printf("%d\n", ans[i]);
	}
	system("pause");
	return 0;
}

```
