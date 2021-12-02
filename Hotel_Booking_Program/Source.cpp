/* Hotel Booking Application */
/* Section 003 */
/* Created by Mekhrol Bazarov(U2010046), Jushkinbek Bekniyozov(U2010047), Abdulaziz Akhmedov(U2010027)*/

#include <iostream>
#include <typeinfo>
using namespace std;

class AllEngine {
private:
	int AllRooms[4][10] = {};
	string AllNames[4][10] = {};

public:
	void AvailableRooms() {

		// If all rooms booked, there is no room for booking
		/*for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 10; j++) {
				AllRooms[i][j] = 1;
			}
		}*/
		

		string floor = "FLOOR ";
		string room = "Room ";

		for (int i = 0; i < 37; i++) {
			if (i == 0) {
				cout << "   ";
			}
			cout << "--";
		}
		cout << "\n                         A v a i l a b l e    R o o m s                         " << endl;
		for (int i = 0; i < 37; i++) {
			if (i == 0) {
				cout << "   ";
			}
			cout << "--";
		}
		cout << endl;
		for (int j = 1; j <= 4; j++) {
			cout << "        " << floor << j << "    ";
		}
		cout << endl;
		for (int i = 0; i < 37; i++) {
			if (i == 0) {
				cout << "   ";
			}
			cout << "--";
		}
		cout << endl;
		// ----------------------booked
		for (int i = 0; i < 10; i++) {
			int a = i + 1;
			for (int j = 0; j < 4; j++) {
				string preSpace = "        ";
				string lastSpace = "     ";
				if (i == 9) {
					lastSpace = "    ";
				}
				if (AllRooms[j][i] == 1) {
					lastSpace = " (Booked)";
				}

				if (AllRooms[j - 1][i] == 1) {
					preSpace = "    ";
					if (i == 9 && j != 0) {
						preSpace = "   ";
					}
				}
				
				if (i == 7 && j == 0) {
					preSpace = "        ";
				}				
				cout << preSpace << room << a << lastSpace;
				
			}
			cout << endl;
			for (int i = 0; i < 37; i++) {
				if (i == 0) {
					cout << "   ";
				}
				cout << "--";
			}
			cout << endl;
		}
	}
	void BookingNewRoom() {
		string name;
		char offBook = 0; // 
		int fl = 0, ro = 0;
		int count1 = 0;

		//---------------------If no free room, print go to other hotel----------------
		AvailableRooms(); // overriding 
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 10; j++) {
				if (AllRooms[i][j] == 0) {
					count1++;
				}
			}
		}
		if (count1 == 0) {
			cout << "\n   There is no free room in our hotel, go to other Hotel." << endl;
		}
		//-----------------------------------------------------------------------------
		else {
			cout << "\n   BOOKING DETAILS" << endl;
			cout << "   Your name: ";
			cin >> name;
			cout << endl;
			cout << "   Which room (Floor, Room): ";
			cin >> fl;  // 4
			cin >> ro;  // 5

			if (fl <= 4 && ro <= 10) {
				if (AllRooms[fl - 1][ro - 1] == 0) {
					AllNames[fl - 1][ro - 1] = name;
					AllRooms[fl - 1][ro - 1] = 1;
					cout << "\n   This room is reserved for you.\n   Have a pleasant rest!" << endl;
				} else if (AllRooms[fl - 1][ro - 1] == 1) {
					cout << "   This room is already occupied.\n   Look for our other rooms. " << endl;
					//----------------------------------For offer booking-------------------------------------------
					for (int i = 0; i < 4; i++) {
						for (int j = 0; j < 10; j++) {
							if (AllRooms[i][j] == 0) {
								cout << "   We can offer you " << "Floor " << i + 1 << ", Room " << j + 1 << endl;
								cout << "\n   Do you want to book it? (Y/N): ";
								cin >> offBook;
								while (offBook == 'Y' || offBook == 'y') {
									AllNames[i][j] = name;
									AllRooms[i][j] = 1;
									cout << "\n   This room is reserved for you.\n   Have a pleasant rest!" << endl;
									break;
								}
								return;
							}
						}
					}
					//---------------------------------------------------------------------------------------------
				}
			} else {
				cout << "   We only have 4 floors and 10 rooms on each floor.\n   Thank you!" << endl;
			}
		}
	}
	// Mehrol up
	void CheckCustomerDetails() {
		int count = 0;
		string name;
		
		cout << "   Enter your name: ";
		cin >> name;

		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 4; j++) {
				if (AllNames[j][i] == name) {
					count = 1;
					cout << "   You have Floor " << j + 1 << ", Room " << i + 1 << endl;
				}
			}
		}
		if (count == 0) {
			cout << "   There is no room reserved for you!" << endl;
		}
	}
	void EditOrders() { 
		int f = 0, r = 0;
		int count = 0;
		int changeOp = 0;
		string name;
		int newI = 0;
		int newJ = 0;

		cout << "   Your name: ";
		cin >> name;

		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 4; j++) {
				if (AllNames[j][i] == name) {
					count = 1;
					newI = i;
					newJ = j;
					cout << "   You have Floor " << j + 1 << ", Room " << i + 1 << endl;
				}
			}
		}
		if (count == 0) {
			cout << "   There is no room reserved for you!" << endl;
		}
		if (count != 0) {
			cout << "\n   1. Delete all details\n   2. Change room\n   3. Book in another person's name\n   4. Back to menu" << endl;
			cout << "\n   Select: ";
			cin >> changeOp;
		}
		switch (changeOp) {
		case 1: {
			AllNames[newJ][newI] = "0";
			AllRooms[newJ][newI] = 0;
			cout << "\n   Deleted successfully" << endl;
			break;
		}
		case 2: {
			cout << "\n   Choose new room." << endl;
			AvailableRooms();
			cout << "   Which room (Floor, Room): ";
			cin >> f;
			cin >> r;
			if ((f <= 4 && r <= 10)) {
				if (AllRooms[f - 1][r - 1] == 0) {
					cout << "\n   This room is reserved for you.\n   Have a pleasant rest!" << endl;
					AllNames[newJ][newI] = "0";
					AllRooms[newJ][newI] = 0;
					AllNames[f - 1][r - 1] = name;
					AllRooms[f - 1][r - 1] = 1;
				} else if (AllRooms[f - 1][r - 1] != 0) {
					cout << "\n   This room is already occupied.\n   Look for our other rooms. " << endl;
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 4; j++) {
							if (AllRooms[j][i] == 0) {
								cout << "   We can offer you " << "Floor " << j + 1 << ", Room " << i + 1 << endl;
								break;
							}
							break;
						}
						break;
					}
				}
			}
			else {
				cout << "\n   We only have 4 floors and 10 rooms on each floor.\n   Thank you!" << endl;
			}
			break;
		}
		case 3: {
			cout << "   Enter new name: ";
			cin >> name;
			AllNames[newJ][newI] = name;
			cout << "   Name changed successfully" << endl;
			break;
		}
		case 4: {
			break;
		}
		}
	}
};

