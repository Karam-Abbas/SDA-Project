#include <iostream>
#include <vector>
#include <cstdlib>
#include <conio.h>
#include <string>
using namespace std;

class CLO
{
private:
    string clo_description;
    string ID;

public:
    CLO(string str, string id) : clo_description(str), ID(id) {}
    string getCloDescription() const
    {
        return clo_description;
    }
    void setCloDescription(string desc)
    {
        clo_description = desc;
    }
    string getCloId() const
    {
        return ID;
    }
};

class Question
{
private:
    string question_description;
    vector<CLO *> clo_list;
    string ID;

public:
    Question(){}
    Question(string Desc, string id)
    {
        question_description = Desc;
        ID = id;
    }
    string get_question_description() const
    {
        return question_description;
    }
    void set_question_description(const string &Desc)
    {
        question_description = Desc;
    }
    void set_question_id(const string &ID)
    {
        question_description = ID;
    }
    CLO *clo_in_question(int index)
    {
        return clo_list[index];
    }
    void add_clo_in_question(CLO *ptr)
    {
        clo_list.push_back(ptr);
    }
    void updateCLO(string cloID, CLO *newClo)
    {
        for (unsigned int i = 0; i < clo_list.size(); i++)
        {
            if (clo_list[i]->getCloId() == cloID)
            {
                clo_list.erase(clo_list.begin() + i);
            }
        }
        clo_list.push_back(newClo);
    }
    void removeCLO(string cloID)
    {
        for (unsigned int i = 0; i < clo_list.size(); i++)
        {
            if (clo_list[i]->getCloId() == cloID)
            {
                clo_list.erase(clo_list.begin() + i);
            }
        }
    }
    string getQuestionID() const
    {
        return ID;
    }
};

class Evaluation
{
private:
    string ID;
    vector<Question> questions;

public:
    Evaluation(string n) : ID(n) {}
    string get_ID() const
    {
        return ID;
    }
    void removeQuestion(string Q_id)
    {
        for (unsigned int i = 0; i < questions.size(); i++)
        {
            if (questions[i].getQuestionID() == Q_id)
            {
                questions.erase(questions.begin() + i);
            }
        }
    }
    void updateQuestion(string Q_id, Question newQuestion)
    {
        for (unsigned int i = 0; i < questions.size(); i++)
        {
            if (questions[i].getQuestionID() == Q_id)
            {
                questions.erase(questions.begin() + i);
            }
            questions.push_back(newQuestion);
        }
    }
    void add_question(Question q1)
    {
        questions.push_back(q1);
    }
    Question &get_questionFromList(int index)
    {
        return questions[index];
    }
    void updateEvaluationWholeQuestionList(vector<Question> obj)
    {
        questions = obj;
    }
    void Questions_printer() {
    for (const auto& question : questions) {
        cout << "Question " << question.getQuestionID() << " : " << question.get_question_description() << endl;
    }
}
};

class PLO
{
private:
    string plo_description;
    vector<CLO *> clo_list;
    string ID;

public:
    PLO(string disp, string id) : plo_description(disp), ID(id) {}
    string getPloDescription() const
    {
        return plo_description;
    }
    void setPloDescription(string desc)
    {
        plo_description = desc;
    }
    CLO *getCloFromList(int index)
    {
        return clo_list[index];
    }
    void addCLO(CLO *clo)
    {
        clo_list.push_back(clo);
    }
    string getPloId() const
    {
        return ID;
    }
    void CLO_printer()
    {
        for (unsigned int i = 0; i < clo_list.size(); i++)
        {
            cout << clo_list[i]->getCloId() << " " << clo_list[i]->getCloDescription() << endl;
        }
    }
    void removeClo(string C_id)
    {
        for (unsigned int i = 0; i < clo_list.size(); i++)
        {
            if (clo_list[i]->getCloId() == C_id)
            {
                clo_list.erase(clo_list.begin() + i);
            }
        }
    }
    void updateClo(string C_id, CLO *obj)
    {
        for (unsigned int i = 0; i < clo_list.size(); i++)
        {
            if (clo_list[i]->getCloId() == C_id)
            {
                clo_list.erase(clo_list.begin() + i);
            }
        }
        clo_list.push_back(obj);
    }
};

