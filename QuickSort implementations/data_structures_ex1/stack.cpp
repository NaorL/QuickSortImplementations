#include "stack.h"
#include "quickSortRec.h"

void quickSortWithStack(int *arr, int left, int right)
{
	Stack callsStack;
	ItemType leftCall, rightCall, currCall;

	int pivot, currLeft, currRight;

	//we insert the data we got from the function call
	callsStack.push(ItemType(left, right, arr));

	while (callsStack.isEmpty() == false)
	{
		currCall = callsStack.pop();
		currLeft = currCall.getLeft();
		currRight = currCall.getRight();

		if (currLeft == currRight)
			continue;
		else if (currLeft < currRight)
		{
			pivot = partition(arr, currLeft, currRight);
			leftCall = { currLeft, pivot - 1, arr };
			rightCall = { pivot + 1,currRight, arr };

			callsStack.push(leftCall);
			callsStack.push(rightCall);
		}
	}
}