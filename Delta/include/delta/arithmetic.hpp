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
#ifndef DLT_COMPILE_MATH_INCLUDED
#define DLT_COMPILE_MATH_INCLUDED
#include "cstdint.hpp"
#include "type_traits.hpp"
_DLT_BEGIN

template<class T>
// Contains mathematical constants and functions for type T.
struct math {
	static_assert(is_arithmetic_v<T>, "Delta arithmetic functions do not work with non-arithmetic types.");
	constexpr static T pi =  T(3.1415926535897932384626433832795028841971693993751);
	constexpr static T e =   T(2.7182818284590452353602874713526624977572470936962);
	constexpr static T phi = T(1.6180339887498948482045868343656381177203091798057);
	inline static T abs(T x) {
		return T >= 0 ? x : -x;
	}
	inline static T exp(T base, T power) {
		auto base1 = base;
		if (power > 0)
			while (--power > 0) {
				base *= base1;
			}
		else if (power < 0)
			while (power++ <= 0) {
				base /= base1;
			}
		else
			return 1;
		return base;
	}
	inline static T fact(T x) {
		for (T i = x; i > 1; i--)
			x *= (i-1);
		return x;
	}
	inline static T square(T x) {
		return T * T;
	}

};

_DLT_END
#endif