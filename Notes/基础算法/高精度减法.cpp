#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+9;
int A[N],B[N],C[N];
int la,lb,lc;

bool cmp(int A[],int B[]){
  if(la!=lb) return la>lb;
  for(int i=la-1;~i;i--){
    if(A[i]!=B[i]) return A[i]>B[i];
  }
  return true;      // 避免为-0
}

void sub(int A[],int B[],int C[]){
  for(int i=0;i<lc;i++){
    if(A[i]<B[i]) A[i+1]--,A[i]+=10;    // 借位
    C[i]=A[i]-B[i];
  }
  while(lc&&C[lc]==0) lc--;             // 消除前导零
}

int main(){
  string a,b;
  cin>>a>>b;
  la=a.size(),lb=b.size(),lc=max(la,lb);
  for(int i=la-1;~i;i--) A[la-i-1]=a[i]-'0';
  for(int i=lb-1;~i;i--) B[lb-i-1]=b[i]-'0';
  if(!cmp(A,B)) swap(A,B),cout<<'-';   // 若A<B
  sub(A,B,C);
  for(int i=lc;~i;i--) cout<<C[i];
  return 0;
}