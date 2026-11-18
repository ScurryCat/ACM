#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;

void solve(){
  int n; cin >> n;
  vector<int> a(n+n+1), s(n+n+1);
  vector<vector<int>> fmx(n+n+1, vector<int>(n+n+1, -inf)), fmn(n+n+1, vector<int>(n+n+1, inf));
  for(int i=1; i<=n+n; i++){
    fmx[i][i] = 0;
    fmn[i][i] = 0;
  }
  for(int i=1; i<=n; i++){
    cin >> a[i];
    a[n+i] = a[i];
  }
  for(int i=1; i<=n+n; i++) s[i] = s[i-1] + a[i];

  for(int len = 1; len <= n; len++){
    for(int l = 1, r = l + len - 1; r <= n + n; l++, r++){
      for(int k = l; k < r; k++){
        fmx[l][r] = max(fmx[l][r], fmx[l][k] + fmx[k+1][r] + s[r] - s[l-1]);
        fmn[l][r] = min(fmn[l][r], fmn[l][k] + fmn[k+1][r] + s[r] - s[l-1]);
      }
    }
  }

  int mx = -inf, mn = inf;
  for(int i=1; i<=n; i++){
    mx = max(mx, fmx[i][i+n-1]);
    mn = min(mn, fmn[i][i+n-1]);
  }
  cout << mn << '\n' << mx;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  solve();
  
  return 0;
}