//#include <stdio.h>
//#define maxn 150000
//
//int a[maxn];
//int n;
//
//void qqsort(int left, int right) {
//	if (left >= right) return;
//	int i = left, j = right;
//	int x = a[(left + right) >> 1];
//	while (i <= j) {
//		while (a[i] < x && i <= right) i++;
//		while (a[j] > x && j >= left) j--;
//		if (i <= j) {
//			int t = a[i];
//			a[i] = a[j];
//			a[j] = t;
//			i++;
//			j--;
//		}
//	}
//	qqsort(left, j);
//	qqsort(i, right);
//}
//
//int main() {
//	scanf("%d", &n);
//	for (int i = 1; i <= n; i++) {
//		scanf("%d", a + i);
//	}
//	qqsort(1, n);
//	for (int i = 1; i <= n; i++) {
//		printf("%d ", a[i]);
//	}
//
//	return 0;
//}
//
