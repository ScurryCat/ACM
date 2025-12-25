#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
const int N = 1e3+9, M = 2e5+9, mod = 998244353; int t_ = 1;
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

// void fun(int n,vector<int> &a){
// 	int mx=0;
// 	for(int x : a) mx=max(mx,x);
// 	vector<vector<int>> sg(mx+1,vector<int>(mx+1));
// 	vector<int> ap(n+1);
// 	for(int i=2;i<=mx;i++){ // sg[i][j] = mex(mex(sg[0~j][j~0]),mex(sg[i~0][0~i]))
// 		for(int j=2;j<=mx;j++){
// 			fill(ap.begin(),ap.end(),0);
// 			for(int k=1;k<=mx&&k<=i;k++) ap[sg[i-k][j]]=1;
// 			for(int k=1;k<=mx&&k<=j;k++) ap[sg[i][j-k]]=1;
// 			for(int k=1;k<=mx;k++){
// 				if(!ap[k]){
// 					sg[i][j]=k;
// 					break;
// 				}
// 			}
// 		}
// 	}
// 	for(int i=1;i<=mx;i++){
// 		for(int j=1;j<=mx;j++){
// 			printf("sg[%d][%d]=%d\n",i,j,sg[i][j]);
// 		}
// 	}
// }

class solve{
	private:
		int dp[N][N];
	public:
		solve(){memset(dp,-1,sizeof dp);}
		int sg(int a,int b){
			if(~dp[a][b]) return dp[a][b];
			if(a==1&&b==1) return dp[a][b]=0;
			int ap[N];
			memset(ap,0,sizeof ap);
			if(a>1) for(int l=1,r=a-1;l<a;l++,r--) ap[sg(l,r)]=1;
			if(b>1) for(int l=1,r=b-1;l<b;l++,r--) ap[sg(l,r)]=1;
			for(int i=0;i<=N ;i++){
				if(!ap[i]) return dp[a][b]=i;
			}
		}
		void print(int a,int b){
			printf("     ");
			for(int i=1;i<=a;i++) printf("%-2d ",i); printf("\n\n");
			for(int i=1;i<=a;i++){
				printf("%-4d",i);
				for(int j=1;j<=b;j++){
					printf("%2d ",dp[i][j]);
				}
				printf("\n");
			}
		}
};

inline void qwq_(){
	int n; cin>>n;
	ll xo=0;
	for(int i=1;i<=n/2;i++){
		ll a,b; cin>>a>>b;
		ll c= (a-1)|(b-1);
		for(int j=0;j<32;j++){
			if((~c) & (1<<j)){
				xo ^= j;
				break;
			}
		}
	}
	cout<<(xo?"YES\n":"NO\n");
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	// solve x;
	// x.sg(100,100);
	// x.print(18,18);

	int yyy = 1;
	cin >> yyy;
	while(yyy--){
		qwq_();
		t_+=1;
	}
	return 0;
}