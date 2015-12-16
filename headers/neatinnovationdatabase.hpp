#ifndef __NEATINNOVATIONDATABASE_HPP__
#define __NEATINNOVATIONDATABASE_HPP__

#include <map>

class NEAT;

#include "headers/neatlinkinnovation.hpp"
#include "headers/neatneuroninnovation.hpp"

class NEATInnovationDatabase {
public:
    NEATInnovationDatabase(NEAT& neat);
    
    // returns proper id (new/existing matching) for new link
    unsigned get_id_for_link_innovation(unsigned from_neuron, unsigned to_neuron, bool recurrent);
    
    // returns proper id for neurons that are inserted into connection
    unsigned get_id_for_neuron_innovation(unsigned from_neuron, unsigned to_neuron);

    // returns proper id for input, output and bias neurons 
    unsigned get_id_for_neuron_innovation();

private:
    NEAT& neat_;
    unsigned global_innovation_counter_=0;
    std::map<NEATLinkInnovation, unsigned> link_innovations_;
    std::map<NEATNeuronInnovation, unsigned> neuron_innovations_;
};

#endif //__NEATINNOVATIONDATABASE_HPP__