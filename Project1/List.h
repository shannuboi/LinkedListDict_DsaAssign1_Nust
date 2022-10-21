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
	~SinglyLinkedList();
	SinglyLinkedList(const SinglyLinkedList& src);
	void operator=(const SinglyLinkedList& rhs);
	bool IsEmpty() const;
	int GetLength() const;
	bool Search(Dictionary d) const;
	void Insert(Dictionary d, int pos = 0);
	void Delete(Dictionary d);
	void ClearList();
private:
	void InsertAfter(Dictionary d, ListNode* node, int pos);
	ListNode* start = nullptr;
};