#pragma once
#include <string>
#include <string_view>
#include "../Utilities/FixedSizeStack.h"
#include "Atom.h"
#include "Config.h"

// Favor blocks over atoms algorithm:
// - An atoms is considered a single littoral or instruction.
// - A block is zero or more atoms surrounded by parenthesis.
// - An item is an atom or a block
// - A genome is a list of one or more items.  A genome must end in a block to mark the end of the genome if not the last genome.
// - A genome is processed as a list object, i.e., an open parenthesis is assumed to exist before the first item on the stack.
// - A genome block level starts at 0 (after first implied open parenthesis) and increments for each nested block
// - Nested blocks begin with the item after a block requiring items
// - Closing parenthesis on block 0 is interpreted as an close - open instruction
// - Closing parenthesis on any other level is an open - close if the block level expects more items of a close if not.
// - Block levels are closed when all expected items are found

namespace Plush
{
	template <class T, unsigned long N = Config::maximum_stack_size>
	class Genome : public Utilities::FixedSizeStack<T, N>
	{
	private:
		// The genome stack
		//Utilities::FixedSizeStack<T, N> genome_stack_;

		// Human readable version of the Plush genome
		std::string genome_string_;

		// Convert genome to a Human readable string
		std::string convert_genome_to_string();

		// Ingest genome string
		void ingest_plush_genome(std::string_view _genome_str);

	public:
		// Constructor
		Genome() = default;

		// Destructor
		~Genome() = default;

		typedef typename std::array<T, N>::value_type value_type;
		typedef typename std::array<T, N>::reference reference;
		typedef typename std::array<T, N>::const_reference const_reference;
		typedef typename std::array<T, N>::size_type size_type;

		//inline reference get_atom_at_index(size_t index)
		//{
		//	return genome_stack_.get_atom_at_index(index);
		//}

		//// Push an item onto the genome stack
		//void push(const T& _value);
		//
		//// Pop an item from the genome stack
		//T pop();
		//
		//// Return the top item on the genome stack
		//T top();

		//// Return the size of the genome stack		
		//unsigned long size();

		//// Return true if the genome stack is empty
		//bool empty();
		//
		//// Return true if the genome stack is full
		//bool full();
		//
		//// Return a human readable version of the genome
		//std::string_view to_string();
	};
}