#include "header.cpp"

/**
 * Return the result of FFT. Here x's size must be
 * power of 2.
 *
 * @param x The coefficient vector
 * @param invert Whether to invert rather than compute FFT
 * @return The computed vector
 */
vector<point> fft(vector<point> x, bool invert) {
  // make sure size of x is power of 2
  int cnt = sz(x);
  assert(__builtin_popcount(cnt) == 1);
  for (int i = 1, j = 0; i < cnt; i++) {
    int bit = cnt >> 1;
    for (; j >= bit; bit >>= 1)
      j -= bit;
    j += bit;
    if (i < j) swap(x[i], x[j]);
  }
  for (int len = 2; len <= cnt; len <<= 1) {
    int halfLen = len >> 1;
    double angle = 2 * M_PI / len;
    if (invert)
      angle = -angle;
    point wLen(cos(angle), sin(angle));
    for (int i = 0; i < cnt; i += len) {
      point w(1,0);
      rep(j, halfLen) {
        auto u = x[i + j];
        auto v = x[i + j + halfLen] * w;
        x[i + j] = u + v;
        x[i + j + halfLen] = u - v;
        w *= wLen;
      }
    }
  }
  if (invert) rep(i, cnt) x[i] /= cnt;
  return x;
}

/**
 * Compute the mulplication of two polynomials.
 * We use vi to represent polynomial where ith
 * element is the coefficient of ith power of x.
 *
 * @param a The first polynomial
 * @param b The second polynomial
 * @return The product of two polynomials
 */
vi poly_multiply(vi a, vi b) {
  int resultSize = sz(a)+sz(b)-1;
  int cnt = 1 << (33 - __builtin_clz(max(sz(a), sz(b)) - 1));
  a.resize(cnt), b.resize(cnt);
  vector<point> aa(all(a)), bb(all(b));
  aa = fft(aa, false), bb = fft(bb, false);
  vector<point> cc(cnt);
  rep(i, cnt) cc[i] = aa[i] * bb[i];
  cc = fft(cc, true);
  vi res(resultSize);
  rep(i, resultSize) res[i] = round(real(cc[i]));
  return res;
}
