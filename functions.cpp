#include "classes.h"

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
        objects.emplace_back(substrings[1],substrings[0]);
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

void Write_To_CLO_File(const vector<CLO>& objects) {
    ofstream outFile("CLO.txt");
    if (!outFile.is_open()) {
        cerr << "Failed to open the file for writing." << endl;
        return;
    }
    for (const auto& obj : objects) {
        outFile << obj.getCloId() << "," << obj.getCloDescription() << endl;
    }
    outFile.close();
}

void Write_To_Question_File(vector<Question> objects) {
    ofstream outFile("Questions.txt");
    if (!outFile.is_open()) {
        cerr << "Failed to open the file for writing." << endl;
        return;
    }
    for (int i=0;i<objects.size();i++) {
        outFile << objects[i].getQuestionID() << "," << objects[i].get_question_description();
        vector<CLO *> list  = objects[i] .get_clo_list();
        for ( auto& clo : list) {
            outFile << "," << clo->getCloId();
        }
        outFile << endl;
    }
    outFile.close();
}

void Write_To_Evaluation_File(vector<Evaluation> objects) {
    ofstream outFile("Evaluations.txt");
    if (!outFile.is_open()) {
        cerr << "Failed to open the file for writing." << endl;
        return;
    }
    for (int i=0;i<objects.size();i++) {
        outFile << objects[i].get_ID();
        for (auto& question : objects[i].get_question_list()) {
            outFile << "," << question.getQuestionID();
        }
        outFile << endl;
    }
    outFile.close();
}

void Write_To_PLO_File(const vector<PLO>& objects) {
    ofstream outFile("PLO.txt");
    if (!outFile.is_open()) {
        cerr << "Failed to open the file for writing." << endl;
        return;
    }
    for (auto obj : objects) {
        outFile << obj.getPloId() << "," << obj.getPloDescription();
        for (const auto& clo : obj.get_clo_list()) {
            outFile << "," << clo->getCloId();
        }
        outFile << endl;
    }
    outFile.close();
}

void Write_To_Course_File(vector<Course> objects) {
    ofstream outFile("Courses.txt");
    if (!outFile.is_open()) {
        cerr << "Failed to open the file for writing." << endl;
        return;
    }
    for (auto obj : objects) {
        outFile << obj.getCourseID() << "," <<obj.getCourseName();
        for (const auto& clo : obj.get_clo_list()) {
            outFile << "," << clo.getCloId();
        }
        for (const auto& evaluation : obj.get_evaluations_list()) {
            outFile << "," << evaluation->get_ID();
        }
        outFile << endl;
    }
    outFile.close();
}

void Write_To_Programs_File(vector<Program> objects) {
    ofstream outFile("Programs.txt");
    if (!outFile.is_open()) {
        cerr << "Failed to open the file for writing." << endl;
        return;
    }
    for (auto obj : objects) {
        outFile << obj.getId() << "," << obj.getName();
        for (const auto& course : obj.get_course_list()) {
            outFile << "," << course->getCourseID();
        }
        for (const auto& plo : obj.get_plo_list()) {
            outFile << "," << plo.getPloId();
        }
        outFile << endl;
    }
    outFile.close();
}

void addProgram(AcademicOfficer *ao,vector<Program> a) // checked
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
    a.push_back(new_program);
    Write_To_Programs_File(a);
    cout << endl;
    cout << "Program added successfully!\n" << endl;
    cout << "Press enter to continue.";
    getch();
    system("cls");
}

void addPLO(AcademicOfficer *ao,vector<PLO> d,vector<Program> a) // checked
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
    d.push_back(new_plo);
    Write_To_PLO_File(d);
    for(int i=0;i<a.size();i++)
    {
        if(a[i].getId()==program_id)
        {
            a[i].addTo_plo_list(new_plo);
        }
    }
    Write_To_Programs_File(a);
    cout << endl;
    cout << "PLO added successfully!\n" << endl;
    cout << "Press enter to continue.";
    getch();
    system("cls");
}

void addCourse(AcademicOfficer *ao,vector<Course> e,vector<Program> a) // checked
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

    Course new_course(course_name, course_id); 
    e.push_back(new_course);
    Write_To_Course_File(e);
    program.addTo_course_list(&new_course);
    for(int i=0;i<a.size();i++)
    {
        if(a[i].getId()==program_id)
        {
            a[i].addTo_course_list(&new_course);
        }
    }
    Write_To_Programs_File(a);
    cout << endl;
    cout << "Course added successfully!\n" << endl;
    cout << "Press enter to continue.";
    getch();
    system("cls");
}

void addCLOInCourse(AcademicOfficer *ao,vector<Program> a,vector<CLO> b) //checked
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
    b.push_back(new_clo);
    Write_To_CLO_File(b);
    for(int i =0; i<a.size(); i++)
    {
        for(int j =0; j<a[i].get_course_list().size(); j++)
        {
            if(a[i].get_course_list()[j]->getCourseID()==course_id)
            {
                a[i].get_course_list()[j]->addCLO(new_clo);
            }
        }
    }
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
        cout << "Course ID: " << course->getCourseID() << "\n\n";
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
    cout << "CLOs in " << course.getCourseName() << " (" << course.getCourseID() << ")"<< ":\n" << endl;
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
