#include "Header.h"

int main()
{
    vector<CLO> obj = Read_From_CLO_File();
    vector<Question> a = Read_From_Question_File(&obj);
    vector<Evaluation> b = Read_From_Evaluation_File(a);
    vector<PLO> abb = Read_From_PLO_File(&obj);
    vector<Course> c = Read_From_Course_File(obj,&b);
    vector<Program> d = Read_From_Programs_File(&c,abb);
    return 0;
}