int main() {
	AllEngine temp;
	system("color 30");
	int serviceType = 0;
	char backOp = 0;
	
	do {
		system("cls");
		cout << "\n         Welcome to the JAM Hotel!" << endl;
		cout << "   --------------------------------------" << endl;
		cout << "   1. Available rooms" << endl;
		cout << "   2. Booking a new room" << endl;
		cout << "   3. Checking customer details" << endl;
		cout << "   4. Editing orders" << endl;
		cout << "   --------------------------------------" << endl;
		cout << "   Select service: ";
		cin >> serviceType;

		switch (serviceType) {
		case 1: {
			cout << endl;
			temp.AvailableRooms();
			cout << "\n   Need extra service? (Y/N): ";
			cin >> backOp;
			break;
		}
		case 2: {
			cout << endl;
			temp.BookingNewRoom();
			cout << "\n   Need extra service? (Y/N): ";
			cin >> backOp;
			break;
		}
		case 3: {
			cout << endl;
			temp.CheckCustomerDetails();
			cout << "\n   Need extra service? (Y/N): ";
			cin >> backOp;
			break;
		}
		case 4: {
			cout << endl;
			temp.EditOrders();
			cout << "\n   Need extra service? (Y/N): ";
			cin >> backOp;
			break;
		}
		default: {
			cout << endl;
			cout << "   Sorry, Enter appropriate number!" << endl;
			cout << "\n   Need extra service? (Y/N): ";
			cin >> backOp;
		}
		}
	} while (backOp == 'Y' || backOp == 'y');
}
