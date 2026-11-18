#include <bits/stdc++.h>
using namespace std;

inline void qwq_(){
  int n, ans = 0; cin>>n;
  vector<int> a(n+1), f(n+1);
  f[1] = 1;
  for(int i=1; i<n; i++){
    cin >> a[i];
    if(a[i] == a[i-1]+1) f[i] = f[i-1]+1;
    else f[i] = 1;
  }
  for(int i=2; i<n; i++){
    if(a[i-1]+2 == a[i]){
      int j = i;
      while(f[j] < f[j+1]) j++;
      ans = max(ans, f[i-1]+f[j]+1);
    }
  }
  if(!ans) ans = n;
  cout << ans << '\n';
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int t; cin >> t;
  while(t--) qwq_();
  return 0;
}