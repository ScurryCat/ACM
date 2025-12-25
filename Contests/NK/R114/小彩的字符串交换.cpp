#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef pair<int,int> PII;

const int N = 1e5+9, mod = 998244353;

void solve(){
	int n;
  int cnt[4]={0};
  bool ok=false;
  cin>>n;
  string s;
  s.resize(n);
  for(int i=0;i<n;i++){
    cin>>s[i];
    cnt[s[i]-'0']++;
    if(i>1){
      if(s[i-1]!=s[i-2]&&s[i]!=s[i-1]){
        ok=true;
      }
    }
  }
  if(cnt[1]==0||cnt[2]==0||cnt[3]==0){
    cout<<"-1\n";
  }
  else{
    if(ok){
      cout<<"0\n";
    }
    else{
      cout<<"1\n";
    }
  }
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int yyy = 1;
	cin >> yyy;
	while(yyy--) solve();
	return 0;
}