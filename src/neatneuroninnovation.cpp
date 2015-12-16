#include "headers/neatneuroninnovation.hpp"

NEATNeuronInnovation::NEATNeuronInnovation(unsigned from_neuron, unsigned to_neuron)
:from_neuron_(from_neuron), to_neuron_(to_neuron)
{
}

bool NEATNeuronInnovation::operator<(const NEATNeuronInnovation& other) const
{
    if(from_neuron_<other.from_neuron_)
        return true;
    if(from_neuron_>other.from_neuron_)
        return false;
    if(to_neuron_<other.to_neuron_)
        return true;
    return false;
}