#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"quickSort.h"//퀵정렬 함수
#include"setting.h"

void printArr(int list[]) {//배열 출력 함수
	int i;
	for (i = 0; i < LISTMAX - 1; i++)
		printf("%d | ", list[i]);
	printf("%d\n", list[i]);
}
void randomNum(int list[], int num) {//1~10000난수 배열 생성함수
	srand((unsigned)time(NULL));
	for (int i = 0; i < num; i++) {
		list[i] = (rand() % 10000) + 1;
	}
}
int main() {
	clock_t start, end;


	//int arr[12] = { 6, 3, 11, 9, 12, 2, 8, 15, 18, 10, 7, 14 };//12개 입력 배열
	//printArr(arr);//주어진 12개의 값을 출력
	//quickSort(arr, 0, LISTMAX - 1);//퀵정렬
	//printArr(arr);//정렬된 후의 배열 

	int arr2[LISTMAX] = { 0 }; //LISTMAX개 입력 배열
	randomNum(arr2, LISTMAX);//LISTMAX개의 랜덤 값 생성
	quickSort(arr2, 0, LISTMAX - 1);//퀵정렬
	printArr(arr2);//정렬된 후의 배열 

	int arr3[LISTMAX] = { 0 };

	for (int i = 0; i < LISTMAX; i++)
	{
		arr3[i] = arr2[i];
	}
	start = clock();

	quickSort(arr3, 0, LISTMAX - 1);//퀵정렬
	printArr(arr3);//정렬된 후의 배열 

	end = clock();
	printf("프로그램 수행시간: %lf", (double)(end - start) / CLOCKS_PER_SEC); //프로그램 수행하는데 걸린 시간
	return 0;
}