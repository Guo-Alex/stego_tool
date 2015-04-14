#ifndef _lsb_embedder_h
#define _lsb_embedder_h

#include "embedder.h"
#include "lsb_embedder_config.h"

namespace StegoTool {
	class LsbEmbedder : public Embedder
	{
	public:
		LsbEmbedder(LsbEmbedderConfig* config);

		virtual Image Embed(const Image& cover);
		
		virtual ~LsbEmbedder();

	private:
		LsbEmbedderConfig* lsbConfig;
	};
}
#endif