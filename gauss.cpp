#include "header.cpp"

// LinSys with n vars on Z(p)
// Use A[i][n] as constant term
struct LinSystem {
  int n, p, rank;
  vector<vi> A;

  LinSystem(int n, int p) : n(n), p(p) {}

  // Add one constraint, where the vector contains
  // the coefficients of the constraint. Size should
  // be n+1, and the last one is constant term.
  void add_constr(vi& constr) {
    A.push_back(constr);
  }

  inline int reg(int x) { return mod(x, p);}

  // Try to solve this linear system, will return
  // whether the system is feasible. If feasible,
  // can find out rank by accessing `rank`
  bool solve() {
    int m = A.size();
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
