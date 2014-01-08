#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <cstdio>
#include <iostream>
#include <complex>
#include <cassert>
#define REP(i, n) for (int i = 0; i < n; i++)
#define SZ(c) int((c).size())
#define MSET(c, v) memset(c, v, sizeof(c))
#define ALL(c) (c).begin(), (c).end()
#define PB push_back
#define TRACE(x...) x
#define PRINT(x...) TRACE(fprintf(stderr, x))
#define WATCH(x) TRACE({auto _VAL = (x); cerr << #x << " = " << _VAL << endl;})
using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vd = vector<double>;
using point = complex<double>;
const int INF = 0x3f3f3f3f;

template<class K, class V> ostream& operator<<(ostream& out, const pair<K,V>& v) { out<<'('<<v.first<<','<<v.second<<')'; return out;}
template<class C, class=typename C::iterator> struct _cprint { using type = void;}; template<> struct _cprint<string> {};
template<class C, class=typename _cprint<C>::type> ostream& operator<<(ostream& out, const C& v) {for(auto x : v) out<<x<<' '; return out;}
template<class C> inline void chmax(C& x, const C& a) { if (x < a) x = a;}
template<class C> inline void chmin(C& x, const C& a) { if (x > a) x = a;}
template<class C> inline C mod(C a, C b) { return (a%b+b)%b;}
