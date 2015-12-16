#ifndef __NEATPYTHONWRAPPER_HPP__
#define __NEATPYTHONWRAPPER_HPP__

#include <boost/python.hpp>

#include "headers/neat.hpp"
#include "headers/neatnetwork.hpp"

namespace py = boost::python;

class PyNEAT {
public:
    PyNEAT(int inputs, int outputs);
    void populate();
    py::list get_networks();
private:
    NEAT neat_;
};

class PyNEATNetwork {
public:
    PyNEATNetwork(NEATNetwork& network);
private:
    NEATNetwork& neatnetwork_;
};

#endif // __NEATPYTHONWRAPPER_HPP__