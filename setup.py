import os
from setuptools import Extension, setup

src_dir = os.path.join('src', 'test.c')
setup(name='testing_stuff', version='1.0.5', ext_modules=[Extension('testing_stuff', [src_dir])])