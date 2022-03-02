#pragma once
#include<iostream>
using namespace std;
#include<queue>
#include<stack>

class Graph
{

private:
	int **Matrix;
	int Max_Nodes;
	int *Visited;
	int *SPT;

public:
	Graph(int Max = 5)
	{
		Max_Nodes = Max;
		Matrix = new int*[Max_Nodes];
		for (int i = 0; i < Max_Nodes; i++)
		{
			Matrix[i] = new int[Max_Nodes];
			for (int c = 0; c < Max_Nodes; c++)
			{
				Matrix[i][c] = 0;

			}
		}
		SPT = new int[Max_Nodes];
		Visited = new int[Max_Nodes];
	
	}

	void SetEdge(int V1,int V2,int W=1)
	{
	
			
		Matrix[V1][V2] = W;
	
	
	}
	void DeleteEdge(int V1, int V2)
	{


		Matrix[V1][V2] = 0;

	}
	int Weight(int V1, int V2)
	{
		return Matrix[V1][V2];
		
	}
	int first(int T)
	{
		
		if (T >= 0 && T < Max_Nodes)
		{
			for (int i = 0; i < Max_Nodes; i++)
			{
				if (Matrix[T][i] == 1)
				{
					return i;
				}

			}

		}
		
		return -1;
	}
	int Next(int V1 , int V2)
	{

		if (V1 >= 0 && V1 < Max_Nodes)
		{
			for (int i = V2+1; i < Max_Nodes; i++)
			{
				if (Matrix[V1][i] == 1)
				{
					return i;
				}

			}

		}

		return -1;
	}

	void Print()
	{
		
		for (int i = 0; i < Max_Nodes; i++)
		{
			for (int c = 0; c < Max_Nodes; c++)
			{
				cout << Matrix[i][c] << " ";
			}
			cout << endl;

		}
	
	
	
	
	}


	void SetVisitedToNull()
	{
	
		for (int i = 0; i < Max_Nodes; i++)
		{
			Visited[i] = 0;
		}
	
	
	}

	void BFS()
	{

		queue<int>Q;

		int Currenti = 0;
		int Currentj = 0;
		bool found = false;
		for (int i = 0; i < Max_Nodes; i++)                 ///FINDING THE FIRST 1 To start with
		{
			for (int c = 0; c < Max_Nodes; c++)
			{
				if (Matrix[i][c] == 1 && found == false)
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

				for (int i = 0; i < Max_Nodes; i++)
				{
					if (Matrix[t][i] == 1)
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
		for (int i = 0; i < Max_Nodes && found == false; i++)                 ///FINDING THE FIRST 1 To start with
		{
			for (int c = 0; c < Max_Nodes && found ==false; c++)
			{
				if (Matrix[i][c] == 1)
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
			int col; found  =false;
			for (col = 0; found == false && col < Max_Nodes; col++)
			{
				if (Matrix[t][col] == 1)
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
		for (int i = 0; i < Max_Nodes && found == false; i++)                 ///FINDING THE FIRST 1 To start with
		{
			for (int c = 0; c < Max_Nodes && found == false; c++)
			{
				if (Matrix[i][c] == 1)
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
		for (int c = 0; c < Max_Nodes; c++)
		{
			if (Matrix[i][c] == 1)
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

		for (int i = 0; i < Max_Nodes; i++)
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
	void Dijkstra(int start,int end)
	{

		int *PreNode = new int[Max_Nodes];
		int No_of_Visited_nodes = 0;



		for (int a = 0; a < Max_Nodes; a++)
		{
				SPT[a] = 99;
				PreNode[a] = 99;

		}
		SPT[start] = 0;
		
		int Current = start;

		while (No_of_Visited_nodes != Max_Nodes)
		{
			for (int i = 0; i < Max_Nodes; i++)
			{

				if (Matrix[Current][i] != 0)
				{
					if (Visited[i] != 1)
					{

						if (SPT[Current] + Matrix[Current][i] < SPT[i])
						{
							SPT[i] = SPT[Current] + Matrix[Current][i];
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

	~Graph(){ ; }

};
