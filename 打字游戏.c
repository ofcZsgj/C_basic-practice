#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>

#define _CRT_SECURE_NO_WARNINGS

/*
  1��������ʾ
  2����������ַ�
  3�����մ�ӡ����������
*/

void typeTips() {
	printf("**************������Ϸ****************\n");
	printf("*************��Esc �˳�***************\n");
	printf("************�����������**************\n");
	char ch = _getch();
	if (ch == 27) {
		exit(0);//�˳�����
	}
}

void randChar(char* arr) {
	srand((unsigned int)time(NULL));//��ʱ���������������
	for (int i = 0; i < 50; i++) {
		*(arr + i) = rand() % 26 + 'a';//26��Ӣ����ĸ��a��ʼ
	}
	printf("%s\n", arr);
}

void printChar(char* arr) {
	// ��ʼʱ�� ����ʱ�� ��ȷ��
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
	printf("������ʱΪ��%d��s��\n", endTime - startTime);
	printf("��ȷ��Ϊ��%.1f%%\n", val*1.0/50*100);
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