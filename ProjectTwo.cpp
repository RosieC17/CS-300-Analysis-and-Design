//==============================================================
// Name			: Project Two
// Author		: Rosalinda Castaneda
// Verison		: 1.0
// Copyright	: Copyright © 2025 SNHU Code
//==============================================================

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class Course {
public:
    string courseId;
    string courseTitle;
    vector<string> preRequisite;

    Course() = default;
};

void loadVector(const string& textFile, vector<Course>& courses) {
    ifstream file(textFile);

    if (file.is_open()) {
        Course tempCourse;
        while (file >> tempCourse.courseId) {
            getline(file, tempCourse.courseTitle);

            string; preReq;
            tempCourse.preRequisite.clear();

            while (file >> preReq && preReq != "-1") {
                tempCourse.preRequisite.push_back(preReq);
            }

            courses.push_back(tempCourse);
        }
        file.close();
        cout << "Courses have been imported." << endl;
    }
    else {
        cout << "File not found." << endl;
    }
}

void printCourseList(const vector<Course>& courses) {
    for (const Course& course : courses) {
        if (course.courseId.substr(0, 4) == "CSCI" || course.courseId.substr(0, 4) == "MATH") {
            cout << course.courseId << ", " << course.courseTitle << endl;
        }
    }
}

void printCourseInformation(const vector<Course>& courses, const string& courseNumber) {
    bool found = false;
    for (const Course& course : courses) {
        if (course.courseId == courseNumber) {
            found = true;
            cout << course.courseId << " - " << course.courseTitle << endl;

            if (!course.preRequisite.empty()) {
                cout << "Prerequisites: ";
                for (const string& preReq : course.preRequisite) {
                    cout << preReq << " ";
                }
                cout << endl;
            }
            else {
                cout << "Prerequisites: None" << endl;
            }
            break;
        }
    }
    if (!found) {
        cout << "Course not found." << endl;
    }
}

int main() {
    vector<Course> courses;
    int choice;
    string filename;
    string courseNumber;

    do {
        cout << "\nMenu:" << endl;
        cout << "1. Load Data Structure." << endl;
        cout << "2. Print Course List." << endl;
        cout << "3. Print Course." << endl;
        cout << "9. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter filename: ";
            cin >> filename;
            loadVector(filename, courses);
            break;
        case 2:
            cout << "Here is a sample schedule:" << endl;
            printCourseList(courses);
            break;
        case 3:
            cout << "Enter course number: ";
            cin >> courseNumber;
            printCourseInformation(courses, courseNumber);
            break;
        case 9:
            cout << "Thank you for using the course planner!" << endl;
            break;
        default:
            cout << "Invalid choice." << endl;
        }
    } while (choice != 9);

    return 0;
}
