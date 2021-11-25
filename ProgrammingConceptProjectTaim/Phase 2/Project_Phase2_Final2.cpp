//Work of TaimHu
//From https://github.com/TaimHu
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

// Function prototypes

void menu(); 
void makeNewReservations();
void listCurrentReservation();
void searchReservation();
void changeReservation(string, string, string);
void cancelReservation();
void PrintStatusReport();

// defining arrays globally with the fixed size of 700

string name[700],  
ID[700], 
seat[700],  
seat2[700]; 

int Mobile_Number[700],  
Menu_Number[700], 
reserved[700]; 

int main() // Main function
{
    menu();
    return 0;
}

void menu() // Menu function
{
    int num;   // defining the variables used

    string testID,
        recordedSeat,
        newSeat;


    do                                           // used do while loop to execute many statement depending on condition 
    {
        cout << "=========================================== " << endl;                    // design before the menu 
        cout << "        Airplane reservation system " << endl;                            // display menu 
        cout << "=========================================== " << endl;                    // design after the menu 
        cout << "[1] Make a new reservation " << endl;                                     // option 1 in the menu 
        cout << "[2] List current reservations " << endl;                                  // option 2 in the menu  
        cout << "[3] Search reservastions done by passenger " << endl;                     // option 3 in the menu 
        cout << "[4] Update reservation " << endl;                                         // option 4 in the menu 
        cout << "[5] Cancel reservation " << endl;                                         // option 5  in the menu 
        cout << "[6] Print Status Report " << endl << endl;                                // option 6 in the menu
        cout << "[7] Exit " << endl << endl;                                               // option 7 in the menu 
        cout << "Enter your choice: ";                                                     // ask the user to choose number from the menu 
        cin >> num;                                                                        // save the value in memory location call : num 


        while (cin.fail())                      /* This would make sure the user enters an integer when choosing from menu and not any
                                                other character as in alphabets and would ask the user to choose again.*/
        {
            cout << "Invalid entry, please try again.\n";
            cout << "=========================================== " << endl;
            cout << "        Airplane reservation system " << endl;
            cout << "=========================================== " << endl;
            cout << "[1] Make a new reservation " << endl;
            cout << "[2] List current reservations " << endl;
            cout << "[3] Search reservation done by passenger " << endl;
            cout << "[4] Update reservation " << endl;
            cout << "[5] Cancel reservation " << endl;
            cout << "[6] Print Status Report " << endl << endl;
            cout << "[7] Exit " << endl << endl;
            cout << "Enter your choice: ";
            cin.clear();
            cin.ignore();
            cin >> num;
        }

        switch (num)                            // used switch case so that the entered number carries out its job listed in the menu
        {
        case 1:  // option 1 from the menu
            makeNewReservations();
            break;   // if user enter 1 the compiler will execute this case only 

        case 2:  // option 2 from the menu
            listCurrentReservation();
            break;  // if user enter 2 the compiler will execute this case only  

        case 3:  // option 3 from the menu
            searchReservation();
            break;  // if user enter 3 the compiler will execute this case only 
        case 4:  // option 4 from the menu
            cin.ignore();
            cout << "Enter the person's ID: "; 
            getline(cin, testID);
            cout << "Enter the reserved seat: ";
            getline(cin, recordedSeat);
            cout << "Enter the new seat to be booked: ";
            getline(cin, newSeat);
            changeReservation(testID, recordedSeat, newSeat);  // The three parameters of this funtion are testID, recordedSeat, newSeat

            break;  // if user enter 4 the compiler will execute this case only 

        case 5:  // option 5 from the menu
            cancelReservation();

            break;  // if user enter 5 the compiler will execute this case only 

        case 6:  // option 6 from the menu
            PrintStatusReport();

            break;  // if user enter 6 the compiler will execute this case only 

        case 7:  // option 7 from the menu
            cout << "Bye, see you again later!";
            break;

        default:
            cout << "Invalid entry, please try again.\n" << endl;   // if user enter any number other than 1,2,3 or 7  the compiler will dispaly invalid value 
        }

    } while (num != 7);  // the condition to stop the do while loop (if the user enter 7 , the menu will not appear again)

}

