#include <iostream>
#include <thread>
//#include <mingw.thread.h>

//#include <pthread.h>

using namespace std;

void hello()
{
    std::cout << "Hello Concurrent Word\n";
}

void func001()
{
    thread t(hello);
    t.join();
}

int main()
{
    func001();
}

//https://qna.habr.com/q/547925
//$ cat > thr.cpp
//#include <thread>
//using namespace std;
//void doIt(){
  //do nothing
//}
//int main(){
//  thread t(doIt);
//  t.detach();
//  return 0;
//}
//$ g++ -std=c++11 thr.cpp -o thr
///tmp/ccVyziLM.o: In function `std::thread::thread<void (&)()>(void (&)())':
//thr.cpp:(.text._ZNSt6threadC2IRFvvEJEEEOT_DpOT0_[_ZNSt6threadC5IRFvvEJEEEOT_DpOT0_]+0x20): undefined reference to `pthread_create'//
//collect2: error: ld returned 1 exit status

//g++ -std=c++11 concarency001.cpp -o thr -pthread -std=c++11