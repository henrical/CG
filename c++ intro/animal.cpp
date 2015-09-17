#ifndef _ANIMAL_CPP_
#define _ANIMAL_CPP_

#include <string>
#include <sstream>

class Animal {
	
	public:
		Animal(int age, std::string name){
			this->age = age;
			this->name = name;
		}
		
		std::string sleep() {
			std::ostringstream sstream;
			sstream << this->getName() << " is sleeping.";
			
			return sstream.str();
		}
		
		int getAge() { return this->age; }
		
		std::string getName() { return this->name; }
		
		std::string toString() {
			std::ostringstream sstream;
			
			sstream << "Animal with:\nName: " << this->getName() << ".\nAge: " << this->getAge() << "."; 
			return sstream.str();
		}
			
	private:
		int age;
		std::string name ;
};

#endif