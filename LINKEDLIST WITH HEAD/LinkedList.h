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





template <class T>
class LinkedList
{
private:

	Node<T> *head;

public:
	LinkedList()
	{
		head = nullptr;
	}
	void insertatend(T V)
	{

		if (head == nullptr)
		{

			Node<T> *temp = new Node<T>();
			temp->data = V;
			temp->next = nullptr;
			head = temp;
		}
		else
		{
			Node<T> *Current = head;
			for (; Current->next != nullptr; Current = Current->next);

			Node<T> *temp = new Node<T>();
			temp->data = V;
			temp->next = nullptr;
			Current->next = temp;
		}


	}
	void InsertAtBegin(T V)
	{
		if (head == nullptr)
		{

			Node<T> *temp = new Node<T>();
			temp->data = V;
			temp->next = nullptr;
			head = temp;

		}
		else
		{
			Node<T> *Current = new Node<T>();
			Current->data = V;
			Current->next = head;
			head = Current;
		}
	}
	bool Insert(T v1, T v2)
	{
		bool found = 0;

		Node<T> *Current = head;
		Node <T>* Previous = nullptr;

		while (Current->next != nullptr)
		{

			if (Current->data == v2)
			{
				found = true;
				Previous = Current;
				
			}
			Current = Current->next;

		}

		if (found)
		{

			Node<T>* temp = new Node<T>();
			temp->data = v1;
			temp->next = Current;
			Previous->next = temp;
		}
		return found;

	}



	bool Is_empty()
	{
		if (head == nullptr)
		{
			return 1;
		}
	
		return 0;

	}
			

	void DeleteAll(int v)
	{
		Node<T>* Current = head;
		Node<T>* previous = nullptr;

		while( Current != nullptr)
		{
		
			if (Current->data == v)
			{
				previous->next = Current->next;
				Current = previous;
			}
			else
			{
				previous = Current;
				Current = Current->next;
			}
		}

	}

	void DeletefromStart()
	{

		head = head->next;

	}



	void Print()
	{

		for (Node<T>* Current = head; Current != nullptr; Current = Current->next)
		{
			cout << Current->data << "  ";

		}

	}
	~LinkedList()
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

