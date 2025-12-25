#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

const ll N = 1e5+9, mod = 1777777777;

ll n, xo, ans = 1;

void qwq_(){
	cin >> n;
  vector<ll> x(n+1), p(n+1);
  for(int i=1; i<=n; i++){
    cin >> x[i]; 
    p[i] = (x[i] ^ p[i-1]) % mod;
  }
  if(n <= 8192){
    for(int i=1; i<=n; i++){
      for(int j=i; j<=n; j++){
        xo = p[i-1] ^ p[j];
        ans = (ans * xo) % mod;
      }
    }
    cout << ans;
  }
  else cout << "0\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int yyy = 1;
	// cin >> yyy;
	while(yyy--) qwq_();
	return 0;
}