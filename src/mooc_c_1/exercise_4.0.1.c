#include <stdio.h>
#include <math.h>

/*
题目内容：

我们认为2是第一个素数，3是第二个素数，5是第三个素数，依次类推。
现在，给定两个整数n和m，0<n<=m<=200，你的程序要计算第n个素数到第m个素数之间所有的素数的和，包括第n个素数和第m个素数。

输入格式:
两个整数，第一个表示n，第二个表示m。
输出格式：
一个整数，表示第n个素数到第m个素数之间所有的素数的和，包括第n个素数和第m个素数。

输入样例：
2 4 
输出样例：
15
*/

int main(int argc, char const *argv[]) {
	int m,n;
	int count = 0;
	int sum = 0;
	scanf("%d", &m);
	scanf("%d", &n);

	int i = 2;
	
	
	while (count <= 200 ) {
		int isPrime = 1;
		int j = 2;	
		for (; j <= sqrt(i); ++j) {
			if (i % j == 0){
				isPrime = 0;
				break;
			}
		}

		if (isPrime) {
			count++;
			if (count >= m && count <= n ) {
				sum += i;
				
			}
		}
		i++;
	}
	printf("%d\n", sum);	
	return 0;
}