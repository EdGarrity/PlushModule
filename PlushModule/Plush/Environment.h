#pragma once
#include <map>
#include <string>
#include <vector>
#include "Genome.h"

namespace Plush
{
	class Environment
	{
	private:
		// Stacks
		Genome<long> int_stack_;

	public:
		virtual void clear_stacks()
		{
			int_stack_.clear();
		}

		virtual void initialize(std::vector<double>& _input)
		{
			clear_stacks();
		}

		template <typename T> inline Genome<T>& get_stack() {}
		template <> inline Genome<long>& get_stack()
		{
			return int_stack_;
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
	};
}