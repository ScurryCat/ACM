#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 1e5+9;

int n, m;

struct seg{
  int l, r;
};

vector<seg> s, S;

inline bool cmp(seg x, seg y){
  if(x.l != y.l){
    return x.l < y.l;
  }
  return x.r < y.r;
}

inline void solve(){
  cin >> n >> m;
  s.resize(n+1), S.resize(m+1);
  for(int i=1; i<=n; i++){
    cin >> s[i].l >> s[i].r;
  }
  for(int i=1; i<=m; i++){
    cin >> S[i].l >> S[i].r;
  }

  sort(s.begin()+1, s.end(), cmp);
  sort(S.begin()+1, S.end(), cmp);

  int b = 1;
  for(int i=1; i<=m; i++){
    int L = S[i].l, R = S[i].r, ans = 0;
    for(int j=b; j<=n; j++){
      int l = s[i].l, r = s[i].r;
      if(((R - L) << 1) >= r - l) ans++;
    }
    cout << ans << '\n';
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int t = 1;
  // cin >> t;
  while(t--){
    solve();
  }

  return 0;
}