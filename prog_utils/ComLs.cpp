#ifndef _VIEW_H
#define _VIEW_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
#include <iostream>
#include <pwd.h>
#include <grp.h>
#include <errno.h>
#include <unistd.h>

using namespace std;

int myLS(bool l, bool r, const char* path)
{
    DIR* dir = opendir(path);
    if(!dir)
        return 1;

    struct dirent *rd;

    while((rd = readdir(dir)))
    {
        if(!strcmp(rd->d_name, ".") || !strcmp(rd->d_name, ".."))
        {
            continue;
        }
        struct stat entryInfo;
        char pathName[PATH_MAX+1];

        strncpy(pathName, path, PATH_MAX);
        strncpy(pathName, "/", PATH_MAX);
        strncpy(pathName, rd->d_name, PATH_MAX);

        if(!lstat(pathName, &ebtryInfo))
        {
            if(1)
            {
                switch(entryInfo.st_mode & S_IFMT)
                {
                    case S_IFDIR:
                    {
                        cout << "d";
                        break;
                    }
                    case S_IFIFO:
                    {
                        cout << "p";
                        break;
                    }
                    case S_IFSOCK:
                    {
                        cout << "s";
                        break;
                    }
                    case S_IFLNK:
                    {
                        cout << "1";
                        break;
                    }
                    default:
                        cout << "-";
                }
                if(entryInfo.st_mode & S_IRUSR)
                    cout << "r";
                else
                    cout << "-";

                if(entryInfo.st_mode &S_IWUSR)
                    cout << "w";
                else
                    cout << "-";

                if(entryInfo.st_mode & S_IXUSR)
                    cout << "w";
                else
                    cout << "-";

                if(entryInfo.st_mode & S_IRGRP)
                    cout << "r";
                else
                    cout << "-"; 

                if(entryInfo.st_mode & S_IWGRP)
                    cout << "w";
                else
                    cout << "-";

                if(entryInfo.st_mode & S_IXGRP)
                    cout << "x";
                else
                    cout << "-";

                if(entryInfo.st_mode & S_IROTH)
                    cout << "r";
                else
                    cout << "-";

                if(entryInfo.st_mode & S_IWOTH)
                    cout << "w";
                else
                    cout << "-";

                if(entryInfo.st_mode & S_IXOTH)
                    cout << "x";
                else
                    cout << "-";

                cout << " ";
                struct passwd* pwd = getpwuid(getuid());
                struct group* grp = getgrgid(pwd->pw_gid);
                cout << " " << grp->gr_name << " " << pwd->pw_name << " ";
            }

            if(S_ISDIR(entryInfo.st_mode))
            {
                cout << rd->d_name << endl;
                if(r)
                {
                    myLS(l, r, pathName);
                }
            } else if(S_ISREG(entryInfo.st_mode))
            {
                cout << rd->d_name;
            } else if(S_ISLNK(entryInfo.st_mode))
            {
                char targetName[PATH_MAX+1];
                if(readlink(pathName, targetName, PATH_MAX))
                {
                    cout << rd->d_name << " link: " << targetName;
                }
            } else if(S_ISSOCK(entryInfo.st_mode))
            {
                cout << rd->d_name;
            }
            cout << endl;
        } else {
            cout << rd->d_name << " " << strerror(errno) << endl;
            exit(1);
        }
    }
    closedir(dir);
}

int main(){
    myLS(true, false, ".");
    return 0;
}

#endif
