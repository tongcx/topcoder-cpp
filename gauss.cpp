#include <vector>
#include <algorithm>
#define REP(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef vector<int> vi;

template<class C> inline C mod(C a, C b) { return (a%b+b)%b;}

int euclid(int a, int b, int& x, int& y) {
  if (b == 0) {
    x = 1; y = 0;
    return a;
  }
  int res = euclid(b, a%b, x, y);
  int t = x; x = y; y = t - (a/b) * y;
  return res;
}

// LinSys with m eqs and n vars on Z(p)
// Use A[i][n] as constant term
struct LinSystem {
  int m, n, p, rank;
  vector<vi> A;

  LinSystem(int m, int n, int p) : m(m), n(n), p(p), A(m, vi(n+1)) {}
  inline int reg(int x) { return mod(x, p);}
  int inv(int a) {
    int x,y;
    euclid(a, p, x, y);
    return x;
  }

  bool solve() {
    REP(i, m) REP(j, n+1) A[i][j] = reg(A[i][j]);
    rank = 0;
    REP(j, n) {
      for (int i = rank; i < m; i++) if (A[i][j] != 0) {
        swap(A[i], A[rank]);
        break;
      }
      if (A[rank][j] == 0) continue;
      for (int l = n; l >= j; l--) A[rank][l] = reg(A[rank][l]*inv(A[rank][j]));
      for (int i = rank+1; i < m; i++) for (int l = n; l >= j; l--)
        A[i][l] = reg(A[i][l]-A[rank][l] * A[i][j]);
      rank++;
    }
    for (int i = rank; i < m; i++) if (A[i][n] != 0) return false;
    return true;
  }
};
