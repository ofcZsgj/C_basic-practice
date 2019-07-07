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

int main1101() {// д
	stu s[5] = {
		{"���",10,'M',"110"},
		{"���",20,'F',"119"},
		{"���",30,'M',"114"},
		{"���",40,'F',"911"},
		{"����",50,'M',"120"},
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

int main1102() { //��
	FILE* fp = fopen("li.txt", "r");//дrb��ȡ�쳣����֪Ϊ�Σ���
	if (!fp) {
		return -1;
	}

	stu s[5] = {0};
	int i = 0;
	while (!feof(fp)) {
		fread(&s[i++], sizeof(stu), 1, fp);
	}

	for (int i = 0; i < 5; i++) {
		printf("����Ϊ: %s\t����Ϊ: %d\t�Ա�Ϊ: %s\t�绰Ϊ: %s\n", s[i].name, s[i].age, s[i].sex == 'M' ? "��" : "Ů", s[i].tel);
	}
	
	fclose(fp);
}