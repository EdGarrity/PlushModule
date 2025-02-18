#include "pch.h"
#include "CppUnitTest.h"
#include "..\UnitTest\Utilities\HelperFunctions.h"
#include "..\PlushModule\Plush\Environment.h"
#include "..\PlushModule\Plush\Processor.h"
#include "..\PlushModule\Plush\Plush.StaticInit.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Plush
{
	thread_local StaticInit static_initializer;
}

namespace PlushUnitTest
{
	//Plush::Environment env;


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
		//Plush::Environment env;

		TEST_METHOD(EQUALS_No_Parameters)
		{
			Plush::Environment env;
			//Assert::IsTrue(is_stack_state(env, {}, {}, {}, {}, {}));

			//env.enable_function("BOOLEAN.=");

			//Plush::run(env, \
			//	"\
			//		{:instruction BOOLEAN.= :close 0}\
			//	");

			//Assert::IsTrue(is_stack_state(env, {}, {}, {}, {},
			//	{
			//		CodeAtom("{:instruction BOOLEAN.= :close 0}")
			//	}));
		}
	};
}
