#pragma once

#include <assert.h>

template <typename T>
class ListNode{   //class definition of Node 
  public:
    T data;
    ListNode *next;
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

			const ListNode* rhsptr = rhs.start;
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
		for (ListNode* cur = start; cur; cur = cur->next) // loop until cur becomes null
		{
			count++;
		}
		return count;
	}
	bool Search(T d) const
	{
		for (ListNode* cur = start; cur; cur = cur->next) // loop until cur becomes null
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
			ListNode* newnode = new ListNode;
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
		ListNode* cur = start;
		ListNode* last = nullptr;
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
		for (ListNode* cur = start; cur;) // loop until cur becomes null
		{
			ListNode* temp = cur;
			cur = cur->next;
			delete temp;
		}
		start = nullptr;
	}

protected:
	typedef ListNode<T> ListNode;

	// Since it will insert after a node, pos acts like pos + 1 (Insertion happens after specified pos)  
	void InsertAfter(T d, ListNode * node, int pos)
	{
		if (pos == 0)
		{
			ListNode* newnode = new ListNode;
			newnode->data = d;
			newnode->next = node->next;
			node->next = newnode;
		}
		else
		{
			InsertAfter(d, node->next, pos - 1);
		}
	}
	ListNode* start = nullptr;
};