#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>

//1�����ļ�����
//2�����ļ�
//3���ж��ļ�������
//4��ѭ��¼������
//5���˳�����
//6����¼�������д�뵽�ļ���
//7���ر��ļ�

int main05() {
	//1�����ļ�����
	printf("�������ļ���");
	char fileName[256];
	scanf("%s", fileName);
	//���ջ��У�Ҳ��ʹ��scanf("%[^\n]",fileName)
	getchar();
	
	//2�����ļ�
	FILE* fp = NULL;
	fp = fopen(fileName, "w");//��סfopen�Ĳ���һ����˫����

	//3������ļ�������
	if (!fp) {
		return -1;
	}
	
	//4��ѭ��¼������
	char buf[1024];

	while (1) {
		memset(buf, 0, 1024);
		fgets(buf, 1024, stdin);//fgets�������Զ���\n
	//5������¼��
		//�����յ�common=exitʱ������¼��
		if (!(strncmp("common=exit", buf, 11))) {//�ܿ�\n
			break;
		}
	//6����¼�������д�뵽�ļ���
		int i = 0;
		while (buf[i] != '\0') {
			fputc(buf[i++], fp);
		}
	}

	//7���ر��ļ�
	fclose(fp);

	return 0;
}





