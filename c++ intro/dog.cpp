#ifndef _DOG_CPP_
#define _DOG_CPP_

#include <string>
#include <sstream>

#include "animal.cpp"

class Dog : public Animal {
	
	public:
		Dog(int age, std::string name, float weight)
		:Animal(age,name)
		{
			this->weight = weight;
		}
		
		float getWeight()
		{
			return this->weight;
		}
		
		std::string bark() {
			
			std::ostringstream sstream;
			
			sstream << "Dog " << this->getName() << " is barking.";
			
			return sstream.str();
		}
		
		std::string toString() {
			std::ostringstream float_converter;
			std::string result;
			
			result = Animal::toString();
			
			float_converter << this->getWeight();
			
			result.append("\nWeight: ");
			result.append(float_converter.str());
			result.append(".");
			return result;
		}
		
	private:
		float weight;
};

#endif