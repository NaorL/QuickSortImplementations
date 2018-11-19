//Data structures ex1
//Naor

#include "quickSortRec.h"
#include "stack.h"

using namespace std;

void printArr(int *arr, int size);
void readArray(int *arrRec, int *arrStack, int size);

void main()
{
	int size, *arrRec, *arrStack;

	cout << "Plese enter the size of the array:" << endl;

	cin >> size;

	arrRec = new int[size];
	arrStack = new int[size];

	cout << "Please enter " << size << " numberes to array:" << endl;

	readArray(arrRec, arrStack, size);

	int left = 0, right = size - 1;

	quickSortRec(arrRec, left, right);

	cout << "Quick sort - recursive version: \n";

	printArr(arrRec, size);

	cout << "\nQuick sort - iterative version with stack: \n";

	quickSortWithStack(arrStack, left, right);

	printArr(arrStack, size);

	cout << endl;

	delete []arrRec;
	delete []arrStack;

}

void printArr(int *arr, int size)
{
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
}

void readArray(int *arrRec, int *arrStack, int size)
{
	int temp;
	for (size_t i = 0; i < size; i++)
	{
		cin >> temp;
		arrRec[i] = temp;
		arrStack[i] = temp;
	}
}