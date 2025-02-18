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

		// The limit for the number of point(instruction) evaluations to execute during the run.
		const unsigned long max_point_evaluations = 1000; //10000;  //10,000,000; //INT_MAX; // 100000; // 10e100
	}
}
