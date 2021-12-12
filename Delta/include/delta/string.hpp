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
#ifndef DLT_STRING_INCLUDED
#define DLT_STRING_INCLUDED
#include "utility.hpp"
#include "memory.hpp"
#include "type_traits.hpp"
#include "exception.hpp"
_DLT_BEGIN
template<class char_type, class size_type = size_t, class Allocator = allocator<Ch>>
class string {
public:
	string() : len(1), alloc() {
		ptr = alloc.allocate(2);
	}
	string(size_type l) : len(l), alloc() {
		ptr = alloc.allocate(l + 1);
	}
	string(char_type* co) : alloc() {
		ptr = alloc.allocate(30);
		if (is_same_v<char, remove_cv<char_type>>)
			for (len = 0; co[len] != '\0'; len++) {
				ptr[len] = co[len];
			}
		else {
			len = 0;
		}

	}
	string(const string& co) : len(co.len), ptr(co.ptr), alloc() {

	}
	string& operator= (const string& co) {

	}
	~string() {

	}
	char_type& operator[] (size_type at) {
		if (at < 0 || at > len)
			throw new out_of_bounds();
		return ptr[at];
	}

private:
	size_type len;
	char_type* ptr;
	Allocator alloc;
};
_DLT_END
#endif