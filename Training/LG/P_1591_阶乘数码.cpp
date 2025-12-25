#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

const int N = 1e5+9, mod = 998244353;

int n,a;

void mul(vector<int> &A,int b){
  vector<int> r(A.size()+10);
  for(int i=0;i<A.size();i++){
    r[i] += A[i] * b;
    r[i+1] += r[i] / 10;
    r[i] %= 10;
  }
  while(r.back()==0) r.pop_back();
  while(r.back()>=10) r.push_back(r.back()/10),r[r.size()-2]%=10;
  A=r;
}

void qwq_(){
	cin>>n>>a;
  vector<int> A;
  A.push_back(1);
  for(int i=2;i<=n;i++){
    mul(A,i);
  }
  // for(int i=A.size()-1;~i;i--) cout<<A[i];cout<<'\n';
  cout<<count(A.begin(),A.end(),a)<<'\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int yyy = 1;
	cin >> yyy;
	while(yyy--) qwq_();
	return 0;
}