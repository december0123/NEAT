#ifndef __NEATNETWORK_HPP__
#define __NEATNETWORK_HPP__

#include <map>

using NEATNeuronNumber = unsigned;
using NEATNeuronAnswer = float;

class NEATNetwork {
public:

private:
	std::map<NEATNeuronNumber, NEATNeuronAnswer> answers_;
};

#endif // __NEATNETWORK_HPP__