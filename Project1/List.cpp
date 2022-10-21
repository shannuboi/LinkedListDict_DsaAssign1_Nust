#include "List.h"
#include <assert.h>

SinglyLinkedList::~SinglyLinkedList()
{
	ClearList();
}

SinglyLinkedList::SinglyLinkedList(const SinglyLinkedList & src)
{
	*this = src;
}

void SinglyLinkedList::operator=(const SinglyLinkedList & rhs)
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

bool SinglyLinkedList::IsEmpty() const
{
	return !start; // if start hold nothing return true
}

int SinglyLinkedList::GetLength() const
{
	int count = 0;
	for (ListNode* cur = start; cur; cur = cur->next) // loop until cur becomes null
	{
		count++;
	}
	return count;
}

bool SinglyLinkedList::Search(Dictionary d) const
{
	for (ListNode* cur = start; cur; cur = cur->next) // loop until cur becomes null
	{
		if (cur->data == d) return true;
	}
	return false;
}

// First pos is zero
void SinglyLinkedList::Insert(Dictionary d, int pos)
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
		InsertAfter(d, start, pos-1); // minus one sice insert after
	}
}

void SinglyLinkedList::Delete(Dictionary d)
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

void SinglyLinkedList::ClearList()
{
	for (ListNode* cur = start; cur;) // loop until cur becomes null
	{
		ListNode* temp = cur;
		cur = cur->next;
		delete temp;
	}
	start = nullptr;
}

// Since it will insert after a node, pos acts like pos + 1 (Insertion happens after specified pos)  
void SinglyLinkedList::InsertAfter(Dictionary d, ListNode * node, int pos)
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
