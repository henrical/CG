#include <iostream>
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
			
	private:
		int age;
		std::string name ;
};

class Cat : public Animal {
	
	public:
		std::string climb() {
			
			std::ostringstream sstream;
			
			sstream << "Cat " << this->getName() << " is climbing a tree.";
			
			return sstream.str();
		}
	
	private:
		int lives;
};

class Dog : public Animal {
	
	public:
		std::string bark() {
			
			std::ostringstream sstream;
			
			sstream << "Dog " << this->getName() << " is barking.";
			
			return sstream.str();
		}
		
	private:
		float weight;
};


int main()
{
	return 0;
}