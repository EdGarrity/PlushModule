#include "Processor.h"

namespace Plush
{
	typedef unsigned(*Operator)(Environment& env);
	extern std::vector<double> null_input;

	unsigned int Processor::run(Environment& env, std::string program)
	{
		return run(env, program, null_input);
	}

	// Run provided program with input vector
	unsigned int Processor::run(Environment& env, std::string program, std::vector<double>& input)
	{
		// Initialize environment
		env.clear_stacks();

		return 1;
	}
}
