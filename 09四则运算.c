#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*
	Ч����ԭ�ļ���1+2=      ��ȡ��1+2=3
	1�����ļ� �жϿ�����
	2����ȡ���� ����ѿռ� �ر��ļ�
	3���ٴδ��ļ� ��ȡ�ѿռ����� д���ļ���ر�
*/

int main09() {
	FILE* fp = fopen("s.txt", "r");
	if (!fp) {
		return -1;
	}

	int a, b;
	float val=0;
	char ch;
	char  ** buf = (char **)malloc(sizeof(char *) * 100);//����ָ��
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