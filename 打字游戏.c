#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>

#define _CRT_SECURE_NO_WARNINGS

/*
  1、给出提示
  2、给出随机字符
  3、接收打印所输入内容
*/

void typeTips() {
	printf("**************打字游戏****************\n");
	printf("*************按Esc 退出***************\n");
	printf("************按任意键继续**************\n");
	char ch = _getch();
	if (ch == 27) {
		exit(0);//退出程序
	}
}

void randChar(char* arr) {
	srand((unsigned int)time(NULL));//以时间生成随机数种子
	for (int i = 0; i < 50; i++) {
		*(arr + i) = rand() % 26 + 'a';//26个英文字母，a起始
	}
	printf("%s\n", arr);
}

void printChar(char* arr) {
	// 起始时间 结束时间 正确率
	unsigned int startTime;
	unsigned int endTime;
	int val = 0;
	for (int i = 0; i < 50; i++) {
		char ch = _getch();
		if (i == 0) {
			startTime = time(NULL);//1970?
		}
		if (ch == *(arr + i)) {
			printf("%c", ch);
			val++;
		}
		else if (ch == 27) {
			exit(0);
		}
		else printf("_");
	}
	endTime = time(NULL);//1970?
	printf("打字用时为：%d（s）\n", endTime - startTime);
	printf("正确率为：%.1f%%\n", val*1.0/50*100);
}

int main03() {
	char* arr = (char*)malloc(sizeof(char) * 51);
	if(arr != NULL) {
		memset(arr, 0, 51);
	}

	while (1) {
		typeTips();
		randChar(arr);
		printChar(arr);
	}
	
	if(arr!=NULL) {
		free(arr);
	}
	return 0;
}