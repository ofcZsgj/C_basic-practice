#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
//��ȡ�ļ�״̬ͷ�ļ�
#include<sys/types.h>
#include<sys/stat.h>
//1ΪԴ�ļ�����2Ϊ����������ƣ�MAXSIZEΪ����ʱÿһ��Ĵ�С
#define FILENAME1 "test1.mp4"
#define FILENAME2 "test2.mp4"
#define MAXSIZE 1024*1024*10

int main12() {
	
	unsigned int startTime = time(NULL);

	FILE* fp1 = fopen(FILENAME1, "r");
	FILE* fp2 = fopen(FILENAME2, "w");

	if (!fp1 || !fp2) {
		return -1;
	}

	//��ȡ�ļ�����
	struct stat* s = NULL;//stat��ͷ�ļ��еķ������ṹ��
	//��ȡԴ�ļ�
	//??????????????????????????????, ��������
	stat(FILENAME1, s);

	char* ch;
	int maxSize = 0;
	if (s->st_size < MAXSIZE) {//�ļ�С��10M
		maxSize = s->st_size;
		ch = (char*)malloc(sizeof(char) * s->st_size);
	}
	else
		//�ļ�����10M
		maxSize = MAXSIZE;
		ch = (char*)malloc(sizeof(char) * MAXSIZE);

	while (!feof(fp1)) {
		memset(ch, 0, maxSize);
		//fread()�ķ���ֵ��ʵ�ʳɹ����������Ĵ�С��������һ��С��maxSize�����Խ�Լ����Ŀռ�
		int len = fread(ch, sizeof(char), maxSize, fp1);
		fwrite(ch, len, 1, fp2);
	}

	fclose(fp1);
	fclose(fp2);

	//free(ch);

	unsigned int endTime = time(NULL);

	printf("���ѵ�ʱ��Ϊ%d(s)\n", endTime - startTime);

	return 0;
}