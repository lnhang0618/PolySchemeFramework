#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/numpy.h>
#include <SolversWrapper.H>
#include <Solvers.H>
#include <Data.H>

namespace py = pybind11;

PYBIND11_MODULE(pySolvers, m) {
    py::class_<Solvers>(m, "Solvers")
        .def("run_and_get_data_double", [](Solvers& self, double dx,double dt, double T_end) -> py::list {
            std::vector<TimeStepData> results = self.run_and_get_data_double(dx,dt, T_end);
            
            py::list resultList;
            for (const auto& result : results) {
                resultList.append(py::dict(
                    py::arg("T") = result.T,
                    py::arg("u") = py::array_t<double>(100, result.u),
                    py::arg("u_analy") = py::array_t<double>(100, result.u_analy)
                ));
            }

            return resultList;
        });


    py::class_<SolversWrapper>(m, "SolversWrapper")
        .def(py::init<>())
        .def("createLaxSolver", &SolversWrapper::createLaxSolver, py::return_value_policy::take_ownership)
        .def("destroyLaxSolver", &SolversWrapper::destroyLaxSolver)
        .def("createLax_WendroffSolver", &SolversWrapper::createLax_WendroffSolver, py::return_value_policy::take_ownership)
        .def("destroyLax_WendroffSolver", &SolversWrapper::destroyLax_WendroffSolver)
        .def("createFirstOrderUpwindSolver", &SolversWrapper::createFirstOrderUpwindSolver, py::return_value_policy::take_ownership)
        .def("destroyFirstOrderUpwindSolver", &SolversWrapper::destroyFirstOrderUpwindSolver);
}
