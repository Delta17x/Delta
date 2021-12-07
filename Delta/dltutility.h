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
#ifndef _DLTUTILITY_
#define _DLTUTILITY_
#define _DLT_BEGIN namespace dlt {
#define _DLT_END }
_DLT_BEGIN
#define _HAS_CPP11 __cplusplus > 201103L
#define _HAS_CPP17 __cplusplus > 201703L

#if _HAS_CPP17
#define _INLINE inline
#else
#define _INLINE
#endif

#if _HAS_CPP11
#define _NOEXCEPT noexcept
#else
#define _NOEXCEPT
#endif 

typedef   signed char int1_t;
typedef unsigned char uint1_t;
typedef   signed short int int2_t;
typedef unsigned short int uint2_t;
typedef   signed int int4_t;
typedef unsigned int uint4_t;
#if __WORDSIZE == 64
typedef   signed long int int8_t;
typedef unsigned long int uint8_t;
#else
typedef   signed long long int int8_t;
typedef unsigned long long int uint8_t;
#endif

template<class T, T val>
struct variable_constant {
	constexpr static T data = val;
	inline operator T() const _NOEXCEPT {
		return data;
	}
};
typedef variable_constant<bool, true> true_t;
typedef variable_constant<bool, true> false_t;

template<class T>
struct is_pointer : false_t {};

template<class T>
struct is_pointer<T*> : true_t {};

template<class T>
struct is_const : false_t {};

template<class T>
struct is_const<const T> : true_t {};

template<class T>
struct is_reference : false_t {};

template<class T>
struct is_reference<T&> : true_t {};

template<class T>
struct remove_reference {
	typedef T type;
};

template<class T>
struct remove_reference<T&> {
	typedef T type;
};

template<class T>
struct remove_reference<T&&> {
	typedef T type;
};

template<class SrcT, class DestT>
inline DestT* copy(SrcT* src_begin, const SrcT* src_end, SrcT* dest_begin) {
	while (src_begin != src_end) {
		*dest_begin++ = *src_begin++;
	}
	return dest_begin;
}

inline void* copy(const void* src, void* dest, uint8_t byte_count) {
	auto mod = byte_count % sizeof(int4_t);
	if (mod == 0) { // Copy sizeof(int4_t) bytes at a time
		int4_t* dst = (int4_t*)dest;
		const int4_t* sc = (const int4_t*)src;
		for (uint8_t i = 0; i < byte_count / sizeof(int4_t); i++) {
			dst[i] = sc[i];
		}
	}
	else {
		uint1_t* dst = (uint1_t*)dest;
		const uint1_t* sc = (const uint1_t*)src;
		for (uint8_t i = 0; i < byte_count; i++) {
			dst[i] = sc[i];
		}
	}
	return dest;
}

template<class SrcT, class DestT>
inline DestT* move(SrcT* src_begin, const SrcT* src_end, SrcT* dest_begin) {
	while (src_begin != src_end) {
		*dest_begin++ = *src_begin++;
		*src_begin = 0;
	}
	return dest_begin;
}

_DLT_END
#endif
