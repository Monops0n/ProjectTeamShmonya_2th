#include <stdlib.h>
#include <Windows.h>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <Windows.h>
#include <stdio.h>
#include "header student.h"

using namespace std;

void clear()
{
    system("cls");
}



bool objectIsNull(Student student)
{
    return student.login.empty();
}

bool objectIsNull(Question question)
{
    return question.name.empty();
}

bool objectIsNull(Topic topic)
{
    return topic.name.empty();
}

bool isNumber(string& str)
{
    return !str.empty() && str.find_first_not_of("0123456789") == str.npos;
}

bool isVariant(string& str)
{
    string result;
    for (string::size_type i = 0; i < str.size(); ++i)
    {
        if (str[i] == ')')
        {
            break;
        }
        if (isspace(str[i]))
        {
            continue;
        }
        result += str[i];
    }
    return result.size() == 1 && isalpha(result[0]);
}


bool isCorrectVariant(string& str)
{
    for (string::size_type i = 0; i < str.size(); ++i)
    {
        if (str[i] == '*')
        {
            return true;
        }
        if (!isspace(str[i]))
        {
            return false;
        }
    }
    return false;
}
bool isQuestion(string& str) {
    string result;
    for (string::size_type i = 0; i < str.size(); ++i)
    {
        if (str[i] == ')')
        {
            break;
        }
        result += str[i];
    }
    return isNumber(result);
}

string getQuestionNumberFromString(string& str) {
    string result;
    for (string::size_type i = 0; i < str.size(); ++i)
    {
        result += str[i];
        if (str[i] == ')')
        {
            if ((i + 1) != str.size() && isspace(str[i + 1]))
            {
                result += str[i + 1];
            }
            break;
        }
    }
    return result;
}

void removeSpaceAndAlpha(string& str)
{
    str.erase(remove_if(str.begin(), str.end(), isspace), str.end());
    str.erase(remove_if(str.begin(), str.end(), isalpha), str.end());
}

void removeSpaceAndDigit(string& str)
{
    str.erase(remove_if(str.begin(), str.end(), isspace), str.end());
    str.erase(remove_if(str.begin(), str.end(), isdigit), str.end());
}

int parseTopicOrFinalAndGetGrade(string topic, string str)
{
    str.erase(0, topic.length() + 1);
    removeSpaceAndAlpha(str);
    if (!isNumber(str)) {
        return 0;
    }
    return stoi(str);
}

double parseAverage(string topic, string str)
{
    str.erase(0, topic.length() + 1);
    removeSpaceAndAlpha(str);
    if (!isNumber(str)) {
        return 0;
    }
    return stod(str);
}

void readGradeFromRow(Student* student, string str)
{
    string prefix = str.substr(0, str.find(':'));
    if (prefix.compare("cycles") == 0) {
        student->grades[0] = parseTopicOrFinalAndGetGrade(prefix, str);
        if (student->grades[0] < 0 || student->grades[0] > 5)
            printf("Несуществующая оценка!\n");
    }
    else if (prefix.compare("array") == 0)
    {
        student->grades[1] = parseTopicOrFinalAndGetGrade(prefix, str);
        if (student->grades[1] < 0 || student->grades[1] > 5)
            printf("Несуществующая оценка!\n");
    }
    else if (prefix.compare("string") == 0)
    {
        student->grades[2] = parseTopicOrFinalAndGetGrade(prefix, str);
        if (student->grades[2] < 0 || student->grades[2] > 5)
            printf("Несуществующая оценка!\n");
    }
    else if (prefix.compare("recursion") == 0)
    {
        student->grades[3] = parseTopicOrFinalAndGetGrade(prefix, str);
        if (student->grades[3] < 0 || student->grades[3] > 5)
            printf("Несуществующая оценка!\n");
    }
    else if (prefix.compare("struct") == 0)
    {
        student->grades[4] = parseTopicOrFinalAndGetGrade(prefix, str);
        if (student->grades[4] < 0 || student->grades[4] > 5)
            printf("Несуществующая оценка!\n");
    }
    else if (prefix.compare("files") == 0)
    {
        student->grades[5] = parseTopicOrFinalAndGetGrade(prefix, str);
        if (student->grades[5] < 0 || student->grades[5] > 5)
            printf("Несуществующая оценка!\n");
    }
    else if (prefix.compare("address") == 0)
    {
        student->grades[6] = parseTopicOrFinalAndGetGrade(prefix, str);
        if (student->grades[6] < 0 || student->grades[6] > 5)
            printf("Несуществующая оценка!\n");
    }
    else if (prefix.compare("dinamic") == 0)
    {
        student->grades[7] = parseTopicOrFinalAndGetGrade(prefix, str);
        if (student->grades[7] < 0 || student->grades[7] > 5)
            printf("Несуществующая оценка!\n");
    }
    else if (prefix.compare("final") == 0)
    {
        student->final = parseTopicOrFinalAndGetGrade(prefix, str);
        if (student->final < 0 || student->final > 5)
            printf("Несуществующая оценка!\n");
    }
    else if (prefix.compare("average") == 0)
    {
        student->average = parseAverage(prefix, str);
        if (student->average < 0 || student->average > 5)
            printf("Несуществующая оценка!\n");
    }
    else {
        printf("Вы указали несуществующую строку!\n");
    }
}

