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

PyNEATNetwork::PyNEATNetwork(NEATNetwork& network) : neatnetwork_(network) { }