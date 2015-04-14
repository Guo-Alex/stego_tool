#ifndef _embedder_h
#define _embedder_h

#include "../image/image.h"
#include "embedder_config.h"

namespace StegoTool {
	class Embedder {
	public:
		Embedder(EmbedderConfig* config)
			:config(config)
		{

		}

		virtual Image Embed(const Image& cover) = 0;

		virtual ~Embedder() {}
	protected:
		EmbedderConfig* config;

	};
}
#endif //_embedder_h