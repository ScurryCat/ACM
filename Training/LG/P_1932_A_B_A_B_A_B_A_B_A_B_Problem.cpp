#include <bits/stdc++.h>
using namespace std;

#define INF 0x7FFFFFFF
#define SUP 0x80000000

typedef long long ll;
typedef vector<int> VI;
typedef vector<vector<int>> VVI;

const int N = 2e4+9;

int A[N],B[N],C[N],D[N];
int la,lb,lc,ld;

void add(int A[],int B[],int C[]){
  lc=max(la,lb);
  memset(C,0,sizeof C);
  for(int i=0;i<lc;i++){
    if(i<la) C[i] += A[i];
    if(i<lb) C[i] += B[i];
    C[i+1] += C[i]/10;
    C[i] %= 10;
  }
  if(C[lc]) lc++;
}

void sub(int A[],int B[],int C[]){
  if()
}

void mul(int A[],int B[],int C[]){

}

void div(int A[],int B[],int C[]){

}

void solve(){
	string a,b;
  cin>>a>>b;
  la=a.size(),lb=b.size();
  for(int i=la-1;~i;i--) A[la-1-i]=a[i]-'0';
  for(int i=lb-1;~i;i--) B[lb-1-i]=b[i]-'0';
  add(A,B,C);for(int i=lc-1;~i;i--) cout<<C[i];cout<<'\n';
  sub(A,B,C);for(int i=lc;~i;i--) cout<<C[i];cout<<'\n';
  mul(A,B,C);for(int i=lc;~i;i--) cout<<C[i];cout<<'\n';
  div(A,B,C);for(int i=lc;~i;i--) cout<<C[i];cout<<'\n';
  for(int i=ld;~i;i--) cout<<D[i];cout<<'\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int T = 1;
	// cin>>T;
	while(T--) solve();
	return 0;
}