#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main01() {

	//void* memset(void* s, int c, size_t n);
	//���ܣ���s���ڴ������ǰn���ֽ��Բ���c����
	//	������
	//	s����Ҫ�����ڴ�s���׵�ַ
	//	c�������ַ���c��Ȼ����Ϊint����������unsigned char, ��ΧΪ0~255
	//	n��ָ����Ҫ���õĴ�С
	//	����ֵ��s���׵�ַ

	
	int n = 10;
	int* arr = NULL;
	//printf("������Ҫ���������Ĵ�С��");
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
	//���ܣ�����src��ָ���ڴ����ݵ�ǰn���ֽڵ�dest��ֵ���ڴ��ַ�ϡ�
	//	������
	//	dest��Ŀ���ڴ��׵�ַ
	//	src��Դ�ڴ��׵�ַ��ע�⣺dest��src��ָ���ڴ�ռ䲻���ص�
	//	n����Ҫ�������ֽ���
	//	����ֵ��dest���׵�ַ
	//memmove()�����÷���memcpy()һ�����������ڣ�dest��src��ָ���ڴ�ռ��ص�ʱ��
	//memmove()��Ȼ�ܴ�������ִ��Ч�ʱ�memcpy()��Щ

	int m = 5;
	int* arr1 = NULL;
	arr1 = (int*)malloc((sizeof(int) * m));
	if (arr1 == NULL) {
		printf_s("�ڴ���������ʧ��");
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

        //	���ܣ��Ƚ�s1��s2��ָ���ڴ������ǰn���ֽ�
	    //	������
		//s1���ڴ��׵�ַ1
		//s2���ڴ��׵�ַ2
		//n����Ƚϵ�ǰn���ֽ�
		//����ֵ��
		//��ȣ� = 0
		//���ڣ� > 0
		//С�ڣ� < 0

	int j = memcmp(arr, arr1, 5);
	printf("�ȽϽ��Ϊ%d\n", j);
	free(arr);
	free(arr1);
}
	//printf("HelloWorld");
