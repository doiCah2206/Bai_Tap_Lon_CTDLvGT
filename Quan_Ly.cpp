#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

class Student
{
    string Name;
    // int Date[3];
    int Stu_Code;
    int *Date;
    string Class;
    // int Score[3];
    float *Score;

public:
    Student()
    {
        Name = "";
        // Date[0] = Date[1] = Date[2] = 0;
        Date = new int[3]{0, 0, 0};
        Stu_Code = 0;
        // Score[0] = Score[1] = Score[2] = 0;
        Score = new float[3]{0, 0, 0};
        Class = "";
    }
    Student(string N, int *D, int Scd, int *S, string C)
    {
        Name = N;
        Stu_Code = Scd;
        Class = C;
        Date = new int[3];
        Score = new float[3];
        for (int i = 0; i < 3; i++)
        {
            Date[i] = D[i];
            Score[i] = S[i];
        }
    }
    // ~Student()
    // {
    //     delete[] Date;
    //     delete[] Score;
    // }
    string upperName(string N)
    {
        for (int i = 0; i < N.length(); i++)
        {
            if (i == 0 || (i > 0 && N[i - 1] == ' '))
            {
                if (N[i] >= 'a' & N[i] <= 'z')
                {
                    N[i] = N[i] - 32;
                }
            }
            else
            {
                if (N[i] >= 'A' && N[i] <= 'Z')
                {
                    N[i] = N[i] + 32;
                }
            }
        }
        return N;
    }
    friend istream &operator>>(istream &is, Student &s)
    {
        cout << "Enter Full Name Student: ";
        is.ignore();
        getline(is, s.Name);
        s.Name = s.upperName(s.getName());
        cout << "Enter Student Code: ";
        is >> s.Stu_Code;
        cout << "Enter Date Of Birth(dd mm yyyy): \n";
        cout << "  Day: ";
        is >> s.Date[0];
        cout << "  Month: ";
        is >> s.Date[1];
        cout << "  Year: ";
        is >> s.Date[2];
        cout << "Enter Class(Ex : 10A): ";
        is.ignore();
        getline(is, s.Class);
        cout << "Enter Scores(Literature,Math,English) \n";
        cout << "  Literature: ";
        is >> s.Score[0];
        cout << "  Math: ";
        is >> s.Score[1];
        cout << "  English: ";
        is >> s.Score[2];
        return is;
    }
    friend ostream &operator<<(ostream &os, Student &s)
    {
        os << "Name: " << s.Name << endl
           << "Student Code: " << s.Stu_Code << endl
           << "Date of Birth: " << s.Date[0] << "/" << s.Date[1] << "/" << s.Date[2] << endl
           << "Class: " << s.Class << endl
           << "Scores:" << endl
           << "       Literature: " << s.Score[0] << endl
           << "       Math: " << s.Score[1] << endl
           << "       English: " << s.Score[2] << endl;
        return os;
    }
    // getter
    string getClass()
    {
        return Class;
    }
    int getStuCode()
    {
        return Stu_Code;
    }
    float *getScore()
    {
        return Score;
    }
    int *getDate()
    {
        return Date;
    }
    string getName()
    {
        return Name;
    }
    // setter
    void setName(string N)
    {
        Name = N;
    }
    void setScode(int Sc)
    {
        Stu_Code = Sc;
    }
    void setClass(string C)
    {
        Class = C;
    }
    void setDay(int d)
    {
        Date[0] = d;
    }
    void setMonth(int m)
    {
        Date[1] = m;
    }
    void setYear(int y)
    {
        Date[2] = y;
    }
    void setLiterature(float l)
    {
        Score[0] = l;
    }
    void setMath(float m)
    {
        Score[1] = m;
    }
    void setEnglish(float e)
    {
        Score[2] = e;
    }
};

