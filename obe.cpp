#include "functions.cpp"

// int main()
// {
//     system("cls");
//     string app_name = "FLex++";

//     OBE &obe = OBE::Get();
//     obe.setName(app_name);

//     int user_input = -1;

//     vector<AcademicOfficer> ao;
//     vector<Teacher> teachers;

//     while (user_input != 0)
//     {
//         cout << endl;
//         cout << "Welcome to " << obe.getName() << "\n"
//              << endl;
//         cout << "1. Enter as a Teacher" << endl;
//         cout << "2. Enter as a OBE Officer" << endl;
//         cout << "0. Exit"
//              << "\n"
//              << endl;

//         cout << "Enter your choice: ";
//         cin >> user_input;
//         cout << endl;

//         if (user_input == 1)
//         {
//             // entered as a teacher
//              system("cls");
//             cout << "/////Registration/////\n"
//                  << endl;
//             string name = "";
//             int id = 0;
//             cout << "Enter your name: ";
//             cin.ignore();
//             getline(cin, name);
//             cout << "Enter your ID: ";
//             cin >> id;
//             Teacher new_teacher(name, id);
//             teachers.push_back(new_teacher);
//             system("cls");

//              while (user_input != 0)
//             {
//                 cout << "Welcome, " << ao[0].getName() << "! You are logged in as an Academic Officer.\n" << endl;
//                 cout << "1. Add Evaluation" << endl;
//                 cout << "2. Show Evaluations" << endl;
//                 cout << "3. Delete Evaluation" << endl;
//                 cout << "4. Add Questions" << endl;
//                 cout << "5. Show Questions" << endl;
//                 cout << "6. Delete Question" << endl;
//                 cout << "0. Exit" << "\n" << endl;

//                 cout << "Enter your choice: ";
//                 cin >> user_input;
//                 cout << endl;

//                 if (user_input == 1)
//                 {
//                     AddEvaluationUnderCourse(&ao[0]);
//                 }
//                 else if (user_input == 2)
//                 {
//                     AddEvaluationUnderCourse(&ao[0]);
//                 }
//                 else if (user_input == 3)
//                 {
//                     printAllEvaluationsForCourse(&ao[0]);
//                 }
//                 else if (user_input == 4)
//                 {
//                     addQuestionUnderEvaluation(&ao[0]);
//                 }
//                 else if (user_input == 5)
//                 {
//                     printAllQuestionsForEvaluation(&ao[0]);
//                 }
//                 else if (user_input == 6)
//                 {
//                     printAllQuestionsForEvaluation(&ao[0]);
//                 }
//             }
//         }
//         else if (user_input == 2)
//         {
//             // entered as an officer
//             system("cls");
//             cout << "/////Registration/////\n"
//                  << endl;
//             string name = "";
//             int id = 0;
//             cout << "Enter your name: ";
//             cin.ignore();
//             getline(cin, name);
//             cout << "Enter your ID: ";
//             cin >> id;

//             AcademicOfficer new_officer(name, id);

//             system("cls");

//             while (user_input != 0)
//             {
//                 cout << "Welcome, " << ao[0].getName() << "! You are logged in as an Academic Officer.\n" << endl;
//                 cout << "1. Add Program" << endl;
//                 cout << "2. Add PLO" << endl;
//                 cout << "3. Add Course" << endl;
//                 cout << "4. Add CLO" << endl;
//                 cout << "5. Show Programs" << endl;
//                 cout << "6. Show PLOs" << endl;
//                 cout << "7. Show Courses" << endl;
//                 cout << "8. Show CLOs" << endl;
//                 cout << "9. Delete Program" << endl;
//                 cout << "10. Delete PLO" << endl;
//                 cout << "11. Delete Course" << endl;
//                 cout << "12. Delete CLO" << endl;
//                 cout << "0. Exit" << "\n" << endl;

//                 cout << "Enter your choice: ";
//                 cin >> user_input;
//                 cout << endl;

//                 if (user_input == 1)
//                 {
//                     AddProgram(&ao[0]);
//                 }
//                 else if (user_input == 2)
//                 {
//                     AddPLO(&ao[0]);
//                 }
//                 else if (user_input == 3)
//                 {
//                     AddCourse(&ao[0]);
//                 }
//                 else if (user_input == 4)
//                 {
//                     AddCLOUnderCourse(&ao[0]);
//                 }
//                 else if (user_input == 5)
//                 {
//                     PrintAllPrograms(&ao[0]);
//                 }
//                 else if (user_input == 6)
//                 {
//                     PrintAllPLOsUnderProgram(&ao[0]);
//                 }
//                 else if (user_input == 7)
//                 {
//                     PrintAllCoursesUnderProgram(&ao[0]);
//                 }
//                 else if (user_input == 8)
//                 {
//                     PrintAllCLOsUnderCourse(&ao[0]);
//                 }
//                 else if (user_input == 9)
//                 {
//                     AddEvaluationUnderCourse(&ao[0]);
//                 }
//                 else if (user_input == 10)
//                 {
//                     AddEvaluationUnderCourse(&ao[0]);
//                 }
//                 else if (user_input == 11)
//                 {
//                     printAllEvaluationsForCourse(&ao[0]);
//                 }
//                 else if (user_input == 12)
//                 {
//                     addQuestionUnderEvaluation(&ao[0]);
//                 }
//                 else if (user_input == 13)
//                 {
//                     printAllQuestionsForEvaluation(&ao[0]);
//                 }
//             }
//         }
//     }
//     return 0;
// }

int main()
{
    vector<CLO> a = Read_From_CLO_File();
    vector<Question> b = Read_From_Question_File(&a);
    vector<Evaluation> c = Read_From_Evaluation_File(b);
    vector<PLO> d = Read_From_PLO_File(&a);
    vector<Course> e = Read_From_Course_File(a,&c);
    vector<Program> f = Read_From_Programs_File(&e,d);

    OBE &obe = OBE::Get();
    obe.setName("app_name");
    AcademicOfficer new_officer("Shafqat", 1);
    for(int i = 0; i< f.size(); i++)
    {
        new_officer.getOBE().addProgram(f[i]);
    }
    // addPLO(&new_officer,d,f);
    // addCourse(&new_officer,e,f);
    // addCLOInCourse(&new_officer,f,a);
}