#include <iostream>
#include <vector>
#include <string>
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
    string program_id;
    vector<PLO> plo_list;
    vector<Course *> course_list;

public:
    Program(string Name)
    {
        program_id = Name;
    }
    string get_program_name()
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
    void set_question_description(const string& Desc) 
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
  string get_name() const {
    return name;
  }
  void set_name(string new_name) {
    name = new_name;
  }
  void add_question(Question q1) {
    questions.push_back(q1);
  }
  const vector<Question>& get_questions() const {
    return questions;
  }
};
