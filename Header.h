#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
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
    string ID;
    string question_description;
    vector<CLO *> clo_list;

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
    void CLO_printer()
    {
        for (unsigned int i = 0; i < clo_list.size(); i++)
        {
            cout << clo_list[i]->getCloId() << " " << clo_list[i]->getCloDescription() << endl;
        }
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
                cout << "Evaluation not found!279" << endl;
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
            // cout<< evaluations_list[i]->get_ID()<<endl;
            cout << "Questions of " << evaluations_list[i]->get_ID() << " :--"<<endl;
            evaluations_list[i]->Questions_printer();
        }
    }
    void CLOPrinter()
    {
        for (unsigned int i = 0; i < clo_list.size(); i++)
        {
            cout << clo_list[i].getCloId()<<" "<< clo_list[i].getCloDescription() << endl;
        }
    }
};

class Program
{
public:
    Program(string name, string id) : name(name), id(id) {} // constructor tested

    void setName(string name) // tested
    {
        this->name = name;
    }

    void setId(string id) // tested
    {
        this->id = id;
    }
    string getName() const // tested
    {
        return name;
    }
    string getId() const // tested
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
    void print_courses()
    {
        for(unsigned int i=0;i<course_list.size();i++)
        {
            cout<<course_list[i]->getCourseID()<<endl;
        }
    }
    void print_plos()
    {
        for(unsigned int i=0;i<plo_list.size();i++)
        {
            cout<<plo_list[i].getPloId()<<endl;
        }
    }
private:
    string name;
    string id;
    vector<PLO> plo_list;
    vector<Course *> course_list;
};

vector<CLO> Read_From_CLO_File()
{
    vector<CLO> objects;        // Vector to store objects read from file
    ifstream inFile("CLO.txt"); // Open the text file for reading
    if (!inFile.is_open())
    { // Check if the file is opened successfully
        cerr << "Failed to open the file for reading." << endl;
        return objects;
    }
    string line;
    while (getline(inFile, line))
    { // Read each line from the file
        stringstream ss(line);
        string id, description;
        getline(ss, id, ',');          // Read ID
        getline(ss, description, ','); // Read Description
        // Create an object using the above id and description and then add it to the vector
        objects.emplace_back(description, id);
    }
    inFile.close();
    return objects;
}

vector<Question> Read_From_Question_File(vector<CLO> *obj)
{
    vector<Question> objects;         // Vector to store objects read from file
    ifstream inFile("Questions.txt"); // Open the text file for reading
    if (!inFile.is_open())
    { // Check if the file is opened successfully
        cerr << "Failed to open the file for reading." << endl;
        return objects;
    }
    string line;
    int counter = 0;
    while (getline(inFile, line))
    {
        stringstream ss(line);
        vector<string> substrings;
        string substring;
        while (getline(ss, substring, ','))
        {
            substrings.push_back(substring);
        }
        objects.emplace_back(substrings[1], substrings[0]);
        for (unsigned int i = 0; i < obj->size(); i++)
        {
            for (unsigned int j = 2; j < substrings.size(); j++)
            {
                if ((*obj)[i].getCloId() == substrings[j])
                {
                    objects[counter].add_clo_in_question(&(*obj)[i]);
                }
            }
        }
        counter++;
    }
    inFile.close();
    return objects;
}

vector<Evaluation> Read_From_Evaluation_File(vector<Question> questions)
{
    vector<Evaluation> objects;         // Vector to store objects read from file
    ifstream inFile("Evaluations.txt"); // Open the text file for reading
    if (!inFile.is_open())
    { // Check if the file is opened successfully
        cerr << "Failed to open the file for reading." << endl;
        return objects;
    }
    string line;
    int counter = 0;
    while (getline(inFile, line))
    {
        stringstream ss(line);
        vector<string> substrings;
        string substring;
        while (getline(ss, substring, ','))
        {
            substrings.push_back(substring);
        }
        objects.emplace_back(substrings[0]);
        for (unsigned int i = 0; i < questions.size(); i++)
        {
            for (unsigned int j = 1; j < substrings.size(); j++)
            {
                if (questions[i].getQuestionID() == substrings[j])
                {
                    objects[counter].add_question(questions[i]);
                }
            }
        }
        counter++;
    }
    inFile.close();
    return objects;
}

