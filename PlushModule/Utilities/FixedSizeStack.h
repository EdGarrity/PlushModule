#pragma once
#include <array>

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

namespace Plush
{
	namespace Utilities
	{
		template<class T, unsigned long N>
		class FixedSizeStack
		{
		private:
			std::array<T, N> stack_;
			unsigned long top_ = 0;

		public:
			// Constructor
			FixedSizeStack() = default;

			// Destructor
			~FixedSizeStack() = default;

			// Push an element onto the stack
			void push(const T& _value)
			{
				if (top_ < N)
				{
					stack_[top_] = _value;
					top_++;
				}
				else
				{
					throw std::out_of_range("Stack overflow");
				}
			}

			// Pop an element from the stack
			T pop()
			{
				if (top_ > 0)
				{
					top_--;
					return stack_[top_];
				}
				else
				{
					throw std::out_of_range("Stack underflow");
				}
			}

			// Peek at the top element of the stack without removing it
			T peek() const
			{
				if (top_ > 0)
				{
					return stack_[top_ - 1];
				}
				else
				{
					throw std::out_of_range("Stack is empty");
				}
			}
			bool is_empty() const { return top_ == 0; }
			bool is_full() const { return top_ == N; }
			unsigned long size() const { return top_; }
			unsigned long capacity() const { return N; }

			void clear()
			{
				top_ = 0;
			}

			void resize(unsigned long _new_size)
			{
				if (_new_size > N)
					throw std::out_of_range("New size exceeds maximum capacity");

				top_ = (_new_size < top_) ? _new_size : top_;
			}

			void swap(FixedSizeStack& _other)
			{
				std::swap(stack_, _other.stack_);
				std::swap(top_, _other.top_);
			}
		}
	};
}
