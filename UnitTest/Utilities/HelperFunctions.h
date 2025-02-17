#pragma once
#include <vector>
#include "..\..\PlushModule\Plush\Processor.h"

using namespace Plush;

namespace PlushUnitTest
{
	bool is_stack_state(Environment& env,
		const std::vector<long>& int_array,
		const std::vector<double>& double_array,
		const std::vector<bool>& bool_array,
		const std::vector<ExecAtom>& exec_array,
		const std::vector<CodeAtom>& code_array);
}