/**
 * @author E.S.Boese, Modified by: Jenny Bloom with help from Collin Duncan
 * @version Fall 2014, Modified: Nov 10-16, 2015
 * Project #2: Library class - reads, stores, and displays data.
 */

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include "User.h"
#include "Book.h"
#include "Library.h"
using namespace std;


Library::Library(string bookFilename, string userFilename)
{
	readInBookList(bookFilename);
	readUserFile(userFilename);
}

User Library::getCurrentUser(string currentUserFilename)
{
	string author, ratings;
	ifstream infile;
	infile.open(currentUserFilename.c_str());
	if (infile.is_open())
	{
		getline(infile, author);
		if (author != "")
		{
			getline(infile, ratings);
		}
	}
	infile.close();
	User userLib(author, ratings); //initialized object of user,  userLib.
	return userLib;
}

void Library::printUsers()
{
	for (int i=0; i<userList.size(); i++)
	{
		cout << userList.at(i).toString() << endl;
	}
}

void Library::readInBookList(string filename)
{
	ifstream infile;
	infile.open(filename.c_str());
	string line;
	int count = 0;

	if (infile.is_open())
	{
		cout << "Reading in book list from file: " << filename << endl;
		while ( getline (infile, line) )
		{
			int comma_pos = line.find(",");

			string author = line.substr(0, comma_pos);
			string title = line.substr(comma_pos+1);

			// TODO: create new Book object
			Book book(author, title);

			// TODO: add Book object to vector
			bookList.push_back(book);

			count++;
		}
		cout << count << " books read in. Closing book list file." << endl;
		infile.close();
	}
}

void Library::readUserFile(string filename)
{
	ifstream infile;
	infile.open(filename.c_str());

	if (infile.is_open())
	{
		cout << "Reading in user list from file: " << filename << endl;
		int count = 0;
		while (infile)
		{
			string author, ratings;
			getline(infile, author);

			if (author != "")
			{
				getline(infile, ratings);

				// TODO: Create new User object
				User newuser(author, ratings);

				// TODO: Add new User object to vector
				userList.push_back(newuser);

				count++;
			}
		}
		cout << count << " users read in. Closing user file." << endl;
		infile.close();
	}
}

void Library::printBooks()
{
	for (int i=0; i<bookList.size(); i++)
	{
		Book book = bookList.at(i);
		cout << book.toString() << endl;
	}
}

User Library::getMostSimilarUser(User currentUser)
{
	double bestSimilarity = 0;
	User bestUser; //Default constructor, unknown user.

	for (int u = 0; u < userList.size(); u++)
	{
		if (userList.at(u).getId() != currentUser.getId()) // at(u).getID() of user currently iterating comparing against currentUser.getId()
		{
			int score = currentUser.getSimilarity(userList.at(u)); //Working inside currentUser using getSimilarity method
			if (score > bestSimilarity)
			{
				bestSimilarity = score; //if bestSimilarity is greater, assign to score.
				bestUser = userList.at(u);
			}
		}
	}
	return bestUser;
}

void Library::printRecommendations(User mostSimilarUser, User currentUser)
{
		//create checks: loop through books.
		for (int b = 0; b < bookList.size(); b++)
		{
			if (!currentUser.getRatingAt(b))
			{
				if (mostSimilarUser.getRatingAt(b) >= 3)
				{
					cout << bookList.at(b).getTitle() << " by " << bookList.at(b).getAuthor() << "\n"; //tweak later
				}
			}
		}
}
