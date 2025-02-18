#include <iostream>
#include <cassert> 
#include "Plush\Environment.h"
#include "Plush\Processor.h"
#include "Plush\Atom.h"

Plush::Environment env;

template <typename S1>
bool match(Plush::Environment& env, const std::vector<S1>& s2)
{
	if (env.get_stack<S1>().size() != s2.size())
		return false;

	if (!s2.empty())
	{
		for (size_t n = 0; n < s2.size(); n++)
		{
			if (s2[n] != env.get_stack<S1>().get_atom_at_index(n))
				return false;
		}
	}

	return true;
}

// long, double, bool, ExecAtom, CodeAtom
bool is_stack_state(Plush::Environment& env,
	const std::vector<long>& int_array,
	const std::vector<double>& double_array,
	const std::vector<bool>& bool_array,
	const std::vector<Plush::ExecAtom>& exec_array,
	const std::vector<Plush::CodeAtom>& code_array)
{
	if (match<long>(env, int_array)
		&& match<double>(env, double_array)
		&& match<bool>(env, bool_array)
		&& match<Plush::ExecAtom>(env, exec_array)
		&& match<Plush::CodeAtom>(env, code_array)
		)
		return true;

	else
		return false;
}

int main(int argc, char** argv)
{
    try
    {
		std::cout << "Hello, World!" << std::endl;

		assert(is_stack_state(env, {}, {}, {}, {}, {}));

		env.enable_function("BOOLEAN.=");

		Plush::run(env, \
				"\
					{:instruction BOOLEAN.= :close 0}\
				");
		
		assert(is_stack_state(env, {}, {}, {}, {}, {Plush::CodeAtom("{:instruction BOOLEAN.= :close 0}")}));

		return 0;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
}
