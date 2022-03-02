#pragma once

#include<iostream>
#include<stack>
using namespace std;

template<typename T,typename K>
struct TNode
{
	K key;
	T value;
	int Height;

	TNode<T, K> *Parent;
	TNode<T, K> *Leftchild;
	TNode<T, K> *Rightchild;

};

template<typename T, typename K>
class BST
{


	void RecurrsionDelete(TNode<T, K> *Current, T val)
	{
		if (Current->value == val)
		{
			TNode<T, K>* Temp = findLeftMax(Current, Current->Leftchild);/// FINDS THE LEFT CHILD MAX VALUE TO REPLACE
			Current->key = Temp->key;
			Current->value = Temp->value;
			delete Temp;

		}
		else if (val > Current->value)
		{
			RecurrsionDelete(Current->Rightchild, val);

		}
		else
		{
			RecurrsionDelete(Current->Leftchild, val);
		}

	}
	bool Check_key_Recur(TNode<T, K> *Current, K key, T val)
	{
		if (Current)
		{
			if (Current->key == key)                                  //////   UPDATES ONLY IF THE PROPERTIES OF BST REMAIN INTACT
			{
				if (Current->Rightchild != nullptr  && Current->Leftchild != nullptr)
				{
					if (val < Current->Rightchild->value  && val > Current->Leftchild->value)
					{
						Current->value = val;
						return 1;
					}
				}
				else if (Current->Rightchild != nullptr)
				{
					if (val < Current->Rightchild->value)
					{
						Current->value = val;
						return 1;
					}
				}
				else if (Current->Leftchild != nullptr)
				{
					if (val > Current->Leftchild->value)
					{
						Current->value = val;
						return 1;
					}
				}
				else
				{
					Current->value = val;
					return 1;
				}


			}
			else
			{
				if (Check_key_Recur(Current->Leftchild, key, val))
				{
					return 1;
				}
				else
					return (Check_key_Recur(Current->Rightchild, key, val));

			}
		}
		else
			return 0;

	}
	void InsertRec(TNode<T, K> *Current, K key, T val)
	{
		if (Current == nullptr)
		{
			TNode<T, K> *temp = new TNode<T, K>();
			temp->key = key;
			temp->value = val;
			temp->Leftchild = nullptr;
			temp->Rightchild = nullptr;
			Current = temp;
			root = Current;

		}
		else
		{
			if (val > Current->value)
			{
				if (Current->Rightchild == nullptr)
				{
					TNode<T, K> *temp = new TNode<T, K>();
					temp->key = key;
					temp->value = val;
					temp->Leftchild = nullptr;
					temp->Rightchild = nullptr;
					Current->Rightchild = temp;

				}
				else
					InsertRec(Current->Rightchild, key, val);
			}
			else
			{
				if (Current->Leftchild == nullptr)
				{
					TNode<T, K> *temp = new TNode<T, K>();
					temp->key = key;
					temp->value = val;
					temp->Leftchild = nullptr;
					temp->Rightchild = nullptr;
					Current->Leftchild = temp;

				}
				else
					InsertRec(Current->Leftchild, key, val);
			}

		}
	}

	/*	void InsertRec(TNode<T, K> *Current, K key, T val)
		{
		if (Current == nullptr)
		{
		TNode<T, K> *temp = new TNode<T, K>();
		temp->key = key;
		temp->value = val;
		temp->Leftchild = nullptr;
		temp->Rightchild = nullptr;
		temp->Parent = nullptr;
		temp->Height = 1;
		Current = temp;
		root = Current;

		}
		else
		{
		if (val > Current->value)
		{
		if (Current->Rightchild == nullptr)
		{
		TNode<T, K> *temp = new TNode<T, K>();
		temp->key = key;
		temp->value = val;
		temp->Parent = Current;
		temp->Leftchild = nullptr;
		temp->Rightchild = nullptr;
		temp->Height = 1;

		Current->Rightchild = temp;
		Current->Height++;
		}
		else
		{
		InsertRec(Current->Rightchild, key, val);
		if (Current->Leftchild)
		{
		if (Current->Rightchild)
		{
		Current->Height = Max(Current->Leftchild->Height, Current->Rightchild->Height) + 1;
		}
		else
		Current->Height = Current->Leftchild->Height + 1;
		}
		else
		Current->Height = Current->Rightchild->Height + 1;
		}
		}
		else
		{
		if (Current->Leftchild == nullptr)
		{
		TNode<T, K> *temp = new TNode<T, K>();
		temp->key = key;
		temp->value = val;
		temp->Leftchild = nullptr;
		temp->Rightchild = nullptr;
		temp->Parent = Current;
		temp->Height = 1;
		Current->Leftchild = temp;
		Current->Height++;
		}
		else
		{
		InsertRec(Current->Leftchild, key, val);
		if (Current->Leftchild)
		{
		if (Current->Rightchild)
		{
		Current->Height = Max(Current->Leftchild->Height, Current->Rightchild->Height) + 1;
		}
		else
		Current->Height = Current->Leftchild->Height + 1;
		}
		else
		Current->Height = Current->Rightchild->Height + 1;


		}

		}

		}
		}

		int Max(int a, int b)
		{
		if (a > b)
		return a;
		else
		return b;


		}
		*/
public:

