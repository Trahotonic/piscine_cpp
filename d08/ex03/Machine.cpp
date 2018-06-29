//
// Created by Roman KYSLYY on 6/29/18.
//

# include "Machine.hpp"

Mashine::Mashine(void) : _index(0)
{
	for (int i = 0; i < 30000; i++)
		_array[i] = 0;
}

Mashine::Mashine(Mashine const &src)
{
	*this = src;
}

Mashine::Mashine(std::list<AInstruction*> queue) : _index(0), _queue(queue)
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
	while (_queue.size())
	{
		_queue.front()->execute(_array, _index);
		_queue.pop_front();
	}
}
