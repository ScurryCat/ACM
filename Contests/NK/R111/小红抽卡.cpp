#include <bits/stdc++.h>
using namespace std;

inline int read(){
	int r = 0, w = 1; char ch = getchar();
	while(ch < '0' || ch > '9') { if(ch == '-') w *= -1; ch = getchar();}
	while('0' <= ch && ch <= '9') {r = (r << 1) + (r << 3) + ch - 48; ch = getchar();}
	return r * w;
}

typedef long long ll;
typedef vector<int> VI;
typedef pair<int,int> PII;

const int N = 2e5+9;
const int mod = 998244353;

ll n,k,x,idx;
ll a[N];

void solve(){
  cin>>n>>k>>x;
  k %= x;
  for(ll i=1;i<=n;i++) cin>>a[i];
  for(ll i=n-k+1;i<=n;i++){
    cout<<a[i]<<' ';
  }
  for(ll i=1;i<=n-k;i++){
    cout<<a[i]<<' ';
  }
}

// void solve() {
//   ll n, k, x;
//   cin >> n >> k >> x;
//   k %= x;
//   vector<int> a(n);
//   for (int i = 0; i < n; ++i) cin >> a[i];
//   for (int i = 0; i < x; ++i) cout << a[(i - k + x) % x] << " ";
//   for (int i = x; i < n; ++i) cout << a[i] << " ";
//   cout << "\n";
// }

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int yyy = 1;
	// yyy = read();
	while(yyy--) solve();
	return 0;
}