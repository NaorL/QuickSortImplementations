#ifndef __QUICKSORTREC_H__
#define __QUICKSORTREC_H__

#include <stdlib.h>
#include <iostream>

void quickSortRec(int* arr, int left, int right);
int partition(int arr[], int left, int right);
void setPivot(int *arr, int right, int left);
void swap(int& a, int& b);

#endif // !__QUICKSORTREC_H__
