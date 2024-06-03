#ifndef COMPUTERSCIENTIST_H
#define COMPUTERSCIENTIST_H

#include <string>

using namespace std;

class ComputerScientist {

  public:	
	ComputerScientist(const ComputerScientist& rhs);
	ComputerScientist();
	ComputerScientist(string firstName, string lastName, string speciality, int id);
	~ComputerScientist();

	string getFirstName() const;
	string getLastName() const;
	string getSpeciality() const;
	int getID() const;

	friend ostream& operator << (ostream &out,const ComputerScientist &computerScientist);
	bool operator == (const  ComputerScientist& rhs) const;
	bool operator < (const ComputerScientist& rhs) const;
	ComputerScientist & operator = (const  ComputerScientist& rhs);
	
  private:
	string firstName;
	string lastName;
	string speciality;
	int id;

};	// end of ComputerScientist class

#endif 

