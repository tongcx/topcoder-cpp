#include "header.cpp"

// Min Cost Arborescence - Edmond's Algorithm O(mn)
// C is the final cost, set to -1 if no solution
// all arcs with cc = 0 is the solution
struct MCA {
  int n, m;
  vi src, dest, cost;
  vi cc, rep, pi, mm, color;
  int C, r;

  MCA(int n):n(n), m(0) {}

  void arc(int i, int j, int c) {
    src.PB(i); dest.PB(j); cost.PB(c);
    m++;
  }

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
    REP(i, m) {
      int u = findrep(src[i]), v = findrep(dest[i]);
      if (u != v && mm[v] > cc[i]) { mm[v] = cc[i];pi[v] = u;}
    }
    REP(i, n) if (findrep(i) == i && i != r) {
      if (mm[i] == INF) { C = -1; return false;}
      C += mm[i];
    }
    REP(i, m) {
      int u = findrep(src[i]), v = findrep(dest[i]);
      if (u != v) cc[i] -= mm[v];
    }

    color = vi(n, 0); color[r] = 2;
    REP(i, n) if (findrep(i) == i) {
      int u = cycle(i);
      if (u != -1) {
        for (int v = pi[u]; v != u; v = pi[v]) rep[v] = u;
        return true;
      }
    }
    return false;
  }

  int mca(int root) {
    r = root; C = 0; cc = cost;
    rep.clear(); REP(i, n) rep.PB(i);
    while(iter());
    return C;
  }
};