	TNode<T, K> *root;

	BST()
	{
		root = nullptr;
	}

	void InsertUsingRec(K key, T value = 0)
	{
		value = key;

		if (!Check_key_Recur(root, key, value))
			InsertRec(root, key, value);

	}


	void Print()
	{


		TNode<T, K>* C = root;

		C = root->Leftchild;

		C = C->Parent;

		C = root->Rightchild;

		C = C->Parent;



		cout << root->value;
		cout << root->Leftchild->value;
		cout << root->Rightchild->value;

	}
	void Insert(K key, T val)
	{

		TNode<T, K> *Current = root;

		if (root == nullptr)
		{
			TNode<T, K> *temp = new TNode<T, K>();
			temp->key = key;
			temp->value = val;
			temp->Leftchild = nullptr;
			temp->Rightchild = nullptr;
			root = temp;
		}
		else
		{

			while (1)
			{
				if (Current->value > val)
				{
					if (Current->Leftchild != nullptr)
					{
						Current = Current->Leftchild;
					}
					else
					{
						TNode<T, K> *temp = new TNode<T, K>();
						temp->key = key;
						temp->value = val;
						temp->Leftchild = nullptr;
						temp->Rightchild = nullptr;
						Current->Leftchild = temp;
						break;
					}

				}
				else
				{
					if (Current->Rightchild != nullptr)
					{
						Current = Current->Rightchild;
					}
					else
					{
						TNode<T, K> *temp = new TNode<T, K>();
						temp->key = key;
						temp->value = val;
						temp->Leftchild = nullptr;
						temp->Rightchild = nullptr;
						Current->Rightchild = temp;
						break;
					}
				}
			}
		}

	}


	void Search(K key)
	{
		SearchRec(root, key);

	}
	TNode<T, K>* SearchRec(TNode<T, K> *Current, K key)
	{
		if (Current)
		{
			if (Current->key == key)
			{

				return Current;
			}
			else
			{
				TNode<T, K> *temp = SearchRec(TNode<T, K> *Current->Leftchild, K key);
				if (temp != nullptr)
					return temp;


				return SearchRec(TNode<T, K> *Current->Rightchild, K key);

			}
		}
		else
			return nullptr;

	}








	int Count()
	{
		int C = 0;
		CountRec(root, C);
		return C;
	}
	void CountRec(TNode<T, K> *Current, int &C)
	{
		if (Current)
		{
			C++;
			CountRec(Current->Leftchild, C);
			CountRec(Current->Rightchild, C);

		}

	}

	void InOrder(TNode<T, K> *Current)
	{
		if (Current)
		{


			InOrder(Current->Leftchild);


			cout << Current->value << "." << Current->Height << "  ";

			InOrder(Current->Rightchild);


		}

	}

	void PreOrder(TNode<T, K> *Current)
	{
		if (Current)
		{
			cout << Current->value << "  ";
			PreOrder(Current->Leftchild);
			PreOrder(Current->Rightchild);
		}
	}

