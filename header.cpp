#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <queue>
#define REP(i, n) for (int i = 0; i < n; i++)
#define EACH(i, c) for (typeof ((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define SZ(c) int((c).size())
#define PB push_back
#define MP make_pair
#define MSET(c, v) memset(c, v, sizeof(c))
#define TRACE(x...) x
#define PRINT(x...) TRACE(printf(x))
#define WATCH(x) TRACE(cout << #x << " = " << x << endl)
using namespace std;
typedef vector<int> vi;
typedef long long ll;
const int INF = 0x3f3f3f3f;

template<class C> ostream& operator<<(ostream& out, const vector<C>& v) {EACH(x, v) out<<*x<<' '; return out;}
template<class C> inline void chmax(C& x, const C& a) { if (x < a) x = a;}
template<class C> inline void chmin(C& x, const C& a) { if (x > a) x = a;}
template<class C> string to_string(const C& x) {stringstream ss;ss << x;return ss.str();}
template<class C> C from_string(const string& s) {stringstream ss(s);C x;ss >> x;return x;}
template<class C> inline C mod(C a, C b) { return (a%b+b)%b;}
