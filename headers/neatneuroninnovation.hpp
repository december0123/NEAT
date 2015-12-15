#ifndef __NEATNEURONINNOVATION_HPP__
#define __NEATNEURONINNOVATION_HPP__

class NEATNeuronInnovation {
public:
    NEATNeuronInnovation(unsigned from_neuron, unsigned to_neuron);
    bool operator<(const NEATNeuronInnovation& other) const;
private:
    unsigned from_neuron_;
    unsigned to_neuron_;
};

#endif //__NEATNEURONINNOVATION_HPP__