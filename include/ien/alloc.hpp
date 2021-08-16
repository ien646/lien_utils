#pragma once

#include <cinttypes>
#include <cstdlib>

#include <ien/arithmetic.hpp>
#include <ien/assert.hpp>

namespace ien
{
	template<typename T = uint8_t>
	[[nodiscard]] inline T* aligned_alloc(size_t len, size_t alignment)
	{
		LIEN_DEBUG_ASSERT_MSG(ien::is_power_of_2(alignment), "Alignment value must be a power of 2");

	#ifdef WIN32
		return (T*)_aligned_malloc(sizeof(T) * len, alignment);
	#else
		return (T*)aligned_alloc(sizeof(T) * len, alignment);
	#endif
	}

	void inline aligned_free(void* ptr)
	{
		LIEN_DEBUG_ASSERT_MSG(ptr != nullptr, "Attempt to (aligned) free a null pointer");

	#ifdef WIN32
		return _aligned_free(ptr);
	#else
		return free(ptr);
	#endif
	}

	template<typename T>
	[[nodiscard]] inline T* aligned_realloc(T* ptr, size_t len, size_t alignment)
	{
		aligned_free(ptr);
		return (T*)aligned_alloc(sizeof(T) * len, alignment);
	}
}