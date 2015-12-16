#include <boost/python.hpp>

#include "headers/neatpythonwrapper.hpp"

BOOST_PYTHON_MODULE(neat) {
    py::class_<PyNEAT>("NEAT", py::init<int, int>())
        .def("populate", &PyNEAT::populate)
        .def("get_networks", &PyNEAT::get_networks);
}