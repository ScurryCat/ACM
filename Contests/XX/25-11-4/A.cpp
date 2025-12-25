#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;  

const int N = 1e5+9, mod = 998244353;

int n,ans,f;

void qwq_(){
	cin>>n;
  f=1;
  for(int i=1;i<=n;i++){
    ans += f*i;
    f*=-1;
  }
  cout<<ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int yyy = 1;
	// cin >> yyy;
	while(yyy--) qwq_();
	return 0;
}