# DatabaseManagement
Your task in this project is to create a data structure which provides database management to users. The database keeps name and age values of people.
Data Structures: You can use the C++ string class in order to simplify string operations. Person objects should be kept in a data structure you create. Each person should be stored in a separate node with two pointers, age and name. Age pointer shows the next person in terms of age. Name pointer shows the next person in terms of name.

Your program has to perform the following tasks on a database as well.

void add(string name, int age): adds a new person to database. Person should be added considering list is sorted according to age and name. New person should be placed properly.

bool remove(string name): removes a person with it is name if it exists.

void update(string name, int age): updates age of a given person.

void printByAge(): print the sorted person database according to age.

void printByName(): print the sorted person database according to name.

void loadFile(string filename): loads a database file with txt extension.

void saveToFileByAge(string filename): saves the sorted person database according to age.

void saveToFileByName(string filename): saves the sorted person database according to name.

The Input File
Your database will consist of 2 attributes of person (name and age) and will be given in a txt file in the
following form.

bugra 30

deniz 25

can 35

feyza 32

elif 27

The Output File
In the result, saveToFileByAge(string filename) should be written to an output file such as “age.txt” to
the same directory of the input file. saveToFileByName(string filename) should be written to an output
file like “name.txt” to the same directory of the input file. Note that context of those output files have to
be sorted.
