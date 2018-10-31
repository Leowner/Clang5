//#include <stdio.h>
//#include <string.h>
//#define maxn 150000
//
//
//int n;
//int a[maxn];
//int b[maxn];
//
//void merge_sort(int left, int right) {
//	if (left == right) return;
//	int mid = (left + right) >> 1;
//	merge_sort(left, mid);
//	merge_sort(mid + 1, right);
//	int front1 = left, front2 = mid + 1;
//	int fb = left;
//	while (front1 <= mid && front2 <= right) {
//		if (a[front1] < a[front2]) {
//			b[fb++] = a[front1++];
//		} else if (a[front1] >= a[front2]) {
//			b[fb++] = a[front2++];
//		}
//	}
//	while (front1 <= mid) {
//		b[fb++] = a[front1++];
//	}
//	while (front2 <= right) {
//		b[fb++] = a[front2++];
//	}
//	for (int i = left; i <= right; i++) a[i] = b[i];
//}
//int main() {
//	scanf("%d", &n);
//	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
//	merge_sort(1, n);
//	for (int i = 1; i <= n; i++) printf("%d ", a[i]);
//	return 0;
//}