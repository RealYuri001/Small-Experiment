#define PY_SSIZE_T_CLEAN
#include <Python.h>

static PyObject *add_numbers(PyObject *self, PyObject *args) {
    double num1, num2;
    if (!PyArg_ParseTuple(args, "dd", &num1, &num2)) {
        return NULL;
    }

    double result = num1 + num2;
    return PyFloat_FromDouble(result);
}

static PyMethodDef methods[] = {
    {"add_numbers", add_numbers, METH_VARARGS, "Add two numbers"},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef mymodule = {
    PyModuleDef_HEAD_INIT,
    "testing_stuff",
    "A module that adds two numbers",
    -1,
    methods
};

PyMODINIT_FUNC PyInit_testing_stuff(void) {
    return PyModule_Create(&mymodule);
}