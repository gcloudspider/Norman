
#ifndef _RENTAL_H_
#define _RENTAL_H_
#include "movie.h"

class Rental{
public:
	Rental(Movie movie,int dayRented);
	~Rental();
	int getDaysRented();
	Movie getMovie();
private:
	Movie _movie;
	int _daysRented;
};

#endif
