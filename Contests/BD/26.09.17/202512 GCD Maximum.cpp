#include <bits/stdc++.h>
using namespace std;

void solve(){
  int n;
  cin >> n;
  if(n == 2){
    cout << 2 << ' ' << 1;
  }
  else if(n & 1){
    for(int i=1; i<=n; i++) cout << i << ' ';
  }
  else{
    for(int i=1; i<=n; i+=2) cout << i+1 << ' ' << i << ' ';
  }
}
// 1 2 3 4 ... 2n
// 1 2 3 4 ... 2n
// 2n 4n-2 6n-6 8n-12 ... n^2 ... 2n
// (n+1) / 2 * 

// 1 2 3 4 5 6
// 2 1 4 3 6 5

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int t = 1;

  while(t--){
    solve();
  }

  return 0;
}