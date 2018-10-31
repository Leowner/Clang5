//#include <stdio.h>
//#include <string.h>
//#define maxn 150000
//int n;
//int vn;
//int a[maxn];
//int ans;
//
//void
//qqsort(int left, int right)
//{
//	if (left >= right)
//		return;
//	int i = left;
//	int j = right;
//	int x = a[(i + j) >> 1];
//	while (i <= j) {
//		while (a[i] < x && i <= right)
//			i++;
//		while (a[j] > x && j >= left)
//			j--;
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
//int
//main()
//{
//	while (scanf("%d", &n) == 1) {
//		scanf("%d", &vn);
//		for (int i = 1; i <= n; i++) {
//			scanf("%d", a + i);
//		}
//		qqsort(1, n);
//		/*for (int i = 1; i <= n; i++) {
//			printf("%d ", a[i]);
//	}*/
//		ans = 0;
//		int j = 1;
//		for (int i = n; i >= 1; i--) {
//			if (i == j) {
//				ans++;
//				break;
//			}
//			else if (i < j) {
//				break;
//			}
//			else {
//				if (a[i] + a[j] <= vn) {
//					j++;
//					ans++;
//				} 
//				else {
//					ans++;
//				}
//			}
//		}
//		printf("%d\n", ans);
//	}
//
//	return 0;
//}