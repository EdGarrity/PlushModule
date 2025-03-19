#pragma once
#include <array>
#include <stdexcept>
#include <sstream>

// Purpose: 
//   Impliments a fixed-sized stack (FIFO)
//
//     template<class T> class FixedSizeStack;
//
//   The Utilities::FixedSizeStack class uses a fixed std::array container that gives the programmer 
//   the functionality of a stack - specifically, a LIFO (last-in, first-out) data structure.
//
//   The class template acts as a wrapper to the underlying container - only a specific set of functions 
//   is provided.  The stack pushes and pops the element from the back of the underlying container, 
//   known as the top of the stack.
//
// Template Parameters:
//   T - The type of the stored elements.  The behavior is undefined if T is not the same type as 
//   Container::value_type. (since C++17)
//

namespace Utilities
{
	// Template class definition
	template <class T, unsigned long N>
	class FixedSizeStack
	{
	public:
		typedef typename std::array<T, N>::value_type value_type;
		typedef typename std::array<T, N>::reference reference;
		typedef typename std::array<T, N>::const_reference const_reference;
		typedef typename std::array<T, N>::size_type size_type;

		// Initializes stack
		inline void clear()
		{
			top_ = 0;
		};

		// Constructor
		FixedSizeStack() : stack_(), top_(0), current_thread(999) {}

		// Destructor
		~FixedSizeStack() = default;

		// Checks if the underlying container has no elements
		inline bool is_empty() const
		{
			return top_ == 0;
		}

		inline const_reference get_atom_at_index(size_t index) const
		{
			if (index >= N)
			{
				std::stringstream error_message;
				error_message << "const_reference Utilities::FixedSizeStack::get_atom_at_index - Index Out Of Range.  index = " << index;

				throw std::out_of_range(error_message.str());
			}
			if (index >= top_)
			{
				std::stringstream error_message;
				error_message << "const_reference Utilities::FixedSizeStack::get_atom_at_index - Index Out Of Range.  index = " << index
					<< " top = " << top_;

				throw std::out_of_range(error_message.str());
			}
			return stack_[index];
		}

		inline reference get_atom_at_index(size_t index)
		{
			if (index >= N)
			{
				std::stringstream error_message;
				error_message << "reference Utilities::FixedSizeStack::get_atom_at_index - Index Out Of Range.  index = " << index;

				throw std::out_of_range(error_message.str());
			}
			if (index >= top_)
			{
				std::stringstream error_message;
				error_message << "reference Utilities::FixedSizeStack::get_atom_at_index - Index Out Of Range.  index = " << index
					<< " top = " << top_;

				throw std::out_of_range(error_message.str());
			}
			return stack_[index];
		}

		// Returns the number of elements in the underlying container
		inline unsigned long size() const
		{
			return top_;
		}

	protected:
		// Zero-based index to the first empty slot on the stack
		unsigned long top_ = 0;

		// The containter for the stack
		std::array<T, N> stack_;

		unsigned int current_thread = 999;
	};
}