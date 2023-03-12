//THIS IS Source.cpp
#include <iostream>
#include <string>
#include "Book.h"
using namespace std;

//constructor with no parameters
BookList::BookList()
{
	//MAX_CAPACITY
	 books[0] = {""};
     top = 0;
}

//constructor with parameters
BookList::BookList(string books[],int top)
{
	this->top = top;
	for (int i = 0; i < getCurrentSiz(); i++)
	{
		this->books[i] = books[i];
	}
}

//copy constructor
BookList::BookList(const BookList& other) 
{
	this->top = other.top;
	for (int i = 0; i < getCurrentSiz(); i++) 
	{
		this->books[i] = other.books[i];
	}
}

//destructor
BookList::~BookList()
{
	cout << "Destructor called." << "\n\n";
}

bool BookList::isEmpty()
{
	if (getCurrentSiz()==0)
		return true;
	else
		return false;
}

bool BookList::isFull()
{
	return top >= MAX_CAPACITY;
	
}

int BookList::getCurrentSiz()
{
	int size = 0;
	for (int i = 0; i < top; i++)
		size++;
	
	return size;
}



bool BookList::add_book(string title)
{
	if (isFull())
	{
		cout << "Could not add '" << title << "', the book list is full!\n\n";
		return false;
	}

	books[top] = title;
	top++;
	return true;
	
}

int BookList::contains(string title)
{
	for (int i = 0; i < getCurrentSiz(); i++)
	{
		if (books[i] == title)
			return i;
	}
	cout << "The book '" << title << "' was not found and could not be removed.\n\n";
	return -1;
}

bool BookList::remove(string title)
{
	if (isEmpty())
		return false;

	int pos = contains(title);
	if (pos == -1) 
		return false;

	BookList temp;

	for (int i = 0; i < pos; i++) 
		temp.add_book(books[i]);

	top--;

	for (int i = pos; i < top; i++) 
		books[i] = books[i + 1];
	
	cout << "\nSuccessfully removed: " << title<<"\n\n";
	return true;
	
}

void BookList::display()
{
	for (int i = top - 1; i >= 0; i--)
	{
		cout << books[i] << endl;
	}
	cout << "\n\n";
}

string& BookList::operator[](int index)
{
	return books[index];
}

ostream& operator<<(ostream& out, BookList& obj)
{
	for (int i = obj.top - 1; i >= 0; i--) {
		out << obj.books[i] << endl;
	}
	return out;
}

istream& operator>>(istream& in, BookList& obj)
{
	string book;
	in >> book;
	obj.add_book(book);
	return in;
}

