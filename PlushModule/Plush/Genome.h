#pragma once
#include <string>
#include <string_view>
#include <stack>
#include "../Utilities/FixedSizeStack.h"
#include "Config.h"
#include "Atom.h"

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
		typedef typename std::array<T, N>::value_type value_type;
		typedef typename std::array<T, N>::reference reference;
		typedef typename std::array<T, N>::const_reference const_reference;
		typedef typename std::array<T, N>::size_type size_type;

		// Human readable version of the Plush genome
		std::string genome_string_;

	public:
		// Default constructor
		Genome()
		{
			Utilities::FixedSizeStack<T, Config::maximum_stack_size>::top_ = 0;
		}

		// Purpose: 
		//   Copy constructor
		//
		//   A new Genome object with a new Fixed Stack object is constructed and populated with the 
		//   stack elemets of the provided genome.
		//
		// Parameters:
		//   other - Pointer to genome to copy
		// 
		// Return value:
		//   New genome
		//
		// Side Effects:
		//   None
		//
		// Thread Safe:
		//   Yes.  
		//
		// Remarks:
		//
		inline Genome(Genome* other)
		{
			if (other->top_ >= N)
			{
				std::stringstream error_message;
				error_message << "Utilities::Genome::Genome() - Stack overflow.  top = " << other->top_;

				throw std::overflow_error(error_message.str());
			}

			Utilities::FixedSizeStack<T>::top_ = other->top_;

			for (unsigned long n = 0; n < Utilities::FixedSizeStack<T>::top_; n++)
				Utilities::FixedSizeStack<T>::stack_[n] = other->stack_[n];
		}

		// Purpose: 
		//   Copy constructor
		//
		//   A new Genome object with a new Fixed Stack object is constructed and populated with the 
		//   stack elemets of the provided genome.
		//
		// Parameters:
		//   other - Reference of genome to copy
		// 
		// Return value:
		//   New genome
		//
		// Side Effects:
		//   None
		//
		// Thread Safe:
		//   Yes.  
		//
		// Remarks:
		//
		inline Genome(const Genome<T>& other)
		{
			copy(other);
		}

		// Purpose: 
		//   Copies the provided Genome into the current Genome
		//
		// Parameters:
		//   other - Reference of genome to copy
		// 
		// Return value:
		//   New genome
		//
		// Side Effects:
		//   None
		//
		// Thread Safe:
		//   Yes.  
		//
		// Remarks:
		//
		inline size_t copy(const Genome& other)
		{
			if (other.top_ >= N)
			{
				std::stringstream error_message;
				error_message << "Utilities::Genome::copy() - Stack overflow.  top = " << other.top_;

				throw std::overflow_error(error_message.str());
			}

			Utilities::FixedSizeStack<T>::top_ = other.top_;

			for (long n = 0; n < (long)Utilities::FixedSizeStack<T>::top_; n++)
				Utilities::FixedSizeStack<T>::stack_[n] = other.stack_[n];

			genome_string_ = other.genome_string_;

			return Utilities::FixedSizeStack<T>::top_;
		}

		// Purpose: 
		//   Copies the provided Genome into the current Genome
		//
		// Parameters:
		//   other - Reference of genome to copy
		// 
		// Return value:
		//   New genome
		//
		// Side Effects:
		//   None
		//
		// Thread Safe:
		//   Yes.  
		//
		// Remarks:
		//
		inline void operator= (const Genome& other)
		{
			copy(other);
		}

		// Purpose: 
		//   Clears the genome fields
		//
		// Parameters:
		//   None
		// 
		// Return value:
		//   None
		//
		// Side Effects:
		//   Genome is erased.
		//
		// Thread Safe:
		//   Yes.  
		//
		// Remarks:
		//
		inline size_t clear()
		{
			Utilities::FixedSizeStack<T, Config::maximum_stack_size>::clear();
			genome_string_.clear();

			return 1;
		};
	};
}
