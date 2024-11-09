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
const int NUM_ROBOTS = 5;
const int SIM_PERIODS = 25;


// simulation function
void simulateRobotTasks(map<int, string> &robotMap, vector<string> &taskList);
string selectRandomTask(vector<string> &taskList);
// ramdom item generator
string selectRandomItem();
void loadTasks(vector<string> &taskList);


// main function
int main() {
    // seed random number generator
    srand(time(0));

    // variable declarations
    // initialize a robot map
    map<int, string> robotMap;
    vector<string> taskList;

    loadTasks(taskList);

    // call function to simulate robot tasks over a certain time period
    simulateRobotTasks(robotMap, taskList);

    // display final state of robots
    cout << "Final State of Robots:\n";
    for (const auto &robot : robotMap)
    {
        cout << "Robot: " << robot.first << " final task: " << robot.second << endl;
    }

    return 0;
}

// function definitions
// simulation function
void simulateRobotTasks(map<int, string> &robotMap, vector<string> &taskList)
{
    //randomly assign tasks to each robot
    for(int i = 1; i <= NUM_ROBOTS; i++)
    {
        robotMap[i] = ""; // initially empty
    }

    // for 25 time periods
    for (int t = 1; t <= SIM_PERIODS; t++) 
    {
        cout << "Time Period: " << t << endl;


        for (auto &robot : robotMap) 
        {
            int robotID = robot.first;  // update ID # in the map
            string task = selectRandomTask(taskList);

            //if(task.empty())
            //{
            //    task = "charging";
            //}

            // switch statements including logic for each task
            // picking or packing
            if (task != "recharging")
            {
                // call a random item generator function to assign an item to the task the robot is doing
                string item = selectRandomItem();
                // display the robot ID, task, and item
                cout << "Robot " << robotID << " is " << task << ": " << item << endl;
            }       

            // charging
            else if (task == "recharging")
            {
                // display the robot ID and that its charging
                cout << "Robot " << robotID << " is " << task << endl;

            }

            robot.second = task; // update the task in the map
            
        }
        cout << endl;   
    }
}

void loadTasks(vector<string> &taskList)
{
    // open external file
    ifstream finFileOne("tasks.txt");

    // adding data validation to check if there is an error opening the file
    if (!finFileOne) {
        cerr << "Error opening the first file." << endl;
        return;
    }

    // initialize robot task list
    string task;
    while (finFileOne >> task) {
        taskList.push_back(task);
    }

    // close the file
    finFileOne.close();

}
    
string selectRandomTask(vector<string> &taskList)
{

    if (taskList.empty())
    {
        return "";
    }
    else
    {
        // generate a random number from however big the taskList is
        int randomNumTask = rand() % taskList.size();

        // return that string task
        return taskList[randomNumTask];
    }
}

// random item generator
string selectRandomItem()
{
    // open another file caled items.txt that contains random items
    // open external file
    ifstream finFileTwo("items.txt");

    // adding data validation to check if there is an error opening the file
    if (!finFileTwo) {
        cerr << "Error opening the second file." << endl;
        return "";
    }

    // initialize robot task list
    vector<string> itemList;
    string item;
    while (finFileTwo >> item) {
        itemList.push_back(item);
    }

    // close the file
    finFileTwo.close();

    if (itemList.empty())
    {
        return "";
    }

    else 
    {
        // calculate a random number and select that item from the txt file
        int randomNumItem = rand() % itemList.size();

        // return the random item to the simulate function
        return itemList[randomNumItem];
    }
    
}
    