#pragma once
#include <vector>
#include "..\..\PlushModule\Plush\Environment.h"
#include "..\..\PlushModule\Plush\Processor.h"

using namespace Plush;

namespace PlushUnitTest
{
	template <typename S1>
	bool match(Environment& env, const std::vector<S1>& s2);

	bool is_stack_state(Environment& env,
		const std::vector<long>& int_array);
}
