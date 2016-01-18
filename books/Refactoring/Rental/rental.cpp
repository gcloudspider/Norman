#include "rental.h"

Rental::Rental(Movie movie,int dayRented){
	_movie = movie;
	_daysRented = daysRented;
}

Rental::~Rental(){

}

int Rental::getDaysRented(){
	return _daysRented;
}

Movie Rental::getMovie(){
	return _movie;
}
