#include <vector>
using namespace std;
typedef vector<int> vi;

struct segtree {
  vi count, len;
  int n;

  segtree(int N) {
    for (n = 1; n < N; n *= 2);
    count.resize(2*n-1);
    len.resize(2*n-1);
  }

  void modify(int l, int r, int d) { modify(l, r, d, 0, 0, n);}
  void modify(int l, int r, int d, int u, int L, int R) {
    if (l >= R || r <= L || l >= r) return;
    if (l <= L && r >= R) count[u] += d;
    else {
      int M = (L+R)/2;
      modify(l, r, d, 2*u+1, L, M);
      modify(l, r, d, 2*u+2, M, R);
    }

    if (count[u] > 0) len[u] = R-L;
    else len[u] = R-L>1 ? len[2*u+1] + len[2*u+2] : 0;
  }

  // get the length of covered intervals in [l,r)
  int getlen(int l, int r) { return getlen(l, r, 0, 0, n);}
  int getlen(int l, int r, int u, int L, int R) {
    if (l >= R || r <= L || l >= r) return 0;
    if (l <= L && r >= R) return len[u];
    int M = (L+R)/2;
    return getlen(l, r, u*2+1, L, M) + getlen(l, r, u*2+2, M, R);
  }
};
