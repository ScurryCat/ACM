#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll ans;

int main(){
  for(int i=1; i<=20260606; i++){
    ll j = i, x = 10;
    while(j >= 10){
      j /= 10;
      x *= 10;
    }
    ans += x * 9;
  }
  cout << ans;
  return 0;
}