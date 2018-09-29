#include <maya/MGlobal.h>
#include <pybind11/pybind11.h>

namespace py = pybind11;

void printSome(){

    MGlobal::displayInfo("*********");
    MGlobal::displayWarning("print something use maya Api");
    MGlobal::displayInfo("*********");

}

PYBIND11_MODULE(mayaCommand, m)
{
    // optional module docstring
    m.doc() = "maya api example";
    // expose add function, and add keyword arguments and default arguments
    m.def("printSome", &printSome, "A function print some use api");

    // exporting variables
    m.attr("version") = 42;
    
}
