#pragma once

namespace Plush
{
	namespace Config
	{
		// Default maximum size of the stack buffer.  Must be greater than max_points
		const unsigned long maximum_stack_size = 2000;
		const unsigned long maximum_stack_dept = 100;

		// Dynamic instruction set - Can Push programs add and delete instructions from the Piush Instruction set?
		const bool static_instruction_set = true;
	}
}
