/* 
    ifndef(if not define) or include guard (protects against duplicated includes).
    if this does not exist then there might be an error for duplicated classes.
*/
#ifndef MEDIA_H
#define MEDIA_H

#include <iostream>
using namespace std;

class Media {
  private: 
    string title;
    int sizeInBytes;

  public:
    Media(string, int);                 /* header file */
    string getTitle();
    int getSizeInBytes();
    double getSizeInKB();
    double getSizeInMB();
    double getSizeInGB();
};

#endif