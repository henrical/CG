#include <iostream>
#include <string>
#include <sstream>

#include "animal.cpp"
#include "dog.cpp"
#include "cat.cpp"


int main()
{
	Animal anim = Animal(12, "Goofy ass looking cow");
	Cat cat1 = Cat(3, "Whiskers");
// 	std::cout << anim.toString() << std::endl;
	return 0;
}