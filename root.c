#include "root.h"
#include <Python.h>
#include <stdlib.h>

void Initialize() { Py_Initialize(); }

void Finalize() { Py_Finalize(); }

double* listTOarray(PyObject* pValue) {
    double* p;
    if (PyList_Check(pValue)) {  //检查是否为List对象
        printf("返回的结果result： ");
        int SizeOfList =
            PyList_Size(pValue);  // List对象的大小，这里SizeOfList =
        for (int i = 0; i < SizeOfList; i++) {
            PyObject* Item =
                PyList_GetItem(pValue, i);  //获取List对象中的每一个元素
            int result;
            PyArg_Parse(Item, "i", &result);  // i表示转换成int型变量
            printf("%d ", result);
            // cout << PyInt_AsLong(Item) <<" "; //输出元素
            Py_DECREF(Item);  //释放空间
        }
        printf("\n");
    } else {
        p = NULL;
    }

    return 1;
}

void root_(double* A, double* B, double* y, double* x) {
    PyObject *pName, *pModule, *pFunc;
    PyObject *pArgs, *pValue, *sys, *path;
    static int i;

    if (i == 0) {
        ++i;
        Initialize();
        atexit(Finalize);
    }

    sys = PyImport_ImportModule("sys");
    path = PyObject_GetAttrString(sys, "path");
    PyList_Append(path, PyString_FromString("."));

    pName = PyString_FromString("func");
    pModule = PyImport_Import(pName);

    if (!pModule) {
        PyErr_Print();
        printf("ERROR in pModule\n");
        exit(1);
    }

    pFunc = PyObject_GetAttrString(pModule, "root");
    pArgs = PyTuple_New(2);
    PyTuple_SetItem(pArgs, 0, PyFloat_FromDouble((*A)));
    PyTuple_SetItem(pArgs, 1, PyFloat_FromDouble((*B)));
    // PyTuple_SetItem(pArgs, 2, PyFloat_FromDouble((*t)));

    //	pValue = PyObject_CallObject(pFunc, pArgs);
    //	*x  = PyFloat_AsDouble(pValue);
    // call python function
    pValue = PyObject_CallObject(pFunc, pArgs);
    if (pValue == NULL) {
        printf("CalllObject return NULL");
        exit(1);
    }

    char* ret_str;
    int w = 0, h = 0;
    //解析元组
    PyArg_ParseTuple(pValue, "s,i,i", &ret_str, &w, &h);

    printf("%s, %d, %d\n", ret_str, w, h);
    //*y  = PyFloat_AsDouble(pValue);
    *x = listTOarray(pValue);
}
