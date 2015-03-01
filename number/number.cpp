#include "../header.cpp"

// no need to worry about overflow, |x| <= |b| and |y| <= |a| is an invariant
template<class I> void bezout(I a, I b, I& x, I& y) {
  I t;
  if (b == 0) x=1,y=0;
  else bezout(b, a%b, x, y), t = x, x = y, y = t - (a/b) * y;
}

template<class I> I crt(I p, I a, I q, I b) {
  I m = p*q, x, y;
  bezout(p, q, x, y);
  return mod(a*y%m*q+b*x%m*p,m);
}

template<class C>
inline C mod(C a, int b) {
  return (a%b + b) % b;
}

int inv(int a, int p) {
  return a == 1 ? 1 :
    ll(p - p/a) * inv(p%a, p) % p;
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
