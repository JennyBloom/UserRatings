#!/bin/bash

g++ -c Library.cpp
if [ $? != 0 ]; then
  echo "COMPILE FAILED AT LIBRARY.CPP"
  exit
else
  echo "[SUCCESS] - Library"
fi
g++ -c User.cpp
if [ $? != 0 ]; then
  echo "COMPILE FAILED AT USER.CPP"
  exit
else
  echo "[SUCCESS] - User"
fi
g++ -c Book.cpp
if [ $? != 0 ]; then
  echo "COMPILE FAILED AT BOOK.CPP"
  exit
else
  echo "[SUCCESS] - Book"
fi
g++ Book.o User.o Library.o ProjectDriver.cpp
if [ $? != 0 ]; then
  echo "COMPILE FAILED AT ALL POINTS"
  exit
else
  echo "[SUCCESS]"
  echo "COMPILED - a.out"
fi

exit
