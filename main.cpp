// COMSC-210 | Mauricio Espinosa | Lab 29 Project
// IDE Used: Visual Studio Code & Github

//include necessary headers 
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;


// function declarations
int NUM_ROBOTS = 5;
int SIM_PERIODS = 25;
// simulation function
void simulateRobotTasks(map<int, string> &robotMap, const vector<string> &taskList);
// ramdom item generator


// main function
int main() {
    // seed random number generator
    srand(time(0));

    // variable declarations
    // initialize a robot map
    map<int, string> robotMap;

    // open external file
    ifstream fin("tasks.txt");

    // initialize robot task list
    vector<string> taskList;
    string task;
    while (fin >> task) {
        taskList.push_back(task);
    }

    // close the file
    fin.close();

    // call function to simulate robot tasks over a certain time period
    simulateRobotTasks(robotMap, taskList);

    // display final state of robots
    cout << "Final State of Robots:\n";
    

    return 0;
}

// function definitions
// simulation function
void simulateRobotTasks(map<int, string> &robotMap, const vector<string> &taskList)
{
    // for 25 time periods
    // randomly assign tasks to each robot
    for(int i = 1; i <= NUM_ROBOTS; i++)
    {
        robotMap[i] = ""; // initially empty
    }

    // switch statements including logic for each task
        // picking
            // call a random item generator function to assign an item to the task the robot is doing
            // display the robot ID, task, and item
        // packing
            // call a random item generator function to assign an item to the task the robot is doing
            // display the robot ID, task, and item
        // charging
            // display the robot ID and that its charging

}
    

// random item generator
    // open another file caled items.txt that contains random items
    // calculate a random number and select that item from the txt file
    // return the random item to the simulate function