class Course
{
private:
    string course_name;
    string course_id;
    vector<CLO> clo_list;
    vector<Evaluation *> evaluations_list;

public:
    Course(const string &name, const string &id) : course_name(name), course_id(id) {}
    string getCourseName() const
    {
        return course_name;
    }
    string getCourseId() const
    {
        return course_id;
    }
    CLO &getFromCloList(int index)
    {
        if (index <= clo_list.size())
        {
            return clo_list[index];
        }
        else
        {
            cout << "Index out of range in function getFromCloList()" << endl;
        }
    }
    void addCLO(CLO clo)
    {
        clo_list.push_back(clo);
    }
    Evaluation *getFromEvaluationsList(int Index)
    {
        if (Index <= evaluations_list.size())
        {
            return evaluations_list[Index];
        }
        else
        {
            cout << "Index out of range in function getFromEvaluationsList()" << endl;
        }
    }
    void addEvaluation(Evaluation *ptr)
    {
        evaluations_list.push_back(ptr);
    }
    void removeCLO(string id)
    {
        for (unsigned int i = 0; i < clo_list.size(); i++)
        {
            if (clo_list[i].getCloId() == id)
            {
                clo_list.erase(clo_list.begin() + i);
                cout << "Success" << endl;
                break;
            }
            else
            {
                cout << "CLO not found!" << endl;
            }
        }
    }
    void removeEvaluation(string id)
    {
        for (unsigned int i = 0; i < evaluations_list.size(); i++)
        {
            if (evaluations_list[i]->get_ID() == id)
            {
                evaluations_list.erase(evaluations_list.begin() + i);
                cout << "Success" << endl;
                break;
            }
            else
            {
                cout << "Evaluation not found!" << endl;
            }
        }
    }
    void updateCLO(string id, CLO clo)
    {
        for (unsigned int i = 0; i < clo_list.size(); i++)
        {
            if (clo_list[i].getCloId() == id)
            {
                clo_list.erase(clo_list.begin() + i);
                cout << "Success" << endl;
                break;
            }
            else
            {
                cout << "CLO not found!" << endl;
            }
        }
        clo_list.push_back(clo);
    }
    void updateEvaluation(string id, Evaluation *ptr)
    {
        for (unsigned int i = 0; i < evaluations_list.size(); i++)
        {
            if (evaluations_list[i]->get_ID() == id)
            {
                evaluations_list.erase(evaluations_list.begin() + i);
                cout << "Success" << endl;
                break;
            }
            else
            {
                cout << "Evaluation not found! 312" << endl;
            }
        }
        evaluations_list.push_back(ptr);
    }
    void EvaluationsPrinter()
    {
        for (unsigned int i = 0; i < evaluations_list.size(); i++)
        {
            cout << "Questions of " << evaluations_list[i]->get_ID() << " :";
            evaluations_list[i]->Questions_printer();
        }
    }
    void CLOPrinter()
    {
        for (unsigned int i = 0; i < clo_list.size(); i++)
        {
            cout << "ID: " << clo_list[i].getCloId() << endl;
            cout << "Description: " << clo_list[i].getCloDescription() << endl;
        }
    }

    void printAllEvaluations() const
    {
        cout << "Evaluations in " << getCourseName() << " (" << getCourseId() << ")"<< ":\n" << endl;
        for (const auto &eval : evaluations_list)
        {
            cout << "Evaluation ID: " << eval->get_ID() << endl;
        }
    }
    Evaluation &getEvaluationById(const string &eval_id)
    {
        for (Evaluation *eval : evaluations_list)
        {
            if (eval->get_ID() == eval_id)
            {
                return *eval;
            }
        }
        throw std::runtime_error("Evaluation with ID " + eval_id + " not found.");
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

class Program
{
public:
    Program(string name, string id) : name(name), id(id) {}

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

    const vector<PLO> &get_plo_list() const
    {
        return plo_list;
    }

    PLO &getPLO(int index)
    {
        return plo_list[index];
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

    void printCourses() const
    {
        cout << "Courses offered by Program " << id << " (" << name << "):\n\n";
        for (const auto &course : course_list)
        {
            cout << "Course ID: " << course->getCourseId() << "\n";
            cout << "Course name: " << course->getCourseName() << "\n";
            cout << "\n";
        }
    }

    Course &getCourseById(const string &course_id)
    {
        for (auto &course : course_list)
        {
            if (course->getCourseId() == course_id)
            {
                return *course;
            }
        }
        throw std::runtime_error("Course with ID " + course_id + " not found.");
    }

private:
    string name;
    string id;
    vector<PLO> plo_list;
    vector<Course *> course_list;
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
    Program &getProgram(int index)
    {
        return programs[index];
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

    Program &getProgramById(const string &program_id)
    {
        for (Program &program : programs)
        {
            if (program.getId() == program_id)
            {
                return program;
            }
        }
        throw std::runtime_error("Program with ID " + program_id + " not found.");
    }

    void printPLOs()
    {
        cout << "Programs offered by " << getName() << ":\n\n";
        for (const auto &program : programs)
        {
            cout << "Program Name: " << program.getName() << "\n";
            cout << "Program ID: " << program.getId() << "\n\n";

            const vector<PLO> &plos = program.get_plo_list();

            cout << "PLOs:\n";
            for (const auto &plo : plos)
            {
                cout << "ID: " << plo.getPloId() << "\n";
                cout << "Description: " << plo.getPloDescription() << "\n";
                cout << "\n";
            }
            cout << "\n";
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