void makeNewReservations() // new reeservation function
{
    ifstream in; // 'in' would be used to input data from the file to the programme.
    ofstream out;// 'out' would be used to output data from the programme to the file.

    string name,  // defining variable names
        seat,  
        seat_Test, 
        ID;  


    int Mobile_Number,  
        reserved,  
        Menu_Number; 

    bool seat_taken,
         seat_exist; 

    seat_taken = false; // these are used for validation checks
    seat_exist = false;

    in.open("isReserved.txt");               // Opens up the file stored in 'in' which in this case is isReserved.txt
    out.open("reservations.txt", ios::app);  // Opens up the file stored in 'out' which in this case is reservations.txt

    cout << "\n\n[1] Make a new reservation:  " << endl;
    cout << "===========================================" << endl;
    cout << "\nEnter seat number:";
    cin.ignore();            //used to clear up the buffer before the next data entry from getline to avoid error
    getline(cin, seat_Test); //used to enter data with data type string


    while (in >> seat >> reserved)
    {

        if (seat == seat_Test && reserved == 1)         // test to see if the seat is reserved.
        {
            cout << "This seat has already been reserved sorry.\n";
            seat_taken = true;

            break;

        }
        else if (seat == seat_Test && reserved == 0)    // test to see if the seat exists
        {
            seat_exist = true;
        }

        if (seat_taken == false && seat_exist == true)  // If the seat is available, following commands will be executed.
        {

            cout << "Enter person's ID Number: ";
            cin >> ID;
            cout << "Enter person's mobile number: ";
            cin >> Mobile_Number;
            cout << "Enter Menu preference ( 1-Veg   2-Non Veg   3-No meal ): ";
            cin >> Menu_Number;

            do              //This is to check whether the user enters data for meal menu within the rage 1-3
            {
                if (Menu_Number == 1 || Menu_Number == 2 || Menu_Number == 3) // This is to make sure the range 1-3 is considered valid.
                    break;
                cout << "The number you selected does not exists." <<
                    "\nEnter Menu preference ( 1-Veg   2-Non Veg   3-No meal ): ";
                cin >> Menu_Number;

            } while (Menu_Number <= 0 || Menu_Number >= 4);

            cout << "Enter person's full name: ";
            cin.ignore();
            getline(cin, name);


            cout << "\nPerson ID\tMobile Number\tSeat Number\tMenu Preference\tPerson Name\n\n";
            cout << left << setw(11) << ID << "\t";
            cout << left << setw(8) << Mobile_Number << "\t";
            cout << left << setw(4) << seat << "\t\t";
            cout << left << setw(1) << Menu_Number << "\t\t";
            cout << left << name << endl;

            cout << "\n.....You made a valid reservation, and record is saved.\n";

            out << left << setw(11) << ID << "  ";
            out << left << setw(8) << Mobile_Number << "\t";
            out << left << setw(4) << seat << "\t";
            out << left << setw(1) << Menu_Number << "\t";
            out << left << name << endl;

            break;        //This would exit the loop


        }
    }
    if (seat != seat_Test) /*If user enters data that does not represent any seat from the seat list in file,
                            he will he informed that the seat doesn't exist.*/
    {
        cout << "The seat requested does not exist!\n";
    }

    in.close();
    out.close();
    /*Code from line 139-151 is responsible for updating the isReserved file so
     that if user tries to book the same seat again, it would show them the seat is taken.*/

    in.open("isReserved.txt");
    out.open("isReserved1.txt");
    while (in >> seat >> reserved)
    {
        if (seat == seat_Test && reserved == 0)
            out << seat << "\t" << 1 << endl;
        else
            out << seat << "\t" << reserved << endl;
    }
    in.close(); // closes input text file
    out.close();
    remove("isReserved.txt");
    rename("isReserved1.txt", "isReserved.txt");
}

void listCurrentReservation() // list current reservations function
{
    ifstream in; // 'in' would be used to input data from the file to the programme.
    ofstream out;// 'out' would be used to output data from the programme to the file.

    string name,  // defining variable names
        ID,  
        seat;  

    int Mobile_Number,  
        Menu_Number; 
    in.open("reservations.txt"); // opens text file called reservation for inputs

    cout << "\n[2] Current Reservations " << endl;
    cout << "Person ID\tMobile Number\tSeat Number\tMenu Preference\tPerson Name\n\n";

    while (in >> ID >> Mobile_Number >> seat >> Menu_Number && in.ignore() && getline(in, name))

        // lists all current reservations stored in "reservations.txt"
    {
        cout << left << setw(11) << ID << "\t";
        cout << left << setw(8) << Mobile_Number << "\t";
        cout << left << setw(4) << seat << "\t\t";
        cout << left << setw(1) << Menu_Number << "\t\t";
        cout << left << name << endl << endl;
    }

    in.close(); // closes input text file

    cout << endl;
}

