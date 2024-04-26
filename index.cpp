#include "Header.h"
#include <algorithm> // for std::remove_if
#include <iomanip> // for std::setw

// Define the classes as provided

// Main interface
int main() {
    vector<Course> courses;
    vector<PLO> plos;
    vector<CLO> clos;
    vector<Evaluation> evaluations;

    // Function to print a menu
    auto printMenu = []() {
        cout << "********** Main Menu **********" << endl;
        cout << "1. Manage Courses" << endl;
        cout << "2. Manage CLOs" << endl;
        cout << "3. Manage Evaluations" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
    };

    // Function to add a course
    auto addCourse = [&courses](const string& id) {
        courses.push_back(Course(id));
        cout << "Course added successfully." << endl;
    };

    // Function to remove a course
    auto removeCourse = [&courses](const string& id) {
        auto it = find_if(courses.begin(), courses.end(), [&](const Course& course) {
            return course.getCourseID() == id;
        });
        if (it != courses.end()) {
            courses.erase(it);
            cout << "Course removed successfully." << endl;
        } else {
            cout << "Course not found." << endl;
        }
    };

    // Function to update a course
    auto updateCourse = [&courses](const string& id, const string& newID) {
        auto it = find_if(courses.begin(), courses.end(), [&](const Course& course) {
            return course.getCourseID() == id;
        });
        if (it != courses.end()) {
            it->setCourseID(newID);
            cout << "Course updated successfully." << endl;
        } else {
            cout << "Course not found." << endl;
        }
    };

    // Function to add a CLO
    auto addCLO = [&clos](const string& desc) {
        clos.push_back(CLO(desc));
        cout << "CLO added successfully." << endl;
    };

    // Function to remove a CLO
    auto removeCLO = [&clos](const string& desc) {
        auto it = find_if(clos.begin(), clos.end(), [&](const CLO& clo) {
            return clo.getCloDescription() == desc;
        });
        if (it != clos.end()) {
            clos.erase(it);
            cout << "CLO removed successfully." << endl;
        } else {
            cout << "CLO not found." << endl;
        }
    };

    // Function to update a CLO
    auto updateCLO = [&clos](const string& desc, const string& newDesc) {
        auto it = find_if(clos.begin(), clos.end(), [&](const CLO& clo) {
            return clo.getCloDescription() == desc;
        });
        if (it != clos.end()) {
            it->setCloDescription(newDesc);
            cout << "CLO updated successfully." << endl;
        } else {
            cout << "CLO not found." << endl;
        }
    };

    // Function to add an evaluation
    auto addEvaluation = [&evaluations](const string& name) {
        evaluations.push_back(Evaluation(name));
        cout << "Evaluation added successfully." << endl;
    };

    // Function to remove an evaluation
    auto removeEvaluation = [&evaluations](const string& name) {
        auto it = find_if(evaluations.begin(), evaluations.end(), [&](const Evaluation& eval) {
            return eval.get_name() == name;
        });
        if (it != evaluations.end()) {
            evaluations.erase(it);
            cout << "Evaluation removed successfully." << endl;
        } else {
            cout << "Evaluation not found." << endl;
        }
    };

    // Function to update an evaluation
    auto updateEvaluation = [&evaluations](const string& name, const string& newName) {
        auto it = find_if(evaluations.begin(), evaluations.end(), [&](const Evaluation& eval) {
            return eval.get_name() == name;
        });
        if (it != evaluations.end()) {
            it->set_name(newName);
            cout << "Evaluation updated successfully." << endl;
        } else {
            cout << "Evaluation not found." << endl;
        }
    };

    // Main loop for user interaction
    int choice;
    string id, newID, desc, newDesc, name, newName;
    while (true) {
        printMenu();
        cin >> choice;
        cin.ignore(); // Ignore newline character left in the input buffer
        switch (choice) {
            case 1:
                cout << "********** Manage Courses **********" << endl;
                cout << "1. Add Course" << endl;
                cout << "2. Remove Course" << endl;
                cout << "3. Update Course" << endl;
                cout << "Enter your choice: ";
                cin >> choice;
                cin.ignore();
                switch (choice) {
                    case 1:
                        cout << "Enter Course ID: ";
                        getline(cin, id);
                        addCourse(id);
                        break;
                    case 2:
                        cout << "Enter Course ID to remove: ";
                        getline(cin, id);
                        removeCourse(id);
                        break;
                    case 3:
                        cout << "Enter Course ID to update: ";
                        getline(cin, id);
                        cout << "Enter new Course ID: ";
                        getline(cin, newID);
                        updateCourse(id, newID);
                        break;
                    default:
                        cout << "Invalid choice." << endl;
                        break;
                }
                break;
            case 2:
                cout << "********** Manage CLOs **********" << endl;
                cout << "1. Add CLO" << endl;
                cout << "2. Remove CLO" << endl;
                cout << "3. Update CLO" << endl;
                cout << "Enter your choice: ";
                cin >> choice;
                cin.ignore();
                                    switch (choice) {
                        case 1:
                            cout << "Enter Evaluation Name: ";
                            getline(cin, name);
                            addEvaluation(name);
                            break;
                        case 2:
                            cout << "Enter Evaluation Name to remove: ";
                            getline(cin, name);
                            removeEvaluation(name);
                            break;
                        case 3:
                            cout << "Enter Evaluation Name to update: ";
                            getline(cin, name);
                            cout << "Enter new Evaluation Name: ";
                            getline(cin, newName);
                            updateEvaluation(name, newName);
                            break;
                        default:
                            cout << "Invalid choice." << endl;
                            break;
                    }
                    break;
                case 4:
                    cout << "Exiting program. Goodbye!" << endl;
                    return 0;
                default:
                    cout << "Invalid choice." << endl;
                    break;
            }
        }
    }
