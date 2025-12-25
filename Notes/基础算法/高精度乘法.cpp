#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+9;
int la,lb,lc;
int A[N],B[N],C[N];

void mul(int A[],int B[],int C[]){
  for(int i=0;i<la;i++){
    for(int j=0;j<lb;j++){
      C[i+j] += A[i] * B[j];      // 累加乘积
      C[i+j+1] += C[i+j]/10;      // 进位
      C[i+j] %= 10;               // 存余
    }
  }
  while(lc&&C[lc]==0) lc--;
}

int main(){
  string a,b;
  cin>>a>>b;
  la=a.size(),lb=b.size(),lc=la+lb;   //
  for(int i=la-1;~i;i--) A[la-i-1]=a[i]-'0';
  for(int i=lb-1;~i;i--) B[lb-i-1]=b[i]-'0';
  mul(A,B,C);
  for(int i=lc;~i;i--) cout<<C[i];
  return 0;
}