cmake_minimum_required(VERSION 3.12)
project(pySolvers)

# 指定C++标准
set(CMAKE_CXX_STANDARD 14)

# 指定查找头文件的路径
include_directories(/home/dafoamuser/workspace/CFD_homework/homework3/Include)

# 获取所有的源文件
file(GLOB SOURCE_FILES /home/dafoamuser/workspace/CFD_homework/homework3/Include/*.C)

# 添加库文件搜索路径
list(APPEND CMAKE_PREFIX_PATH "/home/dafoamuser/dafoam/packages/miniconda3/lib/python3.8/site-packages/pybind11/share/cmake/pybind11")

# 找到pybind11
find_package(pybind11 REQUIRED)

# 添加pybind11头文件
pybind11_add_module(pySolvers solver_binding.cpp ${SOURCE_FILES})


