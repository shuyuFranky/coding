#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 200010;

int N;
long long ans = 0;
int data[maxn], _data[maxn];
int label[maxn];

void solve(int l, int r) {
	if (l == r) return;
	solve(l, (l + r) / 2);
	solve((l + r) / 2 + 1, r);
	int index1 = l, mid = (l + r) / 2;
	int index2 = mid + 1, cur = l, right = mid;
	long long num = 0;
	memset(label, 0, sizeof(int) * (r - l + 1));
	while (index1 <= mid && index2 <= r) {
		if (data[index1] <= data[index2]) {
			_data[cur ++] = data[index1 ++];
			while (right + 1 < index2 && data[right + 1] * 2 < _data[cur - 1]) {
				right ++;
				num += label[right];
			} 
			ans += (right - mid);
		}
		else {
			_data[cur ++] = data[index2 ++];
			label[cur - 1] = 1;
		}
	}
	while (index1 <= mid) {
		_data[cur ++] = data[index1 ++];
		while (right + 1 < index2 && data[right + 1] * 2 < _data[cur - 1]) {
			right ++;
			num += label[right];
		} 
		ans += (right - mid);
	}
	while (index2 <= r) {
		_data[cur ++] = data[index2 ++];
		label[cur - 1] = 1;
	}
	memcpy(data + l, _data + l, sizeof(int) * (r - l + 1));
}


int main() {
	while (scanf("%d\n", &N) != EOF) {
		if (N == 0) break;
		for (int i = 1; i <= N; i++)
			scanf("%d", &data[i]);
		ans = 0;
		solve(1, N);
		printf("%lld\n", ans);
	} 
	return 0;
}