void readFileRow(Topic* topic, string str)
{
    if (all_of(str.begin(), str.end(), isalpha))
    {
        topic->name = str;
    }
}

void readFileRow(Student* student, string str, int rowNum) {
    switch (rowNum) {
    case 1: {
        student->login = str;
        break;
    }
    case 2: {
        student->password = str;
        break;
    }
    case 3: {
        student->name = str;
        break;
    }
    default: {
        readGradeFromRow(student, str);
    }
    }
}

int trainingTheme(string questionFile)
{
    FILE* f;

    int tema;
    char temka[50];
    char line[300];
    fopen_s(&f, questionFile.c_str(), "r");
    if (f == NULL) {
        printf("Ошибка открытия файла\n");
        return 1;
    }
    do {
        printf("Выбор темы:\n1.Циклы\n2.Массивы (одномерные и двумерные)\n3.Строки\n4.Рекурсия\n5.Структуры\n6.Файлы\n7.Адреса и указатели\n8.Динамическая память\n");
        scanf_s("%d", &tema);
        if (tema < 1 || tema>8)
            printf("Ошибка ввода");
    } while (tema < 1 || tema>8);
    switch (tema)
    {
    case 1: strcpy_s(temka, "Циклы"); break;
    case 2: strcpy_s(temka, "Массивы (одномерные и двумерные)"); break;
    case 3: strcpy_s(temka, "Строки"); break;
    case 4: strcpy_s(temka, "Рекурсия"); break;
    case 5:strcpy_s(temka, "Структуры"); break;
    case 6:strcpy_s(temka, "Файлы"); break;
    case 7:strcpy_s(temka, "Адреса и указатели"); break;
    case 8:strcpy_s(temka, "Динамическая память"); break;
    }
    while (fgets(line, 300, f))
    {
        line[strcspn(line, "\n")] = '\0';
        if (strcmp(line, temka) == 0)
        {
            break;
        }
    }
    char answer;
    int tasks = atoi(fgets(line, 300, f));
    for (int j = 0; j < tasks; j++)
    {
        int flag = 0;
        while (fgets(line, 300, f))
        {
            line[strcspn(line, "\n")] = '\0';
            if (strchr(line, ')') == 0 && strchr(line, ';') == 0)
                break;
            puts(line);
        }
        getchar();
        do
        {
            answer = getchar();
            if (answer != 'a' && answer != 'b' && answer != 'c' && answer != 'd')
            {
                printf("Ошибка, для ввода ответа используются только символы a,b,с и d\n");
                getchar();
            }
            else if (strchr(line, answer) != 0)
            {
                printf("Ответ верный\n");
                flag = 1;
            }
            else
                printf("Ответ неверный\n");
        } while (flag == 0);
    }
}

void readFile(Topic* topic, string filename)
{
    ifstream file;
    file.open(filename);
    int topicOrdinal = -1;
    int variantOrdinal = 0;
    int questOrdinal = -1;
    Topic* tPtr = &topic[topicOrdinal];
    Question* qPtr = &tPtr->questions[questOrdinal];

    if (file.is_open()) {
        string line;
        while (getline(file, line)) {

            if (isNumber(line))
            {
                tPtr->countQuestion = stoi(line);
            }
            else if (isQuestion(line))
            {
                qPtr->name = line.substr(getQuestionNumberFromString(line).size());
            }
            else if (isVariant(line))
            {
                qPtr->variants[variantOrdinal++] = line;
            }
            else if (isCorrectVariant(line))
            {
                removeSpaceAndDigit(line);
                qPtr->correctIndex = line[1] % 96;
                variantOrdinal = 0;
                qPtr = &tPtr->questions[++questOrdinal];
            }
            else
            {
                questOrdinal = -1;
                tPtr = &topic[++topicOrdinal];
                tPtr->name = line;
                qPtr = &tPtr->questions[++questOrdinal];
            }
            if (file.eof())
                break;
        }
    }
    else {
        printf("Невозможно прочесть файл!\n");
    }
    file.close();
    tPtr = nullptr;
    delete tPtr;
}

