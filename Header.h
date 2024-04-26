#include <iostream>
#include <vector>
using namespace std;

class OBE;

class User {
private:
    string name;
    int id;
public:
    User(string Name, int ID) {
        name = Name;
        id = ID;
    }
    void setName(string Name) {
        name = Name;
    }
    void setID(int ID) {
        id = ID;
    }
    string getName() {
        return name;
    }
    int getID() {
        return id;
    }
};

class Academic_Officer : public User { 
private:
    OBE * obe;
public:
    Academic_Officer(string Name, int ID) : User(Name,ID) {}
    static void setOBE(OBE * obe_ptr) {
        obe = obe_ptr; 
    }
};

 //class Teacher : public User
 //{
 //private:
 //public:
 //    Teacher()
 //    {

 //    }
 //};

 class Program
 {
 private:
     string name;
     // PLO plo[];
     // Course courses *[];
      float GPA;

 public:
     Program(string Name = "", float gpa = 0)
     {
         name = Name;
         GPA = gpa;
         // this->plo = plo;
         // this->courses = courses;
         // this->GPA = GPA;
     }
 };

//Singleton Class
class OBE {
private:
    vector<Academic_Officer*> academicOfficers;
    vector<Program*> program;
public:
    OBE()
    {
    }
    void init_program(Program *p1)
    {
        program.push_back(p1);
    }
    void init_officers(Academic_Officer * a1)
    {
        academicOfficers.push_back(a1);
    }
    vector<Program*> get_programs()
    {
        return program;
    }
    vector<Academic_Officer*> get_officers()
    {
        return academicOfficers;
    }
};




