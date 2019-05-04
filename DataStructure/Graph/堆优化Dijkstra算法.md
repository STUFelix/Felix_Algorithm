```cpp
const int MAX_N = 10000;
const int MAX_M = 100000;
const int inf = 0x3f3f3f3f;
struct edge {
    int v, w, next;
} e[MAX_M];
int p[MAX_N], eid, n;
void mapinit() {
    memset(p, -1, sizeof(p));
    eid = 0;
}
void insert(int u, int v, int w) {  // 插入带权有向边
    e[eid].v = v;
    e[eid].w = w;
    e[eid].next = p[u];
    p[u] = eid++;
}
void insert2(int u, int v, int w) {  // 插入带权双向边
    insert(u, v, w);
    insert(v, u, w);
}
typedef pair<int, int> PII;
set<PII, less<PII> > min_heap;
int dist[MAX_N];  // 存储单源最短路的结果
bool vst[MAX_N];  // 标记每个顶点是否在集合 U 中
bool dijkstra(int s) {
    // 初始化 dist、小根堆和集合 U
    memset(vst, 0, sizeof(vst));
    memset(dist, 0x3f, sizeof(dist));
    min_heap.insert(make_pair(0, s));
    dist[s] = 0;
    for (int i = 0; i < n; ++i) {
        if (min_heap.size() == 0) {  // 如果小根堆中没有可用顶点，说明有顶点无法从源点到达，算法结束
            return false;
        }
        // 获取堆顶元素，并将堆顶元素从堆中删除
        set<PII, less<PII> >::iterator iter = min_heap.begin();
        int v = iter->second;
        min_heap.erase(*iter);
        vst[v] = true;
        // 进行和普通 dijkstra 算法类似的松弛操作
        for (int j = p[v]; j != -1; j = e[j].next) {
            int x = e[j].v;
            if (!vst[x] && dist[v] + e[j].w < dist[x]) {
                // 先将对应的 pair 从堆中删除，再将更新后的 pair 插入堆
                min_heap.erase(make_pair(dist[x], x));
                dist[x] = dist[v] + e[j].w;
                min_heap.insert(make_pair(dist[x], x));
            }
        }
    }
    return true;  // 存储单源最短路的结果
}
```