void searchReservation() // search reservation function
{
    ifstream in; // 'in' would be used to input data from the file to the programme.
    ofstream out; // 'out' would be used to output data from the programme to the file.

    string name,  
        ID,  
        seat,  
        testID; 

    int Mobile_Number,  
        Menu_Number; 

    bool ID_exist; 

    ID_exist = false; // used for validation check.
    in.open("reservations.txt");

    cout << "\n[3] Search reservation(s) done by a passenger" << endl;
    cout << "Please enter the person's ID number: ";

    cin.ignore();
    getline(cin, testID);

    cout << "\nPerson ID\tMobile Number\tSeat Number\tMenu Preference\tPerson Name\n\n";

    while (in >> ID >> Mobile_Number >> seat >> Menu_Number && in.ignore() && getline(in, name)) // starts reading values from reservation file and assigns the different values to different variables
    {
        if (ID == testID) // checks if the ID entered by the user exists
        {

            ID_exist = true;
            cout << left << setw(11) << ID << "\t";
            cout << left << setw(8) << Mobile_Number << "\t";
            cout << left << setw(4) << seat << "\t\t";
            cout << left << setw(1) << Menu_Number << "\t\t";
            cout << left << name << endl << endl;

        }


    }
    if (ID_exist == false) // if the ID doesnt exist the variable "exist" remains false and executes the if statement
    {
        cout << left << setw(11) << "--" << "\t";
        cout << left << setw(8) << "--" << "\t";
        cout << left << setw(4) << "--" << "\t\t";
        cout << left << setw(1) << "--" << "\t\t";
        cout << left << "--" << endl << endl;
        cout << "This ID number doesn't exist!\n\n";
    }

    in.close();

}

void changeReservation(string testID, string recordedSeat, string newSeat) // change reservation function
{
    bool check1 = true, // used for validation checks
        check2 = true;

    ofstream out; // 'out' would be used to output data from the file to the programme.
    ifstream in; // 'in' would be used to input data from the file to the programme.
    in.open("reservations.txt");

    int i = 0;
    while (in >> ID[i] >> Mobile_Number[i] >> seat[i] >> Menu_Number[i] && in.ignore() && getline(in, name[i])) // Making arrays from the file reservations.txt and checks the seat entered belongs to the ID
    {
        if (testID == ID[i] && recordedSeat != seat[i] || recordedSeat == seat[i] && testID != ID[i])
        {
            cout << "The seat " << recordedSeat << " does not belong to the ID " << testID << endl;
            check1 = false;
            break;
        }
        if (testID == ID[i] && recordedSeat == seat[i] || recordedSeat == seat[i] && testID == ID[i])
        {
            check1 = true;
            break;
        }
        i++;
    }
    in.close();

    in.open("reservations.txt");

    int x = 0;
    while (in >> ID[x] >> Mobile_Number[x] >> seat[x] >> Menu_Number[x] && in.ignore() && getline(in, name[x])) 
    {
        if (newSeat == seat[x])
        {
            cout << "The new seat number has already been taken, sorry.\n";
            check2 = false;
            break;
        }
        x++;
    }
    in.close();

    if (check1 == true && check2 == true) // if function executed if both checks are passed
    {

        for (int i = 0; i < 700; i++)  // updating the arrays
        {

            if (testID == ID[i])
            {
                seat[i] = newSeat;
            }

        }

        int y = 0;
        in.open("isReserved.txt");
        out.open("isReserved1.txt");
        while (in >> seat2[y] >> reserved[y])
        {
            if (seat2[y] == newSeat && reserved[y] == 0)
                out << seat2[y] << "\t" << 1 << endl;
            if(seat2[y]== recordedSeat && reserved[y]==1)
                out << seat2[y] << "\t" << 0 << endl;
            else
                out << seat2[y] << "\t" << reserved[y] << endl;
            y++;
        }
        in.close(); 
        out.close();
        remove("isReserved.txt");
        rename("isReserved1.txt", "isReserved.txt");


        int i = 0;
        in.open("reservations.txt");
        out.open("reservations2.txt");
        while (in >> ID[i] >> Mobile_Number[i] >> seat[i] >> Menu_Number[i] && in.ignore() && getline(in, name[i]))
        {
            if (testID == ID[i])
            {
                seat[i] = newSeat;
                out << left << setw(11) << ID[i] << "  ";
                out << left << setw(8) << Mobile_Number[i] << "\t";
                out << left << setw(4) << seat[i] << "\t";
                out << left << setw(1) << Menu_Number[i] << "\t";
                out << left << name[i] << endl;
            }
            else
            {
                out << left << setw(11) << ID[i] << "  ";
                out << left << setw(8) << Mobile_Number[i] << "\t";
                out << left << setw(4) << seat[i] << "\t";
                out << left << setw(1) << Menu_Number[i] << "\t";
                out << left << name[i] << endl;
            }

            i++;
        }
        in.close();
        out.close();
        remove("reservations.txt");
        rename("reservations2.txt", "reservations.txt");


       

        cout << "Reservation has been changed.\n";

    }

}

