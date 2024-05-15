#include "classes.h"

void addProgram(AcademicOfficer *ao) // checked
{
    system("cls");
    cout << "////Add program/////\n" << endl;
    cin.ignore();
    string program_name, program_id;
    cout << "Enter program name: ";
    getline(cin, program_name);
    cout << "Enter program ID: ";
    cin >> program_id;

    Program new_program(program_name, program_id);
    ao->getOBE().addProgram(new_program);

    cout << endl;
    cout << "Program added successfully!\n" << endl;
    cout << "Press enter to continue.";
    getch();
    system("cls");
}

void addPLO(AcademicOfficer *ao) // checked
{
    system("cls");
    cout << "////Select program/////\n" << endl;
    ao->getOBE().printPrograms();
    string program_id;
    cout << "Enter program ID: ";
    cin >> program_id;
    cin.ignore();

    Program& program = ao->getOBE().getProgramById(program_id);

    system("cls");
    cout << "////Add PLO/////\n" << endl;
    string plo_name, plo_id;
    cout << "Enter PLO description: ";
    getline(cin, plo_name); 

    cout << "Enter PLO ID: ";
    cin >> plo_id;

    PLO new_plo(plo_name, plo_id);
    program.addTo_plo_list(new_plo);
    
    cout << endl;
    cout << "PLO added successfully!\n" << endl;
    cout << "Press enter to continue.";
    getch();
    system("cls");
}

void addCourse(AcademicOfficer *ao) // checked
{
    system("cls");
    cout << "////Select Program/////\n" << endl;
    ao->getOBE().printPrograms();
    string program_id;
    cout << "Enter program ID: ";
    cin >> program_id;
    cin.ignore();

    Program& program = ao->getOBE().getProgramById(program_id);

    system("cls");
    cout << "////Add course/////\n" << endl;
    string course_name, course_id;
    cout << "Enter course name: ";
    getline(cin, course_name); 

    cout << "Enter course ID: ";
    cin >> course_id;

    Course* new_course = new Course(course_name, course_id); 
    program.addTo_course_list(new_course);
    cout << endl;
    cout << "Course added successfully!\n" << endl;
    cout << "Press enter to continue.";
    getch();
    system("cls");
}

void addCLOInCourse(AcademicOfficer *ao) //checked
{
    system("cls");
    cout << "////Select Program/////\n" << endl;
    ao->getOBE().printPrograms();
    string program_id;
    cout << "Enter program ID: ";
    cin >> program_id;
    cin.ignore();

    Program& program = ao->getOBE().getProgramById(program_id);

    if (&program == nullptr) {
        cout << "Program not found!" << endl;
        cout << "Press enter to continue.";
        getch();
        system("cls");
        return;
    }

    system("cls");
    cout << "////Select Course/////\n" << endl;
    program.printCourses();
    string course_id;
    cout << "Enter course ID: ";
    cin >> course_id;
    cin.ignore();

    Course &course = program.getCourseById(course_id);

    system("cls");
    cout << "////Add CLO/////\n" << endl;
    string clo_description, clo_id;
    cout << "Enter CLO description: ";
    getline(cin, clo_description);

    cout << "Enter CLO ID: ";
    cin >> clo_id;

    CLO new_clo(clo_description, clo_id);
    course.addCLO(new_clo); 
    cout << endl;
    cout << "CLO added successfully under the selected course!" << endl;
    cout << "Press enter to continue.";
    getch();
    system("cls");
}

void printAllPrograms(AcademicOfficer *ao) // checked
{
    system("cls");
    ao->getOBE().printPrograms();
    cout << "Press enter to continue.";
    getch();
    system("cls");
}

void printPLOsInProgram(AcademicOfficer *ao) // checked
{
    system("cls");
    cout << "////Select program/////\n" << endl;
    OBE& obe = ao->getOBE();
    obe.printPrograms();
    string program_id;
    cout << "Enter program ID: ";
    cin >> program_id;
    cin.ignore();

    Program& program = obe.getProgramById(program_id);
    if (&program == nullptr) {
        cout << "Program not found!" << endl;
        cout << "Press enter to continue.";
        getch();
        system("cls");
        return;
    }

    system("cls");
    cout << "PLOs in " << program.getName() << " (" << program.getId() << ")" << " :\n" << endl;

    const vector<PLO> &plos = program.get_plo_list();
    for (const PLO &plo : plos)
    {
        cout << "PLO ID: " << plo.getPloId() << "\n";
        cout << "PLO Description: " << plo.getPloDescription() << "\n\n";
    }

    cout << "Press enter to continue.";
    getch();
    system("cls");
}


