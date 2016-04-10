#include "movie.h"

Movie::Movie(string title,int priceCode){
	CHILDRENS = 2;
	REGULAR = 0;
	NEW_RELEASE = 1;
	_title = title;
	_priceCode = priceCode;
}

Movie::~Movie(){

}

int Movie::getPriceCode(){
	return _priceCode;
}

void Movie::setPriceCode(int arg){
	_priceCode = arg;
}

string Movie::getTitle(){
	return _title;
}


