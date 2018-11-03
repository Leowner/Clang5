#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define maxn 12000
#define eps 1e-6
int T;
int n;
int m;
int a[maxn];
int b[maxn];
double c[maxn];
int suma, sumb;

double fabs(double x) {
	if (x < 0) return (-x);
	else return x;
}

void qqsort(int left, int right) {
	if (left >= right) return;
	int i = left, j = right;
	double mid = c[(left + right) / 2];
	while (i <= j) {
		while (c[i] > mid && i <= right) i++;
		while (c[j] < mid && j >= left) j--;
		if (i <= j) {
			int t = c[i];
			c[i] = c[j];
			c[j] = t;
			i++;
			j--;
		}
	}
	qqsort(left, j);
	qqsort(i, right);

}

bool gao(double x) {
	for (int i = 1; i <= n; i++) {
		c[i] = (a[i] - x * b[i]);
	}
	qqsort(1, n);
	double csum = 0;
	for (int i = 1; i <= m; i++) {
		csum = csum + c[i];
	}
	if (csum >= 0.0) return 1;
	return 0;
}

int main() {
	scanf("%d", &T);
	for (int tcase = 1; tcase <= T; tcase++) {
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= n; i++) {
			scanf("%d %d", a + i, b + i);
		}
		double left, right = 0;
		for (int i = 1; i <= n; i++) {
			suma += a[i];
			sumb += b[i];
			double x = a[i] * 1.0 / b[i];
			if (x > right) right = x;
		}		
		left = suma / sumb;
		while (fabs(right - left) > eps) {
			double mid = (left + right) / 2;
			if (gao(mid)) {
				left = mid;
			}
			else {
				right = mid;
			}
		}
		printf("Case #%d: %.2lf\n", tcase, left);
	}

	return 0;
}
