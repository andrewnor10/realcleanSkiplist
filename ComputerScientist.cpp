#include <iostream>
#include "ComputerScientist.h"


ostream& operator<< (ostream &out, const ComputerScientist &ComputerScientist)
{
	// Since operator<< is a friend of the ComputerScientist class, we can access
	// ComputerScientist's members directly.
	out << "(" << ComputerScientist.firstName << " " << ComputerScientist.lastName;
	out << ", id: " << ComputerScientist.id;
	out << ", speciality: " << ComputerScientist.speciality;
	out << ")";
	return out;
}

//Initialize class members from constructor arguments 
//by using a member initializer list.
//This method uses direct initialization, which is more
//efficient than using assignment operators inside the constructor body.
ComputerScientist::ComputerScientist(const ComputerScientist& rhs)
	: firstName{ rhs.firstName }, lastName{ rhs.lastName }, speciality{ rhs.speciality }, id{ rhs.id } {
	// empty body of constructor 
}

//Initialize class members from constructor arguments 
//by using a member initializer list.
//This method uses direct initialization, which is more
//efficient than using assignment operators inside the constructor body.
ComputerScientist::ComputerScientist(string firstName, string lastName, string speciality, int id)
	: firstName{ firstName }, lastName{ lastName }, speciality{ speciality }, id{ id } {
	// empty body of constructor 
}

//Initialize class members from constructor arguments 
//by using a member initializer list.
//This method uses direct initialization, which is more
//efficient than using assignment operators inside the constructor body.
ComputerScientist::ComputerScientist()
	: firstName{ "" }, lastName{ "" }, speciality{ "" }, id{ -1 }  {  
	// empty body of constructor 
}

ComputerScientist::~ComputerScientist() { }

bool ComputerScientist::operator==( const ComputerScientist& rhs) const {	
	return this->id == rhs.id;
}
bool  ComputerScientist::operator<( const ComputerScientist& rhs) const {
	return this->id < rhs.id;	
}

ComputerScientist & ComputerScientist::operator=(const ComputerScientist & rhs) {
	this->firstName = rhs.firstName;
	this->lastName = rhs.lastName;
	this->speciality = rhs.speciality;
	this->id = rhs.id;
	return *this;
}

 string ComputerScientist::getFirstName() const {
	return this->firstName;
}

 string ComputerScientist::getLastName() const {
	return this->lastName;
}

 string ComputerScientist::getSpeciality() const {
	return this->speciality;
}

 int ComputerScientist::getID() const {
	return this->id;
}