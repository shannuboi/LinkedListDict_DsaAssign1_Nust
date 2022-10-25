#pragma once

#include <assert.h>

template <typename T>
class List_Node{   //class definition of Node 
  public:
    T data;
    List_Node<T> *next;
};

template <typename T>
class SinglyLinkedList
{
public:
	SinglyLinkedList() = default;
	~SinglyLinkedList()
	{
		ClearList();
	}
	SinglyLinkedList(const SinglyLinkedList & src)
	{
		*this = src;
	}
	void operator=(const SinglyLinkedList & rhs)
	{
		if (this != &rhs)
		{
			ClearList();

			const List_Node<T>* rhsptr = rhs.start;
			for (int i = 0; rhsptr; i++) // loop until rhsptr becomes null
			{
				Insert(rhsptr->data, i);
				rhsptr = rhsptr->next;
			}
		}
	}
	bool IsEmpty() const
	{
		return !start; // if start hold nothing return true
	}
	int GetLength() const
	{
		int count = 0;
		for (List_Node<T>* cur = start; cur; cur = cur->next) // loop until cur becomes null
		{
			count++;
		}
		return count;
	}
	bool Search(T d) const
	{
		for (List_Node<T>* cur = start; cur; cur = cur->next) // loop until cur becomes null
		{
			if (cur->data == d) return true;
		}
		return false;
	}
	// First pos is zero
	void Insert(T d, int pos = 0)
	{
		assert(pos >= 0 && pos <= GetLength());
		if (pos == 0)
		{
			List_Node<T>* newnode = new List_Node<T>;
			newnode->data = d;
			newnode->next = start;
			start = newnode;
		}
		else
		{
			InsertAfter(d, start, pos - 1); // minus one sice insert after
		}
	}
	void Delete(T d)
	{
		List_Node<T>* cur = start;
		List_Node<T>* last = nullptr;
		while (cur && cur->data != d) // loop until cur becomes null
		{
			last = cur;
			cur = cur->next;
		}

		if (cur) // if item found
		{
			if (last) //if it not start
			{
				last->next = cur->next;
				delete cur;
			}
			else // if it is start
			{
				start = cur->next;
				delete cur;
			}
		}
	}
	void ClearList()
	{
		for (List_Node<T>* cur = start; cur;) // loop until cur becomes null
		{
			List_Node<T>* temp = cur;
			cur = cur->next;
			delete temp;
		}
		start = nullptr;
	}

	List_Node<T>* start = nullptr;
private:
	// Since it will insert after a node, pos acts like pos + 1 (Insertion happens after specified pos)  
	void InsertAfter(T d, List_Node<T> * node, int pos)
	{
		if (pos == 0)
		{
			List_Node<T>* newnode = new List_Node<T>;
			newnode->data = d;
			newnode->next = node->next;
			node->next = newnode;
		}
		else
		{
			InsertAfter(d, node->next, pos - 1);
		}
	}
};

typedef List_Node<Dictionary> ListNode;