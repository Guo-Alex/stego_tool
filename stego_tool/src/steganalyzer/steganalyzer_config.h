#ifndef _steganalyzer_config_h
#define _steganalyzer_config_h

namespace StegoTool {
	class SteganalyzerConfig
	{
	public:
		SteganalyzerConfig(bool verbose) {
			verbose = verbose;
		}
		bool get_verbose() { return verbose; }
	private:
		bool verbose;
	};
}
#endif