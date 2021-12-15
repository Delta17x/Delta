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

#ifndef DLT_ITERATOR_INCLUDED
#define DLT_ITERATOR_INCLUDED
#include "utility.hpp"
#include "cstdint.hpp"
#include "exception.hpp"
_DLT_BEGIN
template<class Value_type, class Ref_type = Value_type&, class Ptr_type = Value_type*, class Difference_type = diff_t>
struct iterator_traits {
	typedef Value_type value_type;
	typedef Ref_type ref_type;
	typedef Ptr_type ptr_type;
	typedef Difference_type difference_type;
};

template<class traits>
class iterator_base {
public:
	iterator_base() : cur(nullptr) {};
	iterator_base(traits::ptr_type curr) : cur(curr) {}
	iterator_base(const iterator_base<traits>& other) : cur(other.cur) {}
	inline iterator_base<traits>& operator=(const iterator_base<traits>&) {}
	~iterator_base() {}
	inline traits::ref_type get() {
		return *cur;
	}
	// Jumps forward <elems> elements.
	inline void jump(traits::difference_type elems) noexcept {
		cur += elems;
	}
	inline traits::value_type const* current() const noexcept {
		return cur;
	}
	inline traits::ptr_type operator-> () noexcept {
		return cur;
	}
	inline traits::ref_type operator* () noexcept {
		return *cur;
	}
	// Points to an element in what is being iterated on. Should be managed by obejct being iterated on, so it is left as a raw pointer.
	traits::ptr_type cur;
};
                 
template<class traits>
class iterator : public iterator_base<traits> {
public:
	iterator(traits::ptr_type curr) : iterator_base(curr) {}
	inline traits::ptr_type begin() noexcept {

	}
	inline traits::ptr_type end() noexcept {

	}

};

template<class traits>
inline bool operator< (const iterator<traits>& a, const iterator<traits>& other) noexcept {
	return a.cur < other.cur;
}
template<class traits>
inline bool operator<= (const iterator<traits>& a, const iterator<traits>& other) noexcept {
	return a.cur <= other.cur;
}
template<class traits>
inline bool operator> (const iterator<traits>& a, const iterator<traits>& other) noexcept {
	return a.cur > other.cur;
}
template<class traits>
inline bool operator>= (const iterator<traits>& a, const iterator<traits>& other) noexcept {
	return a.cur >= other.cur;
}
template<class traits>
inline iterator<traits>& operator++(iterator<traits>& a) noexcept {
	a.cur++;
	return a;
}
template<class traits>
inline iterator<traits>& operator--(iterator<traits>& a) noexcept {
	a.cur--;
	return a;
}
template<class traits>
inline iterator<traits> operator++(iterator<traits>& a, int) noexcept {
	auto temp = a;
	a.cur++;
	return temp;
}
template<class traits>
inline iterator<traits> operator--(iterator<traits>& a, int) noexcept {
	auto temp = a;
	a.cur--;
	return temp;
}
template<class traits>
inline iterator<traits> operator+(iterator<traits> a, typename traits::difference_type offset) noexcept {
	return iterator<traits>(*a + offset);
}
template<class traits>
inline iterator<traits> operator-(iterator<traits> a, typename traits::difference_type offset) noexcept {
	return iterator<traits>(*a - offset);
}
template<class traits>
inline bool operator==(iterator<traits> a, iterator<traits> b) {
	return a.cur == b.cur;
}
template<class traits>
inline bool operator!=(iterator<traits> a, iterator<traits> b) {
	return a.cur != b.cur;
}
_DLT_END
#endif
