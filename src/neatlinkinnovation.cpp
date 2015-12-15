#include "headers/neatlinkinnovation.hpp"

NEATLinkInnovation::NEATLinkInnovation(unsigned from_neuron, unsigned to_neuron)
:from_neuron_(from_neuron), to_neuron_(to_neuron)
{
}

bool NEATLinkInnovation::operator<(const NEATLinkInnovation& other) const
{
    if(from_neuron_<other.from_neuron_)
        return true;
    if(from_neuron_>other.from_neuron_)
        return false;
    if(to_neuron_<other.to_neuron_)
        return true;
    if(to_neuron_>other.to_neuron_)
        return false;
    return recurrent_<other.recurrent_;
}
