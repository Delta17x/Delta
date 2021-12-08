/*
MIT License
Copyright (c) 2021 Delta17x
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
SOFTWARE.
*/
#ifndef _DLT_MEMORY_
#define _DLT_MEMORY_
#include "utility.hpp"
#include "cstdint.hpp"
_DLT_BEGIN
template<class SrcT, class DestT>
inline DestT* copy(SrcT* src_begin, const SrcT* src_end, SrcT* dest_begin) {
	while (src_begin != src_end) {
		*dest_begin++ = *src_begin++;
	}
	return dest_begin;
}

inline void* copy(const void* src, void* dest, uint64_t byte_count) {
	auto mod = byte_count % sizeof(int32_t);
	if ((uintptr_t)src % sizeof(int32_t) == 0 &&
		(uintptr_t)dest % sizeof(int32_t) == 0 &&
		mod == 0) { // Copy sizeof(int32_t) bytes at a time
		const int32_t* sc = (const int32_t*)src;
			  int32_t* dst = (     int32_t*)dest;
		for (uint64_t i = 0; i < byte_count / sizeof(int32_t); i++) {
			dst[i] = sc[i];
		}
	}
	else {
		uint8_t* dst = (uint8_t*)dest;
		const uint8_t* sc = (const uint8_t*)src;
		for (uint64_t i = 0; i < byte_count; i++) {
			dst[i] = sc[i];
		}
	}
	return dest;
}

template<class SrcT, class DestT>
inline DestT* move(SrcT* src_begin, const SrcT* src_end, SrcT* dest_begin) {
	while (src_begin != src_end) {
		*dest_begin++ = *src_begin++;
	}
	src_begin = nullptr;
	return dest_begin;
}

template<class T>
struct allocator {
	using value_t = T;
	allocator() {} 
	// Allocates space for "amount" elements.
	_NODISCARD T* allocate(size_t amount) const {
		return new T[amount];
	}
	// Deallocates memory previously allocated with allocator::allocate().
	void deallocate(T* allocated) const {
		delete[] allocated;
	}
	template<class U>
	using other = allocator<U>;
};

template<class Alloc>
struct allocator_traits {
	using allocator_t = Alloc;
	using value_t = typename Alloc::value_t;
	
	//using pointer = /* see description */;
	//using const_pointer = /* see description */;
	//using void_pointer = /* see description */; 
	//using const_void_pointer = /* see description */;
	//
	//using difference_type = /* see description */;
	//using size_type = /* see description */;
	
};
_DLT_END
#endif // !_DLT_MEMORY_