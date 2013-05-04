#include <vector>
#include <queue>
#define REP(i, n) for (int i = 0; i < n; i++)
#define EACH(i, c) for (typeof ((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define SZ(c) int((c).size())
#define PB push_back
using namespace std;
typedef vector<int> vi;

struct Graph {
  int n;
  vi dest, depth;  // use SZ(dest) as nar
  vector<vi> adj;

  Graph(int n):n(n) {adj.resize(n);}
  int inv(int a) { return a ^ 0x1; }

  int arc(int i, int j) {
    dest.PB(j); adj[i].PB(SZ(dest)-1);
    dest.PB(i); adj[j].PB(SZ(dest)-1);
    return SZ(dest)-2;
  }

  // Bridges and articulation points - O(n+m)
  vector<bool> artp, bridge;
  vi least;

  int dfs_artpbridge(int u, int ent) {
    int nf = 0;
    EACH(a, adj[u]) {
      int v = dest[*a];
      if (depth[v] == -1) {
        least[v] = depth[v] = depth[u] + 1;
        dfs_artpbridge(v, *a); nf++;

        if (least[v] >= depth[u]) {
          artp[u] = true;
          if (least[v] == depth[v]) bridge[*a] = bridge[inv(*a)] = true;
        } else least[u] = min(least[u], least[v]);
      }
      else if (inv(*a) != ent) least[u] = min(least[u], depth[v]);
    }
    return nf;
  }

  void partponte() {
    artp = vector<bool>(n, false);
    bridge = vector<bool>(SZ(dest), false);
    depth = vi(n, -1);
    least = vi(n, -1);
    REP(i, n) if (depth[i] == -1) {
        least[i] = depth[i] = 0;
        if (dfs_artpbridge(i, -1) < 2) artp[i] = false;
    }
  }

  // Strongly Connected Components - O(n+m)
  // see [rep] for results

  vi ord, rep;

  int transp(int a) { return (a & 0x1); }

  void dfs_topsort(int u) {
    EACH(a, adj[u]) {
      int v = dest[*a];
      if (!transp(*a) && depth[v] == -1) {
        depth[v] = depth[u] + 1;
        dfs_topsort(v);
      }
    }
    ord.PB(u);
  }

  void dfs_compfortcon(int u, int ent) {
    rep[u] = ent;
    EACH(a, adj[u]) {
      int v = dest[*a];
      if (transp(*a) && rep[v] == -1) dfs_compfortcon(v, ent);
    }
  }

  void compfortcon() {
    depth = vi(n, -1);
    ord.clear();
    REP(u, n) if (depth[u] == -1) {
        depth[u] = 0;
        dfs_topsort(u);
    }

    rep = vi(n, -1);
    for (int i = n-1; i >= 0; i--) if (rep[ord[i]] == -1)
      dfs_compfortcon(ord[i], ord[i]);
  }
};
