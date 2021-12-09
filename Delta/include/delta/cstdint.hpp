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
#ifndef DLT_CSTDINT_INCLUDED
#define DLT_CSTDINT_INCLUDED
#include "utility.hpp"
#include <stdint.h>
_DLT_BEGIN

typedef ::int8_t    int8_t ;
typedef ::int16_t   int16_t;
typedef ::int32_t   int32_t;
typedef ::int64_t   int64_t;
typedef ::uint8_t  uint8_t ;
typedef ::uint16_t uint16_t;
typedef ::uint32_t uint32_t;
typedef ::uint64_t uint64_t;

typedef ::int_least8_t    int_least8_t ;
typedef ::int_least16_t   int_least16_t;
typedef ::int_least32_t   int_least32_t;
typedef ::int_least64_t   int_least64_t;
typedef ::uint_least8_t  uint_least8_t ;
typedef ::uint_least16_t uint_least16_t;
typedef ::uint_least32_t uint_least32_t;
typedef ::uint_least64_t uint_least64_t;

typedef ::int_fast8_t    int_fast8_t ;
typedef ::int_fast16_t   int_fast16_t;
typedef ::int_fast32_t   int_fast32_t;
typedef ::int_fast64_t   int_fast64_t;
typedef ::uint_fast8_t  uint_fast8_t ;
typedef ::uint_fast16_t uint_fast16_t;
typedef ::uint_fast32_t uint_fast32_t;
typedef ::uint_fast64_t uint_fast64_t;

typedef ::intptr_t   intptr_t;
typedef ::uintptr_t uintptr_t;

typedef ::intmax_t intmax_t;
typedef ::uintmax_t uintmax_t;


typedef decltype(sizeof 1) size_t;
_DLT_END

#endif