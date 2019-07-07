#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>

#define N 100000

void ranNumber(FILE *fp) {
	srand((unsigned int) time(NULL));
	for (int i = 0; i < N; i++) {
		fprintf(fp, "%d\n", rand() % 10000);
	}	
	fclose(fp);
}

void bubbleRanNumber(FILE *fp,int * p) {
	unsigned int startTime = time(NULL);
	
	for (int i = 0; i < N; i++) {
		fscanf(fp, "%d\n", &p[i]);
	}

	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < N - i - 1; j++) {
			if (p[j] > p[j + 1]) {
				int temp = p[j];
				p[j] = p[j + 1];
				p[j + 1]= temp;
			}
		}
	}

	FILE* fp1 = fopen("rd.txt", "w");

	for (int k = 0; k < N; k++) {
		fprintf(fp1, "%d\n", p[k]);
	}

	fclose(fp);
	fclose(fp1);
	unsigned endTime = time(NULL);
	printf("ÅÅÐòÓÃÊ±Îª£º%d£¨s£©", endTime - startTime);
}

int main10() {
	FILE* fp = fopen("r.txt", "r+");
	if (!fp) {
		return -1;
	}
	
	int* p = (int *)malloc(sizeof(int) * N);

	//ranNumber(fp);

	bubbleRanNumber(fp,p);

	free(p);

	return 0;
}