#include <stdio.h>

int fab_r (int n) {
	/*using recursion*/
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return fab_r(n - 1) + fab_r(n - 2);
}

int fab_f (int n) {
	/*using for loop*/
	if (n == 0) return 0;
	if (n == 1) return 1;
	int prev = 0, next = 1;
	int i, ans = 0;

	for (i = 2; i < n + 1; ++i) {
		ans = prev + next;
		prev = next;
		next = ans;
	}

	return ans;
}
		


int main() {
	printf("enter a number:\n");
	int n;
	scanf("%d", &n);

	int ans = fab_f(n);

	printf("answer = %d\n", ans);

	return 0;
}
