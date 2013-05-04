#include <vector>
#include <queue>
#define REP(i, n) for (int i = 0; i < n; i++)
#define EACH(i, c) for (typeof ((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define SZ(c) int((c).size())
#define PB push_back
using namespace std;
typedef vector<int> vi;
typedef int cost_type;
const cost_type CINF = 0x3F3F3F3F;

// MinCostMaxFlow - O(n * m^2 * log U) with SPFA
struct MCMF {
  int n, delta, F;    // n is number of nodes
  cost_type C;
  vector<cost_type> cost;
  vi dest, cap, flow;  // use SZ(dest) as nar (including back arcs)
  vector<vi> adj;

  MCMF(int n):n(n) {adj.resize(n);}
  int inv(int a) { return a ^ 0x1; }
  int orig(int a) { return dest[inv(a)]; }
  int capres(int a) { return cap[a] - flow[a]; }
  int arc(int i, int j, int u, cost_type c = 0) {
    dest.PB(j); adj[i].PB(SZ(dest)-1); cap.PB(u); cost.PB(c);
    dest.PB(i); adj[j].PB(SZ(dest)-1); cap.PB(0); cost.PB(-c);
    return SZ(dest)-2;
  }

  bool spfa(int ini, int end) {
    vi ent(n, -1);
    vector<cost_type> dist(n, CINF);
    vector<bool> mark(n); queue<int> q;

    dist[ini] = 0; q.push(ini); mark[ini] = true;
    while(!q.empty()) {
      int u = q.front(); q.pop(); mark[u] = false;
      EACH(a, adj[u]) {
        int v = dest[*a];
        if (capres(*a) >= delta && dist[v] > dist[u]+cost[*a]) {
          dist[v] = dist[u]+cost[*a];
          ent[v] = *a;
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

  cost_type mcmf(int ini, int end) {
    flow = vi(SZ(dest)); F = C = 0; int U = 0;
    REP(a, SZ(dest)) U = max(U, capres(a));
    for (delta = U; delta > 0; delta /= 2) while (spfa(ini, end));
    return C;
  }
};
