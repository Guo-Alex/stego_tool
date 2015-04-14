#ifndef _lsb_embedder_config_h
#define _lsb_embedder_config_h

#include "embedder_config.h"
#include <vector>

namespace StegoTool {
	class LsbEmbedderConfig : public EmbedderConfig
	{
	public:
		LsbEmbedderConfig(double embeddingRate, 
			const std::vector<unsigned char>& message, const std::vector<unsigned int>& positions)
			:	EmbedderConfig(embeddingRate), message(message), positions(positions)
		{

		}
		LsbEmbedderConfig(double embeddingRate, int width, int height, int seed) 
			: EmbedderConfig(embeddingRate)
		{
			int fullSize = width * height;
			int messageLength = (int) embeddingRate * fullSize;
			// genereate message and positions
		}

		int get_message_length() const { return message.size(); }
		unsigned int get_position(int i) const { return positions[i]; }
		unsigned char get_message_char(int i) const{ return message[i]; }

	private:  

		std::vector<unsigned char> message;
		std::vector<unsigned int> positions;
	};
}

#endif
