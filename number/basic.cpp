#ifndef NUMBER_CPP
#define NUMBER_CPP

#include "../header.cpp"

// no need to worry about overflow, |x| <= |b| and |y| <= |a| is an invariant
template<class I> void bezout(I a, I b, I& x, I& y) {
  I t;
  if (b == 0) x=1,y=0;
  else bezout(b, a%b, x, y), t = x, x = y, y = t - (a/b) * y;
}

template<class C>
inline C mod(C a, int b) {
  return (a%b + b) % b;
}

void factorize(int n, vi &primes, vi &orders) {
  primes.clear();
  orders.clear();

  for (int i = 2; i*i <= n; i++)
    if (n % i == 0) {
      int cnt = 0;
      primes.push_back(i);
      while (n % i == 0) {
        n /= i;
        cnt++;
      }
      orders.push_back(cnt);
    }
  if (n > 1) {
    primes.push_back(n);
    orders.push_back(1);
  }
}

// return all primes smaller than n
vi eratosthenes(int n) {
  vector<bool> mask(n);
  vi ret;
  for (int p = 2; p < n; p++) {
    if (mask[p]) continue;
    ret.push_back(p);
    for (int x = 2*p; x < n; x += p)
      mask[x] = true;
  }
  return ret;
}

#endif
