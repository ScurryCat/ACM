#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> VI;

const int N = 2e6+9;
int p;
int la;
int A[N],B[N];

void mul(int A[],int B[],int C[]){
  int D[600]={0};
  for(int i=0;i<500;i++){
    for(int j=0;i+j<500;j++){
      D[i+j] += A[i] * B[j];
      D[i+j+1] += D[i+j] / 10;
      D[i+j] %= 10;
    }
  }
  memcpy(C,D,sizeof D);
}

void sub(int A[]){
  int i=0;
  while(i<500&&A[i]==0) i++;
  A[i]-=1;
  while(i<500&&A[i]==0) A[i]=9,i--;
}

int main(){
  cin>>p;
  la=p*log10(2)+1;
  cout<<la<<'\n';
  memset(A,0,sizeof A);
  memset(B,0,sizeof B);
  A[0]=1;
  B[0]=2;
  while(p){
    if(p&1) mul(A,B,A);
    mul(B,B,B);
    p>>=1;
  }
  sub(A);
  // 计算la，log10(a^p-1)=log10(2^p)=p*log10(2)

  for(int i=499,cnt=0;~i;i--){
    cout<<A[i];
    if((++cnt)%50==0) cout<<'\n';
  }
  return 0;
}