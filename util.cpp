#include "header.cpp"
#include <sstream>

template<class C> string to_string(const C& x) {stringstream ss;ss << x;return ss.str();}
template<class C> C from_string(const string& s) {stringstream ss(s);C x;ss >> x;return x;}
vector<string> split(const string& line, char delim = ' ') { vector<string> ret; stringstream ss(line); string s; while(getline(ss, s, delim)) ret.push_back(s); return ret;}

void hash_combine(size_t& seed, size_t v) { seed ^= v + 0x9e3779b9 + (seed << 6) + (seed >> 2);}
namespace std { template<> struct hash<vi> {
  hash<int> h;
  size_t operator()(const vi& v) const {
    size_t seed = 0;
    for (const auto& x : v) hash_combine(seed, h(x));
    return seed;
  }
};}
namespace std { template<class K, class V> struct hash<pair<K,V>> {
  hash<K> hk;
  hash<V> hv;
  size_t operator()(const pair<K,V>& p) const {
    size_t seed = hk(p.first);
    hash_combine(seed, hv(p.second));
    return seed;
  }
};}

/**
 * Order an sequential container and output the
 * ordered indexes instead of ordered values
 */
template<class C> vi order(C& c) {
  vector<pair<typename C::value_type, int>> seq;
  int cnt = 0;
  for (auto x : c) seq.emplace_back(x, cnt++);
  sort(ALL(seq));
  vi ret;
  for (auto x : seq) ret.push_back(x.second);
  return ret;
}
