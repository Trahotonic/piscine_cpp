//
// Created by Roman KYSLYY on 6/29/18.
//

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

# include <stack>
# include <iostream>
# include <list>

template <typename T>
class MutantStack : public std::stack<T>
{
private:
	std::list<T> _stack;
public:
	MutantStack(void) {}
	MutantStack(MutantStack const & src)
	{
		*this = src;
	}

	MutantStack	&operator=(MutantStack const & src)
	{
		_stack = src._stack;
		return *this;
	}

	~MutantStack(void) {}

	void	push(T newT)
	{
		_stack.push_front(newT);
	}

	void	pop()
	{
		_stack.pop_front();
	}

	T		top(void)
	{
		return _stack.front();
	}

	void	swap(MutantStack <T> & src)
	{
		std::list<T> buffer = _stack;
		_stack = src._stack;
		src._stack = buffer;
	}

	size_t	size(void)
	{
		return _stack.size();
	}

	typedef typename std::list<T>::iterator iterator;

	iterator	begin(void)
	{
		return _stack.begin();
	}

	iterator	end(void)
	{
		return _stack.end();
	}
};

#endif
