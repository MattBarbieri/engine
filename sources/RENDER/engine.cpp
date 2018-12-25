#include "engine.hpp"

engine::engine()
{
    std::cout << "started the engine object" << std::endl;
}

void engine::test()
{
    std::cout << "Hello World From TEST \n";
}
engine::~engine()
{

    std::cout << "destroy engine object \n";
}