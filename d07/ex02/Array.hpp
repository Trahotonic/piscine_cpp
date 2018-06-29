//
// Created by Roman KYSLYY on 6/28/18.
//

#ifndef GIT_CPP_ARRAY_TPP
#define GIT_CPP_ARRAY_TPP

#include <iostream>
#include <iomanip>

template <typename T = float>
class Array
{
private:
	T *		_array;
	int 	_size;
public:

	Array(void) : _array(NULL), _size(0)
	{}


	Array(Array <T> const & src) : _array(NULL), _size(0)
	{
		*this = src;
	}

	Array(unsigned int n) : _size(n)
	{
		if (n)
			_array = new T[n];
		else
			_array = NULL;
	}

	Array	&operator=(Array <T> const & src)
	{
		if (this == &src)
			return *this;
		if (this->_array != NULL)
			delete [] this->_array;
		if (src._size)
		{
			_array = new T[src._size];
			for (int i = 0; i < src._size; i++)
				_array[i] = src._array[i];
			_size = src._size;
		}
		else
		{
			_array = NULL;
			_size = 0;
		}
		return *this;
	}

	size_t size(void)
	{
		return _size;
	}

	class NonExistingIndex : public virtual std::exception
	{
	public:
		NonExistingIndex(void) {}
		NonExistingIndex(NonExistingIndex const & src)
		{
			*this = src;
		}

		NonExistingIndex	&operator=(NonExistingIndex const & src)
		{
			(void)src;
			return *this;
		}

		~NonExistingIndex(void) throw() {}

		virtual const char* what() const throw()
		{
			return "Index does not exist on array";
		}
	};

	class ArrayIsEmpty : public virtual std::exception
	{
	public:
		ArrayIsEmpty(void) {}
		ArrayIsEmpty(ArrayIsEmpty const & src)
		{
			*this = src;
		}

		ArrayIsEmpty	&operator=(ArrayIsEmpty const & src)
		{
			(void)src;
			return *this;
		}

		~ArrayIsEmpty(void) throw() {}

		virtual const char* what() const throw()
		{
			return "Array is empty";
		}
	};

	T      &operator[](int index)
	{
		if (!_size)
			throw ArrayIsEmpty();
		if (index < 0 || index > _size - 1)
			throw NonExistingIndex();
		return _array[index];
	}

	~Array(void)
	{
		if (_array)
			delete [] _array;
	}
};

#endif //GIT_CPP_ARRAY_HPP
