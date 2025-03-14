#include "CppUnitTest.h"
#include "..\UnitTest\Utilities\HelperFunctions.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


Plush::Processor processor;
Plush::Environment env;

namespace PlushUnitTest
{
	//TEST_CLASS(PlushUnitTest)
	//{
	//public:
	//	
	//	TEST_METHOD(TestMethod1)
	//	{
	//	}
	//};

	//TEST_CLASS(BooleanInstructions)
	//{
	//public:
	//	TEST_METHOD(EQUALS_No_Parameters)
	//	{
	//		Assert::IsTrue(is_stack_state(env, {}, {}, {}, {}, {}));

	//		env.enable_function("BOOLEAN.=");

	//		processor.run(env, "{:instruction BOOLEAN.= :close 0}");

	//		Assert::IsTrue(is_stack_state(env, {}, {}, {}, {},
	//			{
	//				CodeAtom("{:instruction BOOLEAN.= :close 0}")
	//			}));
	//	}
	//};

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
