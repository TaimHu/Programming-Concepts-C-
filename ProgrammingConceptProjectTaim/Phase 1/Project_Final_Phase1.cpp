//Work of Taim from
//https://github.com/TaimHu


#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
    ifstream in; // 'in' would be used to input data from the file to the programme.
    ofstream out;// 'out' would be used to output data from the programme to the file.

    int num,   // defining the value (num) that the user will enter to choose option from the menu.
        Mobile_Number,  // defining variable Mobile_Number.
        reserved,  // defining variable reserved (used in case 1).
        Menu_Number; // defining variable Menu_Number (used for food preferences)

    string name,  // defining variable name
        seat,  // defining variable seat
        seat_Test, // defining variable seat_Test (used in case 1)
        ID,  // defining variable ID
        testID; // defining variable testID (used in case 3)

    bool ID_exist, // defining variable exist (used in case 3)
        seat_taken,// defining taken variable (used in case 1)
        seat_exist; // defining seat_exist variable (used in case 1)



    do                                           // used do while loop to execute many statement depending on condition 
    {
        cout << "=========================================== " << endl;                    // design before the menu 
        cout << "        Airplane reservation system " << endl;                            // display menu 
        cout << "=========================================== " << endl;                    // design after the menu 
        cout << "[1] Make a new reservation " << endl;                                     // option 1 in the menu 
        cout << "[2] List current reservations " << endl;                                  // option 2 in the menu  
        cout << "[3] Search reservastions done by passenger " << endl << endl;             // option 3 in the menu 
        cout << "[7] Exit " << endl << endl;                                               // option 4 in the menu 
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
            cout << "[3] Search reservastions done by passenger " << endl << endl;
            cout << "[7] Exit " << endl << endl;
            cout << "Enter your choice: ";
            cin.clear();
            cin.ignore();
            cin >> num;
        }

        switch (num)                            // used switch case so that the entered number carries out its job listed in the menu
        {
        case 1:  // option 1 from the menu 
            seat_taken = false;
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
                        if (Menu_Number == 1 || Menu_Number == 2 || Menu_Number ==3) // This is to make sure the range 1-3 is considered valid.
                            break;
                            cout << "The number you selected does not exists." <<
                                "\nEnter Menu preference ( 1-Veg   2-Non Veg   3-No meal ): ";
                            cin >> Menu_Number;
                           
                    } while (Menu_Number <= 0 || Menu_Number >=4 );

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

                                            
            break;   // if user enter 1 the compiler will execute this case only  

        case 2:  // option 2 from the menu
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

            break;  // if user enter 2 the compiler will execute this case only  

        case 3:  // option 3 from the menu 
            ID_exist = false;
            in.open("reservations.txt");

            cout << "\n[3] Search reservation(s) done by a passenger" << endl;
            cout << "Please enter the person's ID number: ";

            cin.ignore();
            getline(cin, testID);
            
            cout << "\nPerson ID\tMobile Number\tSeat Number\tMenu Preference\tPerson Name\n\n";

            while (in >> ID >> Mobile_Number >> seat >> Menu_Number && in.ignore() && getline(in, name))
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

            break;  // if user enter 3 the compiler will execute this case only 

        case 7:  // option 7 from the menu
            cout << "Bye, see you again later!";
            break;

        default:
            cout << "Invalid entry, please try again.\n" << endl;   // if user enter any number other than 1,2,3 or 7  the compiler will dispaly invalid value 
        }
    } while (num != 7);  // the condition to stop the do while loop (if the user enter 7 , the menu will not appear again)
    return 0;
}