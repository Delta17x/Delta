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
#ifndef DLT_TYPETRAITS_INCLUDED
#define DLT_TYPETRAITS_INCLUDED
#include "utility.hpp"
_DLT_BEGIN

// Represents a constant of type "T" and value "val"
template<class T, T val>
struct variable_constant {
	constexpr static T value = val;
	inline operator T() const noexcept {
		return value;
	}
};
typedef variable_constant<bool, true> true_t;
typedef variable_constant<bool, false> false_t;

template<class T>
struct is_pointer : false_t {};

template<class T>
struct is_pointer<T*> : true_t {};

template<class T> inline constexpr auto is_pointer_v = is_pointer<T>::value;

template<class T>
struct is_const : false_t {};

template<class T>
struct is_const<const T> : true_t {};

template<class T> inline constexpr auto is_const_v = is_const<T>::value;

template<class T>
struct is_reference : false_t {};

template<class T>
struct is_reference<T&> : true_t {};

template<class T>
struct is_reference<T&&> : true_t {};

template<class T> inline constexpr auto is_reference_v = is_reference<T>::value;

template<class T>
struct is_lvalue_reference : false_t {};

template<class T>
struct is_lvalue_reference<T&> : true_t {};

template<class T> inline constexpr auto is_lvalue_reference_v = is_lvalue_reference<T>::value;

template<class T>
struct is_rvalue_reference : false_t {};

template<class T>
struct is_rvalue_reference<T&&> : true_t {};

template<class T> inline constexpr auto is_rvalue_reference_v = is_rvalue_reference<T>::value;

template<class T>
struct is_void : false_t {};

template<>
struct is_void<void> : true_t {};

template<>
struct is_void<const void> : true_t {};

template<class T>
struct is_nullptr : false_t {};

template<>
struct is_nullptr<decltype(nullptr)> : true_t {};

template<class T> inline constexpr auto is_nullptr_v = is_nullptr<T>::value;

template<class T>
struct is_array : false_t {};

template<class T>
struct is_array<T[]> : true_t {};

template<class T, size_t _S>
struct is_array<T[_S]> : true_t {};

template<class T> inline constexpr auto is_array_v = is_array<T>::value;

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

template<class T> using remove_reference_t = typename remove_reference<T>::type;

template<class T>
struct make_ptr {
	typedef typename remove_reference<T>::type* type;
};

template<class T> using make_ptr_t = typename make_ptr<T>::type;

_DLT_END
#endif