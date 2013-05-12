#include <vector>
using namespace std;
typedef vector<int> vi;

// use [val] to store intrinsic values
// use [aux] to store update info
// this verison implements length of covered intervals
struct segtree {
  vi val, aux;
  int n;

  segtree(int N) {
    for (n = 1; n < N; n *= 2);
    val.resize(2*n-1);
    aux.resize(2*n-1);
  }

  void update(int l, int r, int d) { update(l, r, d, 0, 0, n);}
  void update(int l, int r, int d, int u, int L, int R) {
    if (l >= R || r <= L || l >= r) return;
    if (l <= L && r >= R) val[u] += d;
    else {
      int M = (L+R)/2;
      update(l, r, d, 2*u+1, L, M);
      update(l, r, d, 2*u+2, M, R);
    }

    if (val[u] > 0) aux[u] = R-L;
    else aux[u] = R-L>1 ? aux[2*u+1] + aux[2*u+2] : 0;
  }

  int query(int l, int r) { return query(l, r, 0, 0, n);}
  int query(int l, int r, int u, int L, int R) {
    if (l >= R || r <= L || l >= r) return 0;
    if (l <= L && r >= R) return aux[u];

    if (val[u] > 0) return min(r, R) - max(l, L);
    int M = (L+R)/2;
    return query(l, r, u*2+1, L, M) + query(l, r, u*2+2, M, R);
  }
};
