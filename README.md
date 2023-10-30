**本项目测试了以下三种数值格式：**
- **Lax**
- **Lax-Wendroff**
- **First Order Upwind**

**分别验证了它们的：**
1. **稳定性**
2. **数值精度**
3. **耗散现象以及相位的超前与滞后**

**Quick_Start：**
为了快速查看123的结果，请点击文件**Quick_start.ipynb**
1. 在其中每个模块下都有一段已经处理过的动画文件，其中模拟了不同CFL下的稳定性。
2. 固定总时间T与差分时间dt，来验证格式精度随dx的变化。
3. 利用CFL=0.5时的Lax格式观察耗散现象，利用CFL=0.8的Lax-Wendroff来观察相位的超前。

**项目细节：**
本项目求解器完成于C++，作图使用python，其中通过pybind11来构造C++-python API。
本项目试图模仿OpenFoam的设计架构来放置文件。
1. **Lax，Lax-Wendroff，Upwind**等文件夹用于存放同名的数值格式的初边条件设置与求解
2. **Include**文件夹用于扁平化管理文件，其中的文件通过符号链接与各文件夹中的同名文件绑定，主要用于解决层次化目录下头文件彼此找不到的情况
3. **Solvers**文件夹存放了Solvers虚类，用于实现不同求解器的多态问题。
4. **DataTable**文件夹存放了自定义的一些数据结构
5. **Wrapper**文件夹用于创建Solverswrapper,实现了由C++-python的上层函数
6. **Scripts**文件夹中存放脚本，包括：
    - **Allmake**： 将C++封装成.so共享库给ipynb调用
    - **Allclean**： 清除所有生成项
    - **Allink**： 创建Include下的符号链接成员
    - **other**： pybind11的需求对象

    

