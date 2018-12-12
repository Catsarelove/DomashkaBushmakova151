#include <thread>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <cmath>
typedef double doo;

void sum(doo *s, doo *a, int l, int r, int n){
	for(int i = l; i < r && i<n; i++) {
		*s+=a[i];
	}
}

int main() {
	int n;
	doo *a;
	scanf("%d", &n);
	a = new doo[n];
	for(int i = 0; i < n; i++)
		a[i] = rand() % 100 * 1. / (rand() % 100 + 1);
	clock_t start1, stop1, start2, stop2;
	start1 = clock();
	doo summ = 0;
	for(int i = 0; i < n; i++)
		summ += a[i];
	stop1 = clock();
	printf("summ = %f\n", summ);
	printf("Последовательное суммирование: %f секунд\n", (float)(stop1 - start1) / CLK_TCK);
	int k = n / 8 + (n / 8 ? 0: n % 8);
	int c = n / k + (n % k ? 1 : 0);
	doo s[c];
	std::thread *threads[c];
	doo summa = 0;
	start2 = clock();
	for(int i = 0; i < c; i++) {
		s[i] = 0;
		threads[i] = new std::thread(sum, s+i, a, i*k, (i + 1)*k, n);
	}
	for(int i = 0; i < c; i++)
		threads[i]->join();
	for(int i = 0; i < c; i++)
		summa += s[i];
	stop2 = clock();
	printf("summ = %f\n", summa);
	printf("Параллельное суммирование: %f секунд\n", (float)(stop2 - start2) / CLK_TCK);
	delete[]a;
	delete[]s;
	return 0;	
}              
