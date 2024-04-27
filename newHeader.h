#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <algorithm>
using namespace std;
class Question;
class Evaluation;
class CLO;
class Course;
class Topic;
class PLO;
class Program;

class PLO
{
private:
    string plo_description;
    vector<CLO *> clo_list;
    string ID;

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
    string getPloId() const
    {
        return ID;
    }
    void setPloId(const string &str)
    {
        ID = str;
    }
};
class Program
{
private:
    string program_id;
    vector<PLO> plo_list;
    vector<Course *> course_list;
    string program_name;

public:
    Program(string Name)
    {
        program_id = Name;
    }
    string get_program_name()
    {
        return program_name;
    }
    string get_program_id()
    {
        return program_id;
    }
    vector<PLO> get_plo_list()
    {
        return plo_list;
    }
    vector<Course *> get_course_list()
    {
        return course_list;
    }
    void set_program_name(string str)
    {
        program_name = str;
    }
    void set_program_id(string str)
    {
        program_id = str;
    }
    void addTo_plo_list(PLO obj)
    {
        plo_list.push_back(obj);
    }
    void addTo_course_list(Course *obj)
    {
        course_list.push_back(obj);
    }
    void updateInCourseList(const string & c_id, Course *obj)
    {
        for (auto &c_Ptr : course_list)
        {
            if (c_Ptr->getCourseID() == c_id)
            {
                c_Ptr = obj;
            }
        }
    }
    void removeFromCourseList(const string & C_id)
    {
         auto it = std::find_if(course_list.begin(), course_list.end(), [&C_id](Course *c_Ptr)
                               { return c_Ptr->getCourseID() == C_id; });

        if (it != course_list.end())
        {
            course_list.erase(it); // Erase the pointer from the vector
        }
    }
};

class CLO
{
private:
    string clo_description;
    string ID;

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
    string getCloId() const
    {
        return ID;
    }
    void setCloId(const string &str)
    {
        ID = str;
    }
    void updateCLO(const CLO &other)
    {
        clo_description = other.clo_description;
    }
    CLO &operator=(const CLO &other)
    {
        if (this != &other)
        {
            clo_description = other.clo_description;
            ID = other.ID;
        }
        return *this;
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
    vector<Evaluation *> evaluations_list;

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
    const vector<Evaluation *> &getEvaluationsList() const
    {
        return evaluations_list;
    }
    void addEvaluation(Evaluation evaluation)
    {
        Evaluation *ptr = &evaluation;
        evaluations_list.push_back(ptr);
    }
    void removeCLO(CLO clo)
    {
        del_vector_obj(clo_list, clo);
    }
    void removeEvaluation(Evaluation evaluation)
    {
        del_vector_ptr(evaluations_list, evaluation);
    }
    void updateCLO(const CLO &clo)
    {
        string id = clo.getCloId();
        auto it = find_if(clo_list.begin(), clo_list.end(), [&id](const CLO &obj)
                          { return obj.getCloId() == id; });
        if (it != clo_list.end())
        {
            it->updateCLO(clo);
        }
    }
    void updateEvaluation(Evaluation evaluation)
    {
        string id = evaluation.get_ID();
        auto it = find_if(evaluations_list.begin(), evaluations_list.end(), [&id](const Evaluation *evalPtr)
                          { return evalPtr->get_ID() == id; });
        if (it != evaluations_list.end())
        {
            // Delete the Evaluation object pointed to by it
            delete *it;
            // Erase the element from the vector
            evaluations_list.erase(it);
        }
        // Push the new Evaluation object into the vector
        Evaluation *ptr = new Evaluation(evaluation);
        evaluations_list.push_back(ptr);
    }
};

class Question
{
private:
    string question_description;
    vector<CLO *> clo_list;
    string ID;

public:
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
    vector<CLO *> clo_included_in_question()
    {
        return clo_list;
    }
    void add_clo_in_question(CLO *ptr)
    {
        clo_list.push_back(ptr);
    }
    void updateCLO(const string &cloID, CLO *newClo)
    {
        for (auto &cloPtr : clo_list)
        {
            if (cloPtr->getCloId() == cloID)
            {
                cloPtr = newClo;
            }
        }
    }
    void removeCLO(const string &cloID)
    {

        auto it = std::find_if(clo_list.begin(), clo_list.end(), [&cloID](CLO *cloPtr)
                               { return cloPtr->getCloId() == cloID; });

        if (it != clo_list.end())
        {
            clo_list.erase(it); // Erase the pointer from the vector
        }
    }

    string getQuestionID()
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
    void set_ID(string new_ID)
    {
        ID = new_ID;
    }
    void removeQuestion(const string &questionID)
    {
        // Find the question with the given ID
        auto it = std::find_if(questions.begin(), questions.end(), [&questionID](Question q)
                               { return q.getQuestionID() == questionID; });

        // If found, erase the question from the vector
        if (it != questions.end())
        {
            questions.erase(it);
        }
        else
        {
            cout << "question object not found in class:evaluation line 277(headers.h)" << endl;
        }
    }
    void updateQuestion(Question newQuestion)
    {
        // Find the question with the given ID
        string questionID = newQuestion.getQuestionID();
        auto it = std::find_if(questions.begin(), questions.end(), [&questionID](Question q)
                               { return q.getQuestionID() == questionID; });

        // If found, update the question
        if (it != questions.end())
        {
            // Update the question object in place
            *it = newQuestion;
        }
        else
        {
            cout << "question object not found in evaluation line 290(headers.h)" << endl;
        }
    }
    void add_question(Question q1)
    {
        questions.push_back(q1);
    }
    const vector<Question> &get_questions() const
    {
        return questions;
    }
    void updateEvaluation(const Evaluation &obj)
    {
        questions = obj.questions;
    }
};




























