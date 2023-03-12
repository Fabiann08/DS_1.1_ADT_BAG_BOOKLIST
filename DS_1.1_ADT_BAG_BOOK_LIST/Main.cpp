//THIS IS Main.cpp
#include "Book.h"
#include <string>
using namespace std;

int main()
{
	int numOfBooks = 0;
	int counter = 0;
	string bookForDefaultConstructor = "";
	string bookForParameterConstructor = "";
	string bookForCopyConstructor = "";
	string parameterBookArray[5] = { "Berserk", "Love is war", "Hunter X Hunter","Uzumaki","Made In Abyss"};

	BookList firstList;

	//default constructor
	cout << "Using default constructor\n"
		<< "How many books do you want to add to the list? - ";
	cin >> numOfBooks;
	cout << "\nEnter '" << numOfBooks << "' books to the first list : \n";
    do
	{
		cin >> firstList;
		counter++;
	} while (counter < numOfBooks);

	cout << "Enter which book you want to remove: ";
	cin >> bookForDefaultConstructor;
	firstList.remove(bookForDefaultConstructor);

	cout << firstList;

	//list for parameter constructor
	BookList secondList(parameterBookArray, 5);

	//parameter constructor
	cout << "\nUsing parameter constructor\n"
		<< "Elements input into parameter constructor:\n\n";
	for (int i = 0; i < 5; i++)
	{
		cout << parameterBookArray[i] << endl;
	}
	//display parameter constructor array
	cout << "\nDiplaying array for Parameter Constructor: \n" << endl;
	secondList.display();

	//removing a book from parameter constructor
	cout << "Enter a book to remove from the second list: ";
	cin >> bookForParameterConstructor;
	secondList.remove(bookForParameterConstructor);
	//printing again list for parameter contructor
	secondList.display();

	//copy constructor
	BookList thirdList = secondList;

	cout << "\nCopy constructor exectued, copied parameter constructor book list.\n"
		<< "\nChoose a book to remove from this copied list, these are the books:\n";
	//display copy constructor
	thirdList.display();

	cout << "Remove one book: ";
	cin >> bookForCopyConstructor;
	thirdList.remove(bookForCopyConstructor);
	cout << "Copy constructor list with removed book:\n";

	thirdList.display();

	return 0;
}
/*BookList::BookList(): This is the default constructor, which creates an empty BookList object. It initializes the top member variable to 0 and the books array with a single empty string.

BookList::BookList(string books[],int top): This is a parameterized constructor that creates a BookList object from an array of book titles and the number of books in the array.
It copies the book titles from the input array into the books array of the object and sets the top member variable to the input value of top.

BookList::BookList(const BookList& other): This is a copy constructor that creates a new BookList object that is a copy of another BookList object.
It copies the values of the top and books variables from the input BookList object into the new object.
*/





