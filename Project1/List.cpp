#include "List.h"

bool SinglyLinkedList::IsEmpty() const
{
	return !start; // if start hold nothing return true
}

bool SinglyLinkedList::Search(Dictionary d) const
{
	for (ListNode* cur = start; cur; cur = cur->next)
	{
		if (cur->data == d) return true;
	}
	return false;
}

void SinglyLinkedList::TopInsert(Dictionary d)
{
	ListNode* newnode = new ListNode;
	newnode->data = d;
	newnode->next = start;
	start = newnode;
}
