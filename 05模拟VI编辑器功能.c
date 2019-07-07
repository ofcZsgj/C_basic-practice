#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>

//1、给文件命名
//2、打开文件
//3、判断文件可用性
//4、循环录入内容
//5、退出命名
//6、将录入的内容写入到文件中
//7、关闭文件

int main05() {
	//1、给文件命名
	printf("请输入文件名");
	char fileName[256];
	scanf("%s", fileName);
	//接收换行，也可使用scanf("%[^\n]",fileName)
	getchar();
	
	//2、打开文件
	FILE* fp = NULL;
	fp = fopen(fileName, "w");//记住fopen的参数一定加双引号

	//3、检查文件可用性
	if (!fp) {
		return -1;
	}
	
	//4、循环录入内容
	char buf[1024];

	while (1) {
		memset(buf, 0, 1024);
		fgets(buf, 1024, stdin);//fgets方法会自动加\n
	//5、结束录入
		//当接收到common=exit时，结束录入
		if (!(strncmp("common=exit", buf, 11))) {//避开\n
			break;
		}
	//6、将录入的内容写入到文件中
		int i = 0;
		while (buf[i] != '\0') {
			fputc(buf[i++], fp);
		}
	}

	//7、关闭文件
	fclose(fp);

	return 0;
}





