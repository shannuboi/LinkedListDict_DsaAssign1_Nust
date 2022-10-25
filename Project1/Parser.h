#include <fstream>
#include <iostream>
#include "Dictionary.h"
#include "List.h"

using namespace std;

string filename; //stores filename

void readFileData(ListNode **headNode) //reads text from a file. You should add functionality to store the fetched data into a singly linked list. 
{
	Dictionary *dict;
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
		dict = new Dictionary(word,meaning); 

		// Question 1
		ListNode* newnode = new ListNode;
		newnode->data = *dict;
		if (*headNode != nullptr)
		{
			ListNode* cur = *headNode;
			for (; cur->next != nullptr; cur = cur->next);
			cur->next = newnode;
		}
		else
		{
			*headNode = newnode;
		}

		delete dict;
	}
	fin.close();
}

void writeToFile(ListNode *headNode) //write the linked list to a text file
{
	string word, meaning;
	
	fstream dictFile; //create fstream object for the file
	cout << "\x1b[46mEnter the filename\x1b[0m "; 
	cin.ignore();
	cin >> filename;
	dictFile.open(filename, std::ios::app); //create/open a text file in append mode. new information is always added to the end

	// Question 2
	for (ListNode* cur = headNode; cur != nullptr; cur = cur->next) // loop until cur becomes null
	{
		dictFile << cur->data.word << " " << cur->data.meaning << "\n";
	}
	
	dictFile.close();
	cout << "\x1b[0;32mDictionary entries added.\x1b[0m\n";
}

void print(ListNode* headNode)
{
	for (ListNode* cur = headNode; cur; cur = cur->next) // loop until cur becomes null
	{
		cout << cur->data << "\n";
	}
}

void mainMenu() //menu function
{
	string word, meaning; //stores the word and meaning
	char choice = 0;  //stores user choice for the actions
	SinglyLinkedList<Dictionary> list;
	
	cout << "\x1b[1;35mInput 's' to terminate the program anytime.\x1b[0;37m" << endl;
	while (choice != 's') //while loop until 's' is entered
	{
		cout << "\n\x1b[36mPlease select an action: " << endl << endl;
		cout << "\t1. Read file data" << endl;
		cout << "\t2. Write to file" << endl;
		cout << "\t3. Print List" << endl;
		cout << "\t4. Print list in reverse" << endl;
		cout << "\t5. Reverse list" << endl;
		cout << "\t6. Rearrange list by word-length parity" << endl;
		cout << "\t7. Filter list" << endl;
	
		cout << "\x1b[0m"; cin >> choice; cout << endl;
		switch(choice)  //switch statement to check user input and calling respective functions
		{
			case('1'):
			{
				readFileData(&list.start);
			}; break;

			case('2'):
			{
				writeToFile(list.start);
			}; break;

			case('3'):
			{
				print(list.start);
			}; break;

			case('4'):
			{
				printReverse(list.start);
			}; break;

			case('5'):
			{
				list.start = reverseList(list.start);
				cout << "\x1b[0;32mList Reversed.\x1b[0m\n";
			}; break;

			case('6'):
			{
				list.start = rearrangeByEvenOddLength(list.start);
				cout << "\x1b[0;32mList Rearranged.\x1b[0m\n";
			}; break;

			case('7'):
			{
				cout << "\x1b[46mEnter Filter Letter:\x1b[0m ";
				string FilterLetter;
				cin.ignore();
				cin >> FilterLetter;
				list.start = filterByLetters(list.start, FilterLetter);
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