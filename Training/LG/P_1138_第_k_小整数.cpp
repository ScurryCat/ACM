#include <bits/stdc++.h>
using namespace std;

const int N = 3e4+9;

int n, k, cnt;
int vis[N], a[N];

bool cmp(int x, int y){ // 比较函数
	return x<y; // 按照升序排序
}

int main(){
	scanf("%d %d",&n, &k);
	for(int i=1; i<=n; i++){
		int x;
		scanf("%d", &x);
		vis[x]++; // x的出现次数+1
		if(vis[x]==1){ // 当x第一次出现时
			a[++cnt] = x; // 数组大小+1，把x放到数组中最后一位
		}
	}
	if(cnt < k) printf("NO RESULT"); // 如果经过去重后，剩下的数不够k个，则无解
	else{
		// 用sort函数排序，有三个参数，分别为：首位元素地址，末尾元素地址，比较函数
		sort(a+1, a+cnt+1, cmp); // sort内置函数，按照升序排序
		printf("%d", a[k]); // 第k小数即是a[k]
	}
	return 0;
}