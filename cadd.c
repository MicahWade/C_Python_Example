#define PY_SSIZE_T_CLEAN
#include <Python.h>

static PyObject* py_add(PyObject* self, PyObject* args) {
    int a, b;

    if (!PyArg_ParseTuple(args, "ii", &a, &b)) {
        return NULL;
    }

    return PyLong_FromLong(a + b);
}

static PyMethodDef custom_methods[] = {
    {"add", py_add, METH_VARARGS, "Adds two integers in C."},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef mymodule = {
    PyModuleDef_HEAD_INIT,
    "Cadd",
    "Addition in C",
    -1,
    custom_methods
};

PyMODINIT_FUNC PyInit_Cadd(void) {
    return PyModule_Create(&mymodule);
}
