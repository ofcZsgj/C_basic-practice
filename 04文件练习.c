#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>

#define _CRT_SECURE_NO_WARNINGS

//文件练习
/*
  1、文件打开
  2、操作文件（r，w，a）fgetc(读取),fputc(写)
  w方式时，若文件存在则清空文件，不存在则创建
  r方式时，若文件不存在，报错
  a方式时，在文件末尾添加，不存在则创建
  3、文件关闭
*/

int main04() {
	//打开文件
	FILE* fp = NULL;
	fp = fopen("D:\\Studies\\a.txt", "w");
	if (fp != NULL) {
		printf("文件打开成功\n");
	}
	else printf("文件打开失败\n");
	
	//读取、操作文件
	char ch;
	while ((ch = fgetc(fp)) != EOF) {//(ch = fgetc(fp))需要括号，EOF==-1
		printf("%c", ch);
	}

	for (int i = 0; i < 4; i++) {
		ch = fputc('X', fp);
		printf("%c", ch);
	}

	fclose(fp);
}