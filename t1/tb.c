#include <stdio.h>
#include <string.h>
// ʹ�ö���ά�����Ӻ���ǰ���������п��ԷŽ�ȥ�ģ�ѡ���ֵ����
int tim[2000];
int val[2000];
int n;
int que[2000];
int qfront, qend;
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
	qend++;
	q[qend] = x;
}
int pop(void) {
	qfront++;
	return(q[qfront]);
}
int main() {
	while (scanf("%d", &n) == 1) {
		for (int i = 1; i <= n; i++) {
			scanf("%d %d", &tim[i], &val[i]);
		}
		qqsort(1, n);
		/*for (int i = 1; i <= n; i++) {
			printf("%d %d\n", tim[i], val[i]);
		}*/
		qfront = 0;
		qend = 0;
		int timcur = tim[n];
		for (int i = n; i >= 1; i--) {
			if (timcur == tim[i]) {
				push(i);
				for (int i = )
			}
		}
	}

	return 0;
}