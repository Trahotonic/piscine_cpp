#include "Pony.class.cpp"

void    ponyOnTheHeap(std::string name, std::string color, std::string age, std::string trick)
{
    Pony    *pony = new Pony(name, color, age, trick);

    pony->ft_show_off();
    delete pony;
}

void    ponyOnTheStack(std::string name, std::string color, std::string age, std::string trick)
{
    Pony    pony(name, color, age, trick);

    pony.ft_show_off();
}

int main(void)
{
    std::string heap_name = "John";
    std::string heap_color = "brown";
    std::string heap_age = "34";
    std::string heap_trick = "gambling";
    std::string stack_name = "James";
    std::string stack_color = "white";
    std::string stack_age = "50";
    std::string stack_trick = "alcoholism";

    ponyOnTheStack(heap_name, heap_color, heap_age, heap_trick);
    ponyOnTheStack(stack_name, stack_color, stack_age, stack_trick);
    return (0);
}
