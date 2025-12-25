#include <bits/stdc++.h>
using namespace std;

const int N = 109;
int n,m,k;
int A[N][N],B[N][N],C[N][N];

int main(){
  cin>>n>>m>>k;
  for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
      cin>>A[i][j];
  for(int i=1;i<=m;i++)
    for(int j=1;j<=k;j++)
      cin>>B[i][j];
  for(int i=1;i<=n;i++)
    for(int w=1;w<=m;w++)
      for(int j=1;j<=k;j++)
        C[i][j]=(C[i][j]+A[i][w]*B[w][j]);
  for(int i=1;i<=n;i++){
    for(int j=1;j<=k;j++){
      cout<<C[i][j]<<' ';
    }
    cout<<'\n';
  }
  return 0;
}