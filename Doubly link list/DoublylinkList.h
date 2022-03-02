#pragma once
//#include"Node.h"
template<typename T>
class Node
{
public:

	T data;
	Node<T>*next;
	Node<T>*previous;


	Node(){ ; }
	~Node(){ ; }
};


template<typename T>
class DoublylinkList
{

private:


public:
	Node<T>* head;
	Node<T>* tail;

	DoublylinkList()
	{

		head = new Node<T>();
		tail = new Node<T>();

		head->data = -1;
		head->previous = nullptr;
		head->next = tail;

		tail->data = -2;
		tail->next = nullptr;
		tail->previous = head;

	}
	void InsertAtStart(T V)
	{
		Node<T>*temp = new Node<T>();
		temp->data = V;
		temp->previous = head;
		temp->next = head->next;


		if (Is_empty())       // it means that initially the list is empty
		{
			tail->previous = temp;

		}
		head->next = temp;

	}
	void InsertAtEnd(T V)
	{
		
		Node<T>*temp = new Node<T>();
		temp->data = V;

		if (Is_empty())       
		{
			head->next = temp;

		}

		tail->previous->next = temp;
		temp->previous = tail->previous;
		tail->previous = temp;
		temp->next = tail;
	
	}
	void DeleteFromStart()
	{
		if (!Is_empty())
		{

			Node<T>* Current = head->next;
			head->next = head->next->next;
			delete Current;
		}
		else
		{
			cout << "LIST IS EMPTY !!!!!!!!!" << endl;
		}
	}
	void DeleteFromEnd()
	{
		if (!Is_empty())
		{
			Node<T>* Current = tail->previous;
			
			Current->previous->next = tail;
			tail->previous = tail->previous->previous;
			delete Current;

		}
		else
		{
			cout << "LIST IS EMPTY !!!!!!!!!" << endl;
		}
	}

	bool Is_empty()
	{
	
		if (head->next == tail)
		{
			return 1;
		}
		
		return 0;
	
	}
	void Print()
	{
		for (Node<T>*Current = head->next; Current != tail; Current = Current->next)
		{
			cout << Current->data << "  ";
		}
		
	}
	

	void Reverse()
	{
		Node<T>*Current = nullptr, *NextNode = nullptr;

		for (Current = head; Current != nullptr ;)
		{
			NextNode = Current->next;

			Current->next = Current->previous;
			Current->previous = NextNode;

			Current = NextNode;


		}
		Current = head;
		head = tail;
		tail = Current;


	}
	void InsertAtMiddle(T V)
	{
		Node<T>* Start = head->next;
		Node<T>*End = tail->previous;

		while (1)
		{

			if (Start->next == End) 
			{
				break;
			}
			if (Start == End)
			{
				break;
			}
			
			Start = Start->next;
			End = End->previous;
		
		}


		Node<T>*temp = new Node<T>();
		temp->data = V;
		temp->next = Start->next;
		temp->previous = Start;
		Start->next = temp;	
	
	}
	bool Insert(T v1, T v2)
	{
		bool found = 0;

		Node<T> *Current = head->next;
		Node <T>* Previous = nullptr;

		while (Current->next != tail)
		{

			if (Current->data == v2)
			{
				found = true;
				Previous = Current->previous;
				break;

			}
			Current = Current->next;

		}

		if (found)
		{

			Node<T>* temp = new Node<T>();
			temp->data = v1;
			
			temp->next = Current;
			temp->previous = Previous;

			Current->previous = temp;
			Previous->next = temp;
		}

		return found;

	}


	void RemoveDuplicate()
	{
		
		for (Node<T>* Current = head->next; Current != tail; Current = Current->next)
		{
			for (Node<T>* InnerCurrent = Current->next; InnerCurrent != tail; )
			{

				Node<T>*Previous = InnerCurrent->previous;

				if (Current->data == InnerCurrent->data)
				{

					Previous->next = InnerCurrent->next;
					InnerCurrent->next->previous = Previous;


					Node<T>*temp = InnerCurrent;
					InnerCurrent = InnerCurrent->next;

					delete temp;

				}
				else
				{
					InnerCurrent = InnerCurrent->next;
					
				}
			}

		}
		
	}



	~DoublylinkList()
	{
	
		for (Node<T>*Current = head->next; Current != tail; )
		{

			Node<T>* temp = Current;
			Current = Current->next;
			delete temp;


		}

		delete head;
		delete tail;
	
	}


};

