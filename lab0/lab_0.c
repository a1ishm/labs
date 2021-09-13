#include <stdio.h>

#define X_MAX 100
#define X_MIN -100

int solve(int a, int b, int c, int *x1, int *x2) {
	short status;

	if (!a) {
		status = 1;
		return status;
	}

	if ((b % a) || (c % a)) {
		status = 2;
		return status;
	}

	int sum = -b / a;
	int prod = c / a;

	for (int i = X_MIN; i <= X_MAX; i++) {
		for (int j = X_MIN; j <= X_MAX; j++) {
			if ((i + j == sum) && (i * j == prod)) {
				*x1 = i;
				*x2 = j;
				status = 0;
				return status;
			}
		}
	}

	status = 2;
	return status;
}

int main() {
	int a, b, c;
	int x1, x2;
	int status;

	printf("a = ");
	scanf("%d", &a);

	printf("b = ");
	scanf("%d", &b);

	printf("c = ");
	scanf("%d", &c);

	if ((status = solve(a, b, c, &x1, &x2)) != 0) {
		switch (status) {
		case 1:
			printf("Not a quadratic equation\n");
			break;
		case 2:
			printf("No roots found\n");
			break;
		default:
			printf("Should never be reached\n");
		}

		return status;
	}

	if (x1 != x2) {
		printf("x1 = %d\nx2 = %d\n", x1, x2);
	}
	else {
		printf("x = %d\n", x1);
	}

	return 0;
}