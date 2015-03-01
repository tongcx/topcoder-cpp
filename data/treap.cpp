#include <random>
#include "../header.cpp"

template<class C>
struct treap {
  struct node {
    // parent, left, right
    node *p, *l, *r;
    // value
    C v;
    // size of subtree
    int s;
    // priority
    int w;
  };

  default_random_engine gen;
  uniform_int_distribution<int> unif;

  node *root = nullptr;

  int _size(node* n) {
    return n ? n->s : 0;
  }

  node* _insert(const C& v) {
    node* n = new node;
    n->l = n->r = nullptr;
    n->v = v;
    n->s = 1;
    n->w = unif(gen);

    // insertion
    if (root == nullptr) {
      root = n;
      n->p = nullptr;
      return n;
    }

    node* p = root;
    while(true) {
      p->s++;

      if (v < p->v) {
        if (p->l == nullptr) {
          p->l = n;
          break;
        } else p = p->l;
      } else {
        if (p->r == nullptr) {
          p->r = n;
          break;
        } else p = p->r;
      }
    }
    n->p = p;

    return n;
  }

  void _rotate(node* n) {
    while (n != root && n->p->w < n->w) {
      node* p = n->p;
      node* pp = p->p;

      // edge between n and pp
      if (pp) {
        if (p == pp->l) pp->l = n;
        else pp->r = n;
      } else root = n;
      n->p = pp;

      if (n == p->l) {
        // edge between n->r and p
        if (n->r) n->r->p = p;
        p->l = n->r;

        n->r = p;
      } else {
        if (n->l) n->l->p = p;
        p->r = n->l;

        n->l = p;
      }
      p->p = n;

      p->s = 1 + _size(p->l) + _size(p->r);
      n->s = 1 + _size(n->l) + _size(n->r);
    }
  }

  void insert(const C& v) {
    node* n = _insert(v);
    _rotate(n);
  }

  const C& kth(int k) {
    node* n = root;
    while (n) {
      if (k < _size(n->l)) n = n->l;
      else if (k > _size(n->l)) {
        k -= _size(n->l) + 1;
        n = n->r;
      } else return n->v;
    }
    throw out_of_range("k too large");
  }

  // return how many elements are smaller than v
  int position(const C& v) {
    int ret = 0;
    node* n = root;

    while (n) {
      if (n->v < v) {
        ret += _size(n->l) + 1;
        n = n->r;
      } else n = n->l;
    }

    return ret;
  }

  bool contain(const C& v) {
    node* n = root;

    while (n) {
      if (v < n->v) n = n->l;
      else if (v > n->v) n = n->r;
      else return true;
    }

    return false;
  }

  int size() {
    return _size(root);
  }

  bool empty() {
    return size() == 0;
  }
};

template<class C>
void print(ostream& out, const typename treap<C>::node* n, int depth) {
  if (n == nullptr) return;
  cout << string(depth, '|') << 'v' << n->v
    << " s" << n->s
    << " w" << n->w
    << endl;
  print<C>(out, n->l, depth+1);
  print<C>(out, n->r, depth+1);
}

template<class C>
ostream& operator<<(ostream& out, const treap<C>& t) {
  out << endl;
  print<C>(out, t.root, 0);
  return out;
}
