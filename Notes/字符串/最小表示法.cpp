#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+9;
int n;
char s[N];

// 最小表示法寻找字符串的循环同构串中字典序最小的一个
// 时间复杂度O(n)
int get_min(char *p){
  for(int i=1;i<=n;i++) p[n+i]=p[i];    // 复制一倍
  int i=1,j=2,k=0;
  while(i<=n&&j<=n){                    // 最多移动2n的长度
    for(k=0;k<n&&p[i+k]==p[j+k];k++);   // 每次向后比较k的长度
    p[i+k]>s[j+k] ? i=i+k+1 : j=j+k+1;  // 大串后移
    if(i==j) j++;
  }
  return min(i,j);
}

int main(){
  cin>>n;
  for(int i=1;i<=n;i++) cin>>s[i];
  return 0;
}