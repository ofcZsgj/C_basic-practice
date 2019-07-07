#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>

//随机生成100个10以内的四则运算表达式写入到一个文件中去

enum MyEnum
{
	add, sub, mlt, dive
}opt;

int main07() {
	char buf[30];
	
	FILE* fp = fopen("s.txt", "w");
	if (!fp) {
		return -1;
	}
	srand((unsigned int)time(NULL));
	char c=0;
	for (int i = 0; i < 100; i++) {
		switch (rand()%4) {
		case 0:
			c = '+';
			break;
		case 1:
			c = '*';
			break;
		case 2:
			c = '/';
			break;
		case 3:
			c = '-';
			break;
		}

		memset(buf, 0, 30);
		int a, b;
		a = rand() % 10 + 1;
		b = rand() % 10 + 1;
		sprintf(buf, "%d%c%d=\n", a, c, b);//2*3=
		
		int j = 0;
		while (buf[j]) {
			fputc(buf[j++], fp);
		}
	}

	fclose(fp);

	return 0;
}