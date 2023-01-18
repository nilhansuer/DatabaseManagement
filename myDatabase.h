#include <iostream>
#include "LinkedList.h"
#include <fstream>
#include <string>
#include<array>
using namespace std;

class myDatabase{
public:
	LinkedList linkedlist;
	Node* head;
	
	myDatabase()
	{
		head = NULL;
	}
	
	void add(string name, int age)
	{
		Node* new_node = linkedlist.newNode(name, age);
		linkedlist.addNode(&head, new_node);
	}	
	
	bool remove(string name)
	{
		return linkedlist.removeNode(&head, name);
	}
	
	void update(string name, int age)
	{
		linkedlist.updateNode(head, name, age);
	}
	
	void printByAge()
	{	
		linkedlist.agePrinter(head);
	}
	
	void printByName()
	{
		linkedlist.namePrinter(head);
	}
	
	void loadFile(string filename)
	{
		string line;
		ifstream myfile(filename);
		if(myfile.is_open())
		{
			while(getline(myfile, line)){
				string word = "";
				string name;
				for(auto x : line ) 
				{
					if( x == ' ')
					{
						name = word;
						word = "";
					}
					else 
					{
						word = word + x;
					}
				}
				
				int age = stoi(word);
				add(name, age);
			}
			myfile.close();
		}
		else 
			cout << "unable to open file\n";
	}
	
	void saveToFileByAge(string filename)
	{
		std::array<int, 20> arr;
		arr = linkedlist.convertArrAge(head);
		int size = linkedlist.findlenght(head);
		
		fstream my_file;
		my_file.open(filename, ios::out);
		for(int i = 0; i < size; i++)
		{
			my_file << arr[i];
			my_file << "\n";
		}	
		my_file.close();
	}
	
	void saveToFileByName(string filename)
	{
		std::array<string, 20> arr;
		arr = linkedlist.convertArrName(head);
		int size = linkedlist.findlenght(head);
		
		fstream my_file;
		my_file.open(filename, ios::out);
	
		for(int i = 0; i < size; i++)
		{
			my_file << arr[i];
			my_file << "\n";
		}	
		my_file.close();
	}
	
};