#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//fread,fwrite

struct student {
	char name[20];//20
	int age;//4
	char sex;//1
	char tel[15];//15
};

typedef struct student stu;

int main1101() {// 写
	stu s[5] = {
		{"李白",10,'M',"110"},
		{"李黑",20,'F',"119"},
		{"李鬼",30,'M',"114"},
		{"李奎",40,'F',"911"},
		{"李青",50,'M',"120"},
	};

	FILE* fp = fopen("li.txt", "wb");
	if (!fp) {
		return -1;
	}

	for (int i = 0; i < 5; i++) {
		fwrite(&s[i], sizeof(stu), 1, fp);
	}

	fclose(fp);

	return 0;
}

int main1102() { //读
	FILE* fp = fopen("li.txt", "r");//写rb读取异常，不知为何？？
	if (!fp) {
		return -1;
	}

	stu s[5] = {0};
	int i = 0;
	while (!feof(fp)) {
		fread(&s[i++], sizeof(stu), 1, fp);
	}

	for (int i = 0; i < 5; i++) {
		printf("姓名为: %s\t年龄为: %d\t性别为: %s\t电话为: %s\n", s[i].name, s[i].age, s[i].sex == 'M' ? "男" : "女", s[i].tel);
	}
	
	fclose(fp);
}