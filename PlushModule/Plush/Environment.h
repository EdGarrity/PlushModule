#pragma once
#include <map>
#include <string>
#include "Genome.h"
#include "Type.h"
#include "TypeDef.h"

namespace Plush
{
	class Environment
	{
	private:
		// Stacks
		Genome<ExecAtom> exec_stack_;
		Genome<CodeAtom> code_stack_;
		Genome<long> int_stack_;
		Genome<double> double_stack_;
		Genome<bool> bool_stack_;

		typedef std::map<std::string, Instruction*> Func2CodeMapType;
		Func2CodeMapType Func2CodeMap;

	public:
		//Environment()
		//{
		//}

		// Pointer to input & output data
		size_t record_index = 0;
		std::vector<double> output;

		std::array<std::string, Config::maximum_stack_size> temp_genes;

		virtual void clear_stacks()
		{
			exec_stack_.clear();
			int_stack_.clear();
			code_stack_.clear();
			bool_stack_.clear();
			double_stack_.clear();

			//null_input.clear();
			record_index = 0;
			output.clear();
		}

		virtual void initialize(std::vector<double>& _input)
		{
			clear_stacks();
			record_index = 0;
			output.clear();
		}

		void enable_function(std::string function_name)
		{
		}

		void enable_function(unsigned long function_index)
		{
		}

		template<typename T>
		bool assert_length(unsigned long needed)
		{
			Genome<T>& stack = get_stack<T>();
			return stack.size() >= needed;
		}

		template<>
		bool assert_length<CodeAtom>(unsigned long needed)
		{
			Genome<CodeAtom>& genome = get_stack<CodeAtom>();
			//return genome.number_of_blocks() >= needed;

			return genome.number_of_blocks_at_least(needed);
		}

		template<>
		bool assert_length<ExecAtom>(unsigned long needed)
		{
			Genome<ExecAtom>& genome = get_stack<ExecAtom>();
			//return genome.number_of_blocks() >= needed;

			return genome.number_of_blocks_at_least(needed);
		}

		Instruction* get_function(std::string function_name)
		{
			auto search = Func2CodeMap.find(function_name);

			if (search != Func2CodeMap.end())
				return Func2CodeMap[function_name];

			else
				return nullptr;
		}

		template <typename T> inline Genome<T>& get_stack() {}
		template <> inline Genome<ExecAtom>& get_stack()
		{
			return exec_stack_;
		}
		template <> inline Genome<CodeAtom>& get_stack()
		{
			return code_stack_;
		}
		template <> inline Genome<long>& get_stack()
		{
			return int_stack_;
		}
		template <> inline Genome<double>& get_stack()
		{
			return double_stack_;
		}
		template <> inline Genome<bool>& get_stack()
		{
			return bool_stack_;
		}

		template <typename T> inline bool is_empty()
		{
			return (get_stack<T>().is_empty());
		}

		template <typename T> inline void clear()
		{
			get_stack<T>().clear();
		}

		/* pushing and popping */

		template <typename T>
		inline unsigned long push(T value)
		{
			get_stack<T>().push(value);
			return 1;
		}

		template <typename T>
		inline T pop()
		{
			T val = get_stack<T>().get_top_atom();
			get_stack<T>().pop();
			return val;
		}

		/* Needed for type checking of preconditions */
		inline bool check_stack_size_at_least(unsigned long which, unsigned long size_needed) //const
		{
			switch (which)
			{
			case EXEC_STACK: return assert_length<ExecAtom>(size_needed);
			case INTEGER_STACK: return int_stack_.size() >= size_needed;
			case CODE_STACK: return assert_length<CodeAtom>(size_needed);
			case BOOL_STACK: return bool_stack_.size() >= size_needed;
			case FLOAT_STACK: return double_stack_.size() >= size_needed;
			}
			return false;
		}

		/* Needed for type checking of post conditions */
		inline unsigned long get_stack_free(unsigned long which) //const
		{
			switch (which)
			{
			case EXEC_STACK: return exec_stack_.free();
			case INTEGER_STACK: return int_stack_.free();
			case CODE_STACK: return code_stack_.free();
			case BOOL_STACK: return bool_stack_.free();
			case FLOAT_STACK: return double_stack_.free();
			}
			return 0;
		}
	};
}