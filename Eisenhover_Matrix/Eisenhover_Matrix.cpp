#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;

vector <string> UrgentAndImportant;
vector <string> NotUrgentAndImportant;
vector <string> UrgentAndNotImportant;
vector <string> NotUrgentAndNotImportant;

//urgent & important items
//not urgent & important items
//urgent & not important items
//not urgent & not important items

bool isUrgent(int day_today, int month_now) {
  //this functions check urgency. User takes todays date and the date sinc the task has to be conpleted.
    int task_day, task_month;
    int totalDays = 0;

    cout << "What is the deadline" << endl<<"Day: ";
    cin >> task_day;
    cout << "What month is it now: " << endl;
    cin >> task_month;

    int monthDays[] = {0, 31,28,31,30,31,30,31,31,30,31,30,31 };

    if (month_now == task_month) {
        totalDays = task_day - day_today;
    }
    else {


        for (int i = month_now; i < task_month; i++)
        {
            totalDays += monthDays[i];
        }
        totalDays += task_day - day_today;
    }

    if (totalDays <= 3) {
        return true;
    }
    else
        return false;
}

bool isImportant() {
    //checks importance of tasks
    string input;
    cout << "Is your task important? Type 'yes' or 'no': " << endl;

    while (1) {
        cin >> input;
        if (input == "yes") {
            return true;
        }
        else if (input == "no") {
            return false;
        }
        else
            cout << "Invalid input. Try again!" << endl;
            continue;
    }

}

void CheckTask(int day, int month) {
    //adds tasks to the appropriate vector
    bool urgent, important;
    string task;
    
    cin.ignore();
    cout << "Input your task:\n";
    getline(cin, task);
    system("cls");
    urgent = isUrgent(day, month);
    system("cls");
    important = isImportant();
    system("cls");
    
    if ((urgent == 1) && (important == 1)) {
        UrgentAndImportant.push_back(task);
    }
    else if ((urgent == 0) && (important == 1)) {
        NotUrgentAndImportant.push_back(task);
    }
    else if ((urgent == 1) && (important == 0)) {
        UrgentAndNotImportant.push_back(task);
    }
    else if ((urgent == 0) && (important == 0)) {
        NotUrgentAndNotImportant.push_back(task);
    }
    else
        cout << "Invalid input!";
}

void printTasks() {
    //prints inputed tasks
    cout << "Your urgent and important tasks:" << endl;

    for (int i = 0; i < UrgentAndImportant.size(); i++)
        cout << UrgentAndImportant.at(i) << endl;
    cout << "----------------------------------------"<< endl;
    cout << "Your not urgent but important tasks:" << endl;

    for (int i = 0; i < NotUrgentAndImportant.size(); i++)
        cout << NotUrgentAndImportant.at(i) << endl;
    cout << "----------------------------------------"<<endl;
    cout << "Your urgent but not important tasks:" << endl;

    for (int i = 0; i < UrgentAndNotImportant.size(); i++)
        cout << UrgentAndNotImportant.at(i) << endl;
    cout << "----------------------------------------"<<endl;
    cout << "Your not urgent and not important tasks:" << endl;
    for (int i = 0; i < NotUrgentAndNotImportant.size(); i++)
        cout << NotUrgentAndNotImportant.at(i) << endl;
    cout << "----------------------------------------"<< endl;
}


int main()
{
    int opt, day_today, month_now;
    cout << "Welcome in EISENHOWER MATRIX! " << endl;
    cout << "What day is it today: " << endl;//check date to see importancy
    cin >> day_today;
    cout << "What month is it now: " << endl;
    cin >> month_now;
    system("cls");
    while (1) {
        cout << "Choose:\n1. To addad task,\n2. To see your tasks,\n3. To exit the program.\n";        
        cin >> opt;
        if (opt == 1) {
            system("cls");
            CheckTask(day_today, month_now);
        }
        else if (opt == 2) {
            system("cls");
            printTasks();
        }
        else if (opt == 3) {
            cout << "GOOD BYE!";
            break;
        }
        else
            cout << "Invalid input. Try again.";
            continue;
    }

}
