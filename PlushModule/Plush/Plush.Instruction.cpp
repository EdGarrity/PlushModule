#include "Plush.Instruction.h"
//#include "Plush.StaticInit.h"
//#include "GenericInstructions.h"

namespace Plush
{
//#define PUSH_GENERIC(name, func)\
//		push_make_instruction((Operator)func<ExecAtom>, "EXEC", #name, func##_in<ExecAtom>(), func##_out<ExecAtom>());\
//		push_make_instruction((Operator)func<long>, "INTEGER", #name, func##_in<long>(), func##_out<long>());\
//		push_make_instruction((Operator)func<double>, "FLOAT", #name, func##_in<double>(), func##_out<double>());\
//		push_make_instruction((Operator)func<bool>, "BOOLEAN", #name, func##_in<bool>(), func##_out<bool>());\
//		push_make_instruction((Operator)func<CodeAtom>, "CODE", #name, func##_in<CodeAtom>(), func##_out<CodeAtom>());\
//
//	template <typename T> Type yankdup_in()
//	{
//		return make_type<T, long>();
//	}
//	template <typename T> Type yankdup_out()
//	{
//		return make_type<T>();
//	}
//
//	template <typename T> Type dup_in()
//	{
//		return make_type<T>();
//	}
//	template <typename T> Type dup_out()
//	{
//		return make_type<T>();
//	}
//
//	template <typename T> Type equals_in()
//	{
//		return make_type<T, T>();
//	}
//	//template <typename T> Type equals_out()
//	//{
//	//	return make_type<bool>();
//	//}
//
//	template <typename T> Type flush_in()
//	{
//		return nullType;
//	}
//	template <typename T> Type flush_out()
//	{
//		return nullType;
//	}
//
//	template <typename T> Type protected_pop_in()
//	{
//		return make_type<T>();
//	}
//	template <typename T> Type protected_pop_out()
//	{
//		return nullType;
//	}
//
//	template <typename T> Type rot_in()
//	{
//		return make_type<T, T, T>();
//	}
//	template <typename T> Type rot_out()
//	{
//		return nullType;
//	}
//
//	template <typename T> Type shove_in()
//	{
//		return make_type<T, long>();
//	}
//	template <typename T> Type shove_out()
//	{
//		return make_type<T>();
//	}
//
//	template <typename T> Type stackdepth_in()
//	{
//		return nullType;
//	}
//	//template <typename T> Type stackdepth_out()
//	//{
//	//	return make_type<long>();
//	//}
//
//	template <typename T> Type swap_in()
//	{
//		return make_type<T, T>();
//	}
//	template <typename T> Type swap_out()
//	{
//		return nullType;
//	}
//
//	template <typename T> Type yank_in()
//	{
//		return make_type<T, long>();
//	}
//	template <typename T> Type yank_out()
//	{
//		return nullType;
//	}
//
	void initGenerics()
	{
		//PUSH_GENERIC(YANKDUP, yankdup);
		//PUSH_GENERIC(DUP, dup);
		//PUSH_GENERIC(=, equals);
		//PUSH_GENERIC(FLUSH, flush);
		//PUSH_GENERIC(POP, protected_pop);
		//PUSH_GENERIC(ROT, rot);
		//PUSH_GENERIC(SHOVE, shove);
		//PUSH_GENERIC(STACKDEPTH, stackdepth);
		//PUSH_GENERIC(SWAP, swap);
		//PUSH_GENERIC(YANK, yank);
	}
}