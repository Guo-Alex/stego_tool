#include "lsb_embedder.h"
 

namespace StegoTool {
	LsbEmbedder::LsbEmbedder(LsbEmbedderConfig* config)
		: Embedder(config)
	{
		lsbConfig = config;
	}

	Image LsbEmbedder::Embed(const Image& cover)
	{
		Image stego(cover); // todo: is it deep copy?

		for (int i = 0; i < lsbConfig->get_message_length(); ++i)
		{
			unsigned int position = lsbConfig->get_position(i);
			uchar value = stego.get_value_from1d(position);
			value = value - value % 2 + lsbConfig->get_message_char(i);
			stego.set_value_in1d(position, value);
		}

		return stego;
	}

	LsbEmbedder::~LsbEmbedder() {}	
} 