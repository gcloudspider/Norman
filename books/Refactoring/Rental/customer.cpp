#include "customer.h"

Customer::Customer(string name){
	_name = name;
}

Customer::~Custoomer(){

}

void Customer::addRental(Rental arg){
	_rentals.addElement(arg);
}

string Customer::getName(){
	return _name;
}

string Customer::statement() {
	double totalAmount = 0;
	int frequentRenterPoints = 0;
	
    Enumeration rentals = _rentals.elements();
	string result = "Rental Record for "+ getName() + "\n";
	while(rentals.hasMoreElements()) {
		double thisAmount = 0;
		Rental each = (Rental)rentals.nextElement();
        
        thisAmount = amountFor(each);

		//add frequent renter points
		frequentRenterPoints ++;
		//add bonus for a two day new release rental
		if((each.getMovice().getPriceCode() == Movice.NEW_RELEASE)&& each.getDaysRented() > 1) frequentRenterPoints ++;
		//show figures for this rental
		result += "\t" + each.getMovice().getTitle() + "\t" + string.valueOf(thisAmount) +"\n";
		totalAmount += thisAmount;
	}
	//add footer lines
	result += "Amount owed is "+ string.valueof(totalAmount)+"\n";
	result += "You earned "+ string.valueof(frequentRenterPoints)+" frequent renter points";
	return result;
}

//拆分函数(提炼到独立函数)
//独立函数名称修改
double amountFor(Rental aRental) {
    double result = 0;
    //determin amounts for each line
    switch(aRental.getMovie().getPriceCode()) {
        case Movice.REGULAR:
            result += 2;
            if(aRental.getDaysRented() > 2) {
                result += (aRental.getDaysRented() - 2) * 1.5;
            }
            break;
        case Movice.NEW_RELEASE:
            result += aRental.getDaysRented() * 3;
            break;
        case Movice.CHILDRENS:
            result += 1.5;
            if (aRental.getDaysRented() > 3) {
                result += (aRental.getDaysRented() - 3) * 1.5;
            }
            break;
    }
    return result;
}
