#include <iostream>
#include <vector>
using namespace std;
struct contigious_block
{
    FILE f_new;
    string name;
    bool flag = false;
};
void create_cBLOCKS(vector<contigious_block> *B)
{
    char ch = 'y';
    while (ch == 'y' || ch == 'Y')
    {
        cout << "Do you want to allocate next block (Y or N)\t";
        cin >> ch;
        if (ch == 'y' || ch == 'Y')
        {
            contigious_block *S = new contigious_block();
            S->flag = true;
            cout << "\nEnter File name\t";
            cin >> S->name;
            B->push_back(*S);
            cout << "Next Block created successfully\n";
        }
    }
}
void deallocate_cBLOCK(vector<contigious_block> *B)
{
    string naam;
    cout << "\nEnter File name to delete\t";
    cin >> naam;
    auto ate = B->begin();
    for (ate = B->begin(); ate != B->end(); ate++)
    {
        if ((ate)->name == naam)
        {
            B->erase(ate);
            cout << "Block deleted successfully\n";
            return;
        }
    }
    cout << "File did not exists, sahi wali de\n";
}
// int main()
// {
//     vector<contigious_block> B;

//     create_cBLOCKS(&B);
//     deallocate_cBLOCK(&B);
//     return 0;
// }