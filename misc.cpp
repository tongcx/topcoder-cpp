#include <vector>
#include <string>
#include <algorithm>
#define REP(i, n) for (int i = 0; i < n; i++)
#define EACH(i, c) for (typeof ((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define SZ(c) int((c).size())
#define PB push_back
#define MP make_pair
using namespace std;
typedef vector<int> vi;

template<class C> inline void chmax(C& x, const C& a) { if (x < a) x = a;}
template<class C> inline void chmin(C& x, const C& a) { if (x > a) x = a;}

#include <sstream>

template<class C> string to_string(const C& x) {
  stringstream ss;
  ss << x;
  return ss.str();
}

template<class C> C from_string(const string& s) {
  stringstream ss(s);
  C x;
  ss >> x;
  return x;
}
