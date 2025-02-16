#include <algorithm>
#include <string>
#include "Atom.h"
#include "Config.h"
#include "../Utilities/String.h"

namespace Plush
{
	// Definitions of static members
	static const std::string_view boolean_true = "TRUE";
	static const std::string_view boolean_false = "FALSE";

	Atom::Atom()
	{
		clear();
	}

	Atom::Atom(std::string_view instruction_name, unsigned int close_parenthesis, AtomType type)
	{
		this->instruction_name = instruction_name;
		this->close_parenthesis = (close_parenthesis > Config::maximum_stack_dept) ? (Config::maximum_stack_dept) : (close_parenthesis);
		this->type = type;
		//this->instruction_id = Plush::static_initializer.get_function_index(instruction_name);
	}

	Atom::Atom(std::string_view _program_statement)
	{
		instruction_name = "";
		close_parenthesis = 0;
		type = AtomType::empty;
		//instruction_id = -1;
		compile(_program_statement);
	};

	Atom::Atom(long value)
	{
		instruction_name = std::to_string(value);
		close_parenthesis = 0;
		type = AtomType::integer;
	};

	Atom::Atom(const Atom& other)
	{
		instruction_name = other.instruction_name;
		close_parenthesis = other.close_parenthesis > Config::maximum_stack_dept ? Config::maximum_stack_dept : other.close_parenthesis;
		type = other.type;
		//this->instruction_id = Plush::static_initializer.get_function_index(instruction_name);
	};

	Atom::Atom(const Atom* other)
	{
		instruction_name = other->instruction_name;
		close_parenthesis = other->close_parenthesis > Config::maximum_stack_dept ? Config::maximum_stack_dept : other->close_parenthesis;
		type = other->type;
		//this->instruction_id = Plush::static_initializer.get_function_index(instruction_name);
	};

	void Atom::clear()
	{
		instruction_name = "";
		close_parenthesis = 0;
		type = AtomType::empty;
		//this->instruction_id = -1;
	};

	void Atom::set(std::string_view instruction_name, unsigned long close_parenthesis, AtomType type)
	{
		this->instruction_name = instruction_name;
		this->close_parenthesis = std::min(close_parenthesis, Config::maximum_stack_dept);
		this->type = type;
		//this->instruction_id = Plush::static_initializer.get_function_index(instruction_name);
	};

	void Atom::compile(std::string_view _atom_string)
	{
		std::size_t index, start_of_optional_tokens, start_of_optional_value; // , end_of_optional_value;

		// Convert to lower case
		std::transform(_atom_string.begin(), _atom_string.end(), _atom_string.begin(),
			[](unsigned char c) { return std::tolower(c); });

		// Find token for the instruction
		index = _atom_string.find(":instruction");

		if (index == std::string::npos)
			throw;

		// Find start of instruction atom
		index += strlen(":instruction");

		while (_atom_string[index] == ' ')
			index++;

		start_of_optional_tokens = _atom_string.find_first_of(" :}", index);

		instruction_name = _atom_string.substr(index, start_of_optional_tokens - index);

		// Convert instruction to upper case
		std::transform(instruction_name.begin(), instruction_name.end(), instruction_name.begin(),
			[](unsigned char c) { return std::toupper(c); });

		// Check for optional close token
		index = _atom_string.find(":close");

		if (index != std::string::npos)
		{
			start_of_optional_value = index + strlen(":close");

			while (_atom_string[start_of_optional_value] == ' ')
				start_of_optional_value++;

			close_parenthesis = std::abs(std::stoi(std::string(_atom_string.substr(start_of_optional_value, index))));

			if (close_parenthesis > Config::maximum_stack_dept)
				close_parenthesis = Config::maximum_stack_dept;
		}

		// Check for optional silent tiken
		index = _atom_string.find(":silent", start_of_optional_tokens);

		if (index != std::string::npos)
		{
			start_of_optional_value = index + strlen(":silent");

			while (_atom_string[start_of_optional_value] == ' ')
				start_of_optional_value++;

			if (_atom_string.find("true") != std::string::npos)
				type = AtomType::silent;
		}

		// Check for boolean
		else if ((instruction_name == Plush::Atom::boolean_true) || (instruction_name == Plush::Atom::boolean_false))
			type = AtomType::boolean;

		// Check for integer
		else if (Utilities::isNumber(instruction_name))
			type = AtomType::integer;

		// Check for float
		else if (Utilities::isFloat(instruction_name))
			type = AtomType::floating_point;

		else
			type = AtomType::ins;

		//instruction_id = Plush::static_initializer.get_function_index(instruction_name);
	}

}