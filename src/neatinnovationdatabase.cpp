#include "headers/neatinnovationdatabase.hpp"

NEATInnovationDatabase::NEATInnovationDatabase(const NEAT& neat) : neat_(neat)
{
    
}

unsigned NEATInnovationDatabase::get_id_for_link_innovation(
    unsigned from_neuron, unsigned to_neuron, bool recurrent
) {
    auto innovation = NEATLinkInnovation(from_neuron, to_neuron, recurrent);
    auto iterator = link_innovations_.find(innovation);
    if(iterator==link_innovations_::end)
    {
        link_innovations_[innovation] = ++global_innovation_counter_;
        return global_innovation_counter_;
    }
    return *iterator;
}

NEATInnovationDatabase::get_id_for_neuron_innovation(
    unsigned from_neuron, unsigned to_neuron
) {
    auto innovation = NEATNeuronInnovation(from_neuron, to_neuron);
    auto iterator = neuron_innovations_.find(innovation);
    if(iterator==neuron_innovations_::end)
    {
        neuron_innovations_[innovation] = ++global_innovation_counter_;
        return global_innovation_counter_;
    }
    return *iterator;
}

NEATInnovationDatabase::get_id_for_neuron_innovation()
{
    return ++global_innovation_counter_;
}