#include <random>
#include "number.cpp"
using namespace std;

struct FiniteField {
  int p;
  // a generator
  int g;

  struct element {
    FiniteField &ff;
    int x;

    element(int x, FiniteField &ff) : x(x), ff(ff) {}
  };


  FiniteField(int p) : p(p), g(generator()) {}
  element operator[](int x) { return element(mod(x, p), *this);}


  int generator() {
    // return a generator of Zp
    default_random_engine gen;
    uniform_int_distribution<int> unif(1, p-1);

    // factorization of p-1
    vi fac, tmp;
    factorize(p - 1, fac, tmp);

    while(true) {
      int g = unif(gen);
      bool flag = true;

      for (int q : fac)
        if (pow(g, (p - 1) / q) == 1) {
          flag = false;
          break;
        }

      if (flag) return g;
    }
  }
};

FiniteField::element operator+(
    const FiniteField::element &a,
    const FiniteField::element &b) {
  return a.ff[(ll(a.x) + b.x) % a.ff.p];
}

FiniteField::element operator-(
    const FiniteField::element &a,
    const FiniteField::element &b) {
  return a.ff[((a.x - b.x) % a.ff.p + a.ff.p) % a.ff.p];
}

FiniteField::element operator*(
    const FiniteField::element &a,
    const FiniteField::element &b) {
  return a.ff[(ll(a.x) * b.x) % a.ff.p];
}

FiniteField::element operator/(
    const FiniteField::element &a,
    const FiniteField::element &b) {
  return a * b.ff[inv(b.x, b.ff.p)];
}

FiniteField::element pow(const FiniteField::element &n, int k) {
  if (k == 0) return n.ff[1];
  return pow(n*n, k / 2) * (k % 2 ? n : n.ff[1]);
}

ostream& operator<<(ostream &out, const FiniteField::element &n) {
  out << n.x;
}
