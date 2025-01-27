#include <algorithm>
#include "Atom.h"
#include "Config.h"

namespace Plush
{
	// Definitions of static members
	static const std::string_view boolean_true = "TRUE";
	static const std::string_view boolean_false = "FALSE";

	Atom::Atom()
	{
		clear();
	}

	void Atom::clear()
	{
		instruction_name = "";
		close_parenthesis = 0;
		type = AtomType::empty;
		this->instruction_id = -1;
	};

	void Atom::set(std::string instruction_name, unsigned long close_parenthesis, AtomType type)
	{
		this->instruction_name = instruction_name;
		this->close_parenthesis = std::min(close_parenthesis, Config::maximum_stack_dept);
		this->type = type;
		//this->instruction_id = Plush::static_initializer.get_function_index(instruction_name);
	};
}