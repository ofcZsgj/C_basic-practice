#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
//获取文件状态头文件
#include<sys/types.h>
#include<sys/stat.h>
//1为源文件名，2为拷贝后的名称，MAXSIZE为拷贝时每一块的大小
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

	//获取文件属性
	struct stat* s = NULL;//stat是头文件中的方法，结构体
	//获取源文件
	//??????????????????????????????, 参数？？
	stat(FILENAME1, s);

	char* ch;
	int maxSize = 0;
	if (s->st_size < MAXSIZE) {//文件小于10M
		maxSize = s->st_size;
		ch = (char*)malloc(sizeof(char) * s->st_size);
	}
	else
		//文件大于10M
		maxSize = MAXSIZE;
		ch = (char*)malloc(sizeof(char) * MAXSIZE);

	while (!feof(fp1)) {
		memset(ch, 0, maxSize);
		//fread()的返回值是实际成功读到块数的大小，针对最后一块小于maxSize，可以节约分配的空间
		int len = fread(ch, sizeof(char), maxSize, fp1);
		fwrite(ch, len, 1, fp2);
	}

	fclose(fp1);
	fclose(fp2);

	//free(ch);

	unsigned int endTime = time(NULL);

	printf("花费的时间为%d(s)\n", endTime - startTime);

	return 0;
}