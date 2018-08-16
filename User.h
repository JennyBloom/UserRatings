/**
 * Jenny Bloom
 * Nov 17, 2015
 * project #2: User Header file with protofunctions.
 */

#ifndef USER_H
#define USER_H

class User
{
    private:
      std::string _id;
      std::vector<int> _ratings;

    public:
      User() : _id( "User [user_id=Unknown]" ) {} //member initialization
      User(std::string userid, std::string ratings);
      std::string getId();
      int getSimilarity(User otherUser);
      int getRatingAt(int index);
      void addRating(int rating);
      int getNumRatings();
      void printRatings();
      std::string toString() {return (_id);}

}; //objects are stored here


#endif
