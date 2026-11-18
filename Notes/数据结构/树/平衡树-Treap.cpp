#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+9;

struct node{
  int l, r;
  int val;
  int key;
  int size;
}tr[N];
int n, root, idx;

inline int newnode(int v){
  tr[++idx].val = v;
  tr[idx].key = rand();
  tr[idx].size = 1;
  return idx;
}

inline void pushup(int x){
  tr[x].size = tr[tr[x].l].size + tr[tr[x].r].size + 1;
}



int main(){
  srand(time(0));

  return 0;
}