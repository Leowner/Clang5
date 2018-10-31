#include <stdio.h>
#include <string.h>
#define maxn 150000
#define maxmam 1e8
#define inf 2000000000
int T;
int n, m;
int x[maxn];

int gaoshi(int maxm) {
	int tcur = 0;
	int cur = 0;
	x[n + 1] = inf;
	for (int i = 1; i <= n; i++) {
		if (x[i] - cur <= maxm && x[i + 1] - cur > maxm) {
			cur = x[i];
			tcur++;
		}
	}
	if (cur != x[n]) return 0;
	if (tcur > m) return 0;
	return 1;
}

int myabs(int x) {
	if (x < 0) return -x;
	return x;
}

int main() {
	scanf("%d", &T);
	for (int ptime = 1; ptime <= T; ptime++) {
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= n; i++) {
			scanf("%d", x + i);
		}
		int right = 20;
		int left = 0;
		while (myabs(right - left) > 1) {
			int mid = (left + right) >> 1;
			if (gaoshi(mid)) {
				right = mid;
			} else {
				left = mid;
			}
		}
		int ansp = 0;
		if (left < right) {
			if (gaoshi(left)) {
				ansp = left;
			}
			else {
				ansp = right;
			}
		}
		else {
			if (gaoshi(right)) {
				ansp = right;
			}
			else {
				ansp = left;
			}
		}
		printf("Case #%d: %d\n", ptime, ansp);
	}
	return 0;
}