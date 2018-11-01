#ifndef DUMMYSTATIC_HPP
#define DUMMYSTATIC_HPP

#if !defined(__linux__) && defined(DummyLib_EXPORT)
	# define DummyStatic_Shared __declspec(dllexport)
#elif !defined(__linux__)
	# define DummyStatic_Shared __declspec(dllimport)
#endif

#ifndef DummyStatic_Shared
	#define DummyStatic_Shared
#endif

class DummyStatic_Shared DummyStatic
{
public:
	void dummyStaticFunction();
};

#endif // DUMMYSTATIC_HPP
