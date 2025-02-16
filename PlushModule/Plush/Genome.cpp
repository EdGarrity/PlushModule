#include "Genome.h"

namespace Plush
{
	// Purpose: 
	//   Convert genome to a Human readable string
	//
	// Parameters:
	//   None
	//
	// Return value:
	//   Read-only string view of the genome
	//
	// Side Effects:
	//   genome_string_ is updated with human readable version of the genome
	//
	// Thread Safe:
	//   Yes
	//
	// Remarks:
	//
	std::string_view Genome::convert_genome_to_string()
	{
		return std::string_view();
	}

	// Purpose: 
	//   Ingest genome string
	//
	// Parameters:
	//   genome_str
	//
	// Return value:
	//   Read-only string view of the genome
	//
	// Side Effects:
	//   genome_string_ = human readable version of the genome
	//
	// Thread Safe:
	//   Yes
	//
	// Remarks:
	//
	void Genome::ingest_plush_genome(std::string_view _genome_str)
	{
	}
}