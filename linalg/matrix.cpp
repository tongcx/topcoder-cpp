#ifndef MATRIX_CPP
#define MATRIX_CPP

#include "../header.cpp"

template<class C>
struct matrix {
  int n,m;
  vector<C> x;

  matrix(int n, int m, vector<C> v) : n(n), m(m), x(v) {}
  matrix(int n, int m, const C& c = C()) : matrix(n, m, vector<C>(n*m, c) ) {}
  matrix(vector<C> v) : matrix(SZ(v), 1, v) {}

  inline const C& operator()(int i, int j) const {
    return x[i*m + j];
  }
  inline C& operator()(int i, int j) {
    return x[i*m + j];
  }
};

template<class C>
matrix<C> operator+(const matrix<C>& a, const matrix<C>& b) {
  vector<C> c;

  REP(i, a.n * a.m)
    c.push_back(a.x[i] + b.x[i]);

  return matrix<C>(a.n, a.m, c);
}

template<class C>
matrix<C> operator-(const matrix<C>& a, const matrix<C>& b) {
  vector<C> c;

  REP(i, a.n * a.m)
    c.push_back(a.x[i] - b.x[i]);

  return matrix<C>(a.n, a.m, c);
}

template<class C>
matrix<C> operator-(const matrix<C>& a) {
  vector<C> c;

  REP(i, a.n * a.m)
    c.push_back(-a.x[i]);

  return matrix<C>(a.n, a.m, c);
}

template<class C>
matrix<C> operator*(const matrix<C>& a, const matrix<C>& b) {
  vector<C> c;

  REP(i, a.n) REP(j, b.m) {
    // in case C doesn't have default constructor
    C t = a(i, a.m-1) * b(a.m-1, j);

    REP(k, a.m - 1)
      t += a(i, k) * b(k, j);

    c.push_back(t);
  }

  return matrix<C>(a.n, b.m, c);
}

template<class C>
bool operator==(const matrix<C>& a, const matrix<C>& b) {
  return a.n == b.n && a.m == b.m && a.x == b.x;
}

template<class C>
bool operator!=(const matrix<C>& a, const matrix<C>& b) {
  return !(a == b);
}

template<class C>
ostream& operator<<(ostream &out, const matrix<C>& a) {
  out << endl;
  REP(i, a.n) {
    out << '|';
    REP(j, a.m - 1) out << a(i,j) << ' ';
    out << a(i, a.m - 1) << "|\n";
  }

  return out;
}

#endif
