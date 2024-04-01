#include<stdio.h>
#include "insertionSort.h"
#include"setting.h"

int pivot_picker(int arr[], int p, int q) //median방식으로 pivot을 선정하는 경우에 pivot을 선택하는 함수
{
	int a = arr[p];
	int b = arr[(p + q) / 2];
	int c = arr[q];

	if ((a <= b && b <= c) || (c <= b && b <= a))
		return (p + q) / 2;
	else if ((b <= a && a <= c) || (c <= a && a <= b))
		return p;
	else
		return q;
}

void quickSort(int str[], int p, int q)
{
	if (q - p + 1 <= THRESHOLD) {
		insertion_sort(str + p, q - p + 1);
		return;
	}
	//위 네 라인을 활성화 하면 THRESHOLD값 이하 입력일 때 insertion sort를 진행한다.

	int pivot_index = pivot_picker(str, p, q);	//pivot을 세 수 중 중간 값으로 사용하기 위해서 pivot_picker함수 호출
	SWAP(str[p], str[pivot_index]);				//pivot으로 선정된 값과 배열 첫 값의 자리를 교체
	//위 두 라인을 활성화 하면 median방식으로 pivot을 선정하고, 주석처리 할 시 random한 방식으로 선정한다.

	int pivot = str[p];	//pivot 배열의 첫 값을 pivot으로 선정
	int left = p + 1;		//pivot 제외 배열 좌측값
	int right = q;		//배열 우측 값
	if (p < q)
	{
		while (left < right)
		{
			if (pivot < str[left])
			{
				if (pivot < str[right])	//str[left], str[right]값 모두 pivot보다 큰 경우
				{
					right--;
				}
				else					//str[left]값만 pivot보다 큰 경우
				{
					SWAP(str[left], str[right]);
					left++;
					right--;
				}
			}
			else
			{
				if (pivot < str[right])	//str[right]값만 pivot보다 큰 경우
				{
					left++;
					right--;
				}
				else					//str[left], str[right]값 모두 pivot보다 작은 경우
				{
					left++;
				}
			}
		}
		if (right < left) 				//마지막에 right값이 left값 보다 더 작아지는 경우 발생해결
			left = right;

		if (pivot < str[left] && pivot < str[right])
		{
			SWAP(str[p], str[left - 1]);
		}
		else {
			SWAP(str[p], str[left]);		//pivot과 left위치 교체 
		}
		quickSort(str, p, left - 1);	//0~pivot-1까지 재귀호출
		quickSort(str, left, q);	//pivot+1~끝까지 재귀호출
	}
}