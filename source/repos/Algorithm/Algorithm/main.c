#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"quickSort.h"//������ �Լ�
#include"setting.h"

void printArr(int list[]) {//�迭 ��� �Լ�
	int i;
	for (i = 0; i < LISTMAX - 1; i++)
		printf("%d | ", list[i]);
	printf("%d\n", list[i]);
}
void randomNum(int list[], int num) {//1~10000���� �迭 �����Լ�
	srand((unsigned)time(NULL));
	for (int i = 0; i < num; i++) {
		list[i] = (rand() % 10000) + 1;
	}
}
int main() {
	clock_t start, end;


	//int arr[12] = { 6, 3, 11, 9, 12, 2, 8, 15, 18, 10, 7, 14 };//12�� �Է� �迭
	//printArr(arr);//�־��� 12���� ���� ���
	//quickSort(arr, 0, LISTMAX - 1);//������
	//printArr(arr);//���ĵ� ���� �迭 

	int arr2[LISTMAX] = { 0 }; //LISTMAX�� �Է� �迭
	randomNum(arr2, LISTMAX);//LISTMAX���� ���� �� ����
	quickSort(arr2, 0, LISTMAX - 1);//������
	printArr(arr2);//���ĵ� ���� �迭 

	int arr3[LISTMAX] = { 0 };

	for (int i = 0; i < LISTMAX; i++)
	{
		arr3[i] = arr2[i];
	}
	start = clock();

	quickSort(arr3, 0, LISTMAX - 1);//������
	printArr(arr3);//���ĵ� ���� �迭 

	end = clock();
	printf("���α׷� ����ð�: %lf", (double)(end - start) / CLOCKS_PER_SEC); //���α׷� �����ϴµ� �ɸ� �ð�
	return 0;
}