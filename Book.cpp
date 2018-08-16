/*
Jenny Bloom, help from Collin Duncan
11/10/2015
Homework #8
This is a class setting up the books rated by users.
Book class file keeps track of books rated by a user.
*/

#include <iostream>
#include <string>
#include <string.h>
#include "Book.h"

using namespace std;



//CONSTRUCTORS
Book::Book()//being executed in class with Constructor Book()
{
    _author = "Unknown";
    _title = "Unknown";
}

Book::Book(string author, string title) //overloaded
{
    _author = author; //manipulating private data so main() can interact w/it
    _title = title;
}

//METHODS: Getters
string Book::getAuthor()
{
    return (_author);
}

string Book::getTitle()
{
    return (_title);
}

//METHODS: Setters
void Book::setAuthor(string a)
{
  _author = a;
}

void Book::setTitle(string t)
{
  _title = t;
}
