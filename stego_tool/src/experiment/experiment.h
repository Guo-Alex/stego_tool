#ifndef _experiment_h_
#define  _experiment_h_

#include "experiment_result.h"
#include "../steganalyzer/steganalyzer.h"
#include "../embedder/embedder.h"

#include <vector>
#include <string>

namespace StegoTool
{
	class Experiment {
	public:
		static ExperimentResult RunNonMLExperiment(Steganalyzer* steganalyzer, 
			Embedder* embedder,
			const std::vector<std::string>& inputFiles, 
			bool verbose); // TODO: add logger
	};
}

#endif // _experiment_h_


