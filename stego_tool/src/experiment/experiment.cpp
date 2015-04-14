#include "experiment.h"

namespace StegoTool
{
	ExperimentResult Experiment::RunNonMLExperiment(Steganalyzer* steganalyzer,
		Embedder* embedder,
		const std::vector<std::string>& inputFiles,
		bool verbose)
	{
		int dimension = inputFiles.size();

		ExperimentResult result(dimension, embedder->get_embedding_rate());

		for (int fileIdx = 0; fileIdx < dimension; ++fileIdx)
		{
			Image cover(inputFiles[fileIdx]);

			double coverResult = steganalyzer->Steganalyze(cover);

			result.set_result(fileIdx, inputFiles[fileIdx], 0.0, coverResult);

			Image stego = embedder->Embed(cover);

			double stegoResult = steganalyzer->Steganalyze(stego);

			result.set_result(fileIdx, inputFiles[fileIdx], embedder->get_embedding_rate(), stegoResult);			
		}

		return result;
	}
}