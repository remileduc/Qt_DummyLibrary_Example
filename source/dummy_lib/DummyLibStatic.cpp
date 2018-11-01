/*
 * Dummy file included during the compile process of DummyLib.
 *
 * The purpose of this file is to make a call to the DummyStatic class from the static library
 * so its content is exported in the final DLL.
 */

#include <DummyStatic.hpp>

volatile auto _DummyStatic_dummyStaticFunction = &DummyStatic::dummyStaticFunction;
volatile auto _DummyStatic_dummyFunction = &DummyStatic::dummyFunction;
