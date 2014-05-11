#include "header.cpp"

/**
 * Gaussian elimination on field Z(p)
 *
 * @param A The matrix, each element is a row where
 * the last element is constant term. This will be
 * modified by the algorithm to upper triangular.
 * @param p A prime
 * @return -1 if infeasible, and rank of the system
 * otherwise.
 */
int solve(vector<vi>& A, int p) {
  int m = SZ(A);
  int n = SZ(A[0])-1;
  int rank = 0;
  REP(i, m) REP(j, n+1) A[i][j] = mod(A[i][j], p);
  REP(j, n) {
    for (int i = rank; i < m; i++) if (A[i][j] != 0) {
      swap(A[i], A[rank]);
      break;
    }
    if (A[rank][j] == 0) continue;
    for (int l = n; l >= j; l--) A[rank][l] = mod(A[rank][l]*inv(A[rank][j], p), p);
    for (int i = rank+1; i < m; i++) for (int l = n; l >= j; l--)
      A[i][l] = mod(A[i][l]-A[rank][l] * A[i][j], p);
    rank++;
  }
  for (int i = rank; i < m; i++) if (A[i][n] != 0) return -1;
  return rank;
}
