#include "header.cpp"

/**
 * Max Flow using Dinic O(n^2 * m), it's incremental.
 * Use flow to retrieve flow value.
 */
class MaxFlow {
  public:
    /**
     * Initialize a graph with n nodes
     */
    MaxFlow(int n):n(n), adj(n) {}

    /**
     * Add arc from i to j with capacity u. Return
     * id of this arc.
     */
    int arc(int i, int j, int u) {
      dest.push_back(j); adj[i].push_back(SZ(dest)-1); cap.push_back(u);
      dest.push_back(i); adj[j].push_back(SZ(dest)-1); cap.push_back(0);
      return SZ(dest)-2;
    }

    /**
     * Return maxflow from ini to end
     */
    int maxflow(int ini, int end) {
      flow = vi(SZ(dest));
      int F = 0;
      while (MFbfs(ini, end)) while (true) {
        int tmp = MFdfs(ini, end, INF);
        F += tmp;
        if (tmp == 0) break;
      }
      return F;
    }

    vi flow;

  private:
    int n;    // n is number of nodes
    vi dest, cap, d, curAdj;// use SZ(dest) as nar (including back arcs)
    vector<vi> adj;

    int inv(int a) { return a ^ 0x1; }
    int orig(int a) { return dest[inv(a)]; }
    int capres(int a) { return cap[a] - flow[a]; }

    bool MFbfs(int ini, int end) {
      d = vi(n, INF); curAdj = vi(n); d[ini] = 0;
      queue<int> Q; Q.push(ini);
      while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        for(auto i : adj[u]) {
          int v = dest[i];
          if (capres(i) > 0 && d[v] == INF) {
            d[v] = d[u] + 1; Q.push(v);
          }
        }
      }
      return d[end] != INF;
    }

    int MFdfs(int u, int t, int f) {
      if (u == t) return f;
      for(int &i = curAdj[u]; i < SZ(adj[u]); ++i) {
        int ar = adj[u][i], v = dest[ar];
        if (d[v] != d[u]+1 || capres(ar) == 0) continue;
        int tmpF = MFdfs(v, t, min(f, capres(ar)));
        if (tmpF) {
          flow[ar] += tmpF;
          flow[inv(ar)] -= tmpF;
          return tmpF;
        }
      }
      return 0;
    }
};