void readFile(Student* students, string filename)
{
    ifstream file;
    file.open(filename);
    int ordinal = 0;
    Student* sPtr = &students[ordinal];

    if (file.is_open()) {
        string line;
        int rowNum = 1;
        while (file) {
            getline(file, line);
            readFileRow(sPtr, line, rowNum);
            if (rowNum == 13) {
                rowNum = 0;
                ordinal++;
                sPtr = &students[ordinal];
            }
            if (file.eof())
                break;
            rowNum++;
        }
    }
    else {
        cout << "Невозможно прочесть файл!\n";
    }
    file.close();
    sPtr = nullptr;
    delete sPtr;
}

int getStudentIndexByLogin(Student* students, string login)
{
    for (int i = 0; i < DEFAULT_SIZE; i++)
    {
        if (objectIsNull(*(students + i)))
        {
            break;
        }
        if ((students + i)->login.compare(login) == 0)
        {
            return i;
        }
    }
    return -1;
}

bool checkPass(Student* students, string pass)
{
    for (int i = 0; i < DEFAULT_SIZE; i++)
    {
        if (objectIsNull(*(students + i)))
        {
            break;
        }
        if ((students + i)->password.compare(pass) == 0)
        {
            return true;
        }
    }
    return false;
}

int signInSystem(Student* students) {
    int index = -1;

    bool passIsCorrect = false;
    string login;
    string password;
    string name;
    while (index == -1)
    {
        clear();
        cout << "Введите свой логин: ", cin >> login;
        index = getStudentIndexByLogin(students, login);
    }
    while (!passIsCorrect)
    {
        clear();
        cout << "Введите свой пароль: ", cin >> password;
        passIsCorrect = (students + index)->password.compare(password) == 0;
    }
    clear();
    cout << "Добро пожаловать, " << (students + index)->name << "!\n" << endl;
    return index;
}

int grade(int questions, int answared) {
    double result = answared / (double)questions * 100;
    if (result < 50)
    {
        return 2;
    }
    else if (result >= 50 && result < 65)
    {
        return 3;
    }
    else if (result >= 65 && result < 80)
    {
        return 4;
    }
    else
    {
        return 5;
    }
}

void rewriteFileStudents(Student* students, string fileName)
{
    ofstream file(fileName);
    for (int i = 0; i < DEFAULT_SIZE; i++) {
        if (!objectIsNull(*(students + i))) {
            file << (students + i)->login << endl;
            file << (students + i)->password << endl;
            file << (students + i)->name << endl;
            int sum = 0;
            for (int j = 0; j < 8; j++) {
                switch (j) {
                case 0: file << "cycles: "; break;
                case 1: file << "array: "; break;
                case 2: file << "string: "; break;
                case 3: file << "recursion: "; break;
                case 4: file << "struct: "; break;
                case 5: file << "files: "; break;
                case 6: file << "address: "; break;
                case 7: file << "dinamic: "; break;
                }
                int grade = (students + i)->grades[j];
                sum += grade;
                if (grade == 0) {
                    file << endl;
                }
                else {
                    file << grade << endl;
                }
            }
            file << "final: ";
            int final = (students + i)->final;
            if (final == 0) {
                file << endl;
            }
            else {
                file << final << endl;
            }
            file << "average: ";
            double average = sum / 8.0;
            if (average == 0) {
                file << endl;
            }
            else {
                file << average << endl;
            }
        }
    }
}
int getTopicIndex(string topicName)
{
    if (topicName.compare("Циклы") == 0)
    {
        return 0;
    }
    if (topicName.compare("Массивы (одномерные и двумерные)") == 0)
    {
        return 1;
    }
    if (topicName.compare("Строки") == 0)
    {
        return 2;
    }
    if (topicName.compare("Рекурсия") == 0)
    {
        return 3;
    }
    if (topicName.compare("Структуры") == 0)
    {
        return 4;
    }
    if (topicName.compare("Файлы") == 0)
    {
        return 5;
    }
    if (topicName.compare("Адреса и указатели") == 0)
    {
        return 6;
    }
    if (topicName.compare("Динамическая память") == 0)
    {
        return 7;
    }
    return -1;
}

