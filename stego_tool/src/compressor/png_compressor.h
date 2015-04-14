#ifndef _png_compressor_h
#define _png_compressor_h

#include "compressor.h"
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\core\core.hpp>
#include <vector>

namespace StegoTool {
	class PngCompressor : public Compressor
	{
	public:
		virtual int CompressedLength(const Image& image) {
			std::vector<uchar> buffer;
			cv::imencode(".PNG", image.get_mat(), buffer);

			return buffer.size();
		}
		virtual ~PngCompressor(){}
	};
}
#endif //_png_compressor_h