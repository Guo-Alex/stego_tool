#ifndef _image_h
#define _image_h

#include <string>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>

class Image
{
public:
	Image(const std::string& pathToFile);
	~Image();

	// cols = w * c;
	// w * c * h = cols * rows; 
	int get_width() const;
	int get_height() const;
	int get_channels() const;	
	int get_cols() const;
	int get_rows() const;

	int get_value_from1d(int pos) const;
	int get_value_from2d(int i, int j) const;
	int get_value(int i, int j, int c) const;

	unsigned char* get_1d_ptr();
private: 
	cv::Mat image;
};

#endif