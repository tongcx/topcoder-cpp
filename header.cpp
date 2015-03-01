#include <vector>
#include <string>
#include <algorithm>
#define REP(i, n) for (int i = 0; i < n; i++)
#define SZ(c) int((c).size())
#define ALL(c) (c).begin(), (c).end()
using namespace std;
using ll = long long;
using vi = vector<int>;

template<class C> inline void chmax(C& x, const C& a) { x = max(x, a);}
template<class C> inline void chmin(C& x, const C& a) { x = min(x, a);}

// Other functionality
#include <map>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <cstdio>
#include <iostream>
#define IREP(i, n) for (int i = n-1; i >= 0; i--)
#define REP1(i, n) for (int i = 1; i <= n; i++)
#define IREP1(i, n) for (int i = n; i >= 1; i--)
#define MSET(c, v) memset(c, v, sizeof(c))
using vl = vector<ll>;
using vd = vector<double>;
const int INF = 0x3f3f3f3f;

template<class C> inline C mod(C a, C b) { return (a%b+b)%b;}
int inv(int a, int p) { return a == 1 ? 1 : ll(p-p/a) * inv(p%a, p) % p;}

// Debug
#define TRACE(x...) x
#define PRINT(x...) TRACE(fprintf(stderr, x))
#define WATCH(x) TRACE({auto _VAL = (x); cerr << #x << " = " << _VAL << endl;})

template<class K, class V> ostream& operator<<(ostream& out, const pair<K,V>& v) { out<<'('<<v.first<<','<<v.second<<')'; return out;}
template<class C, class=typename C::iterator> struct _cprint { using type = void;}; template<> struct _cprint<string> {};
template<class C, class=typename _cprint<C>::type> ostream& operator<<(ostream& out, const C& v) {for(auto x : v) out<<x<<' '; return out;}
