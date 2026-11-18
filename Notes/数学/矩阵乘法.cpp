#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9+7;

struct Matrix{
  static constexpr int msize = 2;
  int c[msize][msize];
  Matrix(){
    memset(c, 0, sizeof c);
  }

  Matrix operator*(const Matrix &o)const{
    Matrix r;
    for(int k=0; k<msize; k++){
      for(int i=0; i<msize; i++){
        for(int j=0; j<msize; j++){
          r.c[i][j] = (r.c[i][j] + (ll)c[i][k] * o.c[k][j]) % mod;
        }
      }
    }
    return r;
  }

  friend ostream &operator<<(ostream &os, const Matrix &m){
    for(int i=0; i<msize; i++){
      for(int j=0; j<msize; j++){
        os << m.c[i][j] << " \n"[j == msize - 1];
      }
    }
    return os;
  }
};

inline Matrix qpow(Matrix a, Matrix t, ll b){
  if(b <= 0) return a;
  Matrix r = a;
  while(b){
    if(b & 1) r = r * t;
    t = t * t;
    b >>= 1;
  }
  return r;
}

int main(){
  Matrix x, y;
  x.c[0][0] = 1;
  x.c[0][1] = 1;
  y.c[0][0] = 1;
  y.c[0][1] = 1;
  y.c[1][0] = 1;

  ll n; cin >> n;
  Matrix r = qpow(x, y, n-2);

  cout << r.c[0][0];

  return 0;
}