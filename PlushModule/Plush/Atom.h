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

		//size_t instruction_id;
		std::string instruction_name;
		AtomType type;
		unsigned int close_parenthesis;

		explicit Atom();
		explicit Atom(std::string_view instruction_name, unsigned int close_parenthesis, AtomType type);
		explicit Atom(std::string_view _program_statement);
		explicit Atom(long value);
		explicit Atom(const Atom& other);
		explicit Atom(const Atom* other);

		void clear();
		void set(std::string_view instruction_name, unsigned long close_parenthesis, AtomType type);
		void compile(std::string_view _atom_string);
	};

	class ExecAtom : public Atom
	{
	private:

	public:
		explicit ExecAtom() : Atom() {};
		explicit ExecAtom(std::string _program_statement) : Atom(_program_statement) {};
		explicit ExecAtom(char _program_statement[]) : Atom(_program_statement) {};
		explicit ExecAtom(const char* _program_statement) : Atom(_program_statement) {};
		explicit ExecAtom(long value) : Atom(value) {};
		explicit ExecAtom(double value) : Atom(value) {};
		explicit ExecAtom(bool value) : Atom(value) {};
		explicit ExecAtom(const Atom& other) : Atom(other) {};
		explicit ExecAtom(Atom& other) : Atom(other) {};
		explicit ExecAtom(const Atom* other) : Atom(other) {};
		explicit ExecAtom(Atom* other) : Atom(other) {};

		~ExecAtom() {};

		inline bool operator==(const ExecAtom& other)
		{
			return ((instruction_name == other.instruction_name)
				&& (close_parenthesis == other.close_parenthesis)
				&& (type == other.type));
		};

		inline bool operator!=(const ExecAtom& other) { return !(operator==(other)); };
	};
}
