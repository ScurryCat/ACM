#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef pair<int,int> PII;

const int N = 1e5+9, mod = 998244353;

int idx;
// string h[N];
priority_queue<string,vector<string>,greater<string>> h;

void solve(){
  int n; cin>>n;
  for(int i = 1; i <= n; i++){
    string s;
    cin>>s;
    h.push(s);
  }
  string s;
  cin>>s;
  while(h.top()<s) h.pop();
  while(h.size()){
    bool ok=true;
    string x=h.top();
    for(int i = 0;i<s.size();i++){
      if(x[i]!=s[i]) ok=false;
    }
    if(!ok) break;
    cout<<x<<'\n';
    h.pop();
  }
}

// void solve(){
// 	int n;
//   cin>>n;
//   for(int i=1;i<=n;i++){
//     string s;
//     cin>>s;
//     h[++idx]=s;
//     for(int j=idx;j>1;j>>=1){
//       if(h[j]<h[j>>1]) swap(h[j],h[j>>1]);
//       else break;
//     }
//   }
//   string s;
//   cin>>s;
//   for(int i=1;i<=idx;i++){
//     if(==s) cout<<h[i]<<'\n';
//   }
// }

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int yyy = 1;
	// cin >> yyy;
	while(yyy--) solve();
	return 0;
}