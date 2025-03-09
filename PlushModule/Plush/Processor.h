#pragma once
#include <string_view>
#include <map>
#include <utility>
#include "Environment.h"
#include "Atom.h"

namespace Plush
{
	class Processor
	{
	public:
		Processor()
		{
		}

		//typedef unsigned(*Operator)(Environment&); // Move to Instruction.h

		unsigned int run(Environment& env, std::string program);
		unsigned int run(Environment& env, std::string _program, std::vector<double>& _input, bool trace);
		unsigned int run(Environment& env, unsigned _max_effort, bool trace);
	};
}

