#include "experiment\experiment.h"
#include "steganalyzer\shift_compress_steganalyzer.h"
#include "steganalyzer\shift_compress_steganalyzer_config.h"
#include "embedder\lsb_embedder.h"
#include "embedder\lsb_embedder_config.h"
#include "compressor\png_compressor.h"
#include <iostream>

namespace st = StegoTool;

int main(int argc, char* argv[])
{
	std::vector<std::string> files;

	files.push_back("C:\\800\\500_1\\im_0001.bmp");
	files.push_back("C:\\800\\500_1\\im_0002.bmp");
	files.push_back("C:\\800\\500_1\\im_0003.bmp");

	st::LsbEmbedderConfig lsbConfig(0.05, 512, 512, 19);
	st::LsbEmbedder embedder(&lsbConfig);
	st::PngCompressor pngCompressor;

	st::ShiftCompressSteganalyzerConfig stegConfig(&embedder, &pngCompressor, 0.01, 0.05, 0.01);

	st::ShiftCompressSteganalyzer steganalyzer(&stegConfig);

	st::ExperimentResult result = st::Experiment::RunNonMLExperiment(&steganalyzer, &embedder, files, true);

	std::cout << result.get_info() << std::endl;

	std::cin.get();
	return 0;
}