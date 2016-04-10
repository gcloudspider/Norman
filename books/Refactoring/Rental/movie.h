#ifndef _MOVIE_H_
#define _MOVIE_H_
#include <iostream>
using namespace std;

class Movie{
public:
	Movie(string title,int priceCode);
	virtual ~Movie();
	int getPriceCode();
	void setPriceCode(int arg);
	string getTitle();
public:
	int CHILDRENS;
	int REGULAR;
	int NEW_RELEASE;
private:
	string _title;
	int _priceCode;
};

#endif
