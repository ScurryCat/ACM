#include <bits/stdc++.h>
using namespace std;

#define INF 0x7FFFFFFF
#define SUP 0x80000000

typedef long long ll;
typedef vector<int> VI;
typedef vector<vector<int>> VVI;

const int N = 1e5+9;
const int M = 2e5+9;
const int mod = 998244353;

void solve(){
  int n; cin >> n;
  vector<int> a(n), b(n);
  for(auto &x : a) cin >> x;
  for(auto &x : b) cin >> x;

  vector<int> sa = a;
  sort(sa.begin(), sa.end());
  for (int i=0; i<n; i++){
    if(sa[i] > b[i]){
      cout << "-1\n";
      return;
    }
  }

  vector<int> p(n);
  vector<bool> vis(n, 0);
  for(int i=0; i<n; i++){
    for (int j=0; j<n; j++){
      if(!vis[j] && b[j]>=a[i]){
        vis[j] = 1;
        p[i] = j;
        break;
      }
    }
  }

  int cnt = 0;
  for (int i=0; i<n; i++){
    for (int j=i+1; j<n; j++){
      if(p[i] > p[j]) cnt++;
    }
  }

  cout << cnt << '\n';

}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T = 1;
	cin>>T;
	while(T--) solve();
	return 0;
}