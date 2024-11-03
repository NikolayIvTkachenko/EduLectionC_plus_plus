#include <iostream>
#include <random>

#ifdef _WIN32
    #include <windows.h>
    #define msleep(x) Sleep(x)
#else
    #include <unistd.h>
    #define msleep(x) usleep(x * 1000)
#endif

using namespace std;

#define __WORLD_HEIGHT__ 20
#define __WORLD_WIDTH__ 20

struct cell {
    unsigned is_live:1;
};

void make_world(cell world[][__WORLD_HEIGHT__])
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis (1, 10000);

    unsigned int i, j;

    for(i = 0; i < __WORLD_WIDTH__; i++){
        for(j = 0; j < __WORLD_HEIGHT__; j++){
            unsigned int num = dis(gen);
            if(num % 2 == 0) {
                world[i][j].is_live = 1;
            } else {
                world[i][j].is_live = 0;
            }
        }
    }
}

void show_world(cell world[][__WORLD_HEIGHT__]) 
{
    unsigned int i, j;
    for(i = 0; i < __WORLD_WIDTH__; i++) {
        for(j = 0; j < __WORLD_HEIGHT__; j++){
            if(world[i][j].is_live == 1) {
                cout << '*';
            } else {
                cout << ' ';
            }
            cout << ' ';
        }
        cout << endl;
    }
}

unsigned int get_live_cells(cell world[][__WORLD_HEIGHT__])
{
    unsigned int count = 0;
    unsigned i, j;

    for(i = 0; i < __WORLD_WIDTH__; i++){
        for(j = 0; j < __WORLD_HEIGHT__; j++) {
            if(world[i][j].is_live == 1){
                count++;
            }
        }
    }
    return count;
}

void get_cell_neighbors(signed int nb[][2], unsigned int x, unsigned int y)
{
    unsigned int i, j;
    unsigned int k = 0;

    for(i = x - 1; i <= x + 1; i++){
        for(j = y - 1; j <= y + 1; j++) {
            if(i == x && j == y) 
            {
                continue;
            }
            nb[k][0] = i;
            nb[k][1] = j;
            k++;
        }
    }
}

unsigned int get_live_neighbors(cell world[][__WORLD_HEIGHT__], unsigned int x, unsigned int y) {
    unsigned int count = 0;
    unsigned int i;

    signed int nb[8][2];
    signed int _x, _y;

    get_cell_neighbors(nb, x, y);

    for(i = 0; i < 8; i++) {
        _x = nb[i][0];
        _y = nb[i][1];
        if(_x < 0 || _y < 0) {
            continue;
        }
        if(_x >= __WORLD_WIDTH__ || _y >= __WORLD_HEIGHT__) {
            continue;
        }
        if(world[_x][_y].is_live == 1) {
            count++;
        }
    }
    return count;
}

void next_generation(cell world[][__WORLD_HEIGHT__],cell prev_world[][__WORLD_HEIGHT__]){
    unsigned int i, j;
    unsigned int live_nb;
    cell p;

    for(i = 0; i < __WORLD_WIDTH__; i++) {
        for (j = 0; j < __WORLD_HEIGHT__; j++) {
            p = prev_world[i][j];
            live_nb = get_live_neighbors(prev_world, i, j);

            if (p.is_live == 0) {
                if(live_nb == 3) {
                    world[i][j].is_live = 1;
                }
            } else {
                if(live_nb < 2 || live_nb > 3) {
                    world[i][j].is_live = 0;
                }
            }
        }
    }
}

void copy_world(cell src[][__WORLD_HEIGHT__], cell dest[][__WORLD_HEIGHT__]) {
    unsigned int i, j;

    for( i = 0; i < __WORLD_WIDTH__; i++) {
        for(j = 0; j < __WORLD_HEIGHT__; j++) {
            dest[i][j] = src[i][j];
        }
    }
}

int compare_world( cell w1[][__WORLD_HEIGHT__], cell w2[][__WORLD_HEIGHT__]) {
    unsigned int i, j;
    for(i = 0; i < __WORLD_WIDTH__; i++) {
        for(j = 0; j < __WORLD_HEIGHT__; j++) {
            if(w1[i][j].is_live != w2[i][j].is_live) {
                return -1;
            }
        }
    }
    return 0;
}

int main()
{
    cell world[__WORLD_WIDTH__][__WORLD_HEIGHT__];
    cell temp[__WORLD_WIDTH__][__WORLD_HEIGHT__];

    make_world(world);
    unsigned int live_cells = -1;

    bool is_stab = false;

    do {
        show_world(world);
        copy_world(world, temp);
        next_generation(world, temp);

        is_stab = compare_world(world, temp) == 0;
        live_cells = get_live_cells(world);

        if(is_stab) {
            cout << "Not found stable configuration" << endl;
        }
        if(live_cells == 0) {
            cout << "All cells died" << endl;
        }

        msleep(1000);

    } while (live_cells != 0 && !is_stab);

    return 0;
}