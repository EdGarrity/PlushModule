#include "CppUnitTest.h"
#include "..\UnitTest\Utilities\HelperFunctions.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


Plush::Processor processor;
Plush::Environment env;

namespace PlushUnitTest
{
	TEST_CLASS(StackManipulation)
	{
	public:
		TEST_METHOD(Push_One_Integer)
		{
			Assert::IsTrue(is_stack_state(env, {}, {}, {}, {}, {}));

			processor.run(env, "{:instruction 609679783 :close  0}");

			Assert::IsTrue(is_stack_state(env, { 609679783 }, {}, {}, {}, {}));
		}
	};
}
