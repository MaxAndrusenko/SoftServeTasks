#include <iostream>
#include "AnyType.h"


int main() {

	AnyType anytype = 3.2f;
	anytype = true;
	anytype = 1.7;


	try
	{
		int storedValue = anytype.ToInt();
	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}


	return 0;
}
