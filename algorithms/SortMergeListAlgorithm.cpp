#include <iostream>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

struct node {
    int number;
    struct node *next;
};

struct node *addnode(int number, struct node *next);
struct node *mergesort(struct node *head);

struct node *merge(struct node *head_one, struct node *head_two);

void fun001_merge_linked_list()
{
    struct node *head;
    struct node *current;
    struct node *next;

    int test[] = { 8, 3, 2, 6, 1, 5, 4, 7, 9, 0 };
    int i;

    head = NULL;
    for( i = 0; i < 10; i++)
        head = addnode(test[i], head);
    cout << "Before sort" << endl;
    
    head = mergesort(head);

    cout << "After sort" << endl;
    i = 0;
    for(current = head; current != NULL; current = current -> next )
        cout << test[i++] << " " << current->number << endl;

    for(current = head; current != NULL; current = current->next)
        next = current->next, free(current);

}

struct node *addnode(int number, struct node *next) {
    struct node *tnode;
    tnode = (struct node*)malloc(sizeof(*tnode));

    if(tnode != NULL) {
        tnode->number = number;
        tnode->next = next;
    }
    return tnode;
}

//Сортировка слиянием свзязанного списка
struct node *mergesort(struct node *head) {
    struct node *head_one;
    struct node *head_two;

    if((head == NULL) || (head->next == NULL))
        return head;
    
    head_one = head;
    head_two = head->next;

    while((head_two != NULL) && (head_two->next != NULL )){
        head = head->next;
        head_two = head->next->next;
    }
    head_two = head->next;
    head->next = NULL;

    return merge(mergesort(head_one), mergesort(head_two));
}

struct node *merge(struct node *head_one, struct node *head_two)
{
    struct node *head_three;

    if(head_one == NULL)
        return head_two;

    if(head_two == NULL)
        return head_one;
    
    if(head_one->number < head_two->number) {
        head_three = head_one;
        head_three->next = merge(head_one->next, head_two);
    } else {
        head_three = head_two;
        head_three -> next = merge(head_one, head_two->next);
    }
    return head_three;
}


void fun002_sort()
{
    string name[] = {"john", "bobby", "dear", "test1", "catherine", "nomi", "shita", "martin", "abe", "may", "zeno", "rack", "angeal", "gabby"};

    int sname = sizeof(name) / sizeof(name[0]);

    sort(name, name + sname);

    for(int i = 0; i < sname; ++i)
        cout << name[i] << endl;

}

void fun003_iterators()
{
    vector<string> names = {"john", "bobby", "dear", "test1", "catherine", "nomi", "shita", "martin", "abe", "may", "zeno", "rack", "angeal", "gabby"};
    sort(names.begin(), names.end());

    for(const auto& currentName : names)
    {
        cout << currentName << endl;
    }

    for(int y = 0; y < names.size(); y++)
    {
        cout << names[y] << endl;
    }

}

int main() {
    //fun001_merge_linked_list();
    //fun002_sort();
    fun003_iterators();


    return 0;
}