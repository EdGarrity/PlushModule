#include "pch.h"
#include "CppUnitTest.h"
#include "..\UnitTest\Utilities\HelperFunctions.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PlushUnitTest
{
	TEST_CLASS(PlushUnitTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
		}
	};

	TEST_CLASS(BooleanInstructions)
	{
	public:
		TEST_METHOD(EQUALS_No_Parameters)
		{
			Environment env;
			Assert::IsTrue(is_stack_state(env, {}, {}, {}, {}, {}));

			env.enable_function("BOOLEAN.=");

			Plush::run(env, \
				"\
					{:instruction BOOLEAN.= :close 0}\
				");

			Assert::IsTrue(is_stack_state(env, {}, {}, {}, {},
				{
					CodeAtom("{:instruction BOOLEAN.= :close 0}")
				}));
		}
	};
}
