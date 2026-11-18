#include <bits/stdc++.h>
using namespace std;

const int N = 1e4+9;
int p[N], vis[N], idx;

void ora(int n){
  for(int i=2; i<=n; i++){
    if(!vis[i]) p[++idx] = i;
    for(int j=1; i*p[j]<=n; j++){
      vis[i*p[j]] = 1;
      if(i % p[j] == 0) break;
    }
  }
}

void solve(){
  int n;
  cin >> n;
  ora(n);

  for(int i=1; i<=idx; i++){
    cout << p[i] << '\n';
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