void cancelReservation() // cancel reservation function
{
    ifstream in;  // 'in' would be used to input data from the file to the programme.
    ofstream out, cancellations;  // 'out' and 'cancellations' would be used to output data from the file to the programme.

    string  seat_Test; 

    bool seat_exist = false; 


    cout << "\nEnter seat number: ";
    cin.ignore();
    getline(cin, seat_Test);


    int i = 0;
    in.open("reservations.txt");
    out.open("reservations2.txt");
    while (in >> ID[i] >> Mobile_Number[i] >> seat[i] >> Menu_Number[i] && in.ignore() && getline(in, name[i]))
    {
        if (seat[i] == seat_Test)  // if seat matches, the values are written to a new file called cancellations
        {
            cancellations.open("cancellations.txt", ios::app);
            seat_exist = true;
            cout << name[i] << " , your reservation has been updated." << endl;
            cancellations << left << setw(11) << ID[i] << "  ";
            cancellations << left << setw(8) << Mobile_Number[i] << "\t";
            cancellations << left << setw(4) << seat[i] << "\t";
            cancellations << left << setw(1) << Menu_Number[i] << "\t";
            cancellations << left << name[i] << endl;
            cancellations.close();

            continue;
        }
        else // if seat doesnt match, the values it is re-written on aa file called reservations2
        {
            out << left << setw(11) << ID[i] << "  ";
            out << left << setw(8) << Mobile_Number[i] << "\t";
            out << left << setw(4) << seat[i] << "\t";
            out << left << setw(1) << Menu_Number[i] << "\t";
            out << left << name[i] << endl;
        }
        i++;
    }
    in.close();
    out.close();
    remove("reservations.txt");
    rename("reservations2.txt", "reservations.txt");

    int x = 0;
    in.open("isReserved.txt");
    out.open("isReserved1.txt");
    while (in >> seat[x] >> reserved[x])  // used to update the isReserved file so that the cancled seat is now available
    {
        if (seat[x] == seat_Test && reserved[x] == 1)
            out << seat[x] << "\t" << 0 << endl;
        else
            out << seat[x] << "\t" << reserved[x] << endl;
        x++;
    }
    in.close(); // closes input text file               
    out.close();
    remove("isReserved.txt");
    rename("isReserved1.txt", "isReserved.txt");

    if (seat_exist == false)
    {
        cout << "Seat does not exist! \n";
    }
}

void PrintStatusReport()
{
    ifstream in, cancellations;  // 'in' and 'cancellations' would be used to input data from the file to the programme.

    int  sum1 = 0, // Sum of the total number of reservations
         sum2 = 0; // Sum of the total number of cancellations performed

    in.open("reservations.txt");
    int i = 0;
    while (in >> ID[i] >> Mobile_Number[i] >> seat[i] >> Menu_Number[i] && in.ignore() && getline(in, name[i])) // calculates how many rows there are in the file reservation
    {
        int x = 1;
        sum1 += x;
        x++;

        i++;
    }

    cancellations.open("cancellations.txt");
    int x = 0;
    while (cancellations >> ID[x] >> Mobile_Number[x] >> seat[x] >> Menu_Number[x] && cancellations.ignore() && getline(cancellations, name[x])) // calculates how many rows there are in the file cancellations
    {
        int y = 1;
        sum2 += y;
        y++;

        x++;
    }
    in.close();
    cancellations.close();

    cout << "\nTotal number of current reservations = " << sum1 << endl;
    cout << "Total number of cancellations performed = " << sum2 << endl;
}
