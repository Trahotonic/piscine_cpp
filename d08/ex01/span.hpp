#ifndef SPAN_HPP
#define SPAN_HPP

# include <iostream>
# include <vector>

class	Span
{
private:
	std::vector<int>	_vecN;
	size_t 				_size;
public:
	Span(void);
	Span(Span const & src);

	Span(unsigned int size);

	Span	&operator=(Span const & src);

	~Span(void);

	void	addNumber(int n);
	int		longestSpan(void);
	int 	shortestSpan(void);

	class ContainerIsFull : public virtual std::exception
	{
	public:
		ContainerIsFull(void);
		ContainerIsFull(ContainerIsFull const & src);

		ContainerIsFull &operator=(ContainerIsFull const & src);

		~ContainerIsFull(void) throw();

		virtual const char* what() const throw();
	};

	class NotEnoughElementsForSearch : public virtual std::exception
	{
	public:
		NotEnoughElementsForSearch(void);
		NotEnoughElementsForSearch(NotEnoughElementsForSearch const & src);

		NotEnoughElementsForSearch &operator=(NotEnoughElementsForSearch const & src);

		~NotEnoughElementsForSearch(void) throw();

		virtual const char* what() const throw();
	};
};

#endif
