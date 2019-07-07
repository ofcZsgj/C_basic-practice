#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main01() {

	//void* memset(void* s, int c, size_t n);
	//功能：将s的内存区域的前n个字节以参数c填入
	//	参数：
	//	s：需要操作内存s的首地址
	//	c：填充的字符，c虽然参数为int，但必须是unsigned char, 范围为0~255
	//	n：指定需要设置的大小
	//	返回值：s的首地址

	
	int n = 10;
	int* arr = NULL;
	//printf("请输入要输入的数组的大小：");
	//scanf_s("%d", &n);
	arr = (int*)malloc((sizeof(int) * n));
	while (arr != NULL) {
		memset(arr, 0, (sizeof(int) * n));
		break;
	}
	//for (int i = 0; i < n; i++) {
	//	if(arr != NULL) {
	//		printf_s("%d\n", *(arr + i));
	//	}
	//}

	//void* memcpy(void* dest, const void* src, size_t n);
	//功能：拷贝src所指的内存内容的前n个字节到dest所值的内存地址上。
	//	参数：
	//	dest：目的内存首地址
	//	src：源内存首地址，注意：dest和src所指的内存空间不可重叠
	//	n：需要拷贝的字节数
	//	返回值：dest的首地址
	//memmove()功能用法和memcpy()一样，区别在于：dest和src所指的内存空间重叠时，
	//memmove()仍然能处理，不过执行效率比memcpy()低些

	int m = 5;
	int* arr1 = NULL;
	arr1 = (int*)malloc((sizeof(int) * m));
	if (arr1 == NULL) {
		printf_s("内存已满创建失败");
	}
	while (arr1 != NULL) {
		memset(arr1, 0, sizeof(int) * m);
		break;
	}
	for (int i = 0; i < m; i++) {
		//*(arr1 + i) += i;
		arr1[i] += i;
	}
	//memcpy(arr, arr1, 20);
	//for (int i = 0; i < n; i++) {
	//	printf_s("%d\n", arr[i]);
	//}

        //	功能：比较s1和s2所指向内存区域的前n个字节
	    //	参数：
		//s1：内存首地址1
		//s2：内存首地址2
		//n：需比较的前n个字节
		//返回值：
		//相等： = 0
		//大于： > 0
		//小于： < 0

	int j = memcmp(arr, arr1, 5);
	printf("比较结果为%d\n", j);
	free(arr);
	free(arr1);
}
	//printf("HelloWorld");
