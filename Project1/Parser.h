#include<fstream>
#include<iostream>
#include "Dictionary.h"
#include "List.h"
using namespace std;

string filename; //stores filename


// FUNCTIONS NEEDED FOR ASSIGNMENT DEFINED IN THIS SUB-CLASS
class DictList : public SinglyLinkedList<Dictionary>
{
public:
	void WriteToDictionaryFile(fstream& file) const
	{
		for (ListNode* cur = start; cur; cur = cur->next) // loop until cur becomes null
		{
			file << cur->data.word << " " << cur->data.meaning << "\n";
		}
	}
	void Print() const
	{
		for (ListNode* cur = start; cur; cur = cur->next) // loop until cur becomes null
		{
			cout << cur->data << "\n";
		}
	}
	void PrintReverse() const
	{
		PrintReverseRecurrsive(start);
	}
	void ReverseList()
	{
		ListNode* prev = nullptr;
		ListNode* cur = start;
		
		while (cur) // loop until cur becomes null
		{
			ListNode* tempNext = cur->next;

			cur->next = prev;
			prev = cur;
			cur = tempNext;
		}
		start = prev;
	}
	void FilterByLetter(string letter)
	{
		for (ListNode* cur = start; cur;) // loop until cur becomes null
		{
			if (cur->data.word.find(letter) == string::npos) // if it dosn't contain the letter
			{
				Dictionary toBeDel = cur->data;
				cur = cur->next;
				Delete(toBeDel);
			}
			else
			{
				cur = cur->next;
			}
		}
	}

private:
	void PrintReverseRecurrsive(ListNode* node) const
	{
		// if next is not null then recurse
		if (node->next) PrintReverseRecurrsive(node->next);
		cout << node->data << "\n";
	}
};

void readFileData(DictList& list) //reads text from a file and writes it to the AVL tree
{
	Dictionary dict;
	string word, meaning;
	fstream fin;
	cout << "\x1b[46mEnter the filename\x1b[0m "; 
	cin.ignore();
	cin >> filename;
	fin.open(filename);
	cout << "\x1b[0;32mFile reading succesful.\x1b[0m\n";
	while( fin >> word )  //write into file name
	{
		fin.ignore();
		getline(fin,meaning);
		dict = Dictionary(word,meaning);
	
		list.Insert(dict);
	}
	fin.close();
}

void writeToFile(DictList& list) //write the linked list to a text file
{
	fstream dictFile; //create fstream object for the file
	cout << "\x1b[46mEnter the filename\x1b[0m "; 
	cin.ignore();
	cin >> filename;
	dictFile.open(filename, std::ios::app); //create/open a text file in append mode. new information is always added to the end

	list.WriteToDictionaryFile(dictFile);

	dictFile.close();
	cout << "\x1b[0;32mDictionary entries added.\x1b[0m\n";
}

void mainMenu() //menu function
{
	string word, meaning; //stores the word and meaning
	char choice = 0;  //stores user choice for the actions
	DictList list;

	cout << "\x1b[1;35mInput 's' to terminate the program anytime.\x1b[0;37m" << endl;
	while (choice != 's') //while loop until 's' is entered
	{
		cout << "\n\x1b[36mPlease select an action: " << endl << endl;
		cout << "\t1. Read file data to list" << endl;
		cout << "\t2. Write to file from list" << endl;
		cout << "\t3. Print list" << endl;
		cout << "\t4. Filter list" << endl;

		cout << "\x1b[0m"; cin >> choice; cout << endl;
		switch(choice)  //switch statement to check user input and calling respective functions
		{
		case('1'):
		{
			readFileData(list);
		}; break;

		case('2'):
		{
			writeToFile(list);
		}; break;

		case('3'):
		{
			list.Print();
		}; break;

		case('4'):
		{
			cout << "\x1b[46mEnter Filter Letter:\x1b[0m ";
			string FilterLetter;
			cin.ignore();
			cin >> FilterLetter;
			list.FilterByLetter(FilterLetter);
			cout << "\x1b[0;32mList Filtered.\x1b[0m\n";
		}; break;

		case('s'):
		{
			cout << "\x1b[1;33mProgram terminated." << endl;
		}; break;

		default:
			cout << "\x1b[31mInvalid action selected!\x1b[37m" << endl;
		}
	}
}