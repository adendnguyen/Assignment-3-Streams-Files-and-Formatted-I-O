// Programming Assignment 3
// Programming Fundamentals II (COSC 1437)
// Author: Aden Nguyen
// Description: Reads employee records from a file, writes a formatted
//              payroll report, then demonstrates stream-inspection
//              functions and input-failure handling.
 
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
 
using namespace std;
 
int main()
{
    // ---------- PART 1: PAYROLL FILE PROCESSOR ----------
 
    // TODO B: declare inFile (ifstream) and outFile (ofstream)
    ifstream inFile;
    ofstream outFile;
 
 
    // TODO C: open payrollData.txt and payrollReport.txt
    //         then check that the input file opened successfully.
    //         If it failed, print an error and return 1.
    inFile.open("payrollData.txt");
    outFile.open("payrollReport.txt");
    if(!inFile.is_open())
    {
        cout << ("Error: Input file could not be opened") << endl;
        return 1;
    }
    if(!outFile.is_open())
    {
       cout << ("Error: Output file could not be opened") << endl;
        return 1;
    }
 
 
    // Variables for one employee's data
    string firstName, lastName, department;
    double grossSalary, bonusPercent, taxPercent;
    double distance, travelTime;
    double paycheck, averageSpeed;
 
    outFile << fixed << showpoint << setprecision(2);
 
    // TODO D: loop while the input stream still reads a first name.
    //         Inside the loop, read the rest of each employee's data.
    while (inFile >> firstName) 
    {
        // read the remaining fields for this employee
        inFile >> lastName >> department; 
        inFile >> grossSalary >> bonusPercent >> taxPercent;
        inFile >> distance >> travelTime;

 
 
        // TODO E: compute paycheck and averageSpeed
        paycheck = grossSalary + (grossSalary * bonusPercent/100.0) - (grossSalary * taxPercent/100.0);
        averageSpeed = distance/travelTime;
 
 
        // TODO F: write the formatted report block for this employee
        //         remember fixed/showpoint/setprecision are already set,
        //         and use setw at least once.
        outFile  << "Name: "  << firstName << " " << lastName << ", Department: " << department << endl;
        outFile  << "Monthly Gross Salary: $" << grossSalary << ", Bonus: " << bonusPercent << "%, Taxes: " << taxPercent << "%" << endl;
        outFile << "Paycheck: $" << setw(10) << paycheck  << endl;
        outFile  << "Distance Traveled: " << distance << " miles, Travel Time: " << travelTime << " hours" << endl;
        outFile  << "Average Speed: " << averageSpeed << " miles per hour" << endl;
        outFile << endl;
 
    }
 
    // TODO G: close both files
    inFile.close();
    outFile.close();
 
    // ---------- PART 2: STREAM INSPECTOR ----------
    // (reads from the keyboard)
     
    // TODO H: peek at the first character, report digit vs letter,
    //         then read and echo the full line.
    //         (Note on putback(): describe one use case in a comment.)
    string line;
    char firstChar;

     cout << "Enter a line of text >> ";
     
    firstChar = cin.peek();
    if(isdigit(firstChar))
    {
        cout << "The first character is a digit" << endl;
    }
    else if (isalpha(firstChar))
    {
       cout << "The first character is a letter" << endl;
    }
    else
    {
        cout << "The first character is neither a digit nor a letter" << endl;
    }
    getline(cin, line);
    cout <<"You entered: " << line << endl;



 
 
    // TODO I: read an int, use cin.ignore(), then getline a description.
    int integer;
    string description;

    cout << "Enter an integer >> ";
    
    cin >> integer;
    cin.ignore(200, '\n');

    
    cout << "Enter a description >> ";
    getline(cin, description);
    cout <<"You entered the integer: " << integer << endl;
    cout <<"You entered the description: " << description << endl;


 
 
    // TODO J: prompt for a number; if cin.fail(), clear and ignore,
    //         then report invalid input.
    double num;
    cout << "Enter a number >> ";
    cin >> num;
    if(cin.fail())
    {
        cin.clear();
        cin.ignore(200, '\n');
        cout << "Error: Invalid Input " << endl;  
    }
    else
    {
        cout << "You entered: " << num << endl;
    }
    
    return 0;
}

/* One use for putback()
        If you read a character with get(), putback() can return it to the 
        input stream so it can be read again

        EX: string line = "ABCD"
            char ch;
            cin.get(ch);                            //ch = A
            cin.putback(ch);
            cin.get(ch);                            //ch = A instead of B
*/

/*Test Run #1
        Enter a line of text >> Hello World
        H is a letter
        You entered: Hello World
        Enter an integer >> 42
        Enter a description >> The answer to the ultimate question of Life, the Universe, and Everything
        You entered the integer: 42
        You entered the description: The answer to the ultimate question of Life, the Universe, and Everything
        Enter a number >> Yogurt
        Error: invalid input 
*/

/*Test Run #2
        Enter a line of text >> 55 burgers 55 fries
        The first character is a digit
        You entered: 55 burgers 55 fries
        Enter an integer >> 4
        Enter a description >> It is my lucky number!
        You entered the integer: 4
        You entered the description: It is my lucky number!
        Enter a number >> 55
        You entered: 55
*/
