#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>

using namespace std;

#define TRUE 0
#define FALSE 1

void func001_binary_search()
{
    int array[10] = {0, 1, 2, 3, 4, 6, 7, 8, 9, 10};
    int left = 0;
    int right = 10;
    int middle = 0;
    int number = 0;
    int bsearch = FALSE;
    int i = 0;

    cout << "Array: ";
    for(i = 0; i < 10; i++)
        cout << array[i] << " ";
    cout << "\nSearch number: ";

    cin >> number;
    while(bsearch == FALSE && left <=right)
    {
        middle = (left + right) / 2;
        if(number == array[middle])
        {
            bsearch = TRUE;
            cout << "*** FOUND ***\n";
        } else {
            if(number < array[middle]) right = middle - 1;
            if(number > array[middle]) left = middle + 1;
        }
    }

    if(bsearch == FALSE)
        cout << "--- Not Found --\n";
}

int binsearch(char *str[], int max, char *value);

//Бинарный поиск по массиву указателей строк
void func002_pointer_strings()
{
    char *strings[] = {"audi", "bentley", "bmw", "cadillac", "ford"};
    int i, asize, result;

    i = asize = result = 0;

    asize = sizeof(strings) / sizeof(strings[0]);

    for(i= 0; i < asize; i++)
        cout << i << " " << strings[i] << endl;
    cout << endl;

    if((result == binsearch(strings, asize, "bmw")) != 0)
        cout << "bmw found on position: " << result << endl;
    else
        cout << "bmw not found" << endl;
}

int binsearch(char *str[], int max, char *value) {
    int position;
    int begin = 0;
    int end = max - 1;
    int cond = 0;

    while(begin <= end) {
        position = (begin + end) / 2;
        if((cond = strcmp(str[position], value)) == 0)
            return position;
        else if (cond < 0)
            begin = position + 1;
        else
            end = position - 1;
    }
    return 0;
}


//Пузырьковая сортировка
void bubble_sort(int a[], int size);
void func003_bubble_sort()
{
    int arr[10] = {10, 2, 4, 1, 6, 5, 8, 7, 3, 9};
    int i = 0;
    cout << "Before SOrt: \n";
    for(i = 0; i < 10; i++) cout << arr[i] << " ";
    cout << endl;

    bubble_sort(arr, 10);

    cout << "After Sort" << endl;

    for( i = 0; i < 10; i++) cout << arr[i] << " ";
    cout << endl;

}
void bubble_sort(int a[], int size)
{
    int switched = 1;
    int hold = 0;
    int i = 0;
    int j = 0;

    size -= 1;

    for( i = 0; i < size && switched; i++)
    {
        switched = 0;
        for(j = 0; j < size - i; j++)
            if(a[j] > a[j + 1] ) {
                switched = 1;
                hold = a[j];
                a[j] = a[j + 1];
                a[j + 1] = hold;
            }
    }
}


//Быстрая сортировка

#define MAXARRAY 10
void quicksort(int arr[], int low, int high);
void func004_quick_sort()
{
    int array[MAXARRAY] = {0};
    int i = 0;

    for( i = 0; i < MAXARRAY; i++ )
        array[i] = rand() % 100;

    //Вывод массив
    cout << "Before Sort" << endl;
    for(i = 0; i < MAXARRAY; i++){
        cout << array[i] << " ";
    }
    cout << endl;

    quicksort(array, 0, (MAXARRAY - 1));

    //Выводи результат
    for( i = 0; i < MAXARRAY; i++){
        cout << array[i] << " ";
    }
    cout << endl;

}
void quicksort(int arr[], int low, int high) {
    cout << "quicksort ==================" << endl;
    int i = low;
    int j = high;
    int y = 0;
    cout << "i = low = " << i <<  endl;
    cout << "j = high = " << j << endl;
    cout << "y =" << y << endl;

    //опорный элемент
    int z = arr[(low + high) / 2];
    cout << "z = " << z <<  endl;
    //разделение
    do{
        //находим элемент леввее
        while(arr[i] < z) {
            cout << "arr[i] = " << arr[i] <<  endl;
            cout << "i = " << i <<  endl;
            i++; 

        }
       
        //находим элементправее
        while(arr[j] > z) {
            cout << "arr[j] = " << arr[j] <<  endl;
            cout << "j = " << j <<  endl;
            j--;
        }

        cout << "i = " << i <<  endl;
        cout << "j = " << j <<  endl;
        
        if( i <= j ) {
            cout << "i <= j" <<  endl;
            //Меняем местами два элемента
            y = arr[i];
            arr[i] = arr[j];
            arr[j] = y;
            i++;
            j--;
        }
    } while(i <= j);

    //рекурсия
    if(low < j)
        quicksort(arr, low, j);

    if(i < high)
        quicksort(arr, i, high);
}


