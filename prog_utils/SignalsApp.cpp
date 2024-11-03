#include <csignal>
#include <iostream>
#include <cstdlib>

using namespace std;

namespace
{
    volatile std::sig_atomic_t gSignalStatus;
}

void signal_handler(int signal)
{
    gSignalStatus = signal;
    cout << "Get Up!" << endl;
    exit(1);
}

int main()
{
    signal(SIGINT, signal_handler);

    cout << "Sleep...\n";
    while(1);
}