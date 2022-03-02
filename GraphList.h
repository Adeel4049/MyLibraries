#pragma once
#include<queue>
#include<stack>
#include<iostream>
using namespace std;

template<typename T>
class Node
{
public:

	T data;
	T vertex;

	Node *next;
	Node(){ ; }
	~Node(){ ; }
};
template <class T>
class LinkedList
{
private:

	Node<T> *head;
	Node<T> *tail;

public:
	LinkedList()
	{
		head = nullptr;
		tail = nullptr;
	}
	void insertatend(T V, T W)
	{
		if (head == nullptr)
		{

			Node<T> *temp = new Node<T>();
			temp->data = W;
			temp->vertex = V;
			temp->next = nullptr;
			head = temp;
		}
		else
		{
			Node<T> *Current = head;
			for (; Current->next != nullptr; Current = Current->next);

			Node<T> *temp = new Node<T>();
			temp->data = W;
			temp->vertex = V;
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

	void InsertAtTail(T V)
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

	void Print()
	{

		for (Node<T>* Current = head; Current != nullptr; Current = Current->next)
		{
			cout << Current->vertex << "  ";// << "." << Current->data << "  ";

		}

	}


	T WieghtIfExist(int no)
	{
		Node<T>*Current = head;
		for (; Current != nullptr; Current = Current->next)
		{
			if (Current->vertex == no)
			{
				T temp = Current->data;
				return temp;
			}

		}


		return 0;

	}
	int Size()
	{
		Node<T>*Current = head;
		int i = 0;
		for (; Current != nullptr; Current = Current->next)
		{
			i++;
		}
	
		return i;

	}

	bool Is_empty()
	{
		if (head == nullptr)
		{
			return 1;
		}

		return 0;

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


class GraphList
{

	LinkedList<int>*List;
	int Max_nodes;
	int *Visited;
	int *SPT;


public:
	GraphList(int s=5)
	{

		Max_nodes = s;
		Visited = new int[Max_nodes];
		List = new LinkedList<int>[Max_nodes];	
		SPT = new int[Max_nodes];

	}
	void SetEdge(int V1, int V2, int W=1)
	{
		
		List[V1].insertatend(V2,W);

	}
	
	void SetVisitedToNull()
	{

		for (int i = 0; i < Max_nodes; i++)
		{
			Visited[i] = 0;
		}


	}
	void Print()
	{
		
		for (int i = 0; i < Max_nodes; i++)
		{
			
			cout << i << "   ";
			List[i].Print();
			cout << endl;

		}
		
			
	}
	
	void BFS()
	{
		queue<int>Q;

		int Currenti = 0;
		int Currentj = 0;
		bool found = false;
		for (int i = 0; i < Max_nodes; i++)                 ///FINDING THE FIRST 1 To start with
		{
			for (int c = 0; c < Max_nodes; c++)
			{
				
				if (List[i].WieghtIfExist(c) != 0 && found == false)
				{
					Currenti = i;
					Currentj = c;
					found = true;

				}

			}
		}


	
			cout << "BFS TRAVERSE WILL BE ::  ";

			cout << Currenti << "  ";
			Visited[Currenti] = 1;

			Q.push(Currenti);


			while (!Q.empty())
			{

				int t = Q.front();
				Q.pop();

				for (int i = 0; i < Max_nodes; i++)
				{
					if (List[t].WieghtIfExist(i) != 0)
					{

						if (Visited[i] != 1)
						{
							cout << i << "  ";
							Q.push(i);
							Visited[i] = 1;

						}
					}

				}


			}
	}

	void DFS()
	{

		stack<int>S;

		int Currenti = 0;
		int Currentj = 0;
		bool found = false;
		for (int i = 0; i < Max_nodes && found == false; i++)                 ///FINDING THE FIRST 1 To start with
		{
			for (int c = 0; c < Max_nodes && found == false; c++)
			{
				if (List[i].WieghtIfExist(c) != 0)
				{
					Currenti = i;
					Currentj = c;
					found = true;

				}

			}
		}


		S.push(Currenti);

		cout << "DFS TRAVERSAL ::  ";
		cout << Currenti << "  ";
		Visited[Currenti] = 1;


		while (!S.empty())
		{
			int t = S.top();


			int col; found = false;
			for (col = 0; found == false && col < Max_nodes; col++)
			{
				if (List[t].WieghtIfExist(col) != 0)
				{
					if (Visited[col] != 1)
					{

						found = true;
						col--;
					}
				}

			}

			if (found)
			{
				cout << col << "  ";
				Visited[col] = 1;
				S.push(col);
			}
			else
			{
				S.pop();
			}


		}


	}

	void DFSREC()
	{
		int Currenti = 0;
		int Currentj = 0;
		bool found = false;
		for (int i = 0; i < Max_nodes && found == false; i++)                 ///FINDING THE FIRST 1 To start with
		{
			for (int c = 0; c < Max_nodes && found == false; c++)
			{
				if (List[i].WieghtIfExist(c) == 1)
				{
					Currenti = i;
					Currentj = c;
					found = true;

				}

			}
		}


		cout << "DFS WITH RECURSSION :: ";
		Recurrsion(Currenti);




	}

	void Recurrsion(int i)
	{

		if (Visited[i] != 1)
		{

			cout << i << " ";
			Visited[i] = 1;
		}
		for (int c = 0; c < Max_nodes; c++)
		{
			if (List[i].WieghtIfExist(c) == 1)
			{
				if (Visited[c] != 1)
				{
					Recurrsion(c);


				}
			}


		}





	}


	int NextSmallestVertex()
	{

		int min = INT_MAX;
		int minvertex = 0;

		for (int i = 0; i < Max_nodes; i++)
		{
			if (SPT[i] < min && SPT[i] != 0)
			{
				if (Visited[i] != 1)
				{
					minvertex = i;
					min = SPT[i];
				}
			}

		}

		return minvertex;

	}

	void Dijkstra(int start, int end)
	{

		int *PreNode = new int[Max_nodes];
		int No_of_Visited_nodes = 0;

		for (int a = 0; a < Max_nodes; a++)
		{
			SPT[a] = 99;
			PreNode[a] = 99;

		}
		SPT[start] = 0;

		int Current = start;

		while (No_of_Visited_nodes != Max_nodes)
		{
			for (int i = 0; i < Max_nodes; i++)
			{

				if (List[Current].WieghtIfExist(i) != 0)
				{

					if (Visited[i] != 1)
					{

						int T = SPT[Current] + List[Current].WieghtIfExist(i);
						if (T < SPT[i])
						{
							SPT[i] = SPT[Current] + List[Current].WieghtIfExist(i);
							PreNode[i] = Current;

						}
					}
				}
				
			}

			No_of_Visited_nodes++;
			Visited[Current] = 1;

			Current = NextSmallestVertex();


		}



		stack<int>obj;

		int z = end;

		while (z != 0)
		{
			int t = PreNode[z];
			obj.push(t);
			z = t;

		}


		cout << "STARTING VERTEX IS " << start << endl << endl;
		cout << "V       SDistance     " << endl;
		cout << end << "      " << SPT[end] << endl << endl;
		cout << "PATH WILL BE :: ";
		while (!obj.empty())
		{
			cout << obj.top() << "---> ";
			obj.pop();

		}
		cout << end << endl;

	}








	~GraphList(){ ; }
};