void printAllCoursesUnderProgram(AcademicOfficer *ao) // checked
{
    system("cls");
    cout << "////Select program/////\n" << endl;
    OBE& obe = ao->getOBE();
    obe.printPrograms();

    string program_id;
    cout << "Enter program ID: ";
    cin >> program_id;
    cin.ignore();

    Program& program = obe.getProgramById(program_id);
    if (&program == nullptr) {
        cout << "Program not found!" << endl;
        cout << "Press enter to continue.";
        getch();
        system("cls");
        return;
    }

    system("cls");
    cout << "Courses in " << program.getName() << " (" << program.getId() << ")" << " :\n" << endl;

    vector<Course *> courses = program.get_course_list();
    for (Course *course : courses)
    {
        cout << "Course Name: " << course->getCourseName() << "\n";
        cout << "Course ID: " << course->getCourseId() << "\n\n";
    }

    cout << "Press enter to continue.";
    getch();
    system("cls");
}

void printAllCLOsInCourse(AcademicOfficer *ao) // checked
{
    system("cls");
    cout << "////Select program/////\n" << endl;
    ao->getOBE().printPrograms();
    string program_id;
    cout << "Enter program ID: ";
    cin >> program_id;
    cin.ignore();

    Program &program = ao->getOBE().getProgramById(program_id);

    system("cls");
    cout << "////Select course/////\n" << endl;
    program.printCourses();
    string course_id;
    cout << "Enter course ID: ";
    cin >> course_id;
    cin.ignore();

    Course &course = program.getCourseById(course_id);

    system("cls");
    cout << "CLOs in " << course.getCourseName() << " (" << course.getCourseId() << ")"<< ":\n" << endl;
    course.CLOPrinter();

    cout << "\nPress enter to continue.";
    getch();
    system("cls");
}

void addEvaluationInCourse(AcademicOfficer *ao) // checked
{
    system("cls");
    cout << "////Select program/////\n" << endl;
    ao->getOBE().printPrograms();
    string program_id;
    cout << "Enter program ID: ";
    cin >> program_id;
    cin.ignore();

    Program &program = ao->getOBE().getProgramById(program_id);

    system("cls");
    cout << "////Select course/////\n" << endl;
    program.printCourses();
    string course_id;
    cout << "Enter course ID: ";
    cin >> course_id;
    cin.ignore();

    Course &course = program.getCourseById(course_id);

    system("cls");
    cout << "////Add Evaluation/////\n" << endl;
    string eval_id;
    cout << "Enter Evaluation ID: ";
    getline(cin, eval_id);

    Evaluation *new_eval = new Evaluation(eval_id);
    course.addEvaluation(new_eval);

    cout << endl;
    cout << "Evaluation added successfully under the selected course!" << endl;
    cout << "Press enter to continue.";
    getch();
    system("cls");
}

void printAllEvaluationsForCourse(AcademicOfficer* ao) // checked
 {
    system("cls");
    cout << "////Select program/////\n" << endl;
    ao->getOBE().printPrograms();
    string program_id;
    cout << "Enter program ID: ";
    cin >> program_id;
    cin.ignore();

    Program& program = ao->getOBE().getProgramById(program_id);

    system("cls");
    cout << "////Select course/////\n" << endl;
    program.printCourses();
    string course_id;
    cout << "Enter course ID: ";
    cin >> course_id;
    cin.ignore();

    Course& course = program.getCourseById(course_id);

    system("cls");
    course.printAllEvaluations();
    cout << "\nPress enter to continue.";
    getch();
    system("cls");
}

void addQuestionInEvaluation(AcademicOfficer *ao) // checked
{
    system("cls");
    cout << "////Select program/////\n" << endl;
    ao->getOBE().printPrograms();
    string program_id;
    cout << "Enter program ID: ";
    cin >> program_id;
    cin.ignore();

    Program &program = ao->getOBE().getProgramById(program_id);

    system("cls");
    cout << "////Select course/////\n" << endl;
    program.printCourses();
    string course_id;
    cout << "Enter course ID: ";
    cin >> course_id;
    cin.ignore();

    Course &course = program.getCourseById(course_id);

    system("cls");
    cout << "////Select Evaluation ID/////\n" << endl;
    course.printAllEvaluations();
    string eval_id;
    cout << endl;
    cout << "Enter evaluation ID: ";
    getline(cin , eval_id);

    Evaluation *evaluation = nullptr;
    try
    {
        evaluation = &course.getEvaluationById(eval_id);
    }
    catch (const std::runtime_error &e)
    {
        cout << e.what() << endl;
        cout << "Press enter to continue.";
        getch();
        system("cls");
        return;
    }

    system("cls");
    cout << "////Add Question/////\n" << endl;
    string question_desc, question_id;
    cout << "Enter question description: ";
    getline(cin, question_desc);
    cout << "Enter question ID: ";
    cin >> question_id;

    Question new_question(question_desc, question_id);
    evaluation->add_question(new_question);

    cout << "Question added successfully under evaluation " << eval_id << "!" << endl;
    cout << "Press enter to continue.";
    getch();
    system("cls");
}

