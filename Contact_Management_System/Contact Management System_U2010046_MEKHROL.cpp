/***    Full name: MEKHROL BAZAROV
        Student ID: U2010046
        Program statement: CONTACT MANAGEMENT SYSTEM ***/
#include<iostream>
using namespace std;
#include<windows.h> // system("cls") we can use this function  and also for background system("color 0A") 

// maximum contacts 100 (you can also change from arrays)

int telNumbers[100]; // integer array for saving telephone number
string Names[100], Emails[100], Birthdays[100]; //integer array for saving names. // it is a collection of characters = string
 
int k = 0; // variable shows how many contacts has in a user and during adding new contact it shows where to put contact in a array

void inputNewContact()  // user choice 1
{
    system("cls"); // it clears the information on the screen   (it clears main menu)
    int telNumber;
    string Name, Email, Birthday;
    cout << "\n\tPlease enter the details in order to add new contact" << endl;

    cout << "\tName: ";
    cin >> Name;
    Names[k] = Name;    // Names[k] names that you input it will save here

    cout << "\tTel number [9digits suggested]: ";  // only write numbers!!!
    cin >> telNumber;
    telNumbers[k] = telNumber; // telNumbers[k] tel numbers that you input it will save here

    cout << "\tEmail: ";
    cin >> Email;
    Emails[k] = Email;    // Email[k] emails that you input it will save here

    cout << "\tBirthday Format should be [dd.mm.yyyy]: ";
    cin >> Birthday;
    Birthdays[k] = Birthday;    // Email[k] emails that you input it will save here

    cout << "\n\tContact has been successfully created";
    k = k + 1;   
}

void show_contact()  // user choice 2
{   
    system("cls"); // it clears main menu function
    cout << "\n\t\t\t\t\t LIST OF MY CONTACTS";
    cout << "\n\t -------------------------------------------------------------------------------" << endl;
    cout << "\tPosition:" << "\tNames:" << "\t\tTel Numbers:";
    cout << "\tEmails:" << "\t\t\tBirthdays:"<<endl;
    for (int i = 0; i < k; i++)    
    {
        cout<<"\t"<<i<<"\t\t"<<Names[i]<<" "<<"\t" <<telNumbers[i];
        cout << "\t" << Emails[i] << "\t" << Birthdays [i] << endl;
    }

}

void delete_contact()  // user choice 3
{ 
    int pos; 
    cout << "\n\tEnter person's position in your contact list that you want to delete = ";
    cin >> pos;

    for (int i = pos; i < k; i++)     // IDEA FROM WEEK 12 video 4
    {
        Names[i] = Names[i + 1];
        telNumbers[i] = telNumbers[i + 1];  //change position
        Emails[i] = Emails[i + 1];  
        Birthdays[i] = Birthdays[i + 1];
        
    }
    k--;  
    cout << "\t\t\t\nContact has been successfully deleted";
}

