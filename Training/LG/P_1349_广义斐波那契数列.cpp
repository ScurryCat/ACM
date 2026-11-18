#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
const int N = 1e5+9, M = 2e5+9, mod = 998244353; int t_ = 1;
using ll = long long; using ld = long double; using i128 = __int128;

#ifndef ONLINE_JUDGE
template<typename T> ostream& operator<<(ostream& os, const vector<T>& v) {os << "["; for(int i=0; i<v.size(); i++) os << (i?", ":"") << v[i]; return os << "]";}
template<typename T, typename U> ostream& operator<<(ostream& os, const pair<T, U>& p) {return os << "(" << p.first << ", " << p.second << ")";}
void debug_out(vector<string> names, int idx) { cerr << endl;} template <typename Head, typename... Tail>
void debug_out(vector<string> names, int idx, Head H, Tail... T) {if (idx > 0) cerr << ", ";string name = names[idx]; name.erase(0, name.find_first_not_of(' ')); name.erase(name.find_last_not_of(' ') + 1);cerr << name << "=" << H;debug_out(names, idx + 1, T...);}
#define debug(...) {string _s = #__VA_ARGS__, _tmp; vector<string> _names; int _p = 0;for (char c : _s) {if (c == '(' || c == '{') _p++;else if (c == ')' || c == '}') _p--;else if (c == ',' && _p == 0) { _names.push_back(_tmp); _tmp = "";continue;}_tmp += c;} _names.push_back(_tmp);cerr << "T" << t_<< " Line " << __LINE__ << ": "; debug_out(_names, 0, __VA_ARGS__);}
#else
#define debug(...)
#endif

int p, q, a1, a2, n, m;

struct Matrix{
	static constexpr int msize = 2;
	int c[msize][msize];
	Matrix(){memset(c, 0, sizeof c);}

	Matrix operator*(const Matrix &o) const{
		Matrix r;
		for(int k=0; k<msize; k++){
			for(int i=0; i<msize; i++){
				for(int j=0; j<msize; j++){
					r.c[i][j] = (r.c[i][j] + (ll)c[i][k] * o.c[k][j]) % m;
				}
			}
		}
		return r;
	}

	Matrix operator*=(const Matrix &o) {
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

inline Matrix qpow(Matrix A, Matrix T, int b){
	Matrix R = A;
	while(b){
		if(b & 1) R *= T;
		T *= T;
		b >>= 1;
	}
	return R;
}

inline void qwq_(){
	cin >> p >> q >> a1 >> a2 >> n >> m;
	Matrix x, y;

	x.c[0][0] = a2;
	x.c[0][1] = a1;
	y.c[0][0] = p;
	y.c[1][0] = q;
	y.c[0][1] = 1;

	if(n == 1) cout << a1;
	else if(n == 2) cout << a2;
	else{
		Matrix r = qpow(x, y, n-2);
		cout << r.c[0][0];
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int yyy = 1;
	// cin >> yyy;
	while(yyy--){
		qwq_();
		t_+=1;
	}
	return 0;
}