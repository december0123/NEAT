#include <boost/python.hpp>

#include "headers/neat.hpp"
#include "headers/neatnetwork.hpp"


class PyNEAT;
class PyNEATNetwork;

class PyNEAT {
public:
    PyNEAT(int inputs, int outputs) : neat_(inputs, outputs) { }
    void populate()
    {
        neat_.populate();
    }
    list get_networks()
    {
        list output;
        for(NEATNetwork network: neat_.get_networks())
            output.append(PyNEATNetwork(network));
        return output;
    }
private:
    NEAT neat_;
};

class PyNEATNetwork: private NEATNetwork {
public:
    PyNEATNetwork(NEATNetwork& network) : neatnetwork_(network) { }
private:
    NEATNetwork& neatnetwork_;
};

BOOST_PYTHON_MODULE(neat) {

    using namespace boost::python;
    
    class_<NEAT>("NEAT", init<int, int>())
        .def("populate", &PyNEAT::populate)
        .def("get_networks", &PyNEAT::get_networks);
}