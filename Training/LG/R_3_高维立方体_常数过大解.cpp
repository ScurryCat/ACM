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

ll n, p; 

struct Matrix{
	static constexpr int msize = 13;
	int c[msize][msize];
	Matrix(){memset(c, 0, sizeof c);}

	inline Matrix operator+(const Matrix &o) const {
		Matrix r;
		for(int i=0; i<msize; i++){
			for(int j=0; j<msize; j++){
				r.c[i][j] = (c[i][j] + o.c[i][j]) % p;
			}
		}
		return r;
	}

	inline Matrix operator*(const Matrix &o) const {
		Matrix r;
		for(int k=0; k<msize; k++){
			for(int i=0; i<msize; i++){
				for(int j=0; j<msize; j++){
					r.c[i][j] = (r.c[i][j] + 1ll * c[i][k] * o.c[k][j]) % p;
				}
			}
		}
		return r;
	}

	inline Matrix& operator+=(const Matrix &o){
		return *this = *this + o;
	}

	inline Matrix& operator*=(const Matrix &o){
		return *this = *this * o;
	}

	inline Matrix operator!() const{
		Matrix r;
		for(int i=0; i<msize; i++){
			for(int j=0; j<msize; j++){
				r.c[i][j] = c[j][i];
			}
		}
		return r;
	}

	friend ostream& operator<<(ostream &os, const Matrix &o){
		for(int i=0; i<msize; i++){
			for(int j=0; j<msize; j++){
				os << o.c[i][j] << " \n"[j == o.msize - 1];
			}
		}
		return os;
	}

};

inline Matrix qpow(Matrix A, Matrix T, ll b){
	while(b){
		if(b & 1) A *= T;
		T *= T;;
		b >>= 1;
	}
	return A;
}

inline void qwq_(){
	cin >> n >> p;

	if(n == 1){
		cout << 2 % p << '\n';
		return;
	}
	else if(n == 2){
		cout << 4 % p << '\n';
		return;
	}

	Matrix A, T;

	A.c[0][0] = 4;
	A.c[0][1] = 1;
	A.c[0][2] = 4;
	A.c[0][3] = 2;
	A.c[0][4] = 1;
	A.c[0][5] = 1;
	A.c[0][6] = 2;
	A.c[0][7] = 2;
	A.c[0][8] = 1;
	A.c[0][9] = 8;
	A.c[0][10] = 1;
	A.c[0][11] = 2;
	A.c[0][12] = 4;

	T.c[0][0] = 1;
	T.c[2][0] = 1;
	T.c[7][0] = 1;
	T.c[9][0] = 1;

	T.c[1][1] = 1;
	T.c[4][1] = 1;

	T.c[2][2] = 1;
	T.c[4][2] = 1;
	T.c[6][2] = 2;

	T.c[3][3] = 1;
	T.c[5][3] = 1;

	T.c[2][4] = 1;

	T.c[3][5] = 1;

	T.c[2][6] = 1;
	T.c[6][6] = 1;

	T.c[7][7] = 1;
	T.c[8][7] = 1;
	T.c[10][7] = 1;
	T.c[11][7] = 1;

	T.c[7][8] = 1;
	T.c[11][8] = 1;

	T.c[9][9] = 1;
	T.c[10][9] = 1;
	T.c[11][9] = 3;
	T.c[12][9] = 3;

	T.c[9][10] = 1;

	T.c[9][11] = 1;
	T.c[12][11] = 1;

	T.c[9][12] = 1;
	T.c[11][12] = 1;
	T.c[12][12] = 2;

	Matrix R = qpow(A, T, n - 2);

	// cout << A << '\n';
	// cout << R << '\n';

	cout << R.c[0][0] << '\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int yyy = 1;
	cin >> yyy;
	while(yyy--){
		qwq_();
		t_+=1;
	}
	return 0;
}