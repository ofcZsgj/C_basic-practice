#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*
	效果：原文件：1+2=      读取后：1+2=3
	1、打开文件 判断可用性
	2、读取内容 放入堆空间 关闭文件
	3、再次打开文件 读取堆空间内容 写入文件后关闭
*/

int main09() {
	FILE* fp = fopen("s.txt", "r");
	if (!fp) {
		return -1;
	}

	int a, b;
	float val=0;
	char ch;
	char  ** buf = (char **)malloc(sizeof(char *) * 100);//二级指针
	for (int i = 0; i < 100; i++) {
		buf[i] = (char *)malloc(sizeof(char) * 20);		
		fscanf(fp, "%d%c%d=\n", &a, &ch, &b);
		switch (ch) {
		case '+':
			val = a + b;
			break;
		case '-':
			val = a - b;
			break;
		case '*':
			val = a * b;
			break;
		case '/':
			val = a *1.0 / b;
			break;
		}
		sprintf(buf[i], "%d%c%d=%.1f\n", a, ch, b, val);
	}
	//
	//for (int i = 0; i < 100; i++) {
	//	printf("%s", buf[i]);
	//}

	fclose(fp);

	fp = fopen("s.txt", "w");

	for (int j = 0; j < 100; j++) {
		fputs(buf[j], fp);
	}

	fclose(fp);
	for (int k = 0; k < 100; k++) {
		free(buf[k]);
	}
	free(buf);

	return 0;
}