int euclid(int a, int b, int& x, int& y) {
  if (b == 0) {
    x = 1; y = 0;
    return a;
  }
  int res = euclid(b, a%b, x, y);
  int t = x; x = y; y = t - (a/b) * y;
  return res;
}
