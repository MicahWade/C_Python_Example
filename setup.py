from setuptools import Extension, setup

module = Extension("Cadd", sources=["cadd.c"])

setup(
    name="Cadd",
    version="1.0",
    description="Simple addition module written in C",
    ext_modules=[module],
)
