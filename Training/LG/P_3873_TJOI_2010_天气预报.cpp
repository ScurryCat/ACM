#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
const int N = 1e5+9, M = 2e5+9, mod = 4147; int t_ = 1;
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

int n, m;

struct Matrix{
	int c[100][100];
	
	Matrix(){
		memset(c, 0, sizeof c);
	}

	inline Matrix operator*(const Matrix &o) const{
		Matrix r;
		for(int k=0; k<n; k++){
			for(int i=0; i<n; i++){
				for(int j=0; j<n; j++){
					r.c[i][j] = (r.c[i][j] + c[i][k] * o.c[k][j]) % mod;
				}
			}
		}
		return r;
	}

	inline Matrix operator*=(const Matrix &o){
		return *this = *this * o;
	}

	friend ostream& operator<<(ostream& os, const Matrix& m) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        os << m.c[i][j] << " \n"[j == n - 1];
      }
    }
    return os;
  }

	static inline Matrix qpow(Matrix A, Matrix T, int b){
		Matrix R = A;
		while(b){
			if(b & 1) R *= T;
			T *= T;
			b >>= 1;
		}
		return R;
	}
};


inline void qwq_(){
	cin >> n >> m;
	Matrix x, y;
	for(int i=0; i<n; i++) cin >> x.c[0][i];
	for(int i=0; i<n; i++) cin >> y.c[i][0];
	for(int i=1; i<n; i++) y.c[i-1][i] = 1;

	if(m <= n) cout << x.c[0][m-1];
	else{
		Matrix r = Matrix::qpow(x, y, m - n);

		// cout << x << '\n';
		// cout << y << '\n';
		// cout << r << '\n';

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