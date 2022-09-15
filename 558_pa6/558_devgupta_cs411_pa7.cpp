/*Write producer-consumer problem using IPC (shared memory). Producer will produce 5 items
(say item-1, item-2, item-3 etc.) of qty 200 each but at a time it can produce a single item
 (say item-3) of quantity between 5 to 15 (random number) and consumer can consume single item
 (choose the item number randomly) at a time of quantity between 2-25 (also a random number).
 If the available qty of the item required by the consumer is less than the quantity available
 and producer has not produced max unit (200) at any point of time print "Item-#, Required-X
 Available-Y : Waiting for producer to produce". On producing all item of 200 units,
  producer will print "All items
 produced with maximum capacity". At any point of time, if available quantity of an item is less
 than the required quantity by the consumer and producer has produced max quantity (200) of the
 item, exit from the program.*/
// assignment 4 and assignment 6
// create 6 processes(5 for memory allocator, 1 for consumer)
#include <iostream>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int Max_size = 200;
int size[5] = {0};
int Index = 0;
void *addMemory(void *args)
{
    if (size[Index] >= Max_size)
        return NULL;
    int random = 5 + rand() % 11;
    for (int i = 0; i < random; i++)
    {
        if (size[Index] >= Max_size)
            return NULL;
        size[Index]++;
    }
    return NULL;
}
void *item_1(void *args)
{
    int *myID = (int *)args;
    Index = 0;
    pthread_t item1;
    pthread_create(&item1, NULL, addMemory, NULL);
    pthread_join(item1, NULL);
    return NULL;
}
void *item_2(void *args)
{
    Index = 1;
    int *myID = (int *)args;
    pthread_t item2;
    pthread_create(&item2, NULL, addMemory, NULL);
    pthread_join(item2, NULL);
    return NULL;
}
void *item_3(void *args)
{
    Index = 2;
    int *myID = (int *)args;
    pthread_t item3;
    pthread_create(&item3, NULL, addMemory, NULL);
    pthread_join(item3, NULL);
    return NULL;
}
void *item_4(void *args)
{
    Index = 3;
    int *myID = (int *)args;
    pthread_t item4;
    pthread_create(&item4, NULL, addMemory, NULL);
    pthread_join(item4, NULL);
    return NULL;
}
void *item_5(void *args)
{
    Index = 4;
    int *myID = (int *)args;
    pthread_t item5;
    pthread_create(&item5, NULL, addMemory, NULL);
    pthread_join(item5, NULL);
    return NULL;
}
void *item_consumption(void *args)
{
    if (size[Index] == 0)
        return NULL;
    int random = 2 + rand() % 24;
    for (int i = 0; i < random; i++)
    {
        if (size[Index] == 0)
            return NULL;
        size[Index]--;
    }
    return NULL;
}
void display()
{
    for (int i = 0; i < 5; i++)
    {
        cout << "\nItem " << i + 1 << "=" << size[i] << "\n";
    }
}
int main()
{
    pthread_t T[5];
    char ch;
    while (1)
    {

        int n;
        n = 1 + rand() % 5;
        switch (n)
        {
        case 1:
            pthread_create(&T[0], NULL, &item_1, NULL);
            pthread_join(T[0], NULL);
            display();
            break;
        case 2:
            pthread_create(&T[1], NULL, &item_2, NULL);
            pthread_join(T[1], NULL);
            display();
            break;
        case 3:
            pthread_create(&T[2], NULL, &item_3, NULL);
            pthread_join(T[2], NULL);
            display();
            break;
        case 4:
            pthread_create(&T[3], NULL, &item_4, NULL);
            pthread_join(T[3], NULL);
            display();
            break;
        case 5:
            pthread_create(&T[4], NULL, &item_5, NULL);
            pthread_join(T[4], NULL);
            display();
            break;
        case 6:
            Index = 0;
            pthread_create(&T[0], NULL, &item_consumption, NULL);
            pthread_join(T[0], NULL);
            display();
            break;
        case 7:
            Index = 1;
            pthread_create(&T[1], NULL, &item_consumption, NULL);
            pthread_join(T[1], NULL);
            display();
            break;
        case 8:
            Index = 2;
            pthread_create(&T[2], NULL, &item_consumption, NULL);
            pthread_join(T[2], NULL);
            display();
            break;
        case 9:
            Index = 3;
            pthread_create(&T[3], NULL, &item_consumption, NULL);
            pthread_join(T[3], NULL);
            display();
            break;
        case 10:
            Index = 4;
            pthread_create(&T[4], NULL, &item_consumption, NULL);
            pthread_join(T[4], NULL);
            display();
            break;
        }
        cout << "Do you want to allocate next block (Y or N)\t";
        cin >> ch;
        if (ch == 'y' || ch == 'Y')
        {
            continue;
        }
        else
        {
            break;
        }
    }
    return 0;
}