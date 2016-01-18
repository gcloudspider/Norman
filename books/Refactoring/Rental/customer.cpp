#include "customer.h"

Customer::Customer(String name){
	_name = name;
}

Customer::~Custoomer(){

}

void Customer::addRental(Rental arg){
	_rentals.addElement(arg);
}

String Customer::getName(){
	return _name;
}
