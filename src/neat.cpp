#include <random>

#include "headers/neat.hpp"
#include "headers/neatneurongene.hpp"

NEAT::NEAT(int inputs, int outputs)
    :inputs_(inputs), outputs_(outputs), innovation_database_(*this)
{
    
}

void NEAT::populate()
{
    std::random_device rd;
    std::mt19937 re(rd());
    std::uniform_real_distribution<float> random_float(-1,1);
    
    // create one species with the size of desired_population_size_
    population_.emplace_back();
    for(unsigned i=0; i<desired_population_size_; i++)
    {
        population_[0].push_back(std::move(
            NEATGenome(*this)
        ));
    }
    
    // in each genome add input neuron genes
    for(unsigned input=0; input<inputs_; input++)
    {
        unsigned innovation_id_of_input = innovation_database_.get_id_for_neuron_innovation();
        for(auto genome: population_[0])
            genome.add_neuron(innovation_id_of_input, NEATNeuronGene::GeneType::Input);
    }
    
    // in each genome add bias neuron gene
    unsigned innovation_id_of_bias = innovation_database_.get_id_for_neuron_innovation();
    for(auto genome: population_[0])
        genome.add_neuron(innovation_id_of_bias, NEATNeuronGene::GeneType::Bias);
    
    // in each genome add output neuron genes    
    for(unsigned output=0; output<outputs_; output++)
    {
        unsigned innovation_id_of_output = innovation_database_.get_id_for_neuron_innovation();
        for(auto genome: population_[0])
            genome.add_neuron(innovation_id_of_output, NEATNeuronGene::GeneType::Output);
    }
    
    // in each genome add links from input and bias to outputs
    for(unsigned from=0; from<inputs_+1; from++)
    {
        for(unsigned to=inputs_+1; to<inputs_+outputs_+1; to++)
        {
            unsigned innovation_id_of_link = innovation_database_.get_id_for_link_innovation(from, to, false);
            for(auto genome: population_[0])
            {
                genome.add_link(
                    innovation_id_of_link,
                    from,
                    to,
                    random_float(re)
                );
            }
        }
    }
}

std::vector<NEATNetwork> NEAT::get_networks()
{
    std::vector<NEATNetwork> networks;
    for(auto s: species_)
        for(auto genome: s)
            networks.push_back(genome.to_network());
    return networks;
}