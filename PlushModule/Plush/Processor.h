#pragma once
#include <string_view>

namespace Plush
{
	// Purpose: 
	//   Run a Push prgram and calculate the orders
	//
	// Parameters:
	//   program - The Push program to run
	//
	// Return value:
	//   Execution Effort
	//
	// Side Effects:
	//   The Push environment is initialized and the Push stacks are manipulated.
	//
	// Thread Safe:
	//   No
	//
	// Remarks:
	//
	size_t run(std::string_view program);
}
