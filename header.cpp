#include <vector>
#include <string>
#include <algorithm>
#define REP(i, n) for (int i = 0; i < (n); i++)
#define SZ(c) int((c).size())
#define ALL(c) (c).begin(), (c).end()
#define TRACE(x...) x
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

// CUT begin
#include <iostream>
#include <cstdio>
#define PRINT(x...) TRACE(fprintf(stderr, x))
#define WATCH(x) TRACE({auto _VAL = (x); cerr << #x << " = " << _VAL << endl;})

template<class C, class=typename C::iterator>
struct is_container {
  using type = void;
};

template<> struct is_container<string> {};

template<class C, class=typename is_container<C>::type>
ostream& operator<<(ostream& out, const C& v) {
  for (auto x : v) out << x << ' ';
  return out;
}

template<class K, class V>
ostream& operator<<(ostream& out, const pair<K,V>& v) {
  out << '(' << v.first << ',' << v.second << ')';
  return out;
}
// CUT end
