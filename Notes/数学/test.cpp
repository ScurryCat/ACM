#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; cin>>n;
  // 验证恒等式：x+y==x^y+2*(x&y)
  for(int i=1;i<=n;i++){
    int a,b;
    // cin>>a>>b;
    a=i-1,b=i+1;
    printf("%d=%d+%d\n",a+b,a^b,(a&b)<<1);
  }
  return 0;
}