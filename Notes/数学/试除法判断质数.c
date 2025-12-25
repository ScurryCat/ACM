#include <stdio.h>

int check(int n){ // 判断质数函数
  for(int i=2;i*i<=n;i++){ // 依次试除[2,根号n]之间的每一个整数
    if(n%i==0){ // 如果n%i==0 ，那么i是n的因数
      return 0; // 返回0
    }
  }
  return 1; // 如果执行完了前面的所有循环，表示[2,根号n]之间没有n的因数，所以n是质数，返回1
}

int main()
{
  int n;
  scanf("%d",&n);
  if(check(n)){
    printf("%d是质数",n);
  }
  else{
    printf("%d不是质数",n);
  }
  return 0;
}