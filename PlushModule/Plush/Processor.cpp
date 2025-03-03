#include "Processor.h"
#include "Plush.StaticInit.h"

std::vector<double> null_input;

// Run provided program without inputs
unsigned int Plush::Processor::run(Environment& env, std::string program)
{
	return run(env, program, null_input, false);
}

unsigned int Plush::Processor::run(Environment& env, std::string program, std::vector<double>& input, bool trace)
{
	std::string gene;
	int i = 0;

	// Initialize environment
	env.clear_stacks();

	// Load program into temp
	while ((program.length() > 0) && (i < Config::maximum_stack_size))
	{
		gene = first_atom(program);
		program = rest_atom(program);
		Utilities::trim(program);

		env.temp_genes[i++] = gene;
	}

	// Load inputs
	env.initialize(input);

	if (i > 0)
	{
		int j = i;
		for (int n = 0; n < i; n++)
		{
			Atom atom(env.temp_genes[--j]);

			env.get_stack<CodeAtom>().push(CodeAtom(atom));
			env.get_stack<ExecAtom>().push(ExecAtom(atom));
		}
	}

	// Execute
	return run(env, Config::max_point_evaluations, trace);
}

unsigned int Plush::Processor::run(Environment& env, unsigned _max_effort, bool trace)
{
	// The basic pop-exec cycle
	unsigned int effort = 0;
	unsigned int unit = 0;

	while ((!env.is_empty<ExecAtom>()) && (effort < _max_effort))
	{
		try
		{
			//env.current_effort = effort;
			//env.current_unit = unit;
			unit = 0;

			ExecAtom atom = env.pop<ExecAtom>();

			// Debug - Remember current instruction
			//env.current_instruction = atom.instruction_name;

			std::string instruction_type = "";

			switch (atom.type)
			{
			case Atom::AtomType::integer:
				env.push<long>(std::stol(atom.instruction_name));
				unit = 1;

				instruction_type = "integer";

				break;
			case Atom::AtomType::floating_point:
				env.push<double>(std::stod(atom.instruction_name));
				unit = 1;

				instruction_type = "floating_point";

				break;
			case Atom::AtomType::boolean:
				env.push<bool>(atom.instruction_name == Plush::Atom::boolean_true);
				unit = 1;

				instruction_type = "boolean";

				break;
			case Atom::AtomType::ins:
				// Push open parenthesis onto stack if instruction expects any blocks

				int blocks_closed = atom.close_parenthesis;

				instruction_type = "ins";

				// Close expected blocks for each block the instruction is expecting if the instruction closes that block.
				if (atom.instruction_name != "EXEC.NOOP")
				{
					if (atom.instruction_name.substr(0, 5) == "EXEC.")
					{
						if (blocks_closed > 0)
						{
							std::string noop = "{:instruction EXEC.NOOP :close " + std::to_string(blocks_closed) + "}";
							env.push<ExecAtom>(ExecAtom(noop));
						}
					}
				}

				// Execute the instruction
				if (static_initializer.is_function_supported(atom.instruction_name))
				{
					Instruction* pI = env.get_function(atom.instruction_name);

					if ((pI != nullptr) && (pI->can_run(env)))
					{
						Operator op = pI->get_op();
						unit = op(env);
					}

					else
						instruction_type = "cannot_run";
				}

				else
				{
					instruction_type = "unsupported_instruction";
					std::ostringstream ss; ss << atom.instruction_name << " ";
				}

				break;
			}
		}
		catch (std::underflow_error& /* ex */ )
		{
			effort++;
		}
		catch (std::overflow_error& /* ex */)
		{
			effort++;
		}
		catch (std::exception& /* ex */)
		{
			effort++;
		}
		catch (...)
		{
			effort++;
		}

		effort += (1u) > (unit) ? (1u) : (unit);
	}

	return effort;

}

