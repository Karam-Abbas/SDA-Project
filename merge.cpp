#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Question;
class Evaluation;
class Course;
class Topic;
class CLO;
class PLO;
class Program;

class PLO
{
private:
    string plo_description;
    vector<CLO *> clo_list;

public:
    PLO(const string &disp) : plo_description(disp) {}
    string getPloDescription() const
    {
        return plo_description;
    }
    void setPloDescription(const string &desc)
    {
        plo_description = desc;
    }
    const vector<CLO *> &getCloList() const
    {
        return clo_list;
    }
    void addCLO(CLO *clo)
    {
        clo_list.push_back(clo);
    }
};
class Program
{
private:
    string name;
    string id;
    vector<PLO> plo_list;
    vector<Course *> course_list;

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
    vector<PLO> get_plo_list()
    {
        return plo_list;
    }
    vector<Course *> get_course_list()
    {
        return course_list;
    }
    void addTo_plo_list(PLO obj)
    {
        plo_list.push_back(obj);
    }
    void addTo_course_list(Course *obj)
    {
        course_list.push_back(obj);
    }
};

class CLO
{
private:
    string clo_description;

public:
    CLO(const string &str) : clo_description(str) {}
    string getCloDescription() const
    {
        return clo_description;
    }
    void setCloDescription(const string &desc)
    {
        clo_description = desc;
    }
};

class Topic
{
private:
    bool covered;

public:
    Topic() : covered(false) {}
    bool isCovered() const
    {
        return covered;
    }
    void setCovered(bool value)
    {
        covered = value;
    }
};

class Course
{
private:
    string course_id;
    vector<CLO> clo_list;
    vector<Evaluation> evaluations_list;

public:
    Course(const string &id) : course_id(id) {}
    string getCourseID() const
    {
        return course_id;
    }
    void setCourseID(const string &id)
    {
        course_id = id;
    }
    const vector<CLO> &getCloList() const
    {
        return clo_list;
    }
    void addCLO(const CLO &clo)
    {
        clo_list.push_back(clo);
    }
    const vector<Evaluation> &getEvaluationsList() const
    {
        return evaluations_list;
    }
    void addEvaluation(const Evaluation &evaluation)
    {
        evaluations_list.push_back(evaluation);
    }
};

class Question
{
private:
    string question_description;
    vector<CLO *> clo_list;

public:
    Question(string Desc)
    {
        question_description = Desc;
    }
    string get_question_description() const
    {
        return question_description;
    }
    void set_question_description(const string &Desc)
    {
        question_description = Desc;
    }
    vector<CLO *> clo_included_in_question()
    {
        return clo_list;
    }
    void add_clo_in_question(CLO *ptr)
    {
        clo_list.push_back(ptr);
    }
};
class Evaluation
{
private:
    string name;
    vector<Question> questions;

public:
    Evaluation(string n) : name(n) {}
    string get_name() const
    {
        return name;
    }
    void set_name(string new_name)
    {
        name = new_name;
    }
    void add_question(Question q1)
    {
        questions.push_back(q1);
    }
    const vector<Question> &get_questions() const
    {
        return questions;
    }
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

    Program getProgram(int i){
        return programs[i];
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

    // ao1.getOBE().CheckOBE();
    // ao2.getOBE().CheckOBE();
    // ao3.getOBE().CheckOBE();

    Program program1("Computer Science", "CS101");
    Program program2("Mechanical Engineering", "ME201");
    Program program3("Electrical Engineering", "EE301");

    ao1.getOBE().addProgram(program1);
    ao2.getOBE().addProgram(program2);
    ao3.getOBE().addProgram(program3);

    AcademicOfficer ao4("George", 3);

    cout << ao4.getOBE().getProgram(0).getName();

    return 0;
}