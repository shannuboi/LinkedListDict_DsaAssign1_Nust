#include "Dictionary.h"

class ListNode{   //class definition of Node 
  public:
    Dictionary data;
    ListNode *next;
};

class SinglyLinkedList
{
public:
	SinglyLinkedList() = default;
	bool IsEmpty() const;
	bool Search(Dictionary d) const;
	void TopInsert(Dictionary d);
private:
	ListNode* start = nullptr;
};