#include<iostream>
using namespace std;
#pragma once
template<class T>
class Queue
{
private:
	T rear;
	T front;
	T size;
	T *Arr;

public:
	Queue()
	{
		front = 0;
		rear = -1;
		size = 0;
		Arr = nullptr;
	}

	void init(int S)
	{
		size = S;
		Arr = new T[S];
	}

	void Enqueue(T x)
	{
		if (isFull())
		{
			cout << "QUEUE IS FULL" << endl;
		}
		else
		{
			rear++;
			Arr[rear] = x;
		}
	}

	T Dequeue()
	{
		if (!isEmpty())
		{
			T x = Arr[front];
			rearrangeElementsAfterDeletion();
			return x;
		}
	}

	bool isFull()
	{
		if (rear == size-1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool isEmpty()
	{
		if (rear == -1)
		{
			cout << "QUEUE IS EMPTY" << endl;
			return true;
		}
		return false;
	}

	void rearrangeElementsAfterDeletion()
	{
		for (int i = 0; i < rear; i++)
		{
			Arr[i] = Arr[i + 1];
		}
		rear--;
	}
	void Display()
	{
		cout << "DISPLAYING QUEUE: ";
		for (int i = 0; i <=rear; i++)
		{
			cout << Arr[i] << "  ";
		}
		cout << endl;
	}
};
