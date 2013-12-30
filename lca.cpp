#include "header.cpp"

//dynamic lca with addition
struct LCA {
  vector<vi> fa;
  vi depth;
  LCA() : fa(1), depth(1) {}

  void add(int f) {
    int u = SZ(depth);
    depth.push_back(depth[f]+1);
    fa.push_back(vi());
    fa[u].push_back(f);
    for (int i = 0; SZ(fa[f]) > i; fa[u].push_back(fa[f][i]), f = fa[f][i], i++);
  }

  int lca(int u, int v) {
    if (depth[u] > depth[v]) swap(u, v);
    if (depth[u] < depth[v])
      while (depth[v] > depth[u]) v = fa[v][__builtin_ctz(depth[v]-depth[u])];
    if (u == v) return u;
    for (int k = SZ(fa[u])-1; k >= 0; k--)
      if (k < SZ(fa[u]) && fa[u][k] != fa[v][k])
        u = fa[u][k], v = fa[v][k];
    return fa[u][0];
  }

  int dist(int u, int v) {
    int a = lca(u, v);
    return depth[u]-depth[a] + depth[v]-depth[a];
  }
};
