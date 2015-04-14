#ifndef _shift_compress_steganalyzer_config_h
#define _shift_compress_steganalyzer_config_h

#include "steganalyzer_config.h"
#include "../embedder/lsb_embedder.h"
#include "../compressor/compressor.h"


namespace StegoTool {

	class ShiftCompressSteganalyzer;

	class ShiftCompressSteganalyzerConfig : public SteganalyzerConfig
	{
		friend ShiftCompressSteganalyzer; // can see private fields
	public:
		ShiftCompressSteganalyzerConfig(
			LsbEmbedder* embedder, Compressor* compressor,
			double minEmbeddingRate, double maxEmbeddingRate, double step,
			int addVal = 1, int subVal = 1,
			bool verbose = true)

			: SteganalyzerConfig(verbose),
			embedder(embedder), compressor(compressor),
			minEmbeddingRate(minEmbeddingRate), 
			maxEmbeddingRate(maxEmbeddingRate),
			embeddingStep(step),
			addVal(addVal), subVal(subVal)
		{

		}

	private:
		LsbEmbedder* embedder;
		Compressor* compressor;

		double minEmbeddingRate;
		double maxEmbeddingRate;
		double embeddingStep;
		int addVal;
		int subVal;
	};
}

#endif //_shift_compress_steganalyzer_config_h