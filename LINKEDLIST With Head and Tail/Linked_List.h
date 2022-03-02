#pragma once
#include<iostream>
using namespace std;
template<typename T>
class Node
{
public:

	T data;
	Node *next;
	Node(){ ; }
	~Node(){ ; }
};





template<typename T>
class Linked_List
{

public:

	Node<T> *head;
	Node<T> *tail;


	Linked_List()
	{
		head = nullptr;
		tail = nullptr;
	}
	Linked_List(Linked_List<T> &obj)
	{

		for(Node<T>* objCurrent = obj.head; objCurrent != nullptr; objCurrent = objCurrent->next)
		{
			Node<T>* Current = this->head;
			for (; Current != nullptr; Current = Current->next);

				Node<T> *temp = new Node<T>();
				temp->data = objCurrent->data;
				temp->next = nullptr;
				Current = temp;
		
		}
		
		

	}


	void InsertAtEnd(T V)
	{
		if (head == nullptr)
		{

			Node<T> *temp = new Node<T>();
			temp->data = V;
			temp->next = nullptr;
			head = temp;
			tail = head;
		}
		else
		{

			Node<T> *temp = new Node<T>();
			temp->data = V;
			temp->next = nullptr;
			tail->next = temp;
			tail = temp;
		}	
	}
	void InsertAtStart(T V)
	{
	
		if (head == nullptr)
		{
			Node<T> *temp = new Node<T>();
			temp->data = V;
			temp->next = nullptr;
			head = temp;
			tail = head;
		}
		else
		{
			Node<T> *temp = new Node<T>();
			temp->data = V;
			temp->next = nullptr;
			temp->next = head;
			head = temp;
		}
				
	}
	bool Search(int v)
	{
		for (Node<T>* Current = head; Current != nullptr; Current = Current->next)
		{
			if (Current->data == v)
			{
				return true;
			}
		}

		return false;
	}
	bool Is_empty()
	{
		if (tail == nullptr)
		{
			return 1;
		}

		return 0;

	}
	bool Insert(T v1, T v2)
	{
		bool found = 0;

		Node<T> *Current = head;
		Node <T>* Previous = nullptr;

		while (Current!= nullptr) 
		{
			if (Current->data == v2)
			{
				found = true;
				break;

			}
			Previous = Current;
			Current = Current->next;
		}



		if (found)
		{
			if (Current == head)
			{
				this->InsertAtStart(v1);

			}
			else
			{

				Node<T>* temp = new Node<T>();
				temp->data = v1;
				temp->next = Current;
				Previous->next = temp;
			}
		}
		return found;

	}
	Linked_List<T> MidFind(Linked_List<T> &obj)
	{
		int total = 0;
		for (Node<T>* Current = obj.head; Current != nullptr; total++, Current = Current->next);
	
		int c = 0;
		Node<T>* Current = obj.head;
		
		for (; c < total / 2; Current = Current->next,c++)
		{

		}
		
		cout << "MID IS : " << Current->data << endl;

		return obj;

	}

	void Print()
	{

		for (Node<T>* Current = head; Current != nullptr; Current = Current->next)
		{
			cout << Current->data << "  ";

		}

	}

	void DeletefromStart()
	{

		if (head->next == nullptr)
		{
			delete head;
			head = nullptr;
		}
		else
		{
			Node<T> * Current = head;
			head = head->next;
			delete Current;

		}

	}

	void DeleteAll(int v)
	{
		Node<T>* Current = head;
		Node<T>* previous = nullptr;

		while (Current != nullptr)
		{

			if (Current->data == v)
			{
				if (Current == head)
				{
					Current = Current->next;
					DeletefromStart();
				
				}
				else
				{
					previous->next = Current->next;
					delete Current;
					Current = previous->next;
				}
			}
			else
			{
				previous = Current;
				Current = Current->next;
			}
		}

	}

*
	
	void operator+=(T V)
	{
	
		this->InsertAtEnd(V);
		
	
	}
/*	T operator[](int index)
	{

		Node<T> * Current = head;
		for (int i = 0; i <= index || Current != nullptr; i++)
		{
			Current = Current->next;

		}

		if (Current != nullptr)
			return Current->data;
		else
			return -99;


	}
	*/

	~Linked_List()
	{
		Node<T> *Current;
		while (head != nullptr)
		{
			Current = head;
			head = head->next;


			delete Current;

		}
	}


};

