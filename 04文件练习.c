#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>

#define _CRT_SECURE_NO_WARNINGS

//�ļ���ϰ
/*
  1���ļ���
  2�������ļ���r��w��a��fgetc(��ȡ),fputc(д)
  w��ʽʱ�����ļ�����������ļ����������򴴽�
  r��ʽʱ�����ļ������ڣ�����
  a��ʽʱ�����ļ�ĩβ��ӣ��������򴴽�
  3���ļ��ر�
*/

int main04() {
	//���ļ�
	FILE* fp = NULL;
	fp = fopen("D:\\Studies\\a.txt", "w");
	if (fp != NULL) {
		printf("�ļ��򿪳ɹ�\n");
	}
	else printf("�ļ���ʧ��\n");
	
	//��ȡ�������ļ�
	char ch;
	while ((ch = fgetc(fp)) != EOF) {//(ch = fgetc(fp))��Ҫ���ţ�EOF==-1
		printf("%c", ch);
	}

	for (int i = 0; i < 4; i++) {
		ch = fputc('X', fp);
		printf("%c", ch);
	}

	fclose(fp);
}