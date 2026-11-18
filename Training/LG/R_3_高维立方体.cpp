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
	static constexpr int msize = 2;
	ll c[msize][msize];
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
				if(!c[i][k]) continue;
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

inline Matrix mul(Matrix &A, Matrix &B){
	Matrix R;
	for(int i=0; i<A.msize; i++){
		for(int j=0; j<A.msize; j++){
			R.c[0][j] += A.c[0][i] * B.c[i][j];
		}
	}
	for(int i=0; i<A.msize; i++) R.c[0][i] %= p;
	return R;
}


inline Matrix qpow(ll b){
	Matrix A, T;

	A.c[0][0] = 1;
	A.c[0][1] = 1;

	T.c[0][0] = 1;
	T.c[1][0] = 1;

	T.c[0][1] = 1;

	while(b){
		if(b & 1) A *= T;
		T *= T;
		b >>= 1;
	}

	return A;
}

inline ll read(){
	ll r = 0, s = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){
		if(ch == '-') s = -s;
		ch = getchar();
	}
	while('0' <= ch && ch <= '9'){
		r = (r << 1) + (r << 3) + ch - '0';
		ch = getchar();
	}
	return r * s;
}

inline void qwq_(){
	n = read(); p = read();
	if(n == 1) printf("%lld\n", 2 % p);
	else if(n == 2) printf("%lld\n", 4 % p);
	else{
		Matrix R = qpow(n - 2 + 1);
		printf("%lld\n", ((R.c[0][1] * R.c[0][0] % p) * (R.c[0][1] + 1)) % p);
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int yyy = read();
	while(yyy--){
		qwq_();
		t_+=1;
	}
	return 0;
}