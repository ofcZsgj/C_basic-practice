#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>




int main1301() {
	FILE* fp = fopen("gb.txt", "w");
	if (!fp) {
		return -1;
	}

	char arr[] = "Hello World";
	for (int i = 0; i < 12;i++) {
		fputc(arr[i], fp);
		printf("%c", arr[i]);
		printf("%d\n", ftell(fp));
	}
	
	fclose(fp);

	return 0;
}

int main1302() {
	FILE* fp = fopen("gb.txt", "r");
	if (!fp) {
		return -1;
	}

	char ch;
	while ((ch = fgetc(fp)) != EOF) {
		fseek(fp, -1, SEEK_CUR);//���޴�ӡ��һ���ַ�
		printf("%c", ch);
	}

	fclose(fp);

	return 0;
}

int main1303() {
	FILE* fp = fopen("gb.txt", "r");
	if (!fp) {
		return -1;
	}

	char ch;
	while ((ch = fgetc(fp)) != EOF) {
		printf("%c", ch);
		rewind(fp);//������ƶ����ļ���ͷ
	}

	fclose(fp);

	return 0;
}