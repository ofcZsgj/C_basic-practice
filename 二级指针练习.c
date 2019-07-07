#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main02() {
	int** p = (int**)malloc(sizeof(int*) * 3);
	*p = (int*)malloc(sizeof(int) * 3);
	*(p+1) = (int*)malloc(sizeof(int) * 3);//*(p+1) == p[1]
	*(p+2) = (int*)malloc(sizeof(int) * 3);//*(p+2) == p[2]

	if (p != NULL && *p != NULL && *(p + 1) != NULL && *(p + 2) != NULL) {
		printf("堆分配成功！\n");
	}

	int score = 100;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			p[i][j] = score--; 
		    //*(*(p+i)+j) == score--;
		}
	}

	//p[0][0] = 90;
	//p[0][1] = 80;
	//p[0][2] = 70;

	printf("成功赋值\n");

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%d\n", p[i][j]);
		}
	}

	free(p[1]);
	free(p[2]);
	free(p[3]);
	free(p);

}