vector <PLO> Read_From_PLO_File(vector<CLO> *obj)
{
    vector<PLO> objects;         // Vector to store objects read from file
    ifstream inFile("PLO.txt"); // Open the text file for reading
    if (!inFile.is_open())
    { // Check if the file is opened successfully
        cerr << "Failed to open the file for reading." << endl;
        return objects;
    }
    string line;
    int counter = 0;
    while (getline(inFile, line))
    {
        stringstream ss(line);
        vector<string> substrings;
        string substring;
        while (getline(ss, substring, ','))
        {
            substrings.push_back(substring);
        }
        objects.emplace_back(substrings[1], substrings[0]);
        for (unsigned int i = 0; i < obj->size(); i++)
        {
            for (unsigned int j = 2; j < substrings.size(); j++)
            {
                if ((*obj)[i].getCloId() == substrings[j])
                {
                    objects[counter].addCLO(&(*obj)[i]);
                }
            }
        }
        counter++;
    }
    inFile.close();
    return objects;
}

vector<Course> Read_From_Course_File(vector<CLO> obj,vector<Evaluation>*eval)
{
    vector<Course> objects;         // Vector to store objects read from file
    ifstream inFile("Courses.txt"); // Open the text file for reading
    if (!inFile.is_open())
    { 
        cerr << "Failed to open the file for reading." << endl;
        return objects;
    }
    string line;
    int counter_CLO = 0 , counter_eval = 0;
    while (getline(inFile, line))
    {
        stringstream ss(line);
        vector<string> substrings;
        string substring;
        while (getline(ss, substring, ','))
        {
            substrings.push_back(substring);
        }
        objects.emplace_back(substrings[0]);
        for (unsigned int i = 0; i < obj.size(); i++)
        {
            for (unsigned int j = 1; j < substrings.size(); j++)
            {
                if (obj[i].getCloId() == substrings[j])
                {
                    objects[counter_CLO].addCLO(obj[i]);
                }
            }
        }
        for (unsigned int i = 0; i < eval->size(); i++)
        {
            for (unsigned int j = 1; j < substrings.size(); j++)
            {
                if ((*eval)[i].get_ID() == substrings[j])
                {
                    objects[counter_eval].addEvaluation(&(*eval)[i]);
                }
            }
        }
        counter_CLO++;
        counter_eval++;
    }
    inFile.close();
    return objects;
}

vector<Program> Read_From_Programs_File(vector<Course> * obj ,vector<PLO> plo)
{
    
    vector<Program> objects;         // Vector to store objects read from file
    ifstream inFile("Programs.txt"); // Open the text file for reading
    if (!inFile.is_open())
    { // Check if the file is opened successfully
        cerr << "Failed to open the file for reading." << endl;
        return objects;
    }
    string line;
    int counter_course = 0 , counter_plo =0;
    while (getline(inFile, line))
    {
        stringstream ss(line);
        vector<string> substrings;
        string substring;
        while (getline(ss, substring, ','))
        {
            substrings.push_back(substring);
        }
        objects.emplace_back(substrings[1], substrings[0]);
        for (unsigned int i = 0; i < obj->size(); i++)
        {
            for (unsigned int j = 2; j < substrings.size(); j++)
            {
                if ((*obj)[i].getCourseID() == substrings[j])
                {
                    objects[counter_course].addTo_course_list(&(*obj)[i]);
                }
            }
        }

        for (unsigned int i = 0; i < plo.size(); i++)
        {
            for (unsigned int j = 2; j < substrings.size(); j++)
            {
                if (plo[i].getPloId() == substrings[j])
                {
                    objects[counter_plo].addTo_plo_list(plo[i]);
                }
            }
        }
        counter_course++;
        counter_plo++;
    }
    inFile.close();
    return objects;
}