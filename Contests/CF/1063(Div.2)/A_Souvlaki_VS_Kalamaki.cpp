#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

const int N = 1e5+9, mod = 998244353;

void qwq_(){
	int n; cin>>n;
  int cnt=0;
  vector<int> a(n+1);
  for(int i=1;i<=n;i++){
    cin>>a[i];
  }
  for(int i=1;i<=n;i++){
    int cnt2=0;
    for (int j=1;j<=n;j++){
      if(a[j]==a[i]) cnt2++;
    }
    cnt=max(cnt,cnt2);
  }
  if(cnt >= ((n+1)>>1)) cout<<"YES\n";
  else cout<<"NO\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int yyy = 1;
	cin >> yyy;
	while(yyy--) qwq_();
	return 0;
}