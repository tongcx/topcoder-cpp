#include "header.cpp"

// nth element in sorted elements
struct Nth {
  multiset<int> s, l;
  int n;

  Nth(int n) : n(n) {rep(i, n) s.insert(INF); l.insert(INF);}
  void insert(int x) {
    s.insert(x);
    l.insert(*(--s.end()));
    s.erase(--s.end());
  }
  void erase(int x) {
    auto i = l.find(x);
    if (i != l.end()) l.erase(i);
    else if ((i = s.find(x)) != s.end()) {
      s.erase(i);
      s.insert(*l.begin());
      l.erase(l.begin());
    }
  }
  int nth() { return *l.begin();}
};
