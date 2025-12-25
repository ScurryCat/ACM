#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef pair<int,int> PII;

const int N = 1e5+9, mod = 998244353;

int n,m,mx;
vector<int> num;

VI a;

void mul(VI &a, int b, VI &c){
  VI r(a.size()+15,0);
  int i;
  for(i=0;i<a.size();i++){
    r[i] += a[i]*b;
    r[i+1] += r[i]/10;
    r[i] %= 10;
  }
  while(r[i]>=10){
    r[i+1] = r[i]/10;
    r[i] %= 10;
    i++;
  }
  while(r.size()&&r.back()==0) r.pop_back();
  c=r;
}

void qwq_(){
	cin>>n;
  m=0,mx=0;
  for(int i=2;m<n;i++){
    m+=i;
    mx=i;
  }
  m -= n;
  // cout<<m<<'\n';
  for(int i=2;i<=mx;i++) if(i!=m) num.push_back(i);
  if(m==1){
    for(int i=0;i<num.size();i++) num[i]=num[i+1];
    num.pop_back();
    num.back()++;
  }

  a.push_back(1);
  for(auto x : num){
    cout<<x<<' ';
    mul(a,x,a);
  }
  cout<<'\n';
  for(int i=a.size()-1;~i;i--) cout<<a[i];
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int yyy = 1;
	// cin >> yyy;
	while(yyy--) qwq_();
	return 0;
}