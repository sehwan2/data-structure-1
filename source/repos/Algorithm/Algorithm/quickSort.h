#include<stdio.h>
#include "insertionSort.h"
#include"setting.h"

int pivot_picker(int arr[], int p, int q) //median������� pivot�� �����ϴ� ��쿡 pivot�� �����ϴ� �Լ�
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
	//�� �� ������ Ȱ��ȭ �ϸ� THRESHOLD�� ���� �Է��� �� insertion sort�� �����Ѵ�.

	int pivot_index = pivot_picker(str, p, q);	//pivot�� �� �� �� �߰� ������ ����ϱ� ���ؼ� pivot_picker�Լ� ȣ��
	SWAP(str[p], str[pivot_index]);				//pivot���� ������ ���� �迭 ù ���� �ڸ��� ��ü
	//�� �� ������ Ȱ��ȭ �ϸ� median������� pivot�� �����ϰ�, �ּ�ó�� �� �� random�� ������� �����Ѵ�.

	int pivot = str[p];	//pivot �迭�� ù ���� pivot���� ����
	int left = p + 1;		//pivot ���� �迭 ������
	int right = q;		//�迭 ���� ��
	if (p < q)
	{
		while (left < right)
		{
			if (pivot < str[left])
			{
				if (pivot < str[right])	//str[left], str[right]�� ��� pivot���� ū ���
				{
					right--;
				}
				else					//str[left]���� pivot���� ū ���
				{
					SWAP(str[left], str[right]);
					left++;
					right--;
				}
			}
			else
			{
				if (pivot < str[right])	//str[right]���� pivot���� ū ���
				{
					left++;
					right--;
				}
				else					//str[left], str[right]�� ��� pivot���� ���� ���
				{
					left++;
				}
			}
		}
		if (right < left) 				//�������� right���� left�� ���� �� �۾����� ��� �߻��ذ�
			left = right;

		if (pivot < str[left] && pivot < str[right])
		{
			SWAP(str[p], str[left - 1]);
		}
		else {
			SWAP(str[p], str[left]);		//pivot�� left��ġ ��ü 
		}
		quickSort(str, p, left - 1);	//0~pivot-1���� ���ȣ��
		quickSort(str, left, q);	//pivot+1~������ ���ȣ��
	}
}