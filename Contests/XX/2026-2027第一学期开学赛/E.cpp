#include <bits/stdc++.h>
using namespace std;

int fib[51];

void Fib(int n){
  fib[0] = 1;
  fib[1] = 1;
  for(int i=2; i<=n; i++){
    fib[i] = fib[i-1] + fib[i-2];
  }
}

void solve(){
  int a, b;
  cin >> a >> b;
  cout << fib[b-a] << '\n';
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  Fib(50);
  int t = 1;
  cin >> t;
  while(t--){
    solve();
  }

  return 0;
}