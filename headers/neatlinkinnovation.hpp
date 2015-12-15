#ifndef __NEATLINKINNOVATION_HPP__
#define __NEATLINKINNOVATION_HPP__

class NEATLinkInnovation {
public:
    NEATLinkInnovation(unsigned from_neuron, unsigned to_neuron);
    bool operator<(const NEATLinkInnovation& other) const;
private:
    unsigned from_neuron_;
    unsigned to_neuron_;
    bool recurrent_;
};

#endif //__NEATLINKINNOVATION_HPP__