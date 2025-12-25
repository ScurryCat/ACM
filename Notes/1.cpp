#include <bits/stdc++.h>
using namespace std;

int main() {
	srand(time(0));
	unordered_map<int, int> cnt;
	int test_time = 1e7, target = 10000, ans = 0;
	for (int i = 1; i <= test_time; ++i)
		for (int x = 1, t = 0; x <= target; x *= rand() % 6 + 1, ++t)
			if (x == target) cnt[t]++;
	for (auto x : cnt) {
		if (cnt[ans] < x.second) ans = x.first;
		// cout << x.first << ' ' << x.second << '\n';
	}
	cout << "投" << ans << "次概率最高,概率为:" << 100.0 * cnt[ans] / test_time << "%\n";
	return 0;
}