#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9+7;

struct Matrix{
  static constexpr int msize = 6;
  int c[msize][msize];

  Matrix(){
    memset(c, 0, sizeof c);
  }

  Matrix operator*(const Matrix &o)const{
    Matrix r;
    for(int k=0; k<msize; k++){
      for(int i=0; i<msize; i++){
        for(int j=0; j<msize; j++){
          r.c[i][j] = ((ll)r.c[i][j] + (ll)c[i][k] * o.c[k][j]) % mod;
        }
      }
    }
    return r;
  }

  inline Matrix& operator*=(const Matrix &o){
    return *this = *this * o;
  }

  friend ostream& operator<<(ostream& os, const Matrix& m) {
    for (int i = 0; i < msize; i++) {
      for (int j = 0; j < msize; j++) {
        os << m.c[i][j] << " \n"[j == msize - 1];
      }
    }
    return os;
  }
};

inline Matrix qpow(Matrix A, Matrix T, ll b){
  Matrix R = A;
  while(b){
    if(b & 1) R *= T;
    T *= T;
    b >>= 1;
  }
  return R;
}

inline void solve(){
  ll n, a1, a2, x, y;
  cin >> n >> a1 >> a2 >> x >> y;

  if(n == 1){
    cout << 1ll * a1 * a1 % mod << '\n';
    return;
  }
  else if(n == 2){
    cout << (1ll * a1 * a1 + a2 * a2) % mod << '\n';
    return;
  }
  Matrix A, T;

  A.c[0][0] = 1ll * a1 * a1 % mod;
  A.c[0][1] = a2 % mod;
  A.c[0][2] = a1 % mod;
  A.c[0][3] = 1ll * a2 * a2 % mod;
  A.c[0][4] = 1ll * a1 * a1 % mod;
  A.c[0][5] = 1ll * a2 * a1 % mod;

  T.c[0][0] = 1;
  T.c[3][0] = 1;
  
  T.c[1][1] = x % mod;
  T.c[2][1] = y % mod;
  
  T.c[1][2] = 1;

  T.c[3][3] = 1ll * x * x % mod;
  T.c[4][3] = 1ll * y * y % mod;
  T.c[5][3] = 2ll * x * y % mod;

  T.c[3][4] = 1;
  
  T.c[3][5] = x % mod;
  T.c[5][5] = y % mod;

  Matrix R = qpow(A, T, n-2+1);

  cout << A << '\n';
  cout << T << '\n';
  cout << R << '\n';

  cout << R.c[0][0] << '\n';

}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int t; cin >> t;
  while(t--){
    solve();
  }

  return 0;
}