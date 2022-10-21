#include<fstream>
#include<iostream>
#include "Dictionary.h"
#include "List.h"
using namespace std;

string filename; //stores filename

void readFileData(ListNode *headNode) //reads text from a file and writes it to the AVL tree
{
	Dictionary *dict;
	string word, meaning;
	fstream fin;
	cout << "\e[46mEnter the filename\x1b[0m "; 
	cin.ignore();
  cin >> filename;
	fin.open(filename);
  cout << "\e[0;32mFile reading succesful.\x1b[0m\n";
  while( fin >> word )  //write into file name
  {
    fin.ignore();
    getline(fin,meaning);
    dict = new Dictionary(word,meaning);
    cout << *dict << endl; //output newly created Dictionary object
    //remove above line insert data into a  linked list
  }
	fin.close();
}

void writeToFile(ListNode *headNode) //write the linked list to a text file
{
  string word, meaning;
  
  fstream dictFile; //create fstream object for the file
  cout << "\e[46mEnter the filename\x1b[0m "; 
	cin.ignore();
  cin >> filename;
  dictFile.open(filename, std::ios::app); //create/open a text file in append mode. new information is always added to the end

  ListNode *iterator = headNode;

  while(iterator != NULL) { //iterate over the linked list
    word = iterator->data.word;
    meaning = iterator->data.meaning;
    dictFile << word;
    dictFile << " " << meaning << endl; //write to data file 
    iterator = iterator->next;   //advance to next node
  }
  dictFile.close();
  cout << "\e[0;32mDictionary entries added.\x1b[0m\n";
}

void mainMenu() //menu function
{
  string word, meaning; //stores the word and meaning
  char choice;  //stores user choice for the actions

  cout << "\e[1;35mInput 's' to terminate the program anytime.\e[0;37m" << endl;
  while (choice != 's') //while loop until 's' is entered
  {
    cout << "\n\x1b[36mPlease select an action: " << endl << endl;
    cout << "\t1. Read file data" << endl;
    cout << "\t2. Write to file" << endl;

    cout << "\x1b[0m"; cin >> choice; cout << endl;
    switch(choice)  //switch statement to check user input and calling respective functions
    {
      case('1'):
      {
        readFileData(list.start);
      }; break;
      case('2'):
      {
        writeToFile(list.start);
      }; break;
      case('s'):
      {
        cout << "\e[1;33mProgram terminated." << endl;
      }; break;
      default:
        cout << "\x1b[31mInvalid action selected!\x1b[37m" << endl;
    }
  }
}