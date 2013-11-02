#include "header.cpp"

ll bezout(ll a, ll b, ll& x, ll& y) {
  if (b == 0) return x=1,y=0,a;
  ll res = bezout(b, a%b, x, y), t = x;
  return x = y, y = t - (a/b) * y, res;
}

ll crt(ll p, ll a, ll q, ll b) {
  ll m = p*q, x, y;
  bezout(p, q, x, y);
  return mod(mod(a*y,m)*q+mod(b*x,m)*p,m);
}
