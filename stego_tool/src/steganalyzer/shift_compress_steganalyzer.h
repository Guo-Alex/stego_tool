#ifndef _shift_compress_steganalyzer_h
#define _shift_compress_steganalyzer_h

#include "steganalyzer.h"
#include "shift_compress_steganalyzer_config.h"

namespace StegoTool
{
	class ShiftCompressSteganalyzer : public Steganalyzer
	{
	public:
		ShiftCompressSteganalyzer(ShiftCompressSteganalyzerConfig* config);

		virtual double Steganalyze(const Image& image);
		virtual ~ShiftCompressSteganalyzer();

	private:
		ShiftCompressSteganalyzerConfig* myConfig;
	};
}

#endif //_shift_compress_steganalyzer_h