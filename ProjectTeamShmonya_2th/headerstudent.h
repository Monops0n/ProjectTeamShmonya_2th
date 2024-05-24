#include <stdlib.h>
#include <Windows.h>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <stdio.h>
#include <iomanip>
#include <locale>
#include <vector>

#define DEFAULT_SIZE 100
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

struct Student {
    string login;
    string password;
    string name;
    int* grades = new int[8];
    int final;
    double average;
};

struct Question {
    string* variants = new string[4];
    int correctIndex;
    string name;
};

struct Topic {
    string name;
    Question* questions = new Question[DEFAULT_SIZE];
    int countQuestion;
};
void clear();
bool objectIsNull(Student student);
bool objectIsNull(Question question);
bool objectIsNull(Topic topic);
bool isNumber(string& str);
bool isVariant(string& str);
bool isCorrectVariant(string& str);
bool isQuestion(string& str);
string getQuestionNumberFromString(string& str);
void removeSpaceAndAlpha(string& str);
void removeSpaceAndDigit(string& str);
int parseTopicOrFinalAndGetGrade(string topic, string str);
double parseAverage(string topic, string str);
void readGradeFromRow(Student* student, string str);
void readFileRow(Topic* topic, string str);
void readFileRow(Student* student, string str, int rowNum);
int trainingTheme(string questionFile);
void readFile(Topic* topic, string filename);
void readFile(Student* students, string filename);
int getStudentIndexByLogin(Student* students, string login);
bool checkPass(Student* students, string pass);
int signInSystem(Student* students);
int grade(int questions, int answared);
void rewriteFileStudents(Student* students, string fileName);
int getTopicIndex(string topicName);
void testingOnTheTopic(Topic* topics, Student* students, int studentIndex);
void finalTesting(Topic* topics, Student* students, int studentIndex);