/*
 * Dummy file included during the compile process of DummyLib.
 *
 * The purpose of this file is to make a call to the DummyStatic class from the static library
 * so its content is exported in the final DLL.
 */

#include <DummyStatic.hpp>

const auto _dumb = ([]() -> int {
	DummyStatic().dummyStaticFunction();

	return 0;
})();
