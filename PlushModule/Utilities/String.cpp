#include "String.h"
#include <stdexcept>

namespace Utilities
{
	bool isNumber(const std::string& str) 
	{
		try 
		{
			std::size_t pos;
			long num = std::stol(str, &pos);	// Store the return value to avoid C6031 and C4834
			(void)num;							// Explicitly ignore the variable to avoid unused variable warning
			return pos == str.size();
		}
		catch (const std::invalid_argument&) 
		{
			return false;
		}
		catch (const std::out_of_range&) 
		{
			return false;
		}
	}
}