	void PostOrder(TNode <T, K>*Current)
	{

		if (Current)
		{
			PostOrder(Current->Leftchild);
			PostOrder(Current->Rightchild);
			cout << Current->value << "  ";
		}

	}
	void PrintInOrderRec()
	{
		TNode<T, K> *Current = root;
		InOrder(root);
	}
	void PrintPreOrderRec()
	{
		TNode<T, K> *Current = root;
		PreOrder(root);

	}
	void PrintPostOrderRec()
	{
		TNode<T, K> *Current = root;
		PostOrder(root);

	}
	void PrintInorder()
	{
		TNode<T, K> *Current = root;


		if (Current != nullptr)
		{

			stack<TNode<T, K>*> S;

			while (1)
			{
				if (Current != nullptr)
				{
					S.push(Current);
					Current = Current->Leftchild;
				}
				else if (S.empty())
				{
					break;
				}
				else if (Current == nullptr)
				{


					Current = S.top();
					S.pop();
					cout << Current->value << "  ";
					Current = Current->Rightchild;

				}
			}

		}




	}
	void PrintPreOrder()
	{
		TNode<T, K> *Current = root;

		if (Current != nullptr)
		{

			stack<TNode<T, K>*> S;
			while (1)
			{
				if (Current != nullptr)
				{
					cout << Current->value << "  ";
					S.push(Current);
					Current = Current->Leftchild;
				}
				else if (S.empty())
				{
					break;
				}
				else
				{
					Current = S.top();
					S.pop();
					Current = Current->Rightchild;

				}

			}

		}

	}
	void PrintPostOrder()
	{
		TNode<T, K> *Current = root;
		TNode<T, K> *temp = nullptr;
		if (Current != nullptr)
		{
			stack<TNode<T, K>*> S;

			while (1)
			{
				if (Current)
				{
					S.push(Current);

					if (Current->Leftchild == nullptr)
					{
						Current = Current->Rightchild;
					}
					else
						Current = Current->Leftchild;

				}
				else
				{
					Current = S.top();
					S.pop();
					cout << Current->value << "  ";
					if (S.empty())
					{
						break;
					}

					temp = S.top();

					if (temp->Leftchild == Current)
					{
						if (temp->Rightchild != nullptr)
						{
							Current = temp->Rightchild;
						}

					}
					else
						Current = nullptr;

				}
			}
		}
	}
	void DeleteRec(T val)
	{
		RecurrsionDelete(root, val);
	}
	TNode<T, K>* findLeftMax(TNode<T, K> *Parent, TNode<T, K> *Current)
	{

		if (Current != nullptr)
		{
			if (Current->Rightchild == nullptr)
			{
				if (Current == Parent->Leftchild)
				{
					Parent->Leftchild = Current->Leftchild;
				}
				else
					Parent->Rightchild = Current->Leftchild;



				return Current;
			}
			else
			{

				TNode<T, K>* Temp = findLeftMax(Current, Current->Rightchild);
				if (Temp)
				{

					return Temp;
				}
				else
					return Parent;
			}
		}
		return nullptr;

	}
	void Delete(T key)
	{
		TNode<T, K> *Current = root;
		bool found = false;


		while (Current != nullptr && !found)
		{
			if (Current->key == key)
			{
				TNode<T, K>* Temp = findLeftMax(Current, Current->Leftchild);
				if (Temp)
				{
					Current->key = Temp->key;
					Current->value = Temp->value;
				}
				else if (Current->Rightchild)
					Current = Current->Rightchild;


			}
			else if (Current->Leftchild && Current->Leftchild->key == key)
			{
				found = true;
				TNode<T, K>* Temp = findLeftMax(Current->Leftchild, Current->Leftchild->Leftchild);
				if (Temp)
				{
					Current->Leftchild->key = Temp->key;
					Current->Leftchild->value = Temp->value;
				}
				else
					Current->Leftchild = Current->Leftchild->Rightchild;

			}
			else if (Current->Rightchild && Current->Rightchild->key == key)
			{
				found = true;
				TNode<T, K>* Temp = findLeftMax(Current->Rightchild, Current->Rightchild->Leftchild);
				if (Temp)
				{
					Current->Rightchild->key = Temp->key;
					Current->Rightchild->value = Temp->value;
				}
				else
					Current->Rightchild = Current->Rightchild->Rightchild;
			}
			else if (key > Current->key)
			{
				Current = Current->Rightchild;

			}
			else if (key < Current->key)
			{
				Current = Current->Leftchild;
			}
			else
				cout << "\nNOT PRESENT " << endl;


		}
	}





	~BST(){ ; }
};

