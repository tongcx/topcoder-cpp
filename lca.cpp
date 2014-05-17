#include "header.cpp"

//dynamic lca with addition
struct LCA {
  /**
   * Create a tree with one node.
   */
  LCA() : fa(1), depth(1) {}

  /**
   * Add a node with parent f. The node will have id
   * equal to current size of the tree.
   */
  void add(int f) {
    int u = sz(depth);
    depth.push_back(depth[f]+1);
    fa.push_back(vi());
    fa[u].push_back(f);
    for (int i = 0; sz(fa[f]) > i; fa[u].push_back(fa[f][i]), f = fa[f][i], i++);
  }

  /**
   * Compute the least common ancester of u and v
   */
  int lca(int u, int v) {
    if (depth[u] > depth[v]) swap(u, v);
    if (depth[u] < depth[v])
      while (depth[v] > depth[u]) v = fa[v][__builtin_ctz(depth[v]-depth[u])];
    if (u == v) return u;
    for (int k = sz(fa[u])-1; k >= 0; k--)
      if (k < sz(fa[u]) && fa[u][k] != fa[v][k])
        u = fa[u][k], v = fa[v][k];
    return fa[u][0];
  }

  /**
   * Find the distance between u and v
   */
  int dist(int u, int v) {
    int a = lca(u, v);
    return depth[u]-depth[a] + depth[v]-depth[a];
  }

  private:
  vector<vi> fa; // fa[u] is ancestor of depth 1, 2, 4, ... of u
  vi depth;
};
