#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <sstream>
#include <queue>
#define REP(i, n) for (int i = 0; i < n; i++)
#define SZ(c) int((c).size())
#define PB push_back
#define MP make_pair
#define ALL(c) (c).begin(), (c).end()
#define MSET(c, v) memset(c, v, sizeof(c))
#define TRACE(x...) x
#define PRINT(x...) TRACE(printf(x))
#define WATCH(x) TRACE(cout << #x << " = " << x << endl)
using namespace std;
typedef vector<int> vi;
typedef long long ll;
const int INF = 0x3f3f3f3f;

namespace std {
	template<class T> struct hash<vector<T> > {
		hash<T> fn;
		size_t operator()(const vector<T>& v) const {
			size_t seed = 0;
			for (auto x : v) seed ^= fn(x) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
			return seed;
		}
	};
}

template<class C> ostream& operator<<(ostream& out, const vector<C>& v) {for(auto x : v) out<<x<<' '; return out;}
template<class C> inline void chmax(C& x, const C& a) { if (x < a) x = a;}
template<class C> inline void chmin(C& x, const C& a) { if (x > a) x = a;}
template<class C> string to_string(const C& x) {stringstream ss;ss << x;return ss.str();}
template<class C> C from_string(const string& s) {stringstream ss(s);C x;ss >> x;return x;}
template<class C> inline C mod(C a, C b) { return (a%b+b)%b;}
