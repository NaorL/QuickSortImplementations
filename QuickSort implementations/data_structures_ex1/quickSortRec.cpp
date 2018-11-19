#include "quickSortRec.h"


void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void setPivot(int *arr, int right, int left)
{
	int index = left + rand() % (right - left + 1);
	int temp = arr[left];
	arr[left] = arr[index];
	arr[index] = temp;
}

int partition(int arr[], int left, int right)
{
	setPivot(arr, right, left);
	int pivot = arr[left];
	while (left != right)
	{
		if (arr[left] > arr[right])
		{
			swap(arr[left], arr[right]);
		}
		if (pivot == arr[left])
			right--;
		else // Pivot == arr[right]
			left++;
	}
	return left;
}

void quickSortRec(int* arr, int left, int right)
{
	if (left == right)
		return;
	else if (left < right)
	{
		int pivot = partition(arr, left, right);
		quickSortRec(arr, left, pivot - 1);
		quickSortRec(arr, pivot + 1, right);
	}
}