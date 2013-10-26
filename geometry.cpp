#include "header.cpp"
#include <complex>

int cmp(double a, double b = 0, const double eps = 1e-8) { return a-b>eps ? 1 : b-a>eps ? -1 : 0;}

// we use complex<double> as point
typedef complex<double> point;
int cmp(const point &a, const point &b) { int t = cmp(real(a), real(b)); return t ? t : cmp(imag(a), imag(b));}
bool operator<(const point &a, const point &b) { return cmp(a,b)<0;}
double dot(const point &a, const point &b) { return real(b*conj(a));}
double operator%(const point &a, const point &b) { return imag(b*conj(a));}
// orient return -1 if x is on the left of ab, 0 collinear, 1 right
int orient(const point &a, const point &b, const point &x) { return cmp((b-x)%(a-x));}
bool between(const point &a, const point &b, const point &x) { return orient(a,b,x)==0 && cmp(dot(a-x,b-x))<=0;}
// angle from ba to bc
double angle(const point &a, const point &b, const point &c) { return arg((c-b)/(a-b));}

bool seg_intersect(point p, point q, point r, point s) {
  point A = q - p, B = s - r, C = r - p, D = s - q;
  int a = cmp(A % C) + 2 * cmp(A % D);
  int b = cmp(B % C) + 2 * cmp(B % D);
  if (a == 3 || a == -3 || b == 3 || b == -3) return false;
  if (a || b || p == r || p == s || q == r || q == s) return true;
  int t = (p < r) + (p < s) + (q < r) + (q < s);
  return t != 0 && t != 4;
}


double seg_distance(point p, point q, point r) {
  point A = r - q, B = r - p, C = q - p;
  double a = dot(A, A), b = dot(B, B), c = dot(C, C);
  if (cmp(b, a + c) >= 0) return sqrt(a);
  else if (cmp(a, b + c) >= 0) return sqrt(b);
  else return fabs(A % B) / sqrt(c);
}

vector<point> convex_hull(const vector<point> &pts) {
  vector<point> poly(pts);
  point p0 = *min_element(ALL(poly), [](const point &a, const point &b) {return a<b;});
  sort(ALL(poly), [p0](const point &a, const point &b) {
      point p = a-p0, q = b-p0;
      int t = cmp(a%b); return t?t>0:cmp(abs(a),abs(b))<0;});
  int k = 1;
  for (int i = 1; i < SZ(poly); i++) {
    while (k>1 && cmp((poly[k-2]-poly[k-1])%(poly[i]-poly[k-1]))>=0) k--;
    poly[k++] = poly[i];
  }
  poly.resize(k);
  return poly;
}

double poly_area(const vector<point> &pts) {
  double ans = 0; int n = SZ(pts);
  REP(i, n) ans += pts[i]%pts[(i+1)%n];
  return ans / 2;
}

point line_intersect(point p, point q, point r, point s) {
  point a = q - p, b = s - r, c = point(p % q, r % s);
  return point(point(real(a), real(b)) % c, point(imag(a), imag(b)) % c) / (a % b);
}

// return 1 if inside, 0 outside, -1 on a edge
int in_poly(point p, const vector<point> &T) {
  double a = 0; int N = T.size();
  for (int i = 0; i < N; i++) {
    if (between(T[i], T[(i+1) % N], p)) return -1;
    a += angle(T[i], p, T[(i+1) % N]);
  }
  return cmp(a) != 0;
}
