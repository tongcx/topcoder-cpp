  /*
  vi _dft(vi x, int h) {
    // use h as generator, make sure order(h) == size(x)
    int n = SZ(x);
    vi y(n);
    REP(f, n) REP(t, n)
      y[f] = add(y[f], multiply(x[t], pow(h, f*t)));
    return y;
  }

  vi dft(vi x) {
    // make sure size(x) can divide p - 1
    int n = SZ(x);
    int h = pow(g, (p - 1) / n);
    return _dft(x, h);
  }

  vi idft(vi y) {
    int n = SZ(y);
    int h = inv(pow(g, (p - 1) / n));

    vi x = _dft(y, h);
    REP(t, n) x[t] = divide(x[t], n);

    return x;
  }

  vi multiply(vi x, vi y) {
    int n = SZ(x);
    vi z(n);
    REP(i, n) z[i] = multiply(x[i], y[i]);
    return z;
  }
  */
