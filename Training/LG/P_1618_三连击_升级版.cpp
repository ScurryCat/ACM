#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

const int N = 1e5+9, mod = 998244353;

bool flag;
int a,b,c;
int vis[11];

bool check(){
  bool r=1;
  for(int i=1;i<=9;i++){
    r &= vis[i];
  }
  flag |= r;
  return r;
}

void add(int n){
  while(n){
    vis[n%10]=1;
    n/=10;
  }
}

void remove(int n){
  while(n){
    vis[n%10]=0;
    n/=10;
  }
}

void qwq_(){
	cin>>a>>b>>c;
  if(a==0||b==0||c==0){
    cout<<"No!!!";
    return;
  }
  if(a==b||b==c){
    cout<<"No!!!";
    return;
  }
  int i,j,k;
  for(i=123;i<=999;i++){
    j=i*b/a;
    k=j*c/b;
    add(i);add(j);add(k);
    if(k>999){
      if(!flag) cout<<"No!!!";
      return;
    }
    if(check()) cout<<i<<' '<<j<<' '<<k<<'\n';
    remove(i);remove(j);remove(k);
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