//THIS IS Book.h
#pragma once
#include<iostream>
#include<string>
using namespace std;

//max capacity of array
const static int MAX_CAPACITY = 5;

class BookList
{
	//one dimensional array to store books
    string books[MAX_CAPACITY];
	//marker for top of array of books
	int top = 0;

public:

	//default constructor, initializes book array to empty and top to 0.
	BookList();
	//constructor with parameters, uses book array and dimendion
	BookList(string books[], int top);
	//copy constructor, copies book array into new array
	BookList(const BookList& other);
	//destructor, it displays message when it is run and destroys the booklist wehn done using or out of scope.
	~BookList();
	//function that checks if the array is empty
	bool isEmpty();
	//function that checks if the array is full
	bool isFull();
	//function that gets the current sixe of the array
	int getCurrentSiz();
	//function that adds a book to the array only if it still has space
	bool add_book(string title);
	//function that checks if the inputed book is inside the array
	int contains(string position);
	//function that removes book only if it is contained in the array (runs the contained function)
	bool remove(string title);
	//function that displays the books in descending order
	void display();
	//overload of operator []
	string& operator[](int index);
	//overload of operator <<
	friend ostream& operator<< (ostream& out, BookList& obj);
	//overload of operator >>
	friend istream& operator>> (istream& in, BookList& obj);
};