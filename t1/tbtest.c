#include <stdio.h>
#include <string.h>
// 使用堆维护，从后往前，对于所有可以放进去的，选择价值最大的
int tim[5000];
int val[5000];
int n;
int pri_que[5000];
int qfront, qend;
int tot;
void pri_up(int num);
void pri_down(int num);
int mymax(int a, int b);

void qqsort(int left, int right) {
	if (left >= right)
		return;
	int i = left;
	int j = right;
	int x = tim[(i + j) >> 1];
	while (i <= j) {
		while (tim[i] < x && i <= right)
			i++;
		while (tim[j] > x && j >= left)
			j--;
		if (i <= j) {
			int t = tim[i];
			int t2 = val[i];
			tim[i] = tim[j];
			val[i] = val[j];
			tim[j] = t;
			val[j] = t2;
			i++;
			j--;
		}
	}
	qqsort(left, j);
	qqsort(i, right);
}
void push(int x) {
	tot++;
	pri_que[tot] = x;
	pri_up(tot);
}
void pri_up(int num) {
	if (num == 1) return;
	if (pri_que[num] > pri_que[num / 2]) {
		int t = pri_que[num];
		pri_que[num] = pri_que[num / 2];
		pri_que[num / 2] = t;
		pri_up(num / 2);
	}
}
int pop(void) {
	int t = pri_que[1];
	pri_que[1] = 0;
	pri_down(1);
	return t;
}
int mymax(int a, int b) {
	if (pri_que[a] > pri_que[b]) return a;
	else return b;
}
void pri_down(int num) {
	int p = mymax(num * 2, num * 2 + 1);	// p为编号
	if (pri_que[num] < pri_que[p]) {
		int t = pri_que[num];
		pri_que[num] = pri_que[p];
		pri_que[p] = t;
		pri_down(p);
	}
}
int pre_main() {
	while (scanf("%d", &n) == 1) {
		for (int i = 1; i <= n; i++) {
			scanf("%d %d", &tim[i], &val[i]);
		}
		qqsort(1, n);
		tot = 0;
		/*for (int i = 1; i <= n; i++) {
			printf("%d %d\n", tim[i], val[i]);
		}*/
		int ans = 0;
		int curtask = n;
		for (int cur = tim[n]; cur >= 1; cur--) {
			while (tim[curtask] >= cur) {
				push(val[curtask]);
				curtask--;
			}
			ans += pop();
		}
		printf("%d\n", ans);
	}

	return 0;
}