#include <algorithm> // Add this include directive
#include <string>
#include "Atom.h"
#include "Config.h"
#include "../Utilities/String.h"

namespace Plush
{
	// Definitions of static members
	const char Atom::boolean_true[] = "TRUE";
	const char Atom::boolean_false[] = "FALSE";

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
	}

	Atom::Atom(double value)
	{
		instruction_name = std::to_string(value);
		close_parenthesis = 0;
		type = AtomType::floating_point;
	}

	Atom::Atom(bool value)
	{
		instruction_name = (value) ? (boolean_true) : (boolean_false);
		close_parenthesis = 0;
		type = AtomType::boolean;
	}

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
		std::string lowercase_atom_string;
		std::size_t index, start_of_optional_tokens, start_of_optional_value; // , end_of_optional_value;

		// Convert to lower case
		lowercase_atom_string = Utilities::to_lower_copy(std::string(_atom_string));

		// Find token for the instruction
		index = lowercase_atom_string.find(":instruction");

		if (index == std::string::npos)
			throw;

		// Find start of instruction atom
		index += strlen(":instruction");

		while (lowercase_atom_string[index] == ' ')
			index++;

		start_of_optional_tokens = lowercase_atom_string.find_first_of(" :}", index);

		instruction_name = Utilities::to_upper_copy(lowercase_atom_string.substr(index, start_of_optional_tokens - index));

		// Check for optional close token
		index = lowercase_atom_string.find(":close");

		if (index != std::string::npos)
		{
			start_of_optional_value = index + strlen(":close");

			while (lowercase_atom_string[start_of_optional_value] == ' ')
				start_of_optional_value++;

			close_parenthesis = std::abs(std::stoi(std::string(lowercase_atom_string.substr(start_of_optional_value, index))));

			if (close_parenthesis > Config::maximum_stack_dept)
				close_parenthesis = Config::maximum_stack_dept;
		}

		// Check for optional silent tiken
		index = lowercase_atom_string.find(":silent", start_of_optional_tokens);

		if (index != std::string::npos)
		{
			start_of_optional_value = index + strlen(":silent");

			while (lowercase_atom_string[start_of_optional_value] == ' ')
				start_of_optional_value++;

			if (lowercase_atom_string.find("true") != std::string::npos)
				type = AtomType::silent;
		}

		// Check for boolean
		else if ((instruction_name == boolean_true) || (instruction_name == boolean_false))
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

	// Purpose: 
	//   Returns first atom in genome
	//
	// Parameters:
	//   None
	// 
	// Return value:
	//   The genome's first atom as a sting
	//
	// Side Effects:
	//   None
	//
	// Thread Safe:
	//   Yes
	//
	// Remarks:
	//
	std::string first_atom(std::string _genome_instructions)
	{
		size_t found = _genome_instructions.find_first_of("}");

		if (found == std::string::npos)
			return "";

		else
			return _genome_instructions.substr(0, found + 1);
	}

	// Purpose: 
	//   Returns rest of genome atoms after first atom
	//
	// Parameters:
	//   None
	// 
	// Return value:
	//   The remining genome atoms after the first atom as a sting
	//
	// Side Effects:
	//   None
	//
	// Thread Safe:
	//   Yes
	//
	// Remarks:
	//
	std::string rest_atom(std::string _genome_instructions)
	{
		size_t found = _genome_instructions.find_first_of("}");

		if (found == std::string::npos)
			return "";

		else
			return _genome_instructions.substr(found + 1);
	}
}