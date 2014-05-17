#include "header.cpp"

struct Graph {
  /**
   * Create graph with size n
   */
  Graph(int n):n(n),adj(n) {}

  /**
   * Add undirected edge from i to j
   */
  int arc(int i, int j) {
    dest.pb(j); adj[i].pb(sz(dest)-1);
    dest.pb(i); adj[j].pb(sz(dest)-1);
    return sz(dest)-2;
  }

  /**
   * Compute bridges and articulation points - O(n+m)
   *
   * Access artp and bridge for results.
   */
  vector<bool> artp, bridge;
  void partponte() {
    artp = vector<bool>(n, false);
    bridge = vector<bool>(sz(dest), false);
    depth = vi(n, -1);
    least = vi(n, -1);
    rep(i, n) if (depth[i] == -1) {
        least[i] = depth[i] = 0;
        if (dfs_artpbridge(i, -1) < 2) artp[i] = false;
    }
  }

  /**
   * Strongly Connected Components - O(n+m)
   * see rep for results. rep[u] will be the
   * representative for node u.
   */
  vi rep;
  void compfortcon() {
    depth = vi(n, -1);
    ord.clear();
    rep(u, n) if (depth[u] == -1) {
        depth[u] = 0;
        dfs_topsort(u);
    }

    rep = vi(n, -1);
    for (int i = n-1; i >= 0; i--) if (rep[ord[i]] == -1)
      dfs_compfortcon(ord[i], ord[i]);
  }

  private:
  int n;
  vi dest, depth;  // use sz(dest) as nar
  vector<vi> adj;

  int inv(int a) { return a ^ 0x1; }

  vi least;

  int dfs_artpbridge(int u, int ent) {
    int nf = 0;
    for(auto a : adj[u]) {
      int v = dest[a];
      if (depth[v] == -1) {
        least[v] = depth[v] = depth[u] + 1;
        dfs_artpbridge(v, a); nf++;

        if (least[v] >= depth[u]) {
          artp[u] = true;
          if (least[v] == depth[v]) bridge[a] = bridge[inv(a)] = true;
        } else least[u] = min(least[u], least[v]);
      }
      else if (inv(a) != ent) least[u] = min(least[u], depth[v]);
    }
    return nf;
  }

  vi ord;

  int transp(int a) { return (a & 0x1); }

  void dfs_topsort(int u) {
    for(auto a : adj[u]) {
      int v = dest[a];
      if (!transp(a) && depth[v] == -1) {
        depth[v] = depth[u] + 1;
        dfs_topsort(v);
      }
    }
    ord.pb(u);
  }

  void dfs_compfortcon(int u, int ent) {
    rep[u] = ent;
    for(auto a : adj[u]) {
      int v = dest[a];
      if (transp(a) && rep[v] == -1) dfs_compfortcon(v, ent);
    }
  }

};
