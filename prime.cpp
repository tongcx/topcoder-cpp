#include <random>
#include "header.cpp"
using namespace std;

vi factorize(int n) {
  vi ret;

  for (int i = 2; i*i <= n; i++)
    if (n % i == 0) {
      ret.push_back(i);
      while (n % i == 0) n /= i;
    }
  if (n > 1) ret.push_back(n);

  return ret;
}

struct PrimeField {
  int p;
  // a generator
  int g;

  PrimeField(int p) : p(p), g(generator()) {}

  int pow(int n, int k) {
    if (k == 0) return 1;
    return pow(ll(n) * n % p, k / 2) * (k % 2 ? ll(n) : 1) % p;
  }

  int add(int a, int b) { return (ll(a) + b) % p;}
  int subtract(int a, int b) { return ((a - b) % p + p) % p;}
  int multiply(int a, int b) { return ll(a) * b % p;}
  int inv(int a) { return a == 1 ? 1 : ll(p-p/a) * inv(p%a) % p;}
  int divide(int a, int b) { return multiply(a, inv(b));}

  int generator() {
    // return a generator of Zp
    default_random_engine gen;
    uniform_int_distribution<int> unif(1, p-1);

    // factorization of p-1
    vi fac = factorize(p - 1);

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

  vi _dft(vi x, int h) {
    // use h as generator, make sure order(h) == size(x)
    int n = sz(x);
    vi y(n);
    rep(f, n) rep(t, n)
      y[f] = add(y[f], multiply(x[t], pow(h, f*t)));
    return y;
  }

  vi dft(vi x) {
    // make sure size(x) can divide p - 1
    int n = sz(x);
    int h = pow(g, (p - 1) / n);
    return _dft(x, h);
  }

  vi idft(vi y) {
    int n = sz(y);
    int h = inv(pow(g, (p - 1) / n));

    vi x = _dft(y, h);
    rep(t, n) x[t] = divide(x[t], n);

    return x;
  }

  vi multiply(vi x, vi y) {
    int n = sz(x);
    vi z(n);
    rep(i, n) z[i] = multiply(x[i], y[i]);
    return z;
  }
};

int main() {
  PrimeField pf(37);

  vi x = {5, 7, 0, 1};
  vi y = {10, 1, 0, 1};

  watch(pf.idft(pf.multiply(pf.dft(x), pf.dft(y))));
}
