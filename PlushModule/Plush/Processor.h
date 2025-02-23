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

		unsigned int run();
		unsigned int run(Environment& env, std::string program);
	};
}

