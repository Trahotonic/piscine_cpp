void    memoryLeak(void)
{
    std::string*    panthere = new std::string("String panthere");
    delete panthere;
    std::cout << *panthere << std::endl;
}