//
// Created by Roman KYSLYY on 6/29/18.
//

# include <iostream>
# include "Machine.hpp"

Mashine::Mashine(void) : _index(0), _comIndex(0)
{
	for (int i = 0; i < 30000; i++)
		_array[i] = 0;
}

Mashine::Mashine(Mashine const &src)
{
	*this = src;
}

Mashine::Mashine(std::vector<AInstruction*> queue) : _index(0), _comIndex(0), _queue(queue)
{
	for (int i = 0; i < 30000; i++)
		_array[i] = 0;
}

Mashine& Mashine::operator=(Mashine const &src)
{
	_index = src._index;
	_queue = src._queue;

	return *this;
}

Mashine::~Mashine(void)
{}

void Mashine::run(void)
{
	while (_comIndex < static_cast<int>(_queue.size()))
	{
		_queue[_comIndex]->execute(_array, _index, _comIndex, _queue);
	}
	std::cout << std::endl;
}
