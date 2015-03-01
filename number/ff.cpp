#ifndef FF_CPP
#define FF_CPP

#include <random>
#include "number.cpp"

// FiniteField element
// Invariant: 0 <= x < p unless p == 0
//
// Changed from the architecture of FF::element because
// it's hard to play well with matrix for not being
// able to have default constructor
struct FF {
  int p, x;

  FF(int p = 0, int x = 0) : p(p), x(x) {}
};

// When calling these operators, make sure
// a and b have the same p
FF operator+(const FF &a, const FF &b) {
  return FF(a.p, (ll(a.x) + b.x) % a.p);
}

FF& operator+=(FF &a, const FF &b) {
  a = a + b;
  return a;
}

FF operator-(const FF &a, const FF &b) {
  return FF(a.p, ((a.x - b.x) % a.p + a.p) % a.p);
}

FF operator*(const FF &a, const FF &b) {
  return FF(a.p, (ll(a.x) * b.x) % a.p);
}

FF operator/(const FF &a, const FF &b) {
  return a * inv(b.p, b.x);
}

bool operator==(const FF &a, const FF &b) {
  return a.x == b.x && a.p == b.p;
}

FF pow(const FF &n, int k) {
  if (k == 0) return FF(n.p, 1);
  return pow(n*n, k / 2) * (k % 2 ? n : FF(n.p, 1));
}

ostream& operator<<(ostream &out, const FF &n) {
  out << n.x;
}


FF find_generator(int p) {
  // return a generator of Zp
  default_random_engine gen;
  uniform_int_distribution<int> unif(1, p-1);

  // factorization of p-1
  vi fac, tmp;
  factorize(p - 1, fac, tmp);

  while(true) {
    FF g(p, unif(gen));
    bool flag = true;

    for (int q : fac)
      if (pow(g, (p - 1) / q).x == 1) {
        flag = false;
        break;
      }

    if (flag) return g;
  }
}

#endif
