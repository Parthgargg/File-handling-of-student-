#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int ID = 0;
class student
{
public:
    int id;
    int age;
    string name;
    string stream;

    void addStudent()
    {
        cout << "Enter your name : ";
        cin.get();
        getline(cin, name);
        cout << "Enter your age : ";
        cin >> age;
        cout << "Enter your stream : ";
        cin >> stream;
        ID++;

        ofstream fout;
        fout.open("D:/file/student.txt", ios::app);
        fout << "\n"
             << ID;
        fout << "\n"
             << name;
        fout << "\n"
             << age;
        fout << "\n"
             << stream;
        fout.close();

        fout.open("D:/file/id.txt", ios::app);
        fout << "\n"
             << ID;
        fout.close();

        cout << "Record Added Successfully" << endl;
    }
    void printAllStudent()
    {
        ifstream fin;

        fin.open("D:/file/student.txt");
        student s;
        while (!fin.eof())
        {
            fin >> s.id;
            fin.ignore();
            getline(fin, s.name);
            fin >> s.age;
            fin >> s.stream;

            s.print();
        }

        fin.close();
    }

    void print()
    {
        cout << ".................................." << endl;
        cout << " ID = " << id << endl;
        cout << " Name = " << name << endl;
        cout << " Age = " << age << endl;
        cout << " Stream = " << stream << endl;
        cout << ".................................." << endl;
    }
    void searchStudent(int id)
    {
        ifstream fin;
        fin.open("D:/file/student.txt");

        student s;
        while (!fin.eof())
        {
            fin >> s.id;
            fin.ignore();
            getline(fin, s.name);
            fin >> s.age;
            fin >> s.stream;

            if (s.id == id)
            {
                s.print();
                break;
            }
            else
            {
                cout << "Id doesnot exist " << endl;
            }
        }
        fin.close();
    }

    void deleteStudent(int id)
    {
        ifstream fin;
        fin.open("D:/file/student.txt");

        ofstream fout;
        fout.open("D:/file/temp.txt", ios::app);

        student s;
        while (!fin.eof())
        {
            fin >> s.id;
            fin.ignore();
            getline(fin, s.name);
            fin >> s.age;
            fin >> s.stream;

            if (s.id != id)
            {
                fout << "\n"
                     << s.id;
                fout << "\n"
                     << s.name;
                fout << "\n"
                     << s.age;
                fout << "\n"
                     << s.stream;
            }
            else
            {
                cout << "Id doesnot exist " << endl;
            }
        }

        fin.close();
        fout.close();

        remove("D:/file/student.txt");
        rename("D:/file/temp.txt", "D:/file/student.txt");

        cout << "Record Deleted Successfully" << endl;
    }
    void updateStudent(int id)
    {
        deleteStudent(id);

        cout << "Enter your name : ";
        cin.get();
        getline(cin, name);
        cout << "Enter your age :";
        cin >> age;
        cout << "Enter your stream : ";
        cin >> stream;
        ID++;

        ofstream fout;
        fout.open("D:/file/student.txt", ios::app);
        fout << "\n"
             << id;
        fout << "\n"
             << name;
        fout << "\n"
             << age;
        fout << "\n"
             << stream;
        fout.close();

        cout << "Record Added Successfully" << endl;
    }
};
int main()
{
    int choice;

    ifstream fin;
    fin.open("D:/file/id.txt");
    fin.seekg(0, ios::end);
    if (!fin)
    {
        cout << "File Not Found" << endl;
    }
    else
    {
        while (!fin.eof())
        {

            if (fin.tellg() == 0)
            {
                cout << " File is empty " << endl;
                break;
            }
            else
            {
                fin.seekg(0, ios::beg);
                while (!fin.eof())
                {
                    fin >> ID;
                }
            }
        }
    }

    fin.close();
    cout << "ID = " << ID << endl;

    while (true)
    {
        cout << "Enter Your choice" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Print all the students" << endl;
        cout << "3. Search a student" << endl;
        cout << "4. Update a student" << endl;
        cout << "5. Delete a student" << endl;
        cout << "6.Exit" << endl;

        cin >> choice;

        student s;
        int id;
        switch (choice)
        {
        case 1:
            s.addStudent();
            break;
        case 2:
            s.printAllStudent();
            break;
        case 3:
            cout << "Enter student id : ";
            cin >> id;
            s.searchStudent(id);
            break;

        case 4:
            cout << "Enter student id";
            cin >> id;
            s.updateStudent(id);
            break;

        case 5:
            cout << "Enter student id";
            cin >> id;
            s.deleteStudent(id);
            break;

        default:
            cout << "Exited " << endl;
            return 0;
        }
    }

    return 0;
}
