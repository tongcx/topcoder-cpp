#include <random>
#include "number.cpp"

struct FiniteField {
  struct element {
    FiniteField const &ff;
    int x;

    element(int x, const FiniteField &ff) : x(x), ff(ff) {}
  };

  int p;

  FiniteField(int p) : p(p) {}
  element operator[](int x) const { return element(mod(x, p), *this);}
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

bool operator==(
    const FiniteField::element &a,
    const FiniteField::element &b) {
  return a.x == b.x;
}

FiniteField::element pow(const FiniteField::element &n, int k) {
  if (k == 0) return n.ff[1];
  return pow(n*n, k / 2) * (k % 2 ? n : n.ff[1]);
}

ostream& operator<<(ostream &out, const FiniteField::element &n) {
  out << n.x;
}


FiniteField::element find_generator(FiniteField &ff) {
  // return a generator of Zp
  default_random_engine gen;
  uniform_int_distribution<int> unif(1, ff.p-1);

  // factorization of p-1
  vi fac, tmp;
  factorize(ff.p - 1, fac, tmp);

  while(true) {
    FiniteField::element g = ff[unif(gen)];
    bool flag = true;

    for (int q : fac)
      if (pow(g, (ff.p - 1) / q) == ff[1]) {
        flag = false;
        break;
      }

    if (flag) return g;
  }
}
