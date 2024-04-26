#include "Header.h"

void addCourse(Program& program);             // academic officer
void removeCourse(Program& program);          // academic officer 
void updateCourse(Program& program);          // academic officer  

void addCLO(Course& course);                       // academic officer
void removeCLO(Course& course);                       // academic officer
void updateCLO(Course& course);                       // academic officer

void addEvaluation(Course& course);            // teacher
void removeEvaluation(Course& course);            // teacher
void updateEvaluation(Course& course);            // teacher

void addQuestion(Evaluation& evaluation);           // teacher
void removeQuestion(Evaluation& evaluation);           // teacher
void updateQuestion(Evaluation& evaluation);           // teacher

int main()
{ 
    return 0;
}