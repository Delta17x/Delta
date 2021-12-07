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
#ifndef _DLT_TYPE_TRAITS_
#define _DLT_TYPE_TRAITS_
#include "utility.hpp"
_DLT_BEGIN
// Represents a constant of type "T" and value "val"
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
_DLT_END
#endif // !_DLT_TYPE_TRAITS_