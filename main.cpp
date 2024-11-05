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
string selectRandomTask(const vector<string> &taskList);
// ramdom item generator
string selectRandomItem();


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
    // randomly assign tasks to each robot
    for(int i = 1; i <= NUM_ROBOTS; i++)
    {
        robotMap[i] = ""; // initially empty
    }

    // for 25 time periods
    for (int t = 1; t <= SIM_PERIODS; t++)
    {
        for (auto &robot : robotMap) 
        {
            int robotID = robot.first;  // update ID # in the map
            string task = selectRandomTask(taskList);
        }

        // switch statements including logic for each task
        // picking
        if (task == "picking")
        {
            // call a random item generator function to assign an item to the task the robot is doing
            string item = selectRandomItem();
            // display the robot ID, task, and item
            cout << "Robot " << robotID << " is picking: " << item << endl;
        }

        // packing
        else if (task == "packing")
        {
            // call a random item generator function to assign an item to the task the robot is doing
            string item = selectRandomItem();
            // display the robot ID, task, and item
            cout << "Robot " << robotID << " is packing: " << item << endl;
        }
    
        // charging
        else if (task == "charging")
        {
            // display the robot ID and that its charging
            cout << "Robot " << robotID << " is charging." << endl;

        }

        robot.second = task; // update the task in the map
            
    }

  
}
    
string selectRandomTask(const vector<string> &taskList)
{
    // generate a random number from however big the taskList is
    int randomNumTask = rand() % taskList.size();

    // return that string task
    return taskList[randomNumTask];
}

// random item generator
string selectRandomItem()
{
    // open another file caled items.txt that contains random items
    // open external file
    ifstream fin("items.txt");

    // initialize robot task list
    vector<string> itemList;
    string item;
    while (fin >> item) {
        itemList.push_back(item);
    }

    // close the file
    fin.close();

    // calculate a random number and select that item from the txt file
    int randomNumItem = rand() % itemList.size();

    // return the random item to the simulate function
    return itemList[randomNumItem];
}
    