#ifndef __NEATGENOME_HPP__
#define __NEATGENOME_HPP__

#include <set>
#include <map>

#include "headers/neatlinkgene.hpp"
#include "headers/neatneurongene.hpp"

class NEATNetwork;
class NEAT;

using Neurons = std::map<unsigned, NEATNeuronGene>;
using Links = std::map<unsigned, NEATLinkGene>;

class NEATGenome {
public:
    NEATGenome(NEAT& neat);
    NEATGenome(NEAT& neat, NEATGenome& parent1, NEATGenome& parent2);
    void add_neuron(unsigned innovation_id, NEATNeuronGene::GeneType);
    void add_link(
        unsigned innovation_id,
        unsigned from_neuron,
        unsigned to_neuron,
        float weight,
        bool recurrent=false,
        bool enabled=true
    );
    NEATNetwork to_network();
private:
    NEAT& neat_;
    Neurons neurons_;
    Links links_;
};

#endif // __NEATGENOME_HPP__