#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9+7;

struct Matrix{
  static constexpr int msize = 3;
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

  friend ostream& operator<<(ostream& os, const Matrix& m) {
    for (int i = 0; i < msize; i++) {
      for (int j = 0; j < msize; j++) {
        os << m.c[i][j] << " \n"[j == msize - 1];
      }
    }
    return os;
  }
};

inline Matrix qpow(Matrix a, Matrix t, ll b){
  Matrix r = a;
  while(b>0 && b){
    if(b & 1) r = r * t;
    t = t * t;
    b >>= 1;
  }
  return r;
}

const int N = 5e6+9;
int vis[N], p[N], idx;

inline void ora(int n){
  for(int i=2; i<=n; i++){
    if(!vis[i]) p[++idx] = i;
    for(int j=1; i * p[j] <= n; j++){
      vis[i * p[j]] = 1;
      if(!(i % p[j])) break;
    }
  }
}

int main(){
  int n; cin >> n;
  ora(n);
  cout << idx;
  return 0;
}