void testingOnTheTopic(Topic* topics, Student* students, int studentIndex)
{
    int selectedTopic;
    string input;

    do {
        cout << "Выберите тему: " << endl;
        for (int i = 0; i < 8; i++) {

            cout << i + 1 << " " << (topics + i)->name << endl;
        }
        do
        {
            scanf_s("%d", &selectedTopic);
            if (selectedTopic < 1 || selectedTopic > 8)
            {
                printf("Введите корректные значения!\n");
            }
        } while (selectedTopic < 1 || selectedTopic > 8);

    } while (selectedTopic <= 0 && selectedTopic >= 9);

    srand(time(NULL));

    int sum = 0;
    bool examQuestions[DEFAULT_SIZE] = { false };
    bool unansweredExamQuestions[DEFAULT_SIZE] = { false };
    int questionId = -1;
    char c;
    int answeredQuestions = 0;
    int unansweredQuestions = 0;
    int questionIds[10];

    do
    {
        questionId = rand() % 100;

        if (!examQuestions[questionId]) {
            Question question = (topics + (selectedTopic - 1))->questions[questionId];

            if (objectIsNull(question))
            {
                examQuestions[questionId] = true;
                continue;
            }
            cout << question.name << endl;
            cout << question.variants[0] << endl;
            cout << question.variants[1] << endl;
            cout << question.variants[2] << endl;
            cout << question.variants[3] << endl;
            examQuestions[questionId] = true;
            c = NULL;
            do {
                cin >> c;
                if (c < 97 || c > 100)
                {
                    cout << "Введите элемент из списка (a,b,c,d)" << endl;
                }
            } while (c < 97 || c > 100);
            if (question.correctIndex == c % 96)
            {
                answeredQuestions++;
            }
            else
            {
                unansweredQuestions++;
                unansweredExamQuestions[questionId] = true;
            }
            questionIds[sum++] = questionId;
        }

    } while (examQuestions[questionId] && sum < 10);

    printf("Число неправильных ответ: %d\n", unansweredQuestions);
    double ocenka;
    ocenka = (sum - unansweredQuestions) * 1.0 / sum;
    if (ocenka < 0.5) printf("Оценка: 2   .\n");
    else if (ocenka >= 0.5 and ocenka < 0.65) printf("Оценка: 3   .\n");
    else if (ocenka >= 0.65 and ocenka < 0.8) printf("Оценка: 4   .\n");
    else if (ocenka >= 0.8) printf("Оценка: 5   .\n");
    for (int i = 0; i < 10; i++) {
        if (!objectIsNull((topics + (selectedTopic - 1))->questions[questionIds[i]]) && unansweredExamQuestions[questionIds[i]]) {
            cout << (topics + (selectedTopic - 1))->questions[questionIds[i]].name << endl;
        }
    }
    int topic_index = getTopicIndex((topics + (selectedTopic - 1))->name);
    if (topic_index != -1)
    {
        students[studentIndex].grades[topic_index] = grade(10, answeredQuestions);
    }

}

void finalTesting(Topic* topics, Student* students, int studentIndex)
{
    srand(time(NULL));

    bool questionMap[8][DEFAULT_SIZE] = { false };
    int prevTopicId = -1;
    int topicId = -1;
    int sum = 0;
    int questionId = -1;
    char c;
    int answeredQuestions = 0;
    int unansweredQuestions = 0;

    do {
        topicId = rand() % 8;
        if (topicId == prevTopicId) {
            continue;
        }
        questionId = rand() % DEFAULT_SIZE;
        if (!questionMap[topicId][questionId]) {
            Question question = (topics + topicId)->questions[questionId];
            if (objectIsNull(question))
            {
                questionMap[topicId][questionId] = true;
                continue;
            }
            cout << question.name << endl;
            cout << question.variants[0] << endl;
            cout << question.variants[1] << endl;
            cout << question.variants[2] << endl;
            cout << question.variants[3] << endl;
            questionMap[topicId][questionId] = true;
            c = NULL;
            do {
                cin >> c;
            } while (c < 97 || c > 100);
            if (question.correctIndex == c % 96)
            {
                answeredQuestions++;
            }
            else
            {
                unansweredQuestions++;
            }
            sum++;
        }
    } while (questionMap[topicId][questionId] && sum < 40);

    printf("Число неправильных ответ: %d\n", unansweredQuestions);
    double ocenka;
    ocenka = (sum - unansweredQuestions) * 1.0 / sum;
    if (ocenka < 0.5) printf("Оценка: 2   .\n");
    else if (ocenka >= 0.5 and ocenka < 0.65) printf("Оценка: 3   .\n");
    else if (ocenka >= 0.65 and ocenka < 0.8) printf("Оценка: 4   .\n");
    else if (ocenka >= 0.8) printf("Оценка: 5   .\n");
    students[studentIndex].final = grade(40, answeredQuestions);
}
