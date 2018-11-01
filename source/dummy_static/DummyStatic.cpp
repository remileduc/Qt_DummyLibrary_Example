#include <iostream>
#include <string>

#include "DummyStatic.hpp"

int DummyStatic::_counter = 0;

void DummyStatic::dummyStaticFunction()
{
	DummyStatic::_counter++;
	std::cout << "\n\tNumber of calls: " + std::to_string(DummyStatic::_counter) + "\n";
}

void DummyStatic::dummyFunction()
{
	std::cout << "\n\tCall to Static Dummy Library!\n";
}
