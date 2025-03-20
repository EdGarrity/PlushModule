#pragma once
#include <string>
#include <vector>
#include "Environment.h"

namespace Plush
{
	class Processor
	{
	public:
		unsigned int run(Environment& env, std::string program);
		unsigned int run(Environment& env);

	};
}
