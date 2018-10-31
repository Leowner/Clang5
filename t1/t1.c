#include <stdio.h>
#define maxn 150000

int a[maxn];
int n;

void qqsort(int left, int right) {
	if (left >= right) return;
	int i = left, j = right;
	int mid = (left + right) >> 1;
	while (i < j) {
		while (a[i] < a[mid] && i <= right) i++;
		while (a[j] > a[mid] && j >= left) j--;
		if (i < j) {
			int t = a[i];
			a[i] = a[j];
			a[j] = t;
			i++;
			j--;
		}
	}
	qqsort(left, mid);
	qqsort(mid + 1, right);
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
	}
	qqsort(1, n);
	for (int i = 1; i <= n; i++) {
		printf("%d ", a[i]);
	}

	return 0;
}

