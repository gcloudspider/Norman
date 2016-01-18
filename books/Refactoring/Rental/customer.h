
#ifndef _CUSTOMER_H_
#define _CUSTOMER_H_
#include "rental.h"
#include <vector>

class Customer{
public:
	Customer(String name);
	~Customer();
	void addRental(Rental arg);
	String getName();
private:
	String _name;
	Vector _rentals = new Vector();
};

#endif
