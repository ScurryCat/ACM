#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

const int N = 1e5+9, mod = 998244353;

void qwq_(){
	int n;
  cin>>n;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      if(i==j) cout<<'\\';
      else cout<<' ';
    }
    cout<<'|';
    for(int j=n;j>=1;j--){
      if(i==j) cout<<'/';
      else cout<<' ';
    }
    cout<<'\n';
  }
  for(int i=1;i<=n;i++) cout<<'-';
  cout<<'O';
  for(int i=1;i<=n;i++) cout<<'-';
  cout<<'\n';
  for(int i=1;i<=n;i++){
    for(int j=n;j>=1;j--){
      if(i==j) cout<<'/';
      else cout<<' ';
    }
    cout<<'|';
    for(int j=1;j<=n;j++){
      if(i==j) cout<<'\\';
      else cout<<' ';
    }
    cout<<'\n';
  }
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int yyy = 1;
	// cin >> yyy;
	while(yyy--) qwq_();
	return 0;
}