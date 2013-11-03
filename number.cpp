#include "header.cpp"

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
