#pragma once
#include <string>
#include <string_view>

namespace Plush
{
	using namespace std::literals;

	class Atom
	{
	public:
		enum class AtomType
		{
			empty = 0,

			ins,
			integer,
			floating_point,
			boolean,

			// This instruction will be replaced by exec_noop, but will still have effects like :close count
			no_op,

			// This instruction will be ignored
			silent
		};

		static const std::string_view boolean_true;
		static const std::string_view boolean_false;

		size_t instruction_id;
		std::string instruction_name;
		AtomType type;
		unsigned int close_parenthesis;

		explicit Atom();

		void clear();
		void set(std::string instruction_name, unsigned long close_parenthesis, AtomType type);
	};
}
