#ifndef __STACK_H__
#define __STACK_H__

#include <iostream>

using namespace std;

const int STACK_UNDERFLOW = -1;
void quickSortWithStack(int *arr, int left, int right);

class ItemType {
private:
	int left, right;
	int *arr = nullptr;

public:
	//ctor
	ItemType(int _left, int _right, int* _arr) :left(_left), right(_right), arr(_arr) {};
	//empty ctor
	ItemType() {};

	//getters & setters
	void setLeft(int i_left) { left = i_left; }
	int getLeft() { return left; }
	void setRight(int i_right) { right = i_right; }
	int getRight() { return right; }
	void serArr(int* i_arr) { arr = i_arr; }
	int *getArr(){ return arr; }
};

class Node {
	ItemType data;
	Node* next = nullptr;
public:
	Node(ItemType i_data, Node* i_next = nullptr) :data(i_data), next(i_next) {};
	Node();

	//getters & setters
	void setData(ItemType i_data) { data = i_data; }
	ItemType getData() { return data; }
	//allows the class Stack access private members of Node class
	friend class Stack;
};

class Stack {
private:
	Node* top = nullptr;;

public:
	//empty ctor
	Stack() { top = nullptr; }
	~Stack() { makeEmpty(); }
	//return true is the stack is empty, false otherwise
	bool isEmpty() { return top == NULL; }
	//insert new head to stack
	void push(ItemType type) { top = new Node(type, top); }

	ItemType pop() {
		if (isEmpty() == true)
		{
			cout << "The stack is empty!" << endl;
			exit(STACK_UNDERFLOW);
		}
		Node *temp = top;
		ItemType res = temp->getData();
		top = top->next;
		delete temp;
		return res;
	}

	void makeEmpty() {
		Node *temp;
		//delete all nodes
		while (top != NULL)
		{
			temp = top;
			top = top->next;
			delete temp;
		}
	}
};

#endif // __STACK_H__