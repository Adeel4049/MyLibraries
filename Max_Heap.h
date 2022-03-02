#pragma once
template<typename T>
class Node
{
	T Val;
	Node<T>* Leftchild;
	Node<T>* Rightchild;

};


template<typename T>
class Max_Heap
{
	T *Arr;
	int Capacity;
	int Lastindex;

public:
	Max_Heap()
	{
	
		Arr = nullptr;
		Lastindex = 1;

	}
	void Insert(T V)
	{
		if (Arr == nullptr)
		{
			Capacity = 4;
			Arr = new T[Capacity];
			Arr[1] = V;
			Lastindex++;
		}
		else
		{
			if (Lastindex + 1 == Capacity)
			{
				Grow();
			}


			Arr[Lastindex] = V;
		
			Heapify_Up();
			Lastindex++;
			
		}
	
	}
	void Grow()
	{
		Capacity = Capacity * 2;
		T* temp = new T[Capacity];
		
		for (int i = 0; i < Lastindex; i++)
			temp[i] = Arr[i];


		delete Arr;
		Arr = temp;


	}
	void Heapify_Up()
	{
		int Current = Lastindex;
		while (Current > 1)
		{
			if (Current % 2 == 0)
			{
				if (Arr[Current / 2] < Arr[Current])
				{
					Swap(Arr[Current / 2], Arr[Current]);
					Current = Current / 2;
				}
				else
					break;
			}
			else
			{
				if (Arr[(Current-1) / 2] < Arr[Current])
				{
					Swap(Arr[(Current - 1) / 2], Arr[Current]);
					Current = Arr[(Current - 1) / 2];
				}
				else
					break;			
			}

		}	
	}

	void Swap(int &A, int &B)
	{
		int C = A;
		A = B;
		B = C;	
	}
	void Print()
	{
		for (int i = 1; i < Lastindex; i++)
			cout << Arr[i] << "  ";
	
	}

	T Dequeue()
	{

		if (Lastindex >= 1)
		{

			T Temp = Arr[1];
			Heapify_Down();
			return Temp;
		}
		return -99;
	}
	
	void Heapify_Down()
	{
		int Current = 1;
		Arr[Current] = Arr[Lastindex-1];
		Lastindex--;
		

		while (Current*2 < Lastindex)
		{

//			Print();
//			cout << endl;

			if (Arr[Current*2 +1] < Arr[Current * 2])
			{
				if (Arr[Current * 2] > Arr[Current])
				{

					Swap(Arr[Current], Arr[Current * 2]);
					Current *= 2;
				}
				else
					break;
			}
			else if (Arr[Current*2] < Arr[Current * 2 + 1])
			{
				if (Arr[Current * 2 + 1] > Arr[Current])
				{
					Swap(Arr[Current], Arr[Current * 2 + 1]);
					Current *= 2 + 1;

				}
				else
					break;
			}
			else
				break;

		}	

	}




	~Max_Heap(){ ; }
};

