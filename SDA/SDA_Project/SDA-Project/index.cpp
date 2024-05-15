#include "Header.h"

void Write_To_CLO_File(vector<CLO> obj)
{
    ofstream outFile("CLO.txt",ofstream::out); // Open the file in append mode
    if (outFile.is_open())
    {
        // outFile<<endl;
        for (int i = 0; i < obj.size(); i++)
        {
            string a = obj[i].getCloId() + "," + obj[i].getCloDescription();
            outFile <<a<<endl; // Append the line
        }
        outFile.close();
    }
}
void Write_To_Questions_File(vector<Question> obj) 
{
    ofstream outFile("CLO.txt",ofstream::out); // Open the file in append mode
    if (outFile.is_open())
    {
        // outFile<<endl;
        for (int i = 0; i < obj.size(); i++)
        {
            string a = obj[i].getQuestionID() + "," + obj[i].get_question_description();
            for (int j = 0; j < obj[i].get_clo_list().size(); j++)
            {
                vector<CLO*> temp=obj[i].get_clo_list();
                a += "," + temp[j]->getCloId();
                outFile <<a<<endl; // Append the line
            }
        }
        outFile.close();
    }
}
void Write_To_Evaluation_File(vector<Evaluation> obj) {}
void Write_To_PLO_File(vector<PLO> obj) {}
void Write_To_Course_File(vector<Course> obj) {}
void Write_To_Programs_File(vector<Program> obj) {}

int main()
{
    vector<CLO> obj = Read_From_CLO_File();
    vector<Question> a = Read_From_Question_File(&obj);
    vector<Evaluation> b = Read_From_Evaluation_File(a);
    vector<PLO> abb = Read_From_PLO_File(&obj);
    vector<Course> c = Read_From_Course_File(obj, &b);
    vector<Program> d = Read_From_Programs_File(&c, abb);
    CLO c1 ("hello.","CL-7777");
    obj.push_back(c1);
    Write_To_CLO_File(obj);
    Question cd ();
    Write_To_Questions_File(a);
    return 0;
}
