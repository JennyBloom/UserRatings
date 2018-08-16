/*
Jenny Bloom, help from Collin Duncan
11/10/2015
Homework #8
This is a class setting up the users rating books.
User class file keeps track of each user and that user’s ratings.

*/


#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <string.h>
#include "User.h"

using namespace std;


/*Note: Default constructor initialized in Line 22 with
member initialization List*/

//Constructor: overloaded
User::User(string userid, string ratings)
{
    _id = "User [user_id=" + userid + "]";
    stringstream ratingstream(ratings); //Creating stream "ratingstream" to store string "ratings"
    int ratingstemp; //holds "ratings" data
    while (ratingstream >> ratingstemp) //redirect ratingstream >> into ratingstemp
    {
      _ratings.push_back(ratingstemp); //populate vector with ratingstemp
    }

}

//METHODS
string User::getId()
{
    return(_id);
}

int User::getRatingAt(int index)
{
    return(_ratings[index]); //return given parameter index as specific rating of interest per user.
}

int User::getNumRatings()
{
    return(_ratings.size()); //return size of vector to get total number of ratings per user.
}

void User::addRating(int rating)
{
    _ratings.push_back(rating); //adding ratings to vector for user
}

void User::printRatings()
{
    for (int i = 0; i < _ratings.size(); i++)
    {
      cout << _ratings[i] << " ";
    }
}

int User::getSimilarity(User otherUser) //getSimilarity method, creates class instance "otherUser," constructor is run.
{
    int score = 0;
    for (int r = 0; r < otherUser.getNumRatings(); r++)
    {
      int cuRating = User::getRatingAt(r); //get rating of current user object provided to it.
      int otRating = otherUser.getRatingAt(r); //setting current user number of ratings for future iteration.

      score += (cuRating*otRating); //multiply current user and other user ratings, then add together as the score totaled.
    }

    return score;
}
