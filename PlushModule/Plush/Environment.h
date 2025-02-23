#pragma once
#include <map>
#include <string>
#include "Genome.h"

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

	public:
		Environment()
		{
		}

		void enable_function(std::string function_name)
		{
		}

		void enable_function(unsigned long function_index)
		{
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

	};
}