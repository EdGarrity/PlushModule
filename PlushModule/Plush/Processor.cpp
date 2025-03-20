#include "Processor.h"

namespace Plush
{
	typedef unsigned(*Operator)(Environment& env);
	extern std::vector<double> null_input;

	unsigned int Processor::run(Environment& env, std::string program)
	{
		// Initialize environment
		env.clear_stacks();

		return run(env);
	}

	// Run program on the EXEC stack
	unsigned int Processor::run(Environment& env)
	{
		return 1;
	}
}
