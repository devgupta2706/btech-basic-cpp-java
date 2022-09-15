#include <iostream>
#include <vector>
using namespace std;
struct indexed_block
{
    FILE f_new;
    string name;
    bool flag = false;
};
void create_IBLOCKS(vector<indexed_block *> *B)
{
    char ch = 'y';
    while (ch == 'y' || ch == 'Y')
    {
        cout << "Do you want to allocate next block (Y or N)\t";
        cin >> ch;
        if (ch == 'y' || ch == 'Y')
        {
            indexed_block *S = new indexed_block();
            S->flag = true;
            cout << "\nEnter File name\t";
            cin >> S->name;
            B->push_back(S);
            cout << "Next Block created successfully\n";
        }
    }
}
void deallocate_IBLOCK(vector<indexed_block *> *B)
{
    string naam;
    cout << "\nEnter File name to delete\t";
    cin >> naam;
    auto ate = B->begin();
    for (ate = B->begin(); ate != B->end(); ate++)
    {
        if ((*ate)->name == naam)
        {
            B->erase(ate);
            cout << "Block deleted successfully\n";
            return;
        }
    }
    cout << "File did not exists, sahi wali de\n";
}
int main()
{
    vector<indexed_block *> B;

    create_IBLOCKS(&B);
    deallocate_IBLOCK(&B);
    return 0;
}