#include <stdio.h>
#define maxn 300000


int T;
int n;
int a[maxn], b[maxn];
long long ans = 0;

void merge_sort(int left, int right) {
	if (left >= right) return;
	int mid = (left + right) >> 1;
	merge_sort(left, mid);
	merge_sort(mid + 1, right);
	int t1 = left, t2 = mid + 1;
	int t3 = left;
	while (t1 <= mid && t2 <= right) {
		if (a[t1] < a[t2]) {
			b[t3] = a[t1];
			t1++;
			t3++;
		}
		else if (a[t1] >= a[t2]) {
			b[t3] = a[t2];
			ans += (mid - t1 + 1);
			t2++;
			t3++;
		}
	}
	while (t1 <= mid) {
		b[t3] = a[t1];
		t1++;
		t3++;
	}
	while (t2 <= right) {
		b[t3] = a[t2];
		ans += (mid - t1 + 1);
		t2++;
		t3++;
	}
	for (int i = left; i <= right; i++) {
		a[i] = b[i];
	}
}
int main() {
	scanf("%d", &T);
	for (int tcase = 1; tcase <= T; tcase++) {
		scanf("%d", &n);
		ans = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
		}
		merge_sort(1, n);
		printf("Case #%d: %lld\n",tcase, ans);
	}

	return 0;
}