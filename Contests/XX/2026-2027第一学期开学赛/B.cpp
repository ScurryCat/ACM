#include <bits/stdc++.h>
using namespace std;

void solve(){
  int n;
  cin >> n;
  int m = n / 6 + (n % 6) / 2;
  cout << m << '\n';
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int t = 1;
  cin >> t;
  while(t--){
    solve();
  }

  return 0;
}