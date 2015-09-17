#ifndef _CAT_CPP_
#define _CAT_CPP_

#include <string>
#include <sstream>

#include "animal.cpp"

class Cat : public Animal {
	
	public:
		Cat(int age, std::string name)
		:Animal(age,name)
		{
		}
		
		std::string climb() {
			
			std::ostringstream sstream;
			
			sstream << "Cat " << this->getName() << " is climbing a tree.";
			
			return sstream.str();
		}
	
	private:
		int lives;
};

#endif