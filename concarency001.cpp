#include <iostream>
#include <thread>
//#include <mingw.thread.h>

void hello()
{
    std::cout << "Hello Concurrent Word\n";
}

void func001()
{
    std::thread t(hello);
    t.join();
}

int main()
{
    func001();
}