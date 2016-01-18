


#ifndef _MOVIE_H_
#define _MOVIE_H_
#include <iostream>
using namespace std;

class Movie{
public:
	Movie(String title,int priceCode);
	virtual ~Movie();
	int getPriceCode();
	void setPriceCode(int arg);
	String getTitle();
public:
	int CHILDRENS;
	int REGULAR;
	int NEW_RELEASE;
private:
	String _title;
	int _priceCode;
};

#endif
