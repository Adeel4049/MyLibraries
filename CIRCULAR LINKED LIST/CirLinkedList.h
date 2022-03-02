#pragma once
#include"Node.h"
template<typename T>
class CirLinkedList
{

private:

	Node<T> *head;

public:
	CirLinkedList()
	{
		head = nullptr;
	}
	CirLinkedList(Linked_List<T> &obj)
	{

		for (Node<T>* objCurrent = obj.head; objCurrent != obj.head; objCurrent = objCurrent->next)
		{
			Node<T>* Current = this->head;
			for (; Current != obj.head; Current = Current->next);

			Node<T> *temp = new Node<T>();
			temp->data = objCurrent->data;
			temp->next = nullptr;
			Current = temp;

		}



	}





	bool Search(T V)
	{

		Node<T> * Current = head;
		do
		{
			if (Current->data == data)
			{
				return 1;
			}

			Current = Current->next;

		} while (Current != head);

		return 0;

	}

	void insertAtEnd(T V)
	{

		if (head == nullptr)
		{

			Node<T> *temp = new Node<T>();
			temp->data = V;
			temp->next = nullptr;
			head = temp;
			head->next = head;

		}
		else
		{
			Node<T> *Current = head;
			for (; Current->next != head; Current = Current->next);

			Node<T> *temp = new Node<T>();
			temp->data = V;
			temp->next = head;
			Current->next = temp;
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
			head->next = head;

		}
		else
		{
			Node<T> *temp = new Node<T>();
			temp->data = V;
			temp->next = head;

			Node<T>* Current = head;
			for (; Current->next != head; Current = Current->next);

			head = temp;
			Current->next = head;
	
		}

	}

	bool InsertBefore(T v1, T v2)
	{
		bool found = 0;

		Node<T> *Current = head;
		Node <T>* Previous = nullptr;


		if (Current->data == v2)
		{
			found = true;
			this->InsertAtStart(v1);
			return found;

		}

		Current = Current->next;

		while (Current != head)
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
				Node<T>* temp = new Node<T>();
				temp->data = v1;
				temp->next = Current;
				Previous->next = temp;
		}
		return found;

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
			Node<T> * dummy = head;
			for (; dummy->next != head; dummy = dummy->next)
			{

			}
			
			head = head->next;
			delete Current;

			dummy->next = head;


			

		}

	}

	void DeleteAll(int v)
	{
		Node<T>* Current = head;
		Node<T>* previous = nullptr;

		do	{

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

		} while (Current->next != head);


		if (Current->data == v)            //    It handles the case where data is at the start and end of array
		{
			previous->next = head;
			delete Current;
		}
	}





	void Print()
{
	Node<T> * Current = head;
	
	if (Current != nullptr)
	{
		do
		{

			cout << Current->data << " ";
			Current = Current->next;

		} while (Current != head);
	}
}

	~CirLinkedList()
	{

		Node<T> *temp = head;
		Node<T> *Current = nullptr;
		
		head = head->next;

		while (head != temp)
		{
			Current = head;
			head = head->next;
			delete Current;

		}

		delete temp;


	}



};

