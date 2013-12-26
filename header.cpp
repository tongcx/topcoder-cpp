#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <sstream>
#include <map>
#include <queue>
#define REP(i, n) for (int i = 0; i < n; i++)
#define SZ(c) int((c).size())
#define PB push_back
#define MP make_pair
#define ALL(c) (c).begin(), (c).end()
#define MSET(c, v) memset(c, v, sizeof(c))
#define TRACE(x...) x
#define PRINT(x...) TRACE(fprintf(stderr, x))
#define WATCH(x) TRACE({auto _VAL = (x); cerr << #x << " = " << _VAL << endl;})
using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
const int INF = 0x3f3f3f3f;

template<class K, class V> ostream& operator<<(ostream& out, const pair<K,V>& v) { out<<'('<<v.first<<','<<v.second<<')'; return out;}
template<class C, class=typename C::iterator> struct _cprint { using type = void;}; template<> struct _cprint<string> {};
template<class C, class=typename _cprint<C>::type> ostream& operator<<(ostream& out, const C& v) {for(auto x : v) out<<x<<' '; return out;}
template<class C> inline void chmax(C& x, const C& a) { if (x < a) x = a;}
template<class C> inline void chmin(C& x, const C& a) { if (x > a) x = a;}
template<class C> string to_string(const C& x) {stringstream ss;ss << x;return ss.str();}
template<class C> C from_string(const string& s) {stringstream ss(s);C x;ss >> x;return x;}
template<class C> inline C mod(C a, C b) { return (a%b+b)%b;}
vector<string> split(const string& line, char delim = ' ') { vector<string> ret; stringstream ss(line); string s; while(getline(ss, s, delim)) ret.PB(s); return ret;}
void hash_combine(size_t& seed, size_t v) { seed ^= v + 0x9e3779b9 + (seed << 6) + (seed >> 2);}
