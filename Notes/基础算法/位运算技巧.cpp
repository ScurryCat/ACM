#include <bits/stdc++.h>
using namespace std;

int mian(){
  int x=5,k=1,ans;
  // 去掉最后一位
  ans=x>>1;

  // 在最后添加0
  ans=x<<1;

  // 在最后添加1
  ans=(x<<1)|1;

  // 右数第k位变成1
  ans=x|(1<<(k-1));

  // 右数第k位变成0
  ans=x&~(1<<(k-1));
  
  // 获取右数第k位
  ans=(x>>(k-1))&1;
  
  // 截取最后k位
  ans=x&((1<<k)-1);
  
  // 把右边连续第1变成0
  ans=x&(x+1);
  
  // 把右边起第一个0变成1
  ans=x|(x+1);
  
  // 把右边连续的0变成1
  ans=x|(x-1);
  
  // 把右边起第一个1变成0
  ans=x&(x-1);
  
  // 取右边连续的1
  ans=(x^(x+1))>>1;

  return 0;
}