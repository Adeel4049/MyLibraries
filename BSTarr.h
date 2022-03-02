#pragma once
#include<iostream>
using namespace std;

class BSTarr
{

	int *Arr;
	int Lastindex;
	int capacity;


	void InOrder(int Current)
	{
		if (Current < capacity)
		{

			if (Arr[Current] != -99)
			{

				InOrder(Current * 2);
				cout << Arr[Current] << "  ";
				InOrder((Current * 2) + 1);

			}
		}
	}
	void PreOrder(int Current)
	{
		if (Current < capacity)
		{

			if (Arr[Current] != -99)
			{
				cout << Arr[Current] << "  ";
				InOrder(Current * 2);
				InOrder((Current * 2) + 1);

			}
		}

	}
	void PostOrder(int Current)
	{
		if (Current < capacity)
		{

			if (Arr[Current] != -99)
			{

				InOrder(Current * 2);
				InOrder((Current * 2) + 1);
				cout << Arr[Current] << "  ";
			}
		}

	}



public:
	BSTarr()
	{
		capacity = 4;
		Arr = new int[capacity];
		for (int i = 0; i < capacity; i++)
			Arr[i] = -99;
		
		Lastindex = 0;
	}

	void Insert(int V)
	{
			int Current = 1;
			while (1)
			{
				if (Arr[Current] == -99)
				{
					Arr[Current] = V;
					break;
				}
				else if (Arr[Current] < V)
				{
					Current = Current * 2 + 1;
				}
				else
				{
					Current = Current * 2;
				}

				if (Current > capacity)
				{
					AutoGrow();
				}


			}

	
	}
	void AutoGrow()
	{
		int *temp = new int[capacity*2];
	
		for (int i = 0; i < capacity*2; i++)
		{
			temp[i] = -99;
		}

		for (int i = 0; i < capacity; i++)
			temp[i] = Arr[i];
	
		
		capacity = capacity * 2;


		delete Arr;
		Arr = temp;

	}
	void Print()
	{
		for (int i = 0; i < capacity; i++)
		{
			cout << Arr[i] << "  ";

		}
	
	

	}
	
	void Search(int V)
	{
		bool found = false;
		int Current = 1;
		while (Current < capacity)
		{
			if (Arr[Current] == V)
			{
				found = 1;
				break;
			}
			else if (Arr[Current] < V)
			{
				Current = Current * 2 + 1;
			}
			else
			{
				Current = Current * 2;
			}

		}




		if (found)
		{
			cout << "ELEMENT FOUND " << endl;
		}
		else
			cout << "ELEMENT NOT FOUND " << endl;

	}

	void PrintInOrder()
	{
		InOrder(1);
	}
	void PrintPreOrder()
	{
		PreOrder(1);

	}
	void PrintPostOrder()
	{
		PostOrder(1);

	}


	~BSTarr(){ ; }
};