void search_contact()  // user choice 4 
{
    int usersChoice2; 
    for (;;)  // you can search details by 4 options
    {         // it can help you for example if you know one of the following detail of the person you can find other details from search section   
        cout << "\n\t\t\t\t Choose one of the options";
        cout << "\n\t\t\t\t [1] Search by Name";
        cout << "\n\t\t\t\t [2] Search by Tel Number";
        cout << "\n\t\t\t\t [3] Search by Email";
        cout << "\n\t\t\t\t [4] Search by Birthday";
        cout << "\n\t\t\t\t [5] Exit from search section";
        cout << "\n\t\t\t\t Enter your choice: ";
        cin >> usersChoice2;
        if (usersChoice2 == 1)
        {
            int found = 0;
            string input_Name;
            cout << "\tEnter person that has to be searched = ";
            cin >> input_Name;

            for (int i = 0; i < k; i++)
            {
                if (Names[i] == input_Name)
                {
                    found = 1;
                    cout << "\tPosition: " << i << endl;
                    cout << "\tName: " << Names[i] << endl;
                    cout << "\tTel Number: " << telNumbers[i] << endl;
                    cout << "\tEmail: " << Emails[i] << endl;
                    cout << "\tBirthday: " << Birthdays[i] << endl;
                }
            }
            if (found == 0)
            {
                cout << "THIS Person does not exist:" << endl;
            }
            cout << endl;

        }
        else if (usersChoice2 == 2)
        {
            int found = 0;
            int input_Tel;
            cout << "\tEnter Tel Number that has to be searched = ";
            cin >> input_Tel;

            for (int i = 0; i < k; i++)
            {
                if (telNumbers[i] == input_Tel)
                {
                    found = 1;
                    cout << "\tPosition: " << i << endl;
                    cout << "\tName: " << Names[i] << endl;
                    cout << "\tTel Number: " << telNumbers[i] << endl;
                    cout << "\tEmail: " << Emails[i] << endl;
                    cout << "\tBirthday: " << Birthdays[i] << endl;
                }
            }
            if (found == 0)
            {
                cout << "THIS Number does not exist:" << endl;
            }
            cout << endl;
        }
        else if (usersChoice2 == 3)
        {
            int found = 0;
            string input_email;
            cout << "\tEnter email that has to be searched = ";
            cin >> input_email;

            for (int i = 0; i < k; i++)
            {
                if (Emails[i] == input_email)
                {
                    found = 1;
                    cout << "\tPosition: " << i << endl;
                    cout << "\tName: " << Names[i] << endl;
                    cout << "\tTel Number: " << telNumbers[i] << endl;
                    cout << "\tEmail: " << Emails[i] << endl;
                    cout << "\tBirthday: " << Birthdays[i] << endl;
                }
            }
            if (found == 0)
            {
                cout << "THIS Email does not exist:" << endl;
            }
            cout << endl;
        }
        else if (usersChoice2 == 4)
        {
            int found = 0;
            string input_birth;
            cout << "\tEnter birthday that has to be searched = ";
            cin >> input_birth;

            for (int i = 0; i < k; i++)
            {
                if (Birthdays[i] == input_birth)
                {
                    found = 1;
                    cout << "\tPosition: " << i << endl;
                    cout << "\tName: " << Names[i] << endl;
                    cout << "\tTel Number: " << telNumbers[i] << endl;
                    cout << "\tEmail: " << Emails[i] << endl;
                    cout << "\tBirthday: " << Birthdays[i] << endl;
                }
            }
            if (found == 0)
            {
                cout << "THIS Birthday does not exist:" << endl;
            }
            cout << endl;
        }
        else if (usersChoice2 == 5)
        {
        break;
        }

    }
}

void edit_contact() // user choice 5
{
    int pos, NewTel;
    string NewName, NewBirthday, NewEmail;
    cout << "\n\tEnter person's position in your contact list that you want to edit = ";
    cin >> pos;
    cout << "\tEnter a New Name: ";
    cin >> NewName;
    cout << "\tEnter a New Tel number: ";     
    cin >> NewTel;
    cout << "\tEnter a New Email: ";
    cin >> NewEmail;
    cout << "\tEnter a New Birhtday: ";
    cin >> NewBirthday;
        Names[pos] = NewName;    
        telNumbers[pos] = NewTel;
        Emails[pos] = NewEmail;
        Birthdays[pos] = NewBirthday;
// here names, numbers, emails and birthday are updated   
    cout << "\t\t\t\nContact has been successfully updated";
}

int main()
{
    int usersChoice;
    system("color 0A"); // Green words(A) and black background(0)
    for (;;)
    {
        cout << "\n\n\t\t\t\t Welcome to Contact Management System";  // \n means down to (vertical), \t means right to (horizontal)
        cout << "\n\n\t\t\t\t\t      MAIN MENU";
        cout << "\n\t\t\t\t ------------------------------------";
        cout << "\n\t\t\t\t [1] Add contact";
        cout << "\n\t\t\t\t [2] Show my contacts";
        cout << "\n\t\t\t\t [3] Delete contact";
        cout << "\n\t\t\t\t [4] Search contact";
        cout << "\n\t\t\t\t [5] Edit contact";
        cout << "\n\t\t\t\t [6] Exit";
        cout << "\n\t\t\t\t Enter your choice: ";
        cin >> usersChoice;
        if (usersChoice == 1)
        {
            inputNewContact();
        }
        else if (usersChoice == 2)
        {
            show_contact();       
        }
        else if (usersChoice == 3) 
        {
            delete_contact();
        }
        else if (usersChoice == 4) 
        {
            search_contact();
        }
        else if (usersChoice == 5)
        {
            edit_contact();
        }

        else if (usersChoice == 6) 
        {
            cout << "\n\t\t\t\t THANKS FOR USING MEKHROL'S CMS!" << endl;
            break;
        }  
    } 
}
 