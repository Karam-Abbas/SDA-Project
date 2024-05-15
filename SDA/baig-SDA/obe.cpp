#include "functions.cpp"

void menu()
{
    system("cls");
    string app_name = "FLex++";

    OBE &obe = OBE::Get();
    obe.setName(app_name);

    int user_input = -1;

    vector<AcademicOfficer> ao;

    while (user_input != 0)
    {
        cout << "Welcome to " << obe.getName() << "\n"
             << endl;
        cout << "1. Login" << endl;
        cout << "2. Register" << endl;
        cout << "0. Exit"
             << "\n"
             << endl;

        cout << "Enter your choice: ";
        cin >> user_input;
        cout << endl;

        if (user_input == 1)
        {
            int input_id;

            cout << "Enter User ID: ";
            cin >> input_id;

            // yet to be implement
        }
        else if (user_input == 2)
        {
            system("cls");
            cout << "/////Registration/////\n"
                 << endl;
            string name = "";
            int id = 0;
            cout << "Enter your name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter your ID: ";
            cin >> id;

            AcademicOfficer new_officer(name, id);
            ao.push_back(new_officer);

            system("cls");

            while (user_input != 0)
            {
                cout << "Welcome, " << ao[0].getName() << "! You are logged in as an Academic Officer.\n" << endl;
                cout << "1. Add Program" << endl;
                cout << "2. Add PLO" << endl;
                cout << "3. Add Course" << endl;
                cout << "4. Add CLO" << endl;
                cout << "5. Show all programs" << endl;
                cout << "6. Show PLOs" << endl;
                cout << "7. Show Courses" << endl;
                cout << "8. Show CLOs" << endl;
                cout << "9. Add Evaluation" << endl;
                cout << "10. Add Questions" << endl;
                cout << "11. Show Evaluations" << endl;
                cout << "12. Show Questions" << endl;
                cout << "13. Update Question" << endl;
                cout << "14. Delete Question" << endl;
                cout << "0. Exit" << "\n" << endl;

                cout << "Enter your choice: ";
                cin >> user_input;
                cout << endl;

                if (user_input == 1)
                {
                    addProgram(&ao[0]);
                }
                else if (user_input == 2)
                {
                    addPLO(&ao[0]);
                }
                else if (user_input == 3)
                {
                    addCourse(&ao[0]);
                }
                else if (user_input == 4)
                {
                    addCLOInCourse(&ao[0]);
                }
                else if (user_input == 5)
                {
                    printAllPrograms(&ao[0]);
                }
                else if (user_input == 6)
                {
                    printPLOsInProgram(&ao[0]);
                }
                else if (user_input == 7)
                {
                    printAllCoursesUnderProgram(&ao[0]);
                }
                else if (user_input == 8)
                {
                    printAllCLOsInCourse(&ao[0]);
                }
                else if (user_input == 9)
                {
                    addEvaluationInCourse(&ao[0]);
                }
                else if (user_input == 10)
                {
                    addQuestionInEvaluation(&ao[0]);
                }
                else if (user_input == 11)
                {
                    printAllEvaluationsForCourse(&ao[0]);
                }
                else if (user_input == 12)
                {
                    printAllQuestionsForEvaluation(&ao[0]);
                }
                else if (user_input == 13)
                {
                    updateQuestion(&ao[0]);
                }
                else if (user_input == 13)
                {
                    deleteQuestion(&ao[0]);
                }
            }
        }
    }
}

int main()
{
    menu();
    return 0;
}