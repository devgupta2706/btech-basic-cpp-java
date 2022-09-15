#include <iostream>
using namespace std;
struct linked_block
{
    FILE f_new;
    bool flag = false;
    linked_block *next;
};
linked_block *allocate_linkedBLOCKS()
{
    linked_block *B = new linked_block;
    B->next = nullptr;
    B->flag = true;
    cout << "First block allocated\n";
    char ch = 'Y';
    linked_block *temp;
    temp = B;
    // temp=temp->next;
    while (ch == 'y' || ch == 'Y')
    {
        // temp->flag = true;
        // temp = temp->next;

        cout << "Do you want to allocate next block (Y or N)\t";
        cin >> ch;
        if (ch == 'y' || ch == 'Y')
        {
            linked_block *S = new linked_block;
            temp->next = S;
            temp = S;
            cout << "Next Block created successfully\n";
        }
    }

    return B;
}
void deallocate_block(linked_block *A)
{
    delete A;
    cout << "Block cleared\n";
    return;
}
int main()
{
    linked_block *B1;
    B1 = allocate_linkedBLOCKS();
    deallocate_block(B1);
    return 0;
}