#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int inqueue(int* arr, int* f, int* r, int n, int newnum,int *count) {
	if (count==n)
		return 0;
	*r = (*r + 1) % n;
	arr[*r] = newnum;
	(*count)++;
}
int dequeue(int* arr, int* f, int* r, int n, int *count) {
	if (count==0)
		return 0;
	int beforef = *f;
	*f = (*f + 1) % n;
	(*count)--;
	return arr[beforef];

}
int main() {
	int n, k, f = 0, r, newnum, count = 0;
	int* arr = NULL;
	scanf("%d %d", &n, &k);
	r = n - 1;
	arr = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++)
		inqueue(arr, &f, &r, n, i + 1, &count);
	//printf("%d\n", count);
	printf("<");
	while (1) {
		for (int i = 0; i < k - 1; i++) {
			newnum = dequeue(arr, &f, &r, n, &count);
			inqueue(arr, &f, &r, n, newnum, &count);
		}
		printf("%d", dequeue(arr, &f, &r, n, &count));
		if (count == 0) {
			printf(">");
			break;
		}
		printf(", ");
	}
	

}