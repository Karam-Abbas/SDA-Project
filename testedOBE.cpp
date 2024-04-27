#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Program
{
public:
    Program(string name, string id) : name(name), id(id)
    {
    }

    void setName(string name)
    {
        this->name = name;
    }

    void setId(string id)
    {
        this->id = id;
    }
    string getName() const
    {
        return name;
    }
    string getId() const
    {
        return id;
    }

private:
    string name;
    string id;
};

// Singleton class
class OBE
{
public:
    OBE(const OBE &) = delete;
    static OBE &Get()
    {
        return obe_Instance;
    }
    void CheckOBE()
    {
        cout << name << " is operational\n";
    }
    void setName(string name)
    {
        this->name = name;
    }
    string getName() const
    {
        return name;
    }
    void addProgram(const Program &program)
    {
        programs.push_back(program);
    }

    void printPrograms()
    {
        cout << "Programs offered by " << getName() << ":\n\n";
        for (const auto &program : programs)
        {
            cout << "Program Name: " << program.getName() << "\n";
            cout << "Program ID: " << program.getId() << "\n\n";
        }
    }

private:
    OBE() {}

    static OBE obe_Instance;
    string name;
    vector<Program> programs;
};

OBE OBE::obe_Instance;

class User
{
public:
    User(const string &name, const int &id) : name(name), id(id)
    {
    }
    void setName(string name)
    {
        this->name = name;
    }
    void setId(int id)
    {
        this->id = id;
    }
    string getName()
    {
        return name;
    }
    int getId()
    {
        return id;
    }
    void getUserDetails()
    {
        cout << "Name : " << getName() << "\n";
        cout << "ID : " << getId() << "\n";
    }

private:
    string name;
    int id;
};

class AcademicOfficer : public User
{
public:
    AcademicOfficer(const string &name, const int &id) : User(name, id)
    {
    }

    OBE &getOBE()
    {
        return OBE::Get();
    }

private:
};

class Teacher : public User
{
public:
    Teacher(const string &name, const int &id) : User(name, id)
    {
    }

private:
};

int main()
{
    OBE &obe = OBE::Get();
    obe.setName("FLex++");

    AcademicOfficer ao1("Alex", 1);
    AcademicOfficer ao2("Ben", 2);
    AcademicOfficer ao3("Cash", 3);

    // cout << ao1.getName() << "\n";
    // cout << ao1.getId() << "\n";

    // ao2.getUserDetails();
    // ao3.getUserDetails();

    Teacher t1("Daniel", 4);
    Teacher t2("Eugene", 5);
    Teacher t3("Fred", 6);

    // cout << t1.getName() << "\n";
    // cout << t1.getId() << "\n";

    // t2.getUserDetails();
    // t3.getUserDetails();

    ao1.getOBE().CheckOBE();
    ao2.getOBE().CheckOBE();
    ao3.getOBE().CheckOBE();

    Program program1("Computer Science", "CS101");
    Program program2("Mechanical Engineering", "ME201");
    Program program3("Electrical Engineering", "EE301");

    ao1.getOBE().addProgram(program1);
    ao2.getOBE().addProgram(program2);
    ao3.getOBE().addProgram(program3);

    AcademicOfficer ao4("George", 3);

    ao4.getOBE().printPrograms();
    return 0;
}