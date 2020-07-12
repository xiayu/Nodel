#pragma once
#include <memory>

#define BIT(x) (1 << x)

#define ND_EVENT_BIND_FUNC(x) std::bind(&x, this, std::placeholders::_1)

#if ND_ENABLE_ASSERTS
	#define ND_ASSERT(x, ...) {if(!(x)){ND_ERROR("assert fail:", __VA_ARGS__); __debugbreak();}}
#else
	#define ND_ASSERT(x, ...)
#endif 
namespace Nodel {
	template<typename T>
	using Uni = std::unique_ptr<T>;

	template<typename T, typename ... Args>
	constexpr Uni<T> CreateUni(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using Ref = std::shared_ptr<T>;

	template<typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}
}