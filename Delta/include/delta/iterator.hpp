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
	// Required for custom iterator: operator+, operator-, next(), back(), 
	using value_type = typename traits::value_type;
	using ptr_type = typename traits::ptr_type;
	using ref_type = typename traits::ref_type;
	using difference_type = typename traits::difference_type;
	iterator_base() : cur(nullptr) {};
	iterator_base(ptr_type curr) : cur(curr) {}
	iterator_base(const iterator_base<traits>& other) : cur(other.cur) {}
	~iterator_base() {}
	inline ref_type get() {
		return *cur;
	}
	inline ptr_type current() const noexcept {
		return cur;
	}
	inline ptr_type operator-> () noexcept {
		return cur;
	}
	inline ref_type operator* () noexcept {
		return *cur;
	}
	// Points to an element in what is being iterated on. Should be managed by obejct being iterated on, so it is left as a raw pointer.
	ptr_type cur;
};

template<class traits>
class iterator : public iterator_base<traits> {
public:
	iterator(typename traits::ptr_type curr) : iterator_base<traits>(curr) {}
};

template<class traits>
class reverse_iterator : public iterator_base<traits> {
public:
	reverse_iterator(typename traits::ptr_type curr) : iterator_base<traits>(curr) {}
	reverse_iterator(const iterator<traits>& other) : iterator_base<traits>(other.cur - 1) {}
};

template<class traits>
class linked_list_iterator : public iterator_base<traits> {
	linked_list_iterator(typename traits::ptr_type curr) : iterator_base<traits>(curr) {}
};

template<class T>
inline bool operator> (const T& a, const T& other) noexcept {
	return !(a < other || a == other);
}
template<class T>
inline bool operator>= (const T& a, const T& other) noexcept {
	return a > other || a == other;
}
template<class T>
inline bool operator<= (const T& a, const T& other) noexcept {
	return a < other || a == other;
}
template<class T>
inline T& operator++(T& a) noexcept {
	a = a + 1;
	return a;
}
template<class T>
inline T& operator--(T& a) noexcept {
	a = a - 1;
	return a;
}
template<class T>
inline T operator++(T& a, int) noexcept {
	T temp = a;
	a = a + 1;
	return temp;
}
template<class T>
inline T operator--(T& a, int) noexcept {
	T temp = a;
	a = a - 1;
	return temp;
}
template<class T>
inline bool operator!=(T a, T b) {
	return !(a == b);
}
// Standard iterator operators
template<class traits>
inline iterator<traits> operator+(iterator<traits> a, typename traits::difference_type offset) noexcept {
	return iterator<traits>(a.cur + offset);
}
template<class traits>
inline iterator<traits> operator-(iterator<traits> a, typename traits::difference_type offset) noexcept {
	return iterator<traits>(a.cur - offset);
}
template<class traits>
inline bool operator==(iterator<traits> a, iterator<traits> b) {
	return a.cur == b.cur;
}
template<class traits>
inline bool operator< (const iterator<traits>& a, const iterator<traits>& other) noexcept {
	return a.cur < other.cur;
}
// Reverse iterator operators
template<class traits>
inline reverse_iterator<traits> operator+(reverse_iterator<traits> a, typename traits::difference_type offset) noexcept {
	return reverse_iterator<traits>(a.cur - offset);
}
template<class traits>
inline reverse_iterator<traits> operator-(reverse_iterator<traits> a, typename traits::difference_type offset) noexcept {
	return reverse_iterator<traits>(a.cur + offset);
}
template<class traits>
inline bool operator==(reverse_iterator<traits> a, reverse_iterator<traits> b) {
	return a.cur == b.cur;
}
template<class traits>
inline bool operator==(reverse_iterator<traits> a, iterator<traits> b) {
	return a.cur == b.cur - 1;
}
template<class traits>
inline bool operator< (const reverse_iterator<traits>& a, const reverse_iterator<traits>& other) noexcept {
	return a.cur > other.cur;
}

template<class traits>
inline linked_list_iterator<traits> operator+(linked_list_iterator<traits> a, typename traits::difference_type offset) {
	linked_list_iterator<traits> ret(a);
	for (int i = 0; i < offset; i++)
		ret = linked_list_iterator<traits>(ret->cur.next);
	return ret;
}
/*
struct node {
	node* next;
	node* back;

}

*/
_DLT_END
#endif
