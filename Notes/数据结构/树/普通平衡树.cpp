#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+9;

struct node{
  int s[2];     // 左右儿子
  int p;        // 父亲
  int v;        // 节点权值
  int cnt;      // 权值出现次数
  int size;     // 子树大小
  void init(int pp, int vv){  // 插入时的初始化函数
    p = pp; v = vv;
    cnt = size = 1;
  }
}tr[N];
int root; // 根结点编号
int idx;  // 节点个数

void pushup(int x){
  tr[x].size = tr[tr[x].s[0]].size // 左子树大小
             + tr[tr[x].s[1]].size // 右子树大小
             + tr[x].cnt; // 本节点大小
}

void rotate(int x){ // 将x旋转到上一层
  int y = tr[x].p, z = tr[y].p;
  int k = tr[y].s[1] == x;  // 判断x是y的左儿子还是右儿子
  tr[y].s[k] = tr[x].s[k^1];  // 修改y的儿子
  tr[tr[x].s[k^1]].p = y;     // 修改x儿子的父亲
  tr[x].s[k^1] = y; // 修改x的儿子
  tr[y].p = x;  // 修改y的父亲
  tr[z].s[tr[z].s[1] == y] = x; // 修改z的儿子
  tr[x].p = z;  // 修改x的父亲
  pushup(y); pushup(x);
}

void splay(int x, int k){ // 将x节点转到k下面
  while(tr[x].p != k){  // x转为k的儿子时结束
    int y = tr[x].p, z = tr[y].p;
    if(z != k){ // y不是根
      (tr[y].s[0]==x) ^ (tr[z].s[0]==y) // 是否为折线形？
          ? rotate(x) : rotate(y);
    }
    rotate(x);
  }
  if(k == 0) root = x;
}

void find(int v){ // 找到权值为v的节点，并将其转到根节点，若该点不存在，则将距离其最近的点转到根节点
  int x = root;
  while(tr[x].v != v && tr[x].s[v>tr[x].v]){  // 找到权值为v的节点，或没有更近的节点时跳出
    x = tr[x].s[v>tr[x].v];
  }
  splay(x, 0);
}

int get_pre(int v){ // 求v的前驱，返回其节点编号
  find(v);
  int x = root;
  if(tr[x].v < v) return x;
  x = tr[x].s[0];
  while(tr[x].s[1]) x = tr[x].s[1];
  splay(x, 0);
  return x;
}

int get_suc(int v){ // 求v的后继，返回其节点编号
  find(v);
  int x = root;
  if(tr[x].v > v) return x;
  x = tr[x].s[1];
  while(tr[x].s[0]) x = tr[x].s[0];
  splay(x, 0);
  return x;  
}

void del(int v){  //删除一个权值为v的节点
  int pre = get_pre(v);
  int suc = get_suc(v);
  splay(pre, 0); splay(suc, pre);
  int del = tr[suc].s[0];
  if(tr[del].cnt > 1){
    tr[del].cnt--;
    splay(del, 0);  // 更新树的尺寸
  }
  else{
    tr[suc].s[0] = 0;
    splay(suc, 0);
  }
}

int get_rank(int v){  // 排名
  // find(v);
  // return tr[tr[root].s[0]].size;  // 考虑在构建splay树时插入了正负无穷，这里无需+1
  insert(v);
  int r = tr[tr[root].s[0]].size;
  del(v);
  return r;
}

int get_val(int k){ // 查询排名为k的数值
  int x = root;
  while(1){
    int y = tr[x].s[0];
    if(tr[y].size + tr[x].cnt < k){
      k -= tr[y].size + tr[x].cnt;
      x = tr[x].s[1];
    }
    else{
      if(tr[y].size >= k) x = tr[x].s[0];
      else break;
    }
  }
  splay(x, 0);
  return tr[x].v;
}

void insert(int v){
  int x = root, p=0;
  while(x && tr[x].v != v){
    p = x;
    x = tr[x].s[v>tr[x].v];
  }
  if(x) tr[x].cnt++;
  else{
    x = ++idx;
    tr[p].s[v>tr[p].v] = x;
    tr[x].init(p, v);
  }
  splay(x, 0);
}

int main(){
  int n; cin >> n;
	while(n--){
		int opt, x;
		cin >> opt >> x;
		switch(opt){
			case 1: insert(x); break;
			case 2: del(x); break;
			case 3: cout << get_rank(x) << '\n'; break;
			case 4: cout << get_val(x+1) << '\n'; break;
			case 5: cout << tr[get_pre(x)].v << '\n'; break;
			case 6: cout << tr[get_suc(x)].v << '\n'; break;
		}
	}
  return 0;
}