<!--
    MIT License

    Copyright (c) 2018 Rémi Ducceschi

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in all
    copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
    SOFTWARE
-->

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://github.com/remileduc/Qt_DummyLibrary_Example/blob/master/LICENSE)

QT Library test with CMake
==========================

Dummy example to try to build a library with Qt and use it.

Purpose
-------

The goal is to create a simple example to see how we can create a shared library thanks to Qt, and use it in an executable.

In this repo, you have 3 folders under `source`
- `dummy_static`: it creates a static library that exposes one class `DummyStatic` (that doesn't make use of Qt)
- `dummy_lib`: it creates a shared library that is compiled and linked with `dummy_static`. It should expose `DummyStatic` and also `DummyLib`
- `dummy_app`: the applications that is linked to `dummy_lib` and uses the 2 exposed class `DummyStatic` and `DummyLib`

Build
-----

To build the project, follow these steps:

```bash
# create a build dir at the root of the repo
mkdir build && cd build
# run CMake
cmake -G "YOUR IDE" ../source
```
