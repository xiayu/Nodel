#pragma once

#define BIT(x) (1 << x)

#define ND_EVENT_BIND_FUNC(x) std::bind(&x, this, std::placeholders::_1)

#if ND_ENABLE_ASSERTS
	#define ND_ASSERT(x, ...) {if(!(x)){ND_ERROR("assert fail:", __VA_ARGS__); __debugbreak();}}
#else
	#define ND_ASSERT(x, ...)
#endif 