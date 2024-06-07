Food-Warehouse-Management-System
BGU System Programming (SPL) 1st Assignment
Overview
This is a simulation game written in C++11 about managing a warehouse, creating orders, and instructing volunteers to make and ship orders to clients. The system uses object-oriented principles and showcases unique C++ properties such as the "Rule of 5".

How to Run
Clone the repository to your local machine:
bash
Copy code
git clone <repository_url>
Navigate to the project directory in your terminal:
bash
Copy code
cd Food-Warehouse-Management-System
Compile the source files using the provided Makefile:
bash
Copy code
make
Run the compiled executable with the path to the configuration file as the first command-line argument:
bash
Copy code
./bin/warehouse <path_to_configuration_file>
Project Overview
Project Objectives
Design an object-oriented system.
Gain implementation experience in C++.
Use classes, standard data structures, and C++ properties like the "Rule of 5".
Assignment Definition
In a faraway country, SPLand, a war is ongoing. As part of efforts to contribute and take care of the country’s citizens, some citizens established a food warehouse to supply food packages. The warehouse is operated by volunteers in different roles to handle orders made by customers.

Program Flow
The program receives the path of the config file as the first command-line argument:

cpp
Copy code
string configurationFile = argv[1];
The config file describes the initial state of the warehouse before starting the simulation. It contains information about initial customers and volunteers. The program initializes the warehouse using the config file and starts the simulation by calling the start() method of the Warehouse, followed by printing to the console: "Warehouse is open!".

The program then waits for the user to enter an action to execute. After each action, the program waits for the next action in a loop.

Config File Format
The input file contains the initial program data, each on a single line, in the following order:

Customers: Described in the following pattern:

plaintext
Copy code
customer <customer_name> <customer_type> <customer_distance> <max_orders>
Example:

plaintext
Copy code
customer Maya soldier 4 2
Volunteers: Described in the following pattern:

plaintext
Copy code
volunteer <volunteer_name> <volunteer_role> <volunteer_coolDown>/<volunteer_maxDistance> <distance_per_step>(for drivers only) <volunteer_maxOrders>(optional)
Example:

plaintext
Copy code
volunteer Ibrahim limited_collector 3 2
An example config file is available at /Example/configFileExample.txt.

Supported Actions
SimulateStep

Perform a step in the simulation, moving one unit of time forward.
Syntax:
plaintext
Copy code
step <number_of_steps>
Example:
plaintext
Copy code
step 3
AddOrder

Creates an order using the customer ID.
Syntax:
plaintext
Copy code
order <customer_id>
Example:
plaintext
Copy code
order 4
AddCustomer

Creates a new customer and stores them in the warehouse.
Syntax:
plaintext
Copy code
customer <customer_name> <customer_type> <customer_distance> <max_orders>
Example:
plaintext
Copy code
customer Dani soldier 7 3
PrintOrderStatus

Prints information about a given order.
Syntax:
plaintext
Copy code
orderStatus <order_id>
Example:
plaintext
Copy code
orderStatus 3
PrintCustomerStatus

Prints all information about a particular customer.
Syntax:
plaintext
Copy code
customerStatus <customer_id>
Example:
plaintext
Copy code
customerStatus 6
PrintVolunteerStatus

Prints all information about a particular volunteer.
Syntax:
plaintext
Copy code
volunteerStatus <volunteer_id>
Example:
plaintext
Copy code
volunteerStatus 1
PrintActionsLog

Prints all actions performed by the user, excluding the current log action.
Syntax:
plaintext
Copy code
log
Output Format:
plaintext
Copy code
<action_1_name> <action_1_args> <action_1_status> ...
Close

Prints all orders with their status, then closes the warehouse.
Syntax:
plaintext
Copy code
close
Output Format:
plaintext
Copy code
OrderID: <order_id>, CustomerID: <customer_id>, OrderStatus: <order_status>
BackupWarehouse

Saves all warehouse information (customers, volunteers, orders, and actions history) in a backup.
Syntax:
plaintext
Copy code
backup
RestoreWarehouse

Restores the backed-up warehouse status and overwrites the current status.
Syntax:
plaintext
Copy code
restore
Error if no backup available:
plaintext
Copy code
No backup available
Running Example
An example is available at /Example/RunningExample.pdf.
