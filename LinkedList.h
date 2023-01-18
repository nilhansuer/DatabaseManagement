#include <iostream>
#include<string.h>
#include <fstream>
#include<array>
using namespace std;

struct Node {
public:
	string data_name;
	int data_age;
	Node *nextAge;  //age pointer that shows the next person in terms of age
	Node *nextName;  //name pointer that shows the next person in terms of name
};

class LinkedList
{
private:
	Node *head;
public:
	LinkedList()
	{
		head = NULL;
	}
	
	Node* newNode(string dataName, int dataAge)
	{
		Node * new_node = new Node();
		
		new_node -> data_name = dataName;
		new_node -> data_age = dataAge;
		new_node -> nextAge = NULL;
		
		return new_node;
	}
	
	void addNode(Node** head_ref, Node* new_node)
	{	
		Node* ptrAge;
		Node* ptrName;
		if((*head_ref == NULL) || ((*head_ref) -> data_age >= new_node -> data_age)) {
			new_node -> nextAge = *head_ref;
			*head_ref = new_node;
		}
		
		else {
			ptrAge = *head_ref;
			ptrName = *head_ref;
			while((ptrAge -> nextAge != NULL) && (ptrAge -> nextAge -> data_age < new_node -> data_age)) {
				ptrAge = ptrAge -> nextAge;
			}
			new_node -> nextAge = ptrAge -> nextAge;
			ptrAge -> nextAge = new_node;
			
		}	
		
	}
	
	bool removeNode(Node** head_ref, string dataName)
	{
		Node* temp = *head_ref;
		Node* prev = NULL;
		
		if((temp != NULL) && (temp -> data_name == dataName))
		{
			*head_ref = temp -> nextAge;
			delete temp;
			return true;
		}
		else
		{
			while((temp != NULL) && (temp -> data_name != dataName))
			{
				prev = temp;
				temp = temp -> nextAge;
			}
			if( temp == NULL)
				return false;
			prev -> nextAge = temp -> nextAge;
			
			delete temp;
		}
	}
	
	void updateNode(Node* head, string dataName, int dataAge)
	{
		Node *curr = head;
		while(curr != NULL){
			if(curr -> data_name == dataName){
				bool rem = removeNode(&head, dataName);
				if(rem) {
					Node* new_node = newNode(dataName, dataAge);
					addNode(&head, new_node);
				}
			}
			curr = curr -> nextAge;
		}	
	}

	void agePrinter(Node* head) {
		Node *temp = head;
		while(temp != NULL){
			cout<< temp -> data_age <<endl;
			temp = temp -> nextAge;
		}
	}
	void namePrinter(Node* head) {
		Node *temp = head;
		while(temp != NULL){
			cout<< temp -> data_name <<endl;
			temp = temp -> nextAge;
		}
	}
	
	int findlenght(Node* head)
	{
		Node* curr = head;
		int count = 0;
		while( curr != NULL ) {
			count ++;
			curr = curr -> nextAge;
		}
		return count;
	}
	
	std::array<string, 20> convertArrName(Node* head)
	{
		std::array<string, 20> arr;
		
		int index = 0;
		Node* curr = head;
		
		while( curr != NULL ) {
			arr[index++] = curr -> data_name;
			curr = curr -> nextAge;
		}
		return arr;
	}
	
	std::array<int, 20> convertArrAge(Node* head)
	{
		std::array<int, 20> arr;
		
		int index = 0;
		Node* curr = head;
		
		while( curr != NULL ) {
			arr[index++] = curr -> data_age;
			curr = curr -> nextAge;
		}
		
		return arr;
	}
	
};
