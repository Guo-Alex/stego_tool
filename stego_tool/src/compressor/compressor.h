#ifndef _compressor_h
#define _compressor_h

#include "../image/image.h"

namespace StegoTool {
	class Compressor
	{
	public:
		virtual int CompressedLength(const Image& image) = 0;
		virtual ~Compressor(){}

	};
}
#endif //_compressor_h