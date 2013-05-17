#include <vector>
#include <string>
#include <sstream>
#define REP(i, n) for (int i = 0; i < n; i++)
#define EACH(i, c) for (typeof ((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define SZ(c) int((c).size())
#define PB push_back
using namespace std;
typedef vector<int> vi;

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