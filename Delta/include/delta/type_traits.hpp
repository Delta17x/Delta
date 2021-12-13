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
struct value_constant {
	constexpr static T value = val;
	inline operator T() const noexcept {
		return value;
	}
};
template<class T>
struct type_constant {
	typedef T type;
};
typedef value_constant<bool, true> true_t;
typedef value_constant<bool, false> false_t;

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
struct remove_reference : type_constant<T> {};

template<class T>
struct remove_reference<T&> : type_constant<T> {};

template<class T>
struct remove_reference<T&&> : type_constant<T> {};

template<class T> using remove_reference_t = typename remove_reference<T>::type;

template<class T>
struct make_ptr : type_constant<remove_reference_t<T>* > {};

template<class T> using make_ptr_t = typename make_ptr<T>::type;

template<class T>
struct remove_const : type_constant<T> {};

template<class T>
struct remove_const<const T> : type_constant<T> {};

template<class T> using remove_const_t = typename remove_const<T>::type;

template<class T>
struct remove_volatile : type_constant<T> {};

template<class T>
struct remove_volatile<volatile T> : type_constant<T> {};

template<class T> using remove_volatile_t = typename remove_volatile<T>::type;

template<class T> 
struct remove_cv : type_constant<T> {};

template<class T> 
struct remove_cv<const T> : type_constant<T> {};

template<class T> 
struct remove_cv<volatile T> : type_constant<T> {};

template<class T> 
struct remove_cv<const volatile T> : type_constant<T> {};

template<class T> using remove_cv_t = typename remove_cv<T>::type;

template<class T, class U>
struct is_same : false_t {};

template<class T>
struct is_same<T, T> : true_t {};

template<class T, class U> inline constexpr bool is_same_v = is_same<T, U>::value;

_INT_BEGIN
template<class T>
struct is_integral_helper : false_t {};

template<>
struct is_integral_helper<signed char> : true_t {};

template<>
struct is_integral_helper<unsigned char> : true_t {};

template<>
struct is_integral_helper<signed short> : true_t {};

template<>
struct is_integral_helper<unsigned short> : true_t {};

template<>
struct is_integral_helper<signed int> : true_t {};

template<>
struct is_integral_helper<unsigned int> : true_t {};

template<>
struct is_integral_helper<signed long> : true_t {};

template<>
struct is_integral_helper<unsigned long> : true_t {};

template<>
struct is_integral_helper<signed long long> : true_t {};

template<>
struct is_integral_helper<unsigned long long> : true_t {};
_INT_END

template<class T>
struct is_integral : value_constant<bool, internal::is_integral_helper<remove_cv_t<T>>::value> {};

template<class T> inline constexpr bool is_integral_v = is_integral<T>::value;


template<class T>
struct is_floating_point : value_constant<bool, is_same_v<float, remove_cv_t<T>> || is_same_v<double, remove_cv_t<T>> || is_same_v<long double, remove_cv_t<T>>> {};

template<class T> inline constexpr bool is_floating_point_v = is_floating_point<T>::value;

template<class T>
struct is_arithmetic : value_constant<bool, is_integral_v<T> || is_floating_point_v<T>> {};

template<class T> inline constexpr bool is_arithmetic_v = is_arithmetic<T>::value;

/*
_INT_BEGIN
    template<class T>
    struct is_base_of_test_c {};
    template <class Base>
    struct is_base_of_test_c<const volatile Base*> : true_t {};
    template <>
    struct is_base_of_test_c<const volatile void*> : false_t {};

    template <class, class>
    true_t is_base_of_test(...);
    template <class Base, class Child>
    auto is_base_of_test(int) ->
        decltype(is_base_of_test_c<decltype(nullptr)>::value);
_INT_END

template <typename Base, typename Child>
struct is_base_of :
    value_constant<
    bool, internal::is_base_of_test<Base, Child>(0)> {};
    */
_DLT_END
#endif