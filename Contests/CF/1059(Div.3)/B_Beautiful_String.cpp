#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef pair<int,int> PII;

const int N = 1e5+9, mod = 998244353;

void solve(){
	int n;
  string s;
  cin>>n>>s;
  int pos=0;
  bool ok=true;
  while(pos<s.size()-1&&s[pos]<=s[pos+1]) pos++;
  if(pos==s.size()-1) if(s[pos+1]>=s[pos]) pos++;
  for(int i=0,j=s.size()-1;i<j;i++,j--) if(s[i]!=s[j]) ok=false;
  if(ok){
    cout<<"0\n\n";
    return;
  }
  if(pos==n-1){
    cout<<n<<'\n';
    for(int i=1;i<=n;i++) cout<<i<<' ';
    cout<<'\n';
    return;
  }
  if(pos==n-2){
    cout<<n-1<<'\n';
    for(int i=1;i<n;i++) cout<<i<<' ';
    cout<<'\n';
    return;
  }
  for(int i=0;i<s.size();i++){
    ok=true;
    string ss=s;
    char c=s[i];
    VI op;
    for(int j=i;j<s.size();j++){
      if(c<=s[j]){
        c=s[j];
        ss[j]='2';
        op.push_back(j+1);
      }
      else break;
      ok=true;
      for(int i=0,j=ss.size()-1;i<=j;i++,j--){
        while(ss[i]=='2'&&i<j) i++;
        while(ss[j]=='2'&&i<j) j--;
        if(i==j) break;
        if(ss[i]!=ss[j]) ok=false;
      }
      if(ok){
        cout<<op.size()<<'\n';
        for(int i=0;i<op.size();i++) cout<<op[i]<<' ';
        cout<<'\n';
        return;
      }
    }
  }
  cout<<"-1\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int yyy = 1;
	cin >> yyy;
	while(yyy--) solve();
	return 0;
}