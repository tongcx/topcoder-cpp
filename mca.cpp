#include "header.cpp"

struct MCA {
  /**
   * Create graph with n nodes
   */
  MCA(int n):n(n), m(0) {}

  /**
   * Add arc from i to j with cost c
   */
  void arc(int i, int j, int c) {
    src.pb(i); dest.pb(j); cost.pb(c);
    m++;
  }

  /**
   * Compute Min Cost Arborescence with given root, Edmond's Algorithm O(mn)
   * Return total cost or -1 if infeasible.
   * All arcs with cc = 0 is the solution
   */
  vi cc;
  int mca(int root) {
    r = root; C = 0; cc = cost;
    rep.clear(); rep(i, n) rep.pb(i);
    while(iter());
    return C;
  }
  private:
  int C, r;
  int n, m;
  vi src, dest, cost;
  vi rep, pi, mm, color;

  int cycle(int u) {
    if (color[u] == 1) return u;
    if (color[u] == 2) return -1;
    color[u] = 1;
    int res = cycle(pi[u]);
    color[u] = 2;
    return res;
  }

  int findrep(int i) {
    if (rep[i] == i) return i;
    return rep[i] = findrep(rep[i]);
  }

  bool iter() {
    pi = vi(n); mm = vi(n, INF);
    rep(i, m) {
      int u = findrep(src[i]), v = findrep(dest[i]);
      if (u != v && mm[v] > cc[i]) { mm[v] = cc[i];pi[v] = u;}
    }
    rep(i, n) if (findrep(i) == i && i != r) {
      if (mm[i] == INF) { C = -1; return false;}
      C += mm[i];
    }
    rep(i, m) {
      int u = findrep(src[i]), v = findrep(dest[i]);
      if (u != v) cc[i] -= mm[v];
    }

    color = vi(n, 0); color[r] = 2;
    rep(i, n) if (findrep(i) == i) {
      int u = cycle(i);
      if (u != -1) {
        for (int v = pi[u]; v != u; v = pi[v]) rep[v] = u;
        return true;
      }
    }
    return false;
  }
};
