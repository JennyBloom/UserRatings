/**
 * @author E.S.Boese
 * @version Fall 2014
 * project #2
 */
#ifndef LIBRARY_H
#define LIBRARY_H

#include "User.h"
#include "Book.h"

class Library
{
  public:
	Library(std::string book_list_file, std::string user_list_file);
  User getCurrentUser(std::string currentUserFilename);
  User getMostSimilarUser(User currentUser);
  void printRecommendations(User mostSimilarUser, User currentUser);
	void readInBookList(std::string filename);
	void readUserFile(std::string filename);
	void printUsers();
	void printBooks();

  private:
	std::vector<Book> bookList;
	std::vector<User> userList;
};
#endif
