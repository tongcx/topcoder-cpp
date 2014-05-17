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
#define rep(i, n) for (int i = 0; i < n; i++)
#define irep(i, n) for (int i = n-1; i >= 0; i--)
#define rep1(i, n) for (int i = 1; i <= n; i++)
#define irep1(i, n) for (int i = n; i >= 1; i--)
#define sz(c) int((c).size())
#define mset(c, v) memset(c, v, sizeof(c))
#define all(c) (c).begin(), (c).end()
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define trace(x...) x
#define print(x...) trace(fprintf(stderr, x))
#define watch(x) trace({auto _VAL = (x); cerr << #x << " = " << _VAL << endl;})
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
int inv(int a, int p) { return a == 1 ? 1 : ll(p-p/a) * inv(p%a, p) % p;}
