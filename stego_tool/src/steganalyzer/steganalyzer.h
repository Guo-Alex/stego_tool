#ifndef _steganalyzer_h
#define _steganalyzer_h

#include "steganalyzer_config.h"
#include "../image/image.h"

namespace StegoTool {
	class Steganalyzer
	{
	public:
		Steganalyzer(SteganalyzerConfig* config) 
			:config(config)
		{ }

		virtual double Steganalyze(const Image& image) = 0;
		virtual ~Steganalyzer(){}

	protected:
		SteganalyzerConfig* config;
	};
}

#endif