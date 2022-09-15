#include <iostream>
using namespace std;
class Kernalallocate
{
    char *page;
    int flag = 0;
    int allocation_count = 0;

public:
    void Allocate_memory() // function to allocating the memory
    {
        page = new char[4096];
        flag = 1;
        allocation_count++;
    }
    void working()
    {
        cout << "You can use this memory in anyway you want with 4096 characters\n";
    }
    void Deallocate_memory() // function to deallocating the memory
    {
        delete[] page;
        flag = 0;
    }
    int isfree() // to check whether the following block is freed or not
    {
        return this->flag;
    }
    int HowMuchUsed() // to check how many times the block is used
    {
        return this->allocation_count;
    }
};
int main()
{
    Kernalallocate Page[10];
    cout << "Allocating the memory\n";
    for (int i = 0; i < sizeof(Page) / sizeof(Page[0]); i++)
    {
        if (!Page[i].isfree())
            Page[i].Allocate_memory();
        else
            cout << "Memory not Available at  " << i + 1 << "\n";
    }
    cout << "\n\n";
    cout << "Page No.--Status--HowMuchUsed\n";
    for (int i = 0; i < sizeof(Page) / sizeof(Page[0]); i++)
    {
        if (!Page[i].isfree())
            cout << "Page " << i + 1 << ":  Not Allocated   ";
        else
            cout << "Page " << i + 1 << ":  Allocated   ";
        cout << Page[i].HowMuchUsed() << "\n";
    }
    cout << "\n\n";
    cout << "Deallocating some of the memory to reuse\n";
    for (int i = 0; i < sizeof(Page) / sizeof(Page[0]); i += 2)
    {
        if (!Page[i].isfree())
            cout << "Memory Already free at  " << i + 1 << "\n";
        else
            Page[i].Deallocate_memory();
    }
    cout << "\n\n";
    cout << "Reallocating the free memory to reuse\n";
    for (int i = 0; i < sizeof(Page) / sizeof(Page[0]); i++)
    {
        if (!Page[i].isfree())
            Page[i].Allocate_memory();
        else
            cout << "Memory not Available at  " << i + 1 << "\n";
    }
    cout << "\n\n";
    cout << "Page No.--Status--HowMuchUsed\n";
    for (int i = 0; i < sizeof(Page) / sizeof(Page[0]); i++)
    {
        if (!Page[i].isfree())
            cout << "Page " << i + 1 << ":  Not Allocated   ";
        else
            cout << "Page " << i + 1 << ":  Allocated   ";
        cout << Page[i].HowMuchUsed() << "\n";
    }
    cout << "\n\n";
    cout << "Deallocating all the memory \n";
    for (int i = 0; i < sizeof(Page) / sizeof(Page[0]); i++)
    {
        if (!Page[i].isfree())
            cout << "Memory Already free at  " << i + 1 << "\n";
        else
            Page[i].Deallocate_memory();
    }
    cout << "\n\n";
    cout << "----------Final Status--------------\n";
    cout << "Page No.--Status--HowMuchUsed\n";
    for (int i = 0; i < sizeof(Page) / sizeof(Page[0]); i++)
    {
        if (!Page[i].isfree())
            cout << "Page " << i + 1 << ":  Not Allocated   ";
        else
            cout << "Page " << i + 1 << ":  Allocated   ";
        cout << Page[i].HowMuchUsed() << "\n";
    }
}