#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>

//fprintf(写文件),fscanf(读文件)

int main0801() {
	FILE* fp1 = fopen("g.txt", "w");
	if (!fp1) {
		return -1;
	}
	
	int a = 1, b = 2, c = 3;
	fprintf(fp1, "%d+%d=%d\n", a, b, c);

	fclose(fp1);
	return 0;
}

int main0802() {
	FILE* fp1 = fopen("s.txt", "r");
	if (!fp1) {
		return -1;
	}
	
	int a, b;
	char ch;
	for (int i = 0; i < 100; i++) {
		
		fscanf(fp1, "%d%c%d=\n", &a, &ch, &b);

		printf("%d%c%d\n", a, ch, b);
	}

	fclose(fp1);
	return 0;
}