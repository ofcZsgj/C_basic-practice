#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//查看文本文件  cat abc.txt
int main06()
{
	char fileName[256];
	printf("请输入您查看的文件：\n");
	scanf("%s", fileName);
	getchar();

	FILE* fp = fopen(fileName, "r");
	if (!fp)
		return -1;
	//文件的结束标志  EOF -1
	char ch;
	while ((ch = fgetc(fp)) != EOF)
		printf("%c", ch);

	fclose(fp);
	return EXIT_SUCCESS;
}

