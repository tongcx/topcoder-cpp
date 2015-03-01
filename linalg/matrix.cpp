#ifndef MATRIX_CPP
#define MATRIX_CPP

#include "../header.cpp"
#include <valarray>

template<class C>
struct matrix {
  int n,m;
  valarray<C> x;

  matrix(int n, int m) : n(n), m(m), x(n*m) {}
  matrix(valarray<C> v) : n(SZ(v)), m(1), x(v) {}
  matrix(int n, int m, valarray<C> v) : n(n), m(m), x(v) {}

  inline const C& operator()(int i, int j) const {
    return x[i*m + j];
  }
  inline C& operator()(int i, int j) {
    return x[i*m + j];
  }
};

template<class C>
matrix<C> operator+(const matrix<C>& a, const matrix<C>& b) {
  return matrix<C>(a.n, a.m, a.x + b.x);
}

template<class C>
matrix<C> operator-(const matrix<C>& a, const matrix<C>& b) {
  return matrix<C>(a.n, a.m, a.x - b.x);
}

template<class C>
matrix<C> operator*(const matrix<C>& a, const matrix<C>& b) {
  matrix<C> ret(a.n, b.m);
  REP(i, a.n) REP(j, b.m) REP(k, a.m)
    ret(i, j) += a(i, k) * b(k, j);
  return ret;
}

template<class C>
ostream& operator<<(ostream &out, const matrix<C>& a) {
  out << endl;
  REP(i, a.n) {
    out << '|';
    REP(j, a.m) out << a(i,j) << ' ';
    out << "|\n";
  }

  return out;
}

#include "../number/finite_field.cpp"

int main() {
  matrix<FiniteField::element> a(2, 2);
  WATCH(a);
  WATCH(a*a);
}

#endif
