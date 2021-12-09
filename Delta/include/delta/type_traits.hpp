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

#if _HAS_CPP17 || _DEBUG
// Notice: not recommended for user use. Auto creates a _v version of a type_traits struct.
#define __DLT_DATA_HELPER(oft) template<class T> inline constexpr auto oft##_v = typename oft##<T>::value
#else
// Notice: not recommended for user use. Auto creates a _v version of a type_traits struct.
#define __DLT_DATA_HELPER(oft)
#endif
// Notice: not recommended for user use. Auto creates a _t version of a type_traits struct.
#define __DLT_TYPE_HELPER(oft) template<class T> using oft##_t = typename oft##<T>::type

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

__DLT_DATA_HELPER(is_pointer);

template<class T>
struct is_const : false_t {};

template<class T>
struct is_const<const T> : true_t {};

__DLT_DATA_HELPER(is_const);

template<class T>
struct is_reference : false_t {};

template<class T>
struct is_reference<T&> : true_t {};	

__DLT_DATA_HELPER(is_reference);

template<class T>
struct is_lvalue_reference : false_t {};

template<class T>
struct is_lvalue_reference<T&> : true_t {};

__DLT_DATA_HELPER(is_lvalue_reference);

template<class T>
struct is_rvalue_reference : false_t {};

template<class T>
struct is_rvalue_reference<T&&> : true_t {};

__DLT_DATA_HELPER(is_rvalue_reference);

template<class T>
struct is_void : false_t {};

template<>
struct is_void<void> : true_t {};

template<>
struct is_void<const void> : true_t {};

template<class T>
struct is_nullptr : false_t {};

template<>
struct is_nullptr<std::nullptr_t> : true_t {};

__DLT_DATA_HELPER(is_nullptr);

template<class T>
struct is_array : false_t {};

template<class T>
struct is_array<T[]> : true_t {};

template<class T, size_t _S>
struct is_array<T[_S]> : true_t {}; 

__DLT_DATA_HELPER(is_array);

template<class T>
struct is_enum : false_t {};

template<class T>
struct is_enum<enum T> : true_t {};

__DLT_DATA_HELPER(is_enum);

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

__DLT_TYPE_HELPER(remove_reference);

template<class T>
struct make_ptr {
	typedef typename remove_reference<T>::type* type;
};

__DLT_TYPE_HELPER(make_ptr);

_DLT_END
#endif