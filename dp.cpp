#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int> > graph[1000];
int dp[20][1 << 17];
int n, m;

int solve(int u, int mask) {
    if (mask == (1 << n) -1)
        return 0;
    if (dp[u][mask] != 0)
        return dp[u][mask];
    int ans = 1e9;
    for (auto p: graph[u]) {
        int v = p.first, w = p.second;
        if (mask & (1 << v))
            continue;
        else
            ans = min(ans, solve(v, mask | (1 << v)) + w);
    }
    return ans;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        u--;
        v--;
        graph[u].push_back(make_pair(v, w));
        graph[v].push_back(make_pair(u, w));
    }
    int src;
    scanf("%d", &src);
    printf("src= %d\n", src);
    src--;
    printf("%d\n", solve(src, 1 << src));
    return 0;
}
    