void printAllQuestionsForEvaluation(AcademicOfficer* ao) // checked
{
    system("cls");
    cout << "////Select program/////\n" << endl;
    ao->getOBE().printPrograms();
    string program_id;
    cout << "Enter program ID: ";
    cin >> program_id;
    cin.ignore();

    Program& program = ao->getOBE().getProgramById(program_id);

    system("cls");
    cout << "////Select course/////\n" << endl;
    program.printCourses();
    string course_id;
    cout << "Enter course ID: ";
    cin >> course_id;
    cin.ignore();

    Course& course = program.getCourseById(course_id);

    system("cls");
    cout << "////Select Evaluation/////\n" << endl;
    course.printAllEvaluations();
    string eval_id;
    cout << endl;
    cout << "Enter evaluation ID: ";
    getline(cin, eval_id);

    Evaluation* eval = &course.getEvaluationById(eval_id);
    if (eval == nullptr) {
        cout << "Evaluation not found!" << endl;
        cout << "Press enter to continue.";
        getch();
        system("cls");
        return;
    }

    system("cls");
    eval->Questions_printer();
    cout << endl;
    cout << "Press enter to continue.";
    getch();
    system("cls");
}

void updateQuestion(AcademicOfficer* ao) //
{
    system("cls");
    cout << "////Select program/////\n" << endl;
    ao->getOBE().printPrograms();
    string program_id;
    cout << "Enter program ID: ";
    cin >> program_id;
    cin.ignore();

    Program& program = ao->getOBE().getProgramById(program_id);

    system("cls");
    cout << "////Select course/////\n" << endl;
    program.printCourses();
    string course_id;
    cout << "Enter course ID: ";
    cin >> course_id;
    cin.ignore();

    Course& course = program.getCourseById(course_id);

    system("cls");
    cout << "////Select Evaluation ID/////\n" << endl;
    course.printAllEvaluations();
    string eval_id;
    cout << endl;
    cout << "Enter evaluation ID: ";
    getline(cin, eval_id);

    Evaluation* evaluation = nullptr;
    try
    {
        evaluation = &course.getEvaluationById(eval_id);
    }
    catch (const std::runtime_error& e)
    {
        cout << e.what() << endl;
        cout << "Press enter to continue.";
        getch();
        system("cls");
        return;
    }

    system("cls");
    cout << "////Update Question/////\n" << endl;
    evaluation->Questions_printer();
    string question_desc, question_id;
    cout << "/nEnter existing question ID to update: ";
    cin >> question_id;
    cin.ignore();

    Question newQuestion;
    cout << "Enter new question description: ";
    getline(cin, question_desc);
    newQuestion.set_question_id(question_id);
    newQuestion.set_question_description(question_desc);

    try
    {
        evaluation->updateQuestion(question_id, newQuestion);
        cout << "Question updated successfully under evaluation " << eval_id << "!" << endl;
    }
    catch (const std::runtime_error& e)
    {
        cout << e.what() << endl;
    }

    cout << "Press enter to continue.";
    getch();
    system("cls");
}

void deleteQuestion(AcademicOfficer* ao) {
    system("cls");
    cout << "////Select program/////\n" << endl;
    ao->getOBE().printPrograms();
    string program_id;
    cout << "Enter program ID: ";
    cin >> program_id;
    cin.ignore();

    Program& program = ao->getOBE().getProgramById(program_id);

    system("cls");
    cout << "////Select course/////\n" << endl;
    program.printCourses();
    string course_id;
    cout << "Enter course ID: ";
    cin >> course_id;
    cin.ignore();

    Course& course = program.getCourseById(course_id);

    system("cls");
    cout << "////Select Evaluation ID/////\n" << endl;
    course.printAllEvaluations();
    string eval_id;
    cout << endl;
    cout << "Enter evaluation ID: ";
    getline(cin, eval_id);

    Evaluation* evaluation = nullptr;
    try {
        evaluation = &course.getEvaluationById(eval_id);
    } catch (const std::runtime_error& e) {
        cout << e.what() << endl;
        cout << "Press enter to continue.";
        getch();
        system("cls");
        return;
    }

    system("cls");
    cout << "////Delete Question/////\n" << endl;
    string question_id;
    cout << "Enter question ID to delete: ";
    cin >> question_id;
    cin.ignore();

    try {
        evaluation->removeQuestion(question_id);
        cout << "Question deleted successfully from evaluation " << eval_id << "!" << endl;
    } catch (const std::runtime_error& e) {
        cout << e.what() << endl;
    }

    cout << "Press enter to continue.";
    getch();
    system("cls");
}
