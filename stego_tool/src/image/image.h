#ifndef _image_h
#define _image_h

#include <string>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>

namespace StegoTool
{
	class Image
	{
	public:
		Image(const std::string& pathToFile); 
		Image(const cv::Mat& head, const std::string& pathToFile);
		~Image();

		// cols = w * c;
		// w * c * h = cols * rows; 
		int get_width() const;
		int get_height() const;
		int get_channels() const;
		int get_cols() const;
		int get_rows() const;

		uchar get_value_from1d(int pos) const;
		uchar get_value_from2d(int i, int j) const;
		uchar get_value(int i, int j, int c) const;
		
		const cv::Mat& get_mat() const;
		std::string get_original_filename()

		void set_value_in1d(uchar value, int pos);
		void set_value_in2d(uchar value, int i, int j);
		void set_value(uchar value, int i, int j, int c);

		unsigned char* get_1d_ptr();
	private:
		cv::Mat image;
		std::string filename;
	};
}
#endif