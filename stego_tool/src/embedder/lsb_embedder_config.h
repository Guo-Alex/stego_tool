#ifndef _lsb_embedder_config_h
#define _lsb_embedder_config_h

#include "embedder_config.h"
#include <vector>

#include <algorithm>
#include <iterator>
#include <random>
#include <numeric>   


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

			message = std::vector<unsigned char>(messageLength);
			
			// genereate message and positions
			 
			std::mt19937 mt(seed);
			std::uniform_real_distribution<double> dist(0, 1);

			for (int i = 0; i < (int)message.size(); ++i)
				message[i] = dist(mt) > 0.5 ? 1 : 0;
			
			std::vector<unsigned int> all_positions(fullSize);
			std::iota(all_positions.begin(), all_positions.end(), 0);

			std::random_shuffle(all_positions.begin(), all_positions.end());

			positions = std::vector<unsigned int>(all_positions.begin(), all_positions.begin() + messageLength);
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
