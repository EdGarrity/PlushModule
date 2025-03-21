#include "Plush.StaticInit.h"
#include "Environment.h"
#include "Plush.Instruction.h"
//#include "..\Utilities\MyException.h"
#include "TypeDef.h"

namespace Plush
{
	thread_local StaticInit static_initializer;
	//StaticInit static_initializer;

	void initGenerics();
	//void initBool();
	//void initExec();
	//void initFloat();
	//void initInt();

	Type execType; //(EXEC_STACK+1,EXEC_STACK,1);
	Type integerType; //(INTEGER_STACK+1,INTEGER_STACK,1);
	Type codeType; //(CODE_STACK+1, CODE_STACK,1);
	Type boolType; //(BOOL_STACK+1, BOOL_STACK,1);
	Type floatType; //(FLOAT_STACK+1, FLOAT_STACK,1);
	Type nullType;

	void init_types()
	{
		execType = Type(EXEC_STACK + 1, EXEC_STACK, 1);
		integerType = Type(INTEGER_STACK + 1, INTEGER_STACK, 1);
		codeType = Type(CODE_STACK + 1, CODE_STACK, 1);
		boolType = Type(BOOL_STACK + 1, BOOL_STACK, 1);
		floatType = Type(FLOAT_STACK + 1, FLOAT_STACK, 1);
	}

	StaticInit::StaticInit()
	{
		init_types();

		initGenerics();
		//initBool();
		//initExec();
		//initFloat();
		//initInt();
	};

	//void StaticInit::push_register_pushfunc(Instruction* pInstruction)
	//{
	//	std::string func_name = pInstruction->to_string();
	//	Func2CodeMap[func_name] = pInstruction;
	//	function_names.push_back(func_name);
	//}

	//void StaticInit::set_parentheses(std::string type, std::string name, unsigned int block_wants)
	//{
	//	std::string func_name = type + "." + name;

	//	if (is_function_supported(func_name))
	//		Func2BlockWantsMap[func_name] = block_wants;
	//};

	//unsigned long StaticInit::number_of_functions()
	//{
	//	return (unsigned long)function_names.size();
	//}

	//std::string StaticInit::get_function_name(unsigned long function_index)
	//{
	//	return function_names[function_index % number_of_functions()];
	//}

	//unsigned long StaticInit::get_function_index(std::string function_name)
	//{
	//	for (unsigned long n = 0; n < function_names.size(); n++)
	//		if (function_names[n] == function_name)
	//			return n;

	//	return -1;
	//}

	//unsigned int StaticInit::get_function_block_wants(std::string function_name)
	//{
	//	unsigned int blocks = 0;

	//	try
	//	{
	//		blocks = Func2BlockWantsMap.at(function_name);
	//	}
	//	catch (const std::out_of_range&)
	//	{
	//		return 0;
	//	}

	//	return blocks;
	//}

	//Instruction * StaticInit::get_function(std::string function_name)
	//{
	//	//if (!is_function_supported(function_name))
	//	//	throw MyException("StaticInit::get_function() out_of_range");

	//	return Func2CodeMap[function_name];
	//}

	//Instruction* StaticInit::get_function(unsigned long function_index)
	//{
	//	return Func2CodeMap[function_names[function_index % number_of_functions()]];
	//}

	bool StaticInit::is_function_supported(std::string function_name)
	{
		return Func2CodeMap.find(function_name) != Func2CodeMap.end();
	}

	//void push_make_instruction(Operator op, std::string type, std::string name, Type in, Type out)
	//{
	//	static_initializer.push_register_pushfunc(new Instruction(op, type + "." + name, in, out));
	//}
}