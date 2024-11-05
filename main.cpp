// COMSC-210 | Mauricio Espinosa | Lab 29 Project
// IDE Used: Visual Studio Code & Github

//include necessary headers 
#include <iostream>
#include <fstream>
#include <map>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;


// function declarations
// simulation function
void simulateRobotTasks();
// ramdom item generator


// main function
int main() {
    // seed random number generator
    srand(time(0));

    // variable declarations
    // initialize a robot map
    map<int, string> robotTasks;

    // open external file
    ifstream fin("robots.txt");

    // read robot IDs from file and assign to robot std::map
    int robotID;
    while (fin >> robotID) {
        robotTasks[robotID];
    }

    // initialize robot task list

    // close the file
    fin.close();

    // call function to simulate robot tasks over a certain time period
    simulateRobotTasks();

    // display final state of robots
    cout << "Final State of Robots:\n";
    for (const auto& [id, task] : robotTasks) {
        cout << "Robot ID: " << id << ", Task: " << task << endl;
    }

    return 0;
}

// function definitions
// simulation function
    // for 25 time periods
    // randomly assign tasks to each robot
    // switch statements including logic for each task
        // picking
            // call a random item generator function to assign an item to the task the robot is doing
            // display the robot ID, task, and item
        // packing
            // call a random item generator function to assign an item to the task the robot is doing
            // display the robot ID, task, and item
        // charging
            // display the robot ID and that its charging


// random item generator
    // open another file caled items.txt that contains random items
    // calculate a random number and select that item from the txt file
    // return the random item to the simulate function
