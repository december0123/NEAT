#ifndef __NEAT_HPP__
#define __NEAT_HPP__

#include <vector>

#include "headers/neatgenome.hpp"
#include "headers/neatinnovationdatabase.hpp"

using NEATSpecies = std::vector<NEATGenome>;
using NEATPopulation = std::vector<NEATSpecies>;

class NEAT {
public:
    NEAT(int inputs, int outputs);
    void populate();

    void inline set_desired_population_size(unsigned size) { desired_population_size_=size; }
    unsigned inline get_desired_population_size() { return desired_population_size_; }

private:
    unsigned inputs_;
    unsigned outputs_;
    unsigned desired_population_size_;
    NEATPopulation population_;
    NEATInnovationDatabase innovation_database_;
};

#endif // __NEAT_HPP__