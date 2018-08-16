#ifndef BOOK_H
#define BOOK_H

class Book
{
  private:
    std::string _author;
    std::string _title;

  public:
    Book();
    Book(std::string author, std::string title);
    std::string getAuthor();
    std::string getTitle();
    void setAuthor(std::string a); // writing fxn and creating string object
    void setTitle(std::string t);
    std::string toString() {return (_title + " by " + _author);}

};
#endif
