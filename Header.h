#include <iostream>
#include <vector>
#include <algorithm>
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
    void setCloDescription(const string &desc)
    {
        clo_description = desc;
    }
    string getCloId() const
    {
        return ID;
    }
    void updateCLO(const CLO &other)
    {
        if (ID == other.getCloId())
        {
            clo_description = other.clo_description;
        }
        else
        {
            cout << "error";
        }
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
        for (unsigned int i = 0; i < clo_list.size(); i++)
        {
            if (clo_list[i]->getCloId() == cloID)
            {
                clo_list[i] = newClo;
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
    void Questions_printer()
    {
        for (unsigned int i = 0; i < questions.size(); i++)
        {
            cout << questions[i].getQuestionID() << " " << questions[i].get_question_description() << endl;
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
    string course_id;
    vector<CLO> clo_list;
    vector<Evaluation *> evaluations_list;

public:
    Course(const string &id) : course_id(id) {}
    string getCourseID() const
    {
        return course_id;
    }
    CLO &getFromCloList(int index)
    {
        if (index<=clo_list.size())
        {
            return clo_list[index];
        }
        else
        {
            cout<<"Index out of range in function getFromCloList()"<<endl;
        }
    }
    void addCLO(CLO clo)
    {
        clo_list.push_back(clo);
    }
    Evaluation *getFromEvaluationsList(int Index)
    {
          if (Index<=evaluations_list.size())
        {
            return evaluations_list[Index];
        }
        else
        {
            cout<<"Index out of range in function getFromEvaluationsList()"<<endl;
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
                cout<<"Success"<<endl;
                break;
            }
             else
            {
                cout<<"CLO not found!"<<endl;
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
                cout<<"Success"<<endl;
                break;
            }
            else
            {
                cout<<"Evaluation not found!279"<<endl;
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
                cout<<"Success"<<endl;
                break;
            }
            else
            {
                cout<<"CLO not found!"<<endl;
            }
        }
        clo_list.push_back(clo);
    }
    void updateEvaluation(string id,Evaluation *ptr)
    {
        for (unsigned int i = 0; i < evaluations_list.size(); i++)
        {
            if (evaluations_list[i]->get_ID() == id)
            {
                evaluations_list.erase(evaluations_list.begin() + i);
                cout<<"Success"<<endl;
                break;
            }
             else
            {
                cout<<"Evaluation not found! 312"<<endl;
            }
        }
        evaluations_list.push_back(ptr);
    }
    void EvaluationsPrinter()
    {
        for (unsigned int i = 0; i < evaluations_list.size(); i++)
        {
            cout<<"Questions of "<<evaluations_list[i]->get_ID()<<" :";
            evaluations_list[i]->Questions_printer();
        }
    }
    void CLOPrinter()
    {
        for (unsigned int i = 0; i < clo_list.size(); i++)
        {
            cout<<clo_list[i].getCloId()<<clo_list[i].getCloDescription()<<endl;
        }
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