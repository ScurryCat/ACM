#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll gcd(ll x, ll y){
  return x ? gcd(y%x, x) : y;
}

ll lcm(ll x, ll y){
  return x * y / gcd(x, y);
}

int main(){
  ll x = 1, y = 3;
  for(int i=2; i<=2026; i++){
    ll a = 2*i-1; 
    ll b = 2*i+1;
    ll c = a * b;
    x = x * lcm(c, y) / y + lcm(c, y) / c;
    y = lcm(c, y);
    ll nx = x;
    ll ny = y;
    while(gcd(x, y) > 1){
      nx /= gcd(x, y);
      ny /= gcd(x, y);
      x = nx;
      y = ny;
    }
  }
  cout << x + y;
  return 0;
}