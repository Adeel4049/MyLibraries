#include<iostream>
#include<vector>
using namespace std;
#pragma once
template <class T>
class Stack
{
private:
	vector <T>Array;
	int Count;
public:
	Stack()
	{
		Count = 0;
	}

	bool isEmpty()
	{
		if (Array.empty())
		{
			return true;
		}
		return false;
	};

	T Pop()
	{
		if (!isEmpty())
		{
			Count--;
			T x;
			x = Array.back();
			Array.pop_back();
			return x;
		}
		//cout << "The File is Empty" << endl;
		return -1;
	}

	void Push(T num)
	{
		Count++;
		//cout << "Pushing: " << num<<endl;
		Array.push_back(num);
	}

	T GetSize()
	{
		return Array.size();
	}

	void Display()
	{
		for (int i = 0; i <Count; i++)
		{
			cout<<Array[i]<<" ";
		}
		cout << endl;
	}
};
