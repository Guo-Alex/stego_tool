#include "image.h"

namespace StegoTool
{
	Image::Image(const std::string& pathToFile)
	{
		image = cv::imread(pathToFile);
	}

	Image::Image(const cv::Mat& head)
		: image(head)
	{

	}

	Image::~Image(){}

	int Image::get_width() const {
		return image.size().width;
	}

	int Image::get_height() const {
		return image.size().height;
	}

	int Image::get_channels() const {
		return image.channels();
	}

	int Image::get_cols() const {		
		return get_width() * get_channels();
	}

	int Image::get_rows() const {
		return get_height();
	}

	uchar Image::get_value_from1d(int pos) const {
		return image.data[pos];
	}

	uchar Image::get_value_from2d(int i, int j) const {
		int pos = i * get_cols() + j;
		return get_value_from1d(pos);
	}

	uchar Image::get_value(int i, int j, int c) const {
		cv::Vec3b intensity = image.at<cv::Vec3b>(i, j);
		return intensity[c];
	}

	void Image::set_value_in1d(uchar value, int pos) {
		image.data[pos] = value;
	}
	void Image::set_value_in2d(uchar value, int i, int j) {
		set_value_in1d(value, i*get_cols() + j);
	}
	void Image::set_value(uchar value, int i, int j, int c){
		cv::Vec3b intensity = image.at<cv::Vec3b>(i, j);
		intensity[c] = value;
	}

	unsigned char* Image::get_1d_ptr() {
		return image.data;
	}

	const cv::Mat& Image::get_mat() const {
		return image;
	}
}