#include "header.cpp"

vector<point> fft(vector<point> x, bool invert) {
  // make sure size of x is power of 2
  int cnt = SZ(x);
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
      REP(j, halfLen) {
        auto u = x[i + j];
        auto v = x[i + j + halfLen] * w;
        x[i + j] = u + v;
        x[i + j + halfLen] = u - v;
        w *= wLen;
      }
    }
  }
  if (invert) REP(i, cnt) x[i] /= cnt;
  return x;
}

vi poly_multiply(vi a, vi b) {
  int resultSize = SZ(a)+SZ(b)-1;
  int cnt = 1 << (33 - __builtin_clz(max(SZ(a), SZ(b)) - 1));
  a.resize(cnt), b.resize(cnt);
  vector<point> aa(ALL(a)), bb(ALL(b));
  aa = fft(aa, false), bb = fft(bb, false);
  vector<point> cc(cnt);
  REP(i, cnt) cc[i] = aa[i] * bb[i];
  cc = fft(cc, true);
  vi res(resultSize);
  REP(i, resultSize) res[i] = round(real(cc[i]));
  return res;
}
