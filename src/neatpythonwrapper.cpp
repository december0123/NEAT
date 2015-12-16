#include "headers/neatpythonwrapper.hpp"

PyNEAT::PyNEAT(int inputs, int outputs) : neat_(inputs, outputs) { }

void PyNEAT::populate()
{
    neat_.populate();
}

py::list PyNEAT::get_networks()
{
    py::list output;
    for(NEATNetwork network: neat_.get_networks())
        output.append(PyNEATNetwork(network));
    return output;
}

void PyNEAT::set_desired_population_size(int size)
{
	neat_.set_desired_population_size(size);
}

unsigned PyNEAT::get_desired_population_size()
{
	return neat_.get_desired_population_size();
}

PyNEATNetwork::PyNEATNetwork(NEATNetwork& network) : neatnetwork_(network) { }