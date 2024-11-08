#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "Quan_Ly.cpp"
using namespace std;

class App
{
    Managment_List *M;

public:
    App() { M = new Managment_List(); }
    ~App() { delete M; }
    void menu()
    {
        while (true)
        {
            cout << endl;
            const int width = 50;
            const string separator(width, '-');
            cout << separator << endl;
            cout << right;
            cout << setw(27) << "Menu" << endl;
            cout << setw(23) << "0. Exit" << endl;
            cout << setw(30) << "1. Add Student" << endl;
            cout << setw(33) << "2. Delete Student" << endl;
            cout << setw(31) << "3. Find Student" << endl;
            cout << setw(23) << "4. Edit" << endl;
            cout << setw(31) << "5. List Student" << endl;
            cout << "\nYour Choice: ";
            int choice;
            cin >> choice;
            switch (choice)
            {
            case 0:
            {
                cout << "Exit Menu Has Been Completed";
                return;
            }
            case 1:
            {
                cout << setw(28) << "Add Student" << endl;
                Student s;
                cin >> s;
                bool find = false;
                for (auto &m : M->getVector())
                {
                    if (m.getStuCode() == s.getStuCode())
                    {
                        cout << setw(50) << "\n!!! Student with code " << s.getStuCode() << " allready exists!!!" << endl;
                        M->Find(s.getStuCode());
                        cout << right << setw(33) << "!!! Try Again !!!";
                        find = true;
                        break;
                    }
                }
                if (find)
                    break;
                M->Add_Student(s);
                break;
            }
            case 2:
            {
                cout << setw(28) << "Delete Student" << endl;
                cout << "Enter Student Code: ";
                int x;
                cin >> x;
                M->Del_Student(x);
                break;
            }
            case 3:
            {
                cout << setw(29) << "Find Student" << endl;
                cout << "Enter Student Code: ";
                int X;
                cin >> X;
                M->Find(X);
                break;
            }
            case 4:
            {
                cout << setw(29) << "Edit Student" << endl;
                cout << "Enter Student Code: ";
                int X;
                cin >> X;
                auto find = M->Find(X);

                if (find == (M->getVector()).end())
                {
                    break;
                }
                bool found = true;
                while (found)
                {
                    cout << endl;
                    cout << right;
                    cout << setw(50) << "Choose your choice to edit information: \n";
                    cout << " 0. Exit" << endl;
                    cout << " 1. Name" << endl;
                    cout << " 2. Student code " << endl;
                    cout << " 3. Day of birth " << endl;
                    cout << " 4. Month of birth" << endl;
                    cout << " 5. Year of birth" << endl;
                    cout << " 6. Class" << endl;
                    cout << " 7. Literature Score " << endl;
                    cout << " 8. Math Score " << endl;
                    cout << " 9. English Score " << endl;
                    cout << "\nYour Choice: ";
                    int ch;
                    cin >> ch;
                    switch (ch)
                    {
                    case 0:
                    {
                        cout << "Exit Edit Information Student\n";
                        found = false;
                        break;
                    }
                    default:
                    {
                        M->Fix(ch, find);
                        break;
                    }
                    }
                }
                break;
            }
            case 5:
            {
                cout << setw(50) << "Student List" << endl;
                M->Arrange();
                M->Print();
            }
            }
        }
    }
};

int main()
{
    App Menu;
    Menu.menu();
}
