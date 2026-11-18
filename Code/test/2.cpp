#include <bits/stdc++.h>
using namespace std;

int a2, a3, a5, n;
double mx = -1e18;

inline bool decompose(int x) {
  if(x == 1) return 1;
  while(x % 2 == 0) { a2++; x/=2; }
  while(x % 3 == 0) { a3++; x/=3; }
  while(x % 5 == 0) { a5++; x/=5; }
  return x == 1;
}

inline void check(int c2, int c3, int c4, int c5, int c6) {
  int k = c2 + c3 + c4 + c5 + c6;
  double b = lgamma(c2+1) + lgamma(c3+1) + lgamma(c4+1) + lgamma(c5+1) + lgamma(c6+1);
  for(int c1 = 0; c1 <= max(1, k/4); ++c1) {
    int m = k + c1;
    if(m == 0) continue;
    double p = lgamma(m+1) - lgamma(c1+1) - b - m * log(6.0);
    if(p > mx) { mx = p; n = m; }
  }
}

inline void qwq_() {
  a2 = a3 = a5 = 0;
  int m; cin >> m;
  if(decompose(m)){
    for(int c6 = 0; c6 <= min(a2, a3); ++c6) {
      int c3 = a3 - c6;
      int r2 = a2 - c6;
      for(int c4 = 0; c4 <= r2 / 2; ++c4) {
        int c2 = r2 - c4 * 2;
        check(c2, c3, c4, a5, c6);
      }
    }
    cout << "n=" << n << '\n';
    cout << "最大概率为：" << 100 * exp(mx) << '%';
  }
  else cout << "n=0\n";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int yyy = 1;
  // cin >> yyy;
  while(yyy--) qwq_();
  return 0;
}