#ifndef _embedder_config_h
#define _embedder_config_h

namespace StegoTool {
	class EmbedderConfig
	{
	public:
		EmbedderConfig(double embeddingRate)
			: embeddingRate(embeddingRate)
		{
		}

		double get_embedding_rate() const { return embeddingRate; }
	private:
		double embeddingRate;
	};
}
#endif
