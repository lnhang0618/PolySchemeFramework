**This project tests the following three numerical schemes:**
- **Lax**
- **Lax-Wendroff**
- **First Order Upwind**

**They have been validated based on:**
1. **Stability**
2. **Numerical Accuracy**
3. **Dissipation phenomena and the phase lead or lag**

**Quick_Start:**
For a quick review of the results from the above points, please refer to the **Quick_start.ipynb** file:
1. Each module in it contains a pre-processed animation file simulating stability under various CFL conditions.
2. By fixing the total time T and the time difference dt, the change in format accuracy with dx is verified.
3. Dissipation phenomena are observed using the Lax scheme at CFL=0.5, and phase lead is observed with Lax-Wendroff at CFL=0.8.

**Project Details:**
The solver for this project is implemented in C++, while plotting is done using Python. The connection between C++ and Python is achieved through pybind11.
The project's structure attempts to mimic the design of OpenFoam.
1. Folders named **Lax, Lax-Wendroff, and Upwind** store the initial and boundary conditions settings and solutions for the respective numerical schemes.
2. The **Include** folder manages files in a flat structure. The files in this folder are symbolically linked to the files in other folders with the same names, primarily to resolve the issue of header files not finding each other in a hierarchical directory.
3. The **Solvers** folder contains the abstract Solvers class, aiming to implement polymorphism for different solvers.
4. The **DataTable** folder stores some custom data structures.
5. The **Wrapper** folder is for creating the Solverswrapper, establishing the high-level functions from C++ to Python.
6. The **Scripts** folder contains scripts, including:
    - **Allmake**: Wraps C++ into a .so shared library for ipynb invocation.
    - **Allclean**: Clears all generated items.
    - **Allink**: Creates symbolic link members under the Include folder.
    - **other**: Objects required by pybind11.
