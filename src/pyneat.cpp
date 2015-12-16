#include <boost/python.hpp>

#include "headers/neatpythonwrapper.hpp"

BOOST_PYTHON_MODULE(neat) {
    py::class_<PyNEAT>("NEAT", py::init<int, int>())
        .def("populate", &PyNEAT::populate)
        .def("get_networks", &PyNEAT::get_networks)
        .def("get_desired_population_size", &PyNEAT::get_desired_population_size)
        .def("set_desired_population_size", &PyNEAT::set_desired_population_size);
    py::class_<PyNEATNetwork>("NEATNetwork", py::init<NEATNetwork&>());
}