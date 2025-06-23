#include <Python.h>
#include <iostream>
#include <string>

int main() {
    // 初始化 Python 解释器
    Py_Initialize();

    std::string user_input;
    std::cout << "请输入内容: ";
    std::getline(std::cin, user_input);

    // 假设 llm.py 和 main.cpp 在同一个目录下
    std::string script_path = "llm.py";
    std::string function_name = "your_function";  // 替换为你的 Python 函数名

    // 将当前目录添加到 Python 的模块搜索路径中
    PyRun_SimpleString("import sys");
    PyRun_SimpleString("sys.path.append('.')");

    // 导入模块
    PyObject *pName = PyUnicode_FromString(script_path.c_str());
    PyObject *pModule = PyImport_Import(pName);
    Py_DECREF(pName);

    if (pModule != nullptr) {
        // 获取函数
        PyObject *pFunc = PyObject_GetAttrString(pModule, function_name.c_str());

        if (pFunc && PyCallable_Check(pFunc)) {
            // 构造参数
            PyObject *pArgs = PyTuple_New(1);
            PyObject *pInput = PyUnicode_FromString(user_input.c_str());
            PyTuple_SetItem(pArgs, 0, pInput);

            // 调用 Python 函数
            PyObject *pValue = PyObject_CallObject(pFunc, pArgs);
            Py_DECREF(pArgs);

            if (pValue != nullptr) {
                // 获取返回值
                char *result = PyUnicode_AsUTF8(pValue);
                std::cout << "Python 函数返回: " << result << std::endl;
                Py_DECREF(pValue);
            } else {
                Py_DECREF(pFunc);
                PyErr_Print();
                std::cout << "函数调用失败" << std::endl;
                Py_Finalize();
                return 1;
            }
            Py_DECREF(pFunc);
        } else {
            if (PyErr_Occurred()) PyErr_Print();
            std::cout << "不能调用该函数" << std::endl;
        }
        Py_DECREF(pModule);
    } else {
        PyErr_Print();
        std::cout << "模块导入失败" << std::endl;
    }

    // 清理 Python 环境
    Py_Finalize();

    return 0;
}