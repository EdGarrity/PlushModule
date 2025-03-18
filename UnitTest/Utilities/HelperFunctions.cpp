#include "HelperFunctions.h"

namespace PlushUnitTest
{
	template <typename S1>
	bool match(Environment & env, const std::vector<S1>& s2)
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
	bool is_stack_state(Environment & env,
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
}
