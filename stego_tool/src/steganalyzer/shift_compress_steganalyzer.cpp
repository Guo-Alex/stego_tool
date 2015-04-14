#include "shift_compress_steganalyzer.h"

namespace StegoTool
{

	ShiftCompressSteganalyzer::ShiftCompressSteganalyzer(ShiftCompressSteganalyzerConfig* config)
		: Steganalyzer(config)
	{
		myConfig = config;
	}
	
	ShiftCompressSteganalyzer::~ShiftCompressSteganalyzer()
	{ 
	}

	double ShiftCompressSteganalyzer::Steganalyze(const Image& image)
	{
		Image shifted(image.get_mat() / 2, image.get_original_filename()); 
		Image addedShifted((image.get_mat() + myConfig->addVal) / 2);
		Image subbedShifted((image.get_mat() - myConfig->subVal) / 2);
		
		int targetLength = (int)(0.5 *
			myConfig->compressor->CompressedLength(addedShifted) +
			myConfig->compressor->CompressedLength(subbedShifted));

		int prevLength = myConfig->compressor->CompressedLength(shifted);
		if (prevLength > targetLength)
		{
			return 0.0;
		}
		
		for (double q = myConfig->minEmbeddingRate; q <= myConfig->maxEmbeddingRate; q += myConfig->embeddingStep)
		{
			Image stego = myConfig->embedder->Embed(shifted);

			int curStegoLength = myConfig->compressor->CompressedLength(stego);

			if (curStegoLength > targetLength)
			{
				double fx0 = q - myConfig->embeddingStep; // prevLength embeddingRate

				//double fx1 = q;
				//double fx1 - fx0 = options.embeddingRateStep;
				//double x1-x0 = curStegoLength - prevLength
				//double x = targetLength;
				//double x-x0 = targetLength - prevLength
				return fx0 + myConfig->embeddingStep /
					(curStegoLength - prevLength) * (targetLength - prevLength);
			}

			prevLength = curStegoLength;
		}
		return myConfig->maxEmbeddingRate;
	}
	

}