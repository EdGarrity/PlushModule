#include <iostream>
#include "Plush/Environment.h"

Plush::Environment env;

int main(int argc, char** argv)
{
    try
    {
		std::cout << "Hello, World!" << std::endl;
		return 0;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
}

