#include "headers/neat.hpp"
#include "headers/neatgenome.hpp"

NEATGenome::NEATGenome(NEAT& neat) : neat_(neat)
{
    
}

NEATGenome::NEATGenome(NEAT& neat, NEATGenome& parent1, NEATGenome& parent2): neat_(neat)
{
    
}

void NEATGenome::add_neuron(unsigned innovation_id, NEATNeuronGene::GeneType gene_type)
{
    neurons_.emplace(innovation_id, NEATNeuronGene(gene_type));
}

void NEATGenome::add_link(
    unsigned innovation_id,
    unsigned from_neuron,
    unsigned to_neuron,
    float weight,
    bool recurrent=false,
    bool enabled=true
) {
    links_.emplace(innovation_id, NEATLinkGene(
        weight,
        from_neuron,
        to_neuron,
        enabled,
        recurrent
    ));
}