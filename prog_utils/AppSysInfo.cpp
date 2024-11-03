#include <iostream>
#include <stdio.h>
#include <sys/utsname.h>
//#include <sys/utsname.h> // For POSIX
//#define _POSIX_C_SOURCE
//#include <sys/utsname.h>
//#include <windows.h>
//#include "system.h"
//#include <sys/systeminfo.h>


using namespace std;

int main() {
    struct utsname sysinfo;
    uname(&sysinfo);

    cout << "System Name:                   " << sysinfo.sysname << endl;
    cout << "Machine Arch:                  " << sysinfo.machine << endl;
    cout << "Host Name:                     " << sysinfo.nodename << endl;
    cout << "Release (Kernel) Version:      " << sysinfo.release << endl;
    cout << "Kernel Build Timestamp:        " << sysinfo.version << endl;
    cout << "Domain Name:                   " << sysinfo.domainname << endl;

    return 0;
}