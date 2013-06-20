#include "header.cpp"

int inv(int a, int p) { return a == 1 ? 1 : ll(p-p/a) * inv(p%a, p) % p;}

// LinSys with m eqs and n vars on Z(p)
// Use A[i][n] as constant term
struct LinSystem {
  int m, n, p, rank;
  vector<vi> A;

  LinSystem(int m, int n, int p) : m(m), n(n), p(p), A(m, vi(n+1)) {}
  inline int reg(int x) { return mod(x, p);}

  bool solve() {
    REP(i, m) REP(j, n+1) A[i][j] = reg(A[i][j]);
    rank = 0;
    REP(j, n) {
      for (int i = rank; i < m; i++) if (A[i][j] != 0) {
        swap(A[i], A[rank]);
        break;
      }
      if (A[rank][j] == 0) continue;
      for (int l = n; l >= j; l--) A[rank][l] = reg(A[rank][l]*inv(A[rank][j], p));
      for (int i = rank+1; i < m; i++) for (int l = n; l >= j; l--)
        A[i][l] = reg(A[i][l]-A[rank][l] * A[i][j]);
      rank++;
    }
    for (int i = rank; i < m; i++) if (A[i][n] != 0) return false;
    return true;
  }
};
