#include <vector>
#include <string>
#include <algorithm>
#define REP(i, n) for (int i = 0; i < (n); i++)
#define SZ(c) int((c).size())
#define ALL(c) (c).begin(), (c).end()
using namespace std;
using ll = long long;
using vi = vector<int>;
const int INF = 0x3f3f3f3f;

template<class C, class D>
inline void chmax(C& x, const D& a) {
  if (x < a) x = a;
}

template<class C, class D>
inline void chmin(C& x, const D& a) {
  if (x > a) x = a;
}

// Debug
#include <iostream>
#include <cstdio>
#define TRACE(x...) x
#define PRINT(x...) TRACE(fprintf(stderr, x))
#define WATCH(x) TRACE({auto _VAL = (x); cerr << #x << " = " << _VAL << endl;})

template<class C, class=typename C::iterator>
ostream& operator<<(ostream& out, const C& v) {
  for (auto x : v) out << x << ' ';
  return out;
}

template<class K, class V>
ostream& operator<<(ostream& out, const pair<K,V>& v) {
  out << '(' << v.first << ',' << v.second << ')';
  return out;
}
