#ifndef _experiment_result_h
#define _experiment_result_h

#include <vector>
#include <string>
#include <sstream>

namespace StegoTool
{
	class ExperimentResult
	{
	public:
		ExperimentResult(int dimension, double positiveLabel)
			: labels(dimension), scores(dimension), filenames(dimension), positiveLabel(positiveLabel)
		{
			
		}

		void set_result(int result_idx, const std::string& filename, double label, double score)
		{
			filenames[result_idx] = filename;
			labels[result_idx] = label;
			scores[result_idx] = score;
		}

		std::string get_info() const
		{
			std::stringstream ss;

			ss << "Files Count: " << filenames.size() << std::endl; 
			ss << "Positive Label: " << positiveLabel << std::endl;

			return ss.str();
		}

	private:
		std::vector<double> labels;
		std::vector<double> scores;
		std::vector<std::string> filenames;
		double positiveLabel;
	};
}

#endif //_experiment_result_h