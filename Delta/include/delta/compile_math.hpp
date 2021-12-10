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
// Contains useful template-based structs for finding data (traits) about types.
#ifndef DLT_COMPILE_MATH_INCLUDED
#define DLT_COMPILE_MATH_INCLUDED
#include "utility.hpp"
#include "cstdint.hpp"
_DLT_BEGIN

template<class T>
// Contains 50-digit values for mathematical constants.
struct constants {
	constexpr static T pi =  T(3.1415926535897932384626433832795028841971693993751);
	constexpr static T e =   T(2.7182818284590452353602874713526624977572470936962);
	constexpr static T phi = T(1.6180339887498948482045868343656381177203091798057);
};

template<class T, T _D>
struct abs {
	constexpr static T data = _D >= 0 ? _D : -_D;
};

template<size_t N>
struct factorial {
	constexpr static size_t data = N * factorial<N - 1>::data;
};

template<>
struct factorial<0> {
	constexpr static size_t data = 1;
};

template<int64_t Base, int64_t Power>
struct exponent {
	constexpr static int64_t data = Base * exponent<Base, abs<int64_t, Power>::data - 1>::data;
};

template<size_t Base>
struct exponent<Base, 1> {
	constexpr static size_t data = Base;
};

_DLT_END
#endif