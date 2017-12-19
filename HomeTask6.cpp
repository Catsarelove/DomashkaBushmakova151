#include <iostream>
#include <stdio.h>
using namespace std;
int main() {
	int sum = 0;
	int a, b, c, d, e, f, g, m, k, r;   /*f=0 || f=9, если a=0*/ /*d=0 || d=9*/ /*e=0 || e=9*/ /*r=k || r=k-1, если r!=0*/ 
	int def[2] = { 0,9 };
	for (int i = 0; i < 2; i++) {
		d = def[i];
		e = d;
		f = 0;
		for (int j = 0; j <= 9; j++) {
			r = j;
			if (d == 9) k = j - 1;
			if (k != -1) {
				if (d == 0) k = j;
				for (int o = 0; o <= 9; o++) {
					c = o;
					if (d == 9) {
						for (int p = 0; p <= 8; p++)
						{
							for (int p2 = 0; p2 <= p || p2 == 1; p2++)
							{
								b = p2;
								g = p - p2;
								m = p + 1;
								for (int u = 0; u <= 9; u++) {
									a = u;
									{
										printf_s("a = %d   b = %d   c = %d  d = %d e = %d   f = %d  g = %d   m = %d   k = %d   r = %d \n", a, b, c, d, e, f, g, m, k, r);
										sum++;
									}
									if (a == 0)
									{
										printf_s("a = %d   b = %d   c = %d  d = %d e = %d   f = %d  g = %d   m = %d   k = %d   r = %d \n", a, b, c, d, e, 9, g, m, k, r);
										sum++;
									}
								}
							}
						}
					}
					else
					{
						for (int p = 0; p <= 9; p++)
						{
							for (int p2 = 0; p2 <= p || p2==1; p2++)
							{
								b = p2;
								g = p - p2;
								m = p;
								for (int u = 0; u <= 9; u++) {
									a = u;
									{
										printf_s("a = %d   b = %d   c = %d  d = %d e = %d   f = %d  g = %d   m = %d   k = %d   r = %d \n", a, b, c, d, e, f, g, m, k, r);
										sum++;
									}
									if (a == 0)
									{
										printf_s("a = %d   b = %d   c = %d  d = %d e = %d   f = %d  g = %d   m = %d   k = %d   r = %d \n", a, b, c, d, e, 9, g, m, k, r);
										sum++;
									}
								}
							}
						}
					}
				}

			}
		}
	}
	cout << sum;
	/*программа выводит sum = 107140, что совпадает с кол-вом комбинаций, посчитанным математически*/
	/*это значит, что оно работает????*/
	system("pause");
	return 0;
}