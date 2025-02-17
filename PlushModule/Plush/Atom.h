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
		explicit ExecAtom(std::string_view _program_statement) : Atom(_program_statement) {};
		//explicit ExecAtom(char _program_statement[]) : Atom(_program_statement) {};
		//explicit ExecAtom(const char* _program_statement) : Atom(_program_statement) {};
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

	class CodeAtom : public Atom
	{
	private:

	public:
		explicit CodeAtom() : Atom() {};
		explicit CodeAtom(std::string_view _program_statement) : Atom(_program_statement) {};
		//explicit CodeAtom(char _program_statement[]) : Atom(_program_statement) {};
		//explicit CodeAtom(const char* _program_statement) : Atom(_program_statement) {};
		explicit CodeAtom(long value) : Atom(value) {};
		explicit CodeAtom(double value) : Atom(value) {};
		explicit CodeAtom(bool value) : Atom(value) {};
		explicit CodeAtom(const Atom& other) : Atom(other) {};
		explicit CodeAtom(Atom& other) : Atom(other) {};
		explicit CodeAtom(const Atom* other) : Atom(other) {};
		explicit CodeAtom(Atom* other) : Atom(other) {};
		explicit CodeAtom(ExecAtom& other) : Atom(other.instruction_name, other.close_parenthesis, other.type) {};

		~CodeAtom() {};

		inline bool operator==(const CodeAtom& other)
		{
			return ((instruction_name == other.instruction_name)
				&& (close_parenthesis == other.close_parenthesis)
				&& (type == other.type));
		};

		inline bool operator!=(const CodeAtom& other) { return !(operator==(other)); };
	};
}
