#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

const int N = 1e5+9, mod = 998244353;

void qwq_(){
	string s; cin>>s;
  int n=s.size();
  vector<int> f(n+1);
  vector<int> r,e;
  for(int i=1;i<=n;i++){
    if(s[i-1]=='r') r.push_back(i-1);
    if(s[i-1]=='e') e.push_back(i-1);
    if(s[i-1]=='d') r.clear(), e.clear();
    if(r.size() && e.size()) f[i]=f[i-1]+1;
    else f[i]=f[i-1];
  }
  cout<<f[n];
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int yyy = 1;
	// cin >> yyy;
	while(yyy--) qwq_();
	return 0;
}