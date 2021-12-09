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
// Base header file for Delta library. Contains useful macros, functions, and typedefs.
#ifndef _DLT_UTILITY_
#define _DLT_UTILITY_
#define _DLT_BEGIN namespace dlt {
#define _DLT_END }
#define _INT_BEGIN namespace internal {
#define _INT_END }
_DLT_BEGIN
#define _HAS_CPP11 (__cplusplus > 201103L)
#define _HAS_CPP17 (__cplusplus > 201703L)

//static_assert(_HAS_CPP11, "Delta requires at least C++11.");

#if _HAS_CPP17
#define _INLINE inline
#else
#define _INLINE
#endif

#if _HAS_CPP17
#define _NODISCARD [[nodiscard]]
#else
#define _NODISCARD
#endif
_DLT_END
#endif
