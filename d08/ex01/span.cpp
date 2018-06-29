//
// Created by Roman KYSLYY on 6/29/18.
//

#include "span.hpp"

Span::Span() : _size(0)
{
	_vecN.reserve(0);
}

Span::Span(Span const &src)
{
	*this = src;
}

Span::Span(unsigned int size)
{
	_vecN.reserve(size);
	_size = size;
}

Span& Span::operator=(Span const &src)
{
	_vecN.clear();
	for (size_t i = 0; i < src._size; ++i)
		_vecN.push_back(src._vecN[i]);
	_size = src._size;

	return *this;
}

Span::~Span()
{}

void Span::addNumber(int n)
{
	if (_vecN.size() < _size)
		_vecN.push_back(n);
	else
		throw ContainerIsFull();
}

int Span::longestSpan(void)
{
	if (_vecN.size() == 0 || _vecN.size() == 1)
		throw NotEnoughElementsForSearch();
	return *std::max_element(_vecN.begin(), _vecN.end()) -
			*std::min_element(_vecN.begin(), _vecN.end());
}

int Span::shortestSpan(void)
{
	if (_vecN.size() == 0 || _vecN.size() == 1)
		throw NotEnoughElementsForSearch();

	std::vector<int> work = _vecN;
	std::sort(work.begin(), work.end());


	int diff = work[1] - work[0];

	for (size_t i = 1; i < work.size() - 1; i++)
	{
		if (work[i + 1] - work[i] < diff)
			diff = work[i + 1] - work[i];
	}

	return diff;
}

Span::NotEnoughElementsForSearch::NotEnoughElementsForSearch()
{}

Span::NotEnoughElementsForSearch::NotEnoughElementsForSearch(NotEnoughElementsForSearch const &src)
{
	*this = src;
}

Span::NotEnoughElementsForSearch& Span::NotEnoughElementsForSearch::operator=(NotEnoughElementsForSearch const &src)
{
	(void)src;
	return *this;
}

Span::NotEnoughElementsForSearch::~NotEnoughElementsForSearch() throw()
{}

const char* Span::NotEnoughElementsForSearch::what() const throw()
{
	return "Not enough elements for search";
}

Span::ContainerIsFull::ContainerIsFull()
{}

Span::ContainerIsFull::ContainerIsFull(ContainerIsFull const &src)
{
	*this = src;
}

Span::ContainerIsFull& Span::ContainerIsFull::operator=(ContainerIsFull const &src)
{
	(void)src;
	return *this;
}

Span::ContainerIsFull::~ContainerIsFull() throw()
{}

const char* Span::ContainerIsFull::what() const throw()
{
	return "Container is full";
}
