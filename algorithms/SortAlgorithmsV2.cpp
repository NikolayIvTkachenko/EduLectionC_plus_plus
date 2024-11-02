#include <iostream>
#include <stdlib.h>

#define MAX 10

using namespace std;

struct lnode {
    int data;
    struct lnode *next;
} *head, *visit;


void llist_add(struct lnode **g, int num);
void llist_bubble_sort(void);
void llist_print(void);

void func001_bubble_sort_list()
{
    struct lnode *newnode = NULL;
    int i = 0;

    for( i = 0; i < MAX; i++){
        llist_add(&newnode, (rand() % 100));
    }

    head = newnode;
    cout << "Before sort: \n";
    llist_print();

    cout << "After sort \n";
    llist_bubble_sort();
    llist_print();
}

void llist_add(struct lnode **q, int num) {
    
    struct lnode *tmp;
    tmp = *q;

    if(*q == NULL) {
        *q = (struct lnode *)malloc(sizeof(struct lnode));
        tmp = *q;
    } else {
        while(tmp->next != NULL)
            tmp = tmp->next;

        tmp->next = (struct lnode *)malloc(sizeof(struct lnode));
        tmp = tmp->next;
    }
    tmp->data = num;
    tmp->next = NULL;
}

void llist_print(void){
    visit = head;
    while(visit != NULL)
    {
        cout << visit->data << " ";
        visit = visit->next;
    }
    cout << endl;
}

void llist_bubble_sort(void) {
    struct lnode *a = NULL;
    struct lnode *b = NULL;
    struct lnode *c = NULL;
    struct lnode *e = NULL;
    struct lnode *tmp = NULL;

    while(e != head->next) {
        c = a = head;
        b = a->next;
        while( a != e) {
            if(a->data > b->data) {
                if(a == head) {
                    tmp = b -> next;
                    b -> next = a;
                    a -> next = tmp;
                    head = b;
                    c = b;
                } else {
                    tmp = b -> next;
                    b -> next = a;
                    a -> next = tmp;
                    c -> next = b;
                    c = b;
                }
            } else {
                c = a;
                a = a -> next;
            }
            b = a -> next;
            if(b == e) e = a;
        }
    }
}


//Пирамидальная сортировка//heap sort//сортировка кучей
#define MAXARRAY 5

void heapsort(int ar[], int len);

void heapbubble(int pos, int ar[], int len);

void fun002_heap_sort() {

    int array[MAXARRAY];
    int i = 0;

    for(i = 0; i < MAXARRAY; i++)
        array[i] = rand() % 100;

    cout << "Before: " << endl;
    for(i = 0; i < MAXARRAY; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    heapsort(array, MAXARRAY);

    cout << "Aftre: "<< endl;
        for(i = 0; i < MAXARRAY; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

void heapbubble(int pos, int array[], int len) {
    int z = 0;
    int max = 0;
    int tmp = 0;
    int left = 0;
    int right = 0;

    z = pos;

    for(;;) {
        left = 2 * z + 1;
        right = left + 1;

        if(left >= len)
            return;
        else if(right >= len)
            max = left;
        else if(array[left] > array[right])
            max = left;
        else
            max = right;

        if(array[z] > array[max]) return;

        tmp = array[z];
        array[z] = array[max];
        array[max] = tmp;
        z = max;
    }
}

void heapsort(int array[], int len) {
    int i = 0;
    int tmp = 0;
    for(i = len / 2; i >= 0; --i)
        heapbubble(i, array, len);
    for(i = len - 1; i > 0; i--) {
        tmp = array[0];
        array[0] = array[i];
        array[i] = tmp;
        heapbubble(0, array, i);
    }
}


void isort(float arr[], int n);
int fm(float arr[], int b, int n);

void fun003_insert_sort()
{
    float arr1[5] = {4.3, 6.7, 2.8, 8.9, 1.0};
    float arr2[5] = {4.3, 6.7, 2.8, 8.9, 1.0 };

    int i = 0;
    isort(arr2, 5);
    cout << "Before" << endl;
    for(i=0; i < 5; i++)
        cout << arr1[i] << "\t" << arr2[i] << endl;

    cout << "Afrter" << endl;
    for(i=0; i < 5; i++)
        cout << arr1[i] << "\t" << arr2[i] << endl;

}

int fm(float arr[], int b, int n) {
    int f = b;
    int c;

    for(c = b + 1; c < n; c++)
        if(arr[c] < arr[f])
            f = c;
    return f;    
}

void isort(float arr[], int n) {
    int s, w;
    float sm;

    for(s = 0; s < n - 1; s++) {
        w = fm(arr, s, n);
        sm = arr[w];
        arr[w] = arr[s];
        arr[s] = sm;
    }
}


//Сортировка слиянением//mergesort
#define MAXARRAYY 10
void mergesort(int a[], int low, int high);

void fun004_mergesort()
{
    int array[MAXARRAYY];
    int i = 0;

    for(i = 0; i < MAXARRAYY; i++)
        array[i] = rand() % 100;

    cout << "Before Sort: " << endl;
    for(i = 0; i < MAXARRAYY; i++)
        cout << array[i] << " ";
    cout << endl;

    mergesort(array, 0, MAXARRAYY - 1);

    cout << "After Sort: " << endl;
    for(i = 0; i < MAXARRAYY; i++)
        cout << array[i] << " ";
    cout << endl;
}

void mergesort(int a[], int low, int high)
{
    int i = 0;
    int length = high - low + 1;
    int pivot = 0;
    int merge1 = 0;
    int merge2 = 0;
    int working[length];

    if(low == high)
        return;
    pivot = (low + high) / 2;

    mergesort(a, low, pivot);
    mergesort(a, pivot + 1, high);

    for(i = 0; i < length; i++)
        working[i] = a[low + i];

    merge1 = 0;
    merge2 = pivot - low + 1;

    for(i = 0; i < length; i++){
        if(merge2 <= high - low)
            if(merge1 <= pivot - low)
                if(working[merge1] > working[merge2])
                    a[i + low] = working[merge2++];
                else
                    a[i + low] = working[merge1++];
            else
                a[i + low] = working[merge2++];
        else
            a[i + low] = working[merge1++];  
    }
}



int main(){

    //func001_bubble_sort_list();
    //fun002_heap_sort();
    //fun003_insert_sort();
    fun004_mergesort();



    return 0;
}