#define MAX 10
struct lnode {
    int data;
    struct lnode * next;
} *head, *visit;

void llist_add(struct lnode **q, int num);
void llist_selection_sort(void);
void llist_print(void);

//Сортировка выбором
void func005_selection_sort()
{
    struct lnode *newnode = NULL;
    int i = 0;

    for(i = 0; i < MAX; i++) {
        llist_add(&newnode, (rand() % 100));
    }

    head = newnode;
    cout << "Before sort"<< endl;
    llist_print();

    cout << "After sort" << endl;
    llist_selection_sort();

    llist_print();
}

void llist_add(struct lnode **q, int num)
{
    struct lnode *temp;
    temp = *q;
    if (*q == NULL) {
        *q = (struct lnode *)malloc(sizeof(struct lnode));
        temp = *q;
    } else {
        while(temp -> next != NULL)
            temp = temp -> next;
        temp -> next = (struct lnode *)malloc(sizeof(struct lnode));
        temp = temp -> next;
    }
    temp -> data = num;
    temp -> next = NULL;
}

void llist_print(void) {
    visit = head;

    while(visit != NULL) {
        cout << visit->data << " ";
        visit = visit->next;
    }
    printf("\n");
}


void llist_selection_sort(void)
{
    struct lnode *a = NULL;
    struct lnode *b = NULL;
    struct lnode *c = NULL;
    struct lnode *d = NULL;
    struct lnode *tmp = NULL;

    a = c = head;
    while(a->next != NULL) {
        d = b = a -> next;
        while(b != NULL){
            if(a->data > b->data){
                if(a->next == b){
                    if(a==head) {
                        a->next = b->next;
                        b->next = a;
                        tmp = a;
                        a = b;
                        b = tmp;
                        head = a;
                        c = a;
                        d = b;
                        b = b->next;
                    } else {
                        a -> next = b -> next;
                        b -> next = a;
                        c -> next = b;
                        tmp = a;
                        a = b;
                        b = tmp;
                        d = b;
                        b = b->next;
                    }
                } else {
                    if (a == head) {
                        tmp = b -> next;
                        b -> next = a -> next;
                        a -> next = tmp;
                        d -> next = a;
                        tmp = a;
                        a = b;
                        b = tmp;
                        d = b;
                        b = b -> next;
                        head = a;
                    } else {
                        tmp = b->next;
                        b->next = a->next;
                        a->next = tmp;
                        c->next = b;
                        d -> next = a;
                        tmp = a;
                        a = b;
                        b = tmp;
                        d = b;
                        b = b-> next;
                    }
                }
            } else {
                d = b;
                b = b -> next;
            }
        }
        c = a;
        a = a -> next;
    }
}

//Сортировка вставкой связного списка
struct node {
    int numberr;
    struct node *next;
};

struct node *headd = NULL;
void insert_node(int value);

void func006_insert_sort()
{
    struct node *current = NULL;
    struct node *next = NULL;

    int test[] = {8, 3, 2, 6, 1, 5, 4, 7, 9, 0};
    int i = 0;

    for(i = 0; i < 10; i++)
        insert_node(test[i]);

    cout << "Before list"<< endl;
    i = 0;
    while(headd -> next != NULL) {
        cout << test[i++] << "\t" << headd-> numberr << endl;
        headd = headd->next;
    }    

    for(current = headd; current != NULL; current = next)
        next = current->next, free(current);

}

void insert_node(int value) {
    struct node *temp = NULL;
    struct node *one = NULL;
    struct node *two = NULL;

    if(head == NULL) {
        headd = (struct node *)malloc(sizeof(struct node *));
        headd->next = NULL;
    }

    one = headd;
    two = headd->next;

    temp = (struct node *) malloc(sizeof(struct node *));
    temp->numberr = value;

    while(two != NULL && temp->numberr < two->numberr) {
        one = one->next;
        two = two->next;
    }
    one -> next = temp;
    temp -> next = two;
}


int main()
{
    //func001_binary_search();
    //func002_pointer_strings();
    //func003_bubble_sort();
    //func004_quick_sort();
    func005_selection_sort();

    return 0;
}