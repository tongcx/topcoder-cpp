#include "header.cpp"

typedef int cost_type;
const cost_type CINF = 0x3F3F3F3F;

/**
 * MinCostMaxFlow - O(n * m^2 * log U) with SPFA.
 * When cost is double, change cost_type and CINF.
 *
 * After execution, access F to know the flow amount.
 * Access C to know the total cost.
 * Access flow for detailed flow value.
 */
class MCMF {
  public:
    int F;
    cost_type C;
    vi flow;

    /**
     * Initialize a graph with n nodes
     */
    MCMF(int n):n(n), adj(n) {}

    /**
     * Add arc from i to j with capacity u and
     * cost c (default to 0). Return the id of
     * this arc.
     */
    int arc(int i, int j, int u, cost_type c = 0) {
      dest.push_back(j); adj[i].push_back(SZ(dest)-1); cap.push_back(u); cost.push_back(c);
      dest.push_back(i); adj[j].push_back(SZ(dest)-1); cap.push_back(0); cost.push_back(-c);
      return SZ(dest)-2;
    }

    /**
     * Compute min cost max flow from ini to end.
     * Return total cost.
     */
    cost_type mcmf(int ini, int end) {
      flow = vi(SZ(dest)); F = C = 0; int U = 0;
      REP(a, SZ(dest)) U = max(U, capres(a));
      for (delta = U; delta > 0; delta /= 2) while (spfa(ini, end));
      return C;
    }

  private:
    int n, delta;    // n is number of nodes
    vector<cost_type> cost;
    vi dest, cap;  // use SZ(dest) as nar (including back arcs)
    vector<vi> adj;

    int inv(int a) { return a ^ 0x1; }
    int orig(int a) { return dest[inv(a)]; }
    int capres(int a) { return cap[a] - flow[a]; }

    bool spfa(int ini, int end) {
      vi ent(n, -1);
      vector<cost_type> dist(n, CINF);
      vector<bool> mark(n); queue<int> q;

      dist[ini] = 0; q.push(ini); mark[ini] = true;
      while(!q.empty()) {
        int u = q.front(); q.pop(); mark[u] = false;
        for(auto a : adj[u]) {
          int v = dest[a];
          if (capres(a) >= delta && dist[v] > dist[u]+cost[a]) {
            dist[v] = dist[u]+cost[a];
            ent[v] = a;
            if (!mark[v]) { q.push(v); mark[v] = true; }
          }
        }
      }

      if (ent[end] == -1) return false;
      for (int a = ent[end]; a != -1; a = ent[orig(a)]) {
        C += delta * cost[a];
        flow[a] += delta;
        flow[inv(a)] -= delta;
      }
      F += delta;
      return true;
    }
};
