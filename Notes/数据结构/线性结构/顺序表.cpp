#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+9;

typedef struct{
  int *elem;
  int length;
}SqList;

bool InitList_Sq(SqList &L){
  L.elem=new int[N];
}

void Input_Sq(SqList &L){
  int i=0;
  L.length=0;
  cout<<"输入数据：";
  cin>>L.elem[L.length];
  while(L.elem[L.length]){
    cin>>L.elem[++L.length];
  }
  cout<<"输入完毕\n";
}

bool ListDelete(SqList &L,int i){
  
}

int main(){
  SqList L;
  int choose;
  // 1建立 2输入 3取值 4查找 5插入 6删除 7输出 0退出
  cin>>choose;
  while(choose){
    switch(choose){
    case 1:break;
    case 2:break;
    case 3:break;
    case 4:break;
    case 5:break;
    case 6:break;
    case 7:break;
    }
  }
}