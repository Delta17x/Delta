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
template<class T, class size_type = size_t>
class iterator {
public:
	iterator() : data(nullptr), cur(nullptr), size(0) {};
	iterator(T* _first, T* _last = _first) : first(_first), last(_last), cur(_first) {}
	iterator(const iterator<T, size_type>& other) : first(other.first), last(other.last), cur(other.cur) {}
	inline iterator<T, size_type>& operator=(const iterator<T, size_type>&) {}
	~iterator() {}
	inline T* begin() noexcept {
		return first;
	}
	inline T* end() noexcept {
		return last + 1;
	}
	inline T& next() {
		return *(cur + 1);
	}
	inline T& get() {
		return *cur;
	}
	inline T& back() {
		return *(cur - 1);
	}
	// Jumps forward <elems> elements.
	inline void jump(size_type elems) noexcept {
		cur += elems;
	}
	inline const T* current() const noexcept {
		return cur;
	}
	inline T* operator-> () noexcept {
		return cur;
	}
	inline T& operator[] (size_type index) {
		if (index < 0)
			throw new out_of_bounds();
		return *(first + index);
	}
	template<class T2, class size_type2>
	friend bool operator< (const iterator<T2, size_type2>&, const iterator<T2, size_type2>&) noexcept;
	template<class T2, class size_type2>
	friend bool operator<= (const iterator<T2, size_type2>&, const iterator<T2, size_type2>&) noexcept;
	template<class T2, class size_type2>
	friend bool operator> (const iterator<T2, size_type2>&, const iterator<T2, size_type2>&) noexcept;
	template<class T2, class size_type2>
	friend bool operator>= (const iterator<T2, size_type2>&, const iterator<T2, size_type2>&) noexcept;
	template<class T2, class size_type2>
	friend iterator<T2, size_type2>& operator++ (iterator<T2, size_type2>&) noexcept;
	template<class T2, class size_type2>
	friend iterator<T2, size_type2>& operator-- (iterator<T2, size_type2>&) noexcept;
	template<class T2, class size_type2>
	friend iterator<T2, size_type2> operator++ (iterator<T2, size_type2>&, int) noexcept;
	template<class T2, class size_type2>
	friend iterator<T2, size_type2> operator-- (iterator<T2, size_type2>&, int) noexcept;
	template<class T2, class size_type2>
	friend T2& operator* (iterator<T2, size_type2>& a) noexcept;
private:
	T* first;
	T* last;
	T* cur;

	// Points to an element in what is being iterated on. Should be managed by obejct being iterated on, so it is left as a raw pointer.
};

template<class T, class size_type>
inline bool operator< (const iterator<T, size_type>& a, const iterator<T, size_type>& other) noexcept {
	return a.cur < other.cur;
}
template<class T, class size_type>
inline bool operator<= (const iterator<T, size_type>& a, const iterator<T, size_type>& other) noexcept {
	return a.cur <= other.cur;
}
template<class T, class size_type>
inline bool operator> (const iterator<T, size_type>& a, const iterator<T, size_type>& other) noexcept {
	return a.cur > other.cur;
}
template<class T, class size_type>
inline bool operator>= (const iterator<T, size_type>& a, const iterator<T, size_type>& other) noexcept {
	return a.cur >= other.cur;
}
template<class T, class size_type>
inline iterator<T, size_type>& operator++(iterator<T, size_type>& a) noexcept {
	a.cur++;
	return a;
}
template<class T, class size_type>
inline iterator<T, size_type>& operator--(iterator<T, size_type>& a) noexcept {
	a.cur--;
	return a;
}
template<class T, class size_type>
inline iterator<T, size_type> operator++(iterator<T, size_type>& a, int) noexcept {
	auto temp = a;
	a.cur++;
	return temp;
}
template<class T, class size_type>
inline iterator<T, size_type> operator--(iterator<T, size_type>& a, int) noexcept {
	auto temp = a;
	a.cur--;
	return temp;
}
template<class T, class size_type>
inline T& operator* (iterator<T, size_type>& a) noexcept {
	return *a.cur;
}
_DLT_END
#endif