class Managment_List
{
    vector<Student> Vec_Student;

public:
    Managment_List() {}
    vector<Student> &getVector()
    {
        return Vec_Student;
    }
    void Add_Student(const Student &s)
    {
        Vec_Student.push_back(s);
    }
    void Del_Student(int x)
    {
        auto f = Find(x);
        if (f != Vec_Student.end())
        {

            cout << "Confirm deletion (Y/N): ";
            char C;
            cin >> C;
            while (C != 'Y' && C != 'N')
            {
                cout << "Try Again!!!\n";
                cout << "Enter your choice Y or N : ";
                cin >> C;
            }
            if (C == 'Y')
            {
                Vec_Student.erase(f);
                cout << "Student with code " << x << " has been deleted.\n";
            }
        }
    }
    double Average_Score(Student &s)
    {
        double As = 0;
        for (int i = 0; i < 3; i++)
        {
            As += s.getScore()[i];
        }

        return As / 3;
    }
    vector<Student>::iterator Find(int X)
    {
        for (auto it = Vec_Student.begin(); it != Vec_Student.end(); ++it)
        {
            if (it->getStuCode() == X)
            {
                cout << "Student information with code " << X << endl
                     << endl;
                cout << *it;
                return it;
            }
        }
        cout << "Study With Code \"" << X << "\" Not Found.\n ";
        return Vec_Student.end();
    }
    void Fix(int x, vector<Student>::iterator f)
    {
        if (f != Vec_Student.end())
        {
            switch (x)
            {
            case 1:
            {
                cout << "Enter new name: ";
                string newN;
                cin.ignore();
                getline(cin, newN);
                newN = f->upperName(newN);
                f->setName(newN);
                cout << right << setw(20) << "Edit Succesfull\n";
                break;
            }
            case 2:
            {
                cout << "Enter new Student Code : ";
                int newSc;
                cin >> newSc;
                f->setScode(newSc);
                cout << right << setw(20) << "Edit Succesfull\n";
                break;
            }
            case 3:
            {
                cout << "Enter new day of birth: ";
                int newD;
                cin >> newD;
                f->setDay(newD);
                cout << right << setw(20) << "Edit Succesfull\n";
                break;
            }
            case 4:
            {
                cout << "Enter new month of birth: ";
                int newM;
                cin >> newM;
                f->setMonth(newM);
                cout << right << setw(20) << "Edit Succesfull\n";
                break;
            }
            case 5:
            {
                cout << "Enter new year of birth: ";
                int newY;
                cin >> newY;
                f->setYear(newY);
                cout << right << setw(20) << "Edit Succesfull\n";
                break;
            }
            case 6:
            {
                cout << "Enter new class: ";
                string newCl;
                cin.ignore();
                getline(cin, newCl);
                f->setClass(newCl);
                cout << right << setw(20) << "Edit Succesfull\n";
                break;
            }
            case 7:
            {
                cout << "Enter new Literature Score: ";
                int newL;
                cin >> newL;
                f->setLiterature(newL);
                cout << right << setw(20) << "Edit Succesfull\n";
                break;
            }
            case 8:
            {
                cout << "Enter new Math Score: ";
                int newMt;
                cin >> newMt;
                f->setMath(newMt);
                cout << right << setw(20) << "Edit Succesfull\n";
                break;
            }
            case 9:
            {
                cout << "Enter new English Score: ";
                int newE;
                cin >> newE;
                f->setEnglish(newE);
                cout << right << setw(20) << "Edit Succesfull\n";
                break;
            }
            }
        }
    }
    void Arrange()
    {
        sort(Vec_Student.begin(), Vec_Student.end(), [this](Student &a, Student &b)
             { return Average_Score(a) > Average_Score(b); });
    }
    void Print()
    {
        cout << left << setw(20) << "Full name"
             << setw(20) << "Student Code"
             << setw(20) << "Date of Birth"
             << setw(10) << "Class"
             << setw(15) << "Literature"
             << setw(10) << "Math"
             << setw(10) << "English"
             << setw(10) << "Avarage_Score" << endl;

        for (auto &s : Vec_Student)
        {
            cout << left << setw(20) << s.getName()
                 << setw(20) << s.getStuCode()
                 << (s.getDate())[0] << "\\" << (s.getDate())[1] << "\\" << setw(14 + (s.getDate()[0] > 10 ? 0 : 1) + (s.getDate()[1] > 10 ? 0 : 1)) << (s.getDate())[2]
                 << setw(10) << s.getClass()
                 << setw(15) << (s.getScore())[0]
                 << setw(10) << (s.getScore())[1]
                 << setw(10) << (s.getScore())[2]
                 << setw(10) << Average_Score(s) << endl;
        }
    }
};
