#include "Processor.h"

std::vector<double> null_input;

// Run provided program without inputs
unsigned int Plush::Processor::run(Environment& env, std::string program)
{
	return run(env, program, null_input, false);
}

unsigned int Plush::Processor::run(Environment& env, std::string program, std::vector<double>& input, bool trace)
{
	std::string gene;
	int i = 0;

	// Initialize environment
	env.clear_stacks();

	// Load program into temp
	while ((program.length() > 0) && (i < Config::maximum_stack_size))
	{
		gene = first_atom(program);
		program = rest_atom(program);
		Utilities::trim(program);

		env.temp_genes[i++] = gene;
	}

	// Load inputs
	env.initialize(input);

	if (i > 0)
	{
		int j = i;
		for (int n = 0; n < i; n++)
		{
			Atom atom(env.temp_genes[--j]);

			env.get_stack<CodeAtom>().push(CodeAtom(atom));
			env.get_stack<ExecAtom>().push(ExecAtom(atom));
		}
	}

	// Execute
	return run(env, Config::max_point_evaluations, trace);
}

