#pragma once
#include "BST.h"

template<typename T,typename K>
class AVL : public BST<T, K>
{

	void AdjustHeight(TNode<T, K> *Current)
	{
		if (Current->Leftchild)
		{
			if (Current->Rightchild)
			{
				Current->Height = Max(Current->Leftchild->Height, Current->Rightchild->Height) + 1;
			}
			else
				Current->Height = Current->Leftchild->Height + 1;
		}
		else if (Current->Rightchild)
			Current->Height = Current->Rightchild->Height + 1;
		else
			Current->Height = 1;

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
			temp->Parent = nullptr;
			temp->Height = 1;
			Current = temp;
			root = Current;

		}
		else
		{
			if (key > Current->key)
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
					AdjustHeight(Current);
					////


				}
				else
				{
					InsertRec(Current->Rightchild, key, val);
					AdjustHeight(Current);
					CheckHeight(Current);

				}
			}
			else
		-	{
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

					AdjustHeight(Current);

				}
				else
				{
					InsertRec(Current->Leftchild, key, val);
					AdjustHeight(Current);

					CheckHeight(Current);

				}


			}


		}

	}
	void CheckHeight(TNode<T, K> *Current)
	{
		if (Current->Rightchild)
		{
			if (Current->Leftchild)
			{
				if (Current->Rightchild->Height - Current->Leftchild->Height > 1)
				{
					RotateLeft(Current);                                      ////         L L 
				}
				else if (Current->Leftchild->Height - Current->Rightchild->Height > 1)
					RotateRight(Current);
			}
			else
			{
				if (Current->Rightchild->Height > 1)
				{
					if (Current->Rightchild->Rightchild == nullptr)
					{
						RotateRight(Current->Rightchild);
						RotateLeft(Current);

					}
					else
						RotateLeft(Current);

				}

			}

		}
		else if (Current->Leftchild)
		{
			if (Current->Leftchild->Height > 1)
			{
				if (Current->Leftchild->Leftchild == nullptr)    ////   L R
				{

					RotateLeft(Current->Leftchild);
					//					cout << endl;
					//					BST::PrintInOrderRec();
					//					cout << endl;
					RotateRight(Current);

				}
				else
					RotateRight(Current);


			}

		}

	}
	void RotateLeft(TNode<T, K> *Current)
	{
		TNode<T, K>* temp = Current;
		Current = Current->Rightchild;
		temp->Rightchild = Current->Leftchild;
		Current->Leftchild = temp;

		if (temp->Parent)
		{
			if (temp == temp->Parent->Rightchild)
			{
				temp->Parent->Rightchild = Current;
			}
			else
				temp->Parent->Leftchild = Current;

		}


		Current->Parent = temp->Parent;
		temp->Parent = Current;


		AdjustHeight(temp);
		AdjustHeight(Current);

		if (temp == root)
		{
			root = Current;
		}

	}
	void RotateRight(TNode<T, K> *Current)
	{

		TNode<T, K>* temp = Current;
		Current = Current->Leftchild;
		temp->Leftchild = Current->Rightchild;
		Current->Rightchild = temp;

		if (temp->Parent)
		{
			if (temp == temp->Parent->Rightchild)
			{
				temp->Parent->Rightchild = Current;
			}
			else
				temp->Parent->Leftchild = Current;

		}

		Current->Parent = temp->Parent;
		temp->Parent = Current;

		AdjustHeight(temp);
		AdjustHeight(Current);


		if (temp == root)
		{
			root = Current;
		}

	}

	TNode<T, K>* findLeftMax(TNode<T, K> *Parent, TNode<T, K> *Current)
	{
		if (Current != nullptr)
		{
			if (Current->Rightchild == nullptr)
			{
					
				Current->Height--;

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
				AdjustHeight(Temp);

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

	int Max(int a, int b)
	{
		if (a > b)
			return a;
		else
			return b;


	}

public:
	AVL() :BST()
	{


	}
	void Insert(K _key, T _val = 0)
	{

		_val = _key;
		InsertRec(root, _key, _val);

	}
	void Delete(T key)
	{

		TNode<T, K> *Current = root;
		TNode<T, K>* Temp = nullptr;
		bool found = false;
		while (Current != nullptr && !found)
		{
			if (Current->key == key)
			{
				Temp = findLeftMax(Current, Current->Leftchild);
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
				Temp = findLeftMax(Current->Leftchild, Current->Leftchild->Leftchild);


				if (Temp)
				{
					Current->Leftchild->key = Temp->key;
					Current->Leftchild->value = Temp->value;

					CheckHeight(Temp);
				}
				else
					Current->Leftchild = Current->Leftchild->Rightchild;

			}
			else if (Current->Rightchild && Current->Rightchild->key == key)
			{
				found = true;
				Temp = findLeftMax(Current->Rightchild, Current->Rightchild->Leftchild);
				if (Temp)
				{
					Current->Rightchild->key = Temp->key;
					Current->Rightchild->value = Temp->value;
				}
				else
					Current->Rightchild = Current->Rightchild->Rightchild;


				if (Temp)
				{
					CheckHeight(Temp);
				}
				else
					CheckHeight(Current);



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




			if (found)
			{
				Temp = Current;
				while (Temp != nullptr)
				{
					AdjustHeight(Temp);
					CheckHeight(Temp);
					Temp = Temp->Parent;

				}
			}


		}
	}


	void Search(K _key)
	{
	
		BST::Search(_key);
	
	}


	~AVL(){ ; }
};
