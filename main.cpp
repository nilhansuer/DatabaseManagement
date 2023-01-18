#include "myDatabase.h"
#include <iostream>
using namespace std;

int main(){
	
	myDatabase mydatabase;
	
	mydatabase.loadFile("input.txt");
	
	string demoName = "nilhan";
	
	cout<< "\nAdded a new person with the name: " << demoName << endl;
	mydatabase.add(demoName, 21);
	
	cout<< "Updated age of a person with the name '" << demoName << "'" <<endl;
	mydatabase.update(demoName, 22);
	
	
	bool isRemoved = mydatabase.remove(demoName);
	if(isRemoved)
		cout << "The person with the name '"<< demoName << "' is succesfully removed!" << endl;
	else
		cout << "The person with the name '"<< demoName << "' couldn't be found! Removing is unsuccesfull."  << endl;
	
	
	cout<<"\nPrinted by age: " <<endl;
	mydatabase.printByAge();
	
	cout<<"\nPrinted by name: " <<endl;
	mydatabase.printByName();
	
	cout<<"\nThe files 'age.txt' and 'name.txt' are created.\n" << endl; 
	mydatabase.saveToFileByAge("age.txt");
	mydatabase.saveToFileByName("name.txt");
	
}