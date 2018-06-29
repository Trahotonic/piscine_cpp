#ifndef EASYFIND_HPP
#define EASYFIND_HPP

# include <list>
# include <iostream>
# include <algorithm>

class DoesNotContain : public virtual std::exception
{
public:
    DoesNotContain(void) {}
    DoesNotContain(DoesNotContain const & src)
    {
        *this = src;
    }

    DoesNotContain &operator=(DoesNotContain const & src)
    {
        (void)src;
        return *this;
    }

    ~DoesNotContain(void) throw() {}

    virtual const char* what() const throw()
    {
        return "Desired value does not exist in container";
    }
};

class ContainerEmpty : public virtual std::exception
{
public:
	ContainerEmpty(void) {}
	ContainerEmpty(ContainerEmpty const & src)
	{
		*this = src;
	}

	ContainerEmpty &operator=(ContainerEmpty const & src)
	{
		(void)src;
		return *this;
	}

	~ContainerEmpty(void) throw() {}

	virtual const char* what() const throw()
	{
		return "Container is empty";
	}
};


template <typename T>
int easyfind(T container, int needle)
{
    typename T::iterator it = container.begin();
    typename T::iterator ite = container.end();

	if (!container.size())
		throw ContainerEmpty();
    int count = 0;
    while (it != ite)
    {
        if (*it == needle)
            return count;
        count++;
        it++;
    }
    if (*it == needle)
        return count;
    throw DoesNotContain();
}


#endif
