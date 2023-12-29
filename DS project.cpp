// Project


#include<iostream>
#include<string>
using namespace std;
class Node
{
public:
	string name, phone_number, address;
	int id;
	float invoice;
	Node* next;

	Node() {
		next = NULL;
	}
};

bool checkRecord(Node** headPtr, int id) {
	Node* temp = *headPtr;
	if (*headPtr == NULL)
	{
		return false;
	}
	while (temp != NULL && *headPtr != NULL) {
		if (temp->id == id)
			return true;
		temp = temp->next;
	}
	return false;
}
void insertPatient(Node** headPtr, string name, int id, string phone_number, string address, float invoice) {
	Node* new_node = new Node();
	new_node->name = name;
	new_node->id = id;
	new_node->phone_number = phone_number;
	new_node->address = address;
	new_node->invoice = invoice;
	if (!checkRecord(headPtr, id)) {
		if (*headPtr == NULL) {
			(*headPtr) = new_node;

			return;
		}
		Node* temp = *headPtr;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = new_node;
		cout << "\nPatient was added successfully\n";
	}
	else {
		cout << "\nPatient already exist\n";
	}
}

void search(Node** headPtr, int ID) {
	Node* temp = *headPtr;


	if (checkRecord(headPtr, ID)) {
		while (temp != NULL) {
			if (temp->id == ID) {
				cout << "Patients record:\n- ID:" << temp->id << "\n- Name:" << temp->name << "\n- Phone number: " << temp->phone_number << "\n- Address :" << temp->address << "\n- Invoice: " << temp->invoice;
				return;
			}
			temp=temp->next;
		}

	}
	else {

		cout << "\nPatient doesn't exist";
	}
}
void deletePatient(Node** headPtr, int id) {
	if (checkRecord(headPtr, id)) {

		Node* temp = *headPtr, * prev = NULL;
		if (temp != NULL && temp->id == id) {
			*headPtr = temp->next;
		}
		else {
			while (temp != NULL && temp->id != id) {
				prev = temp;
				temp = temp->next;

			}
			prev->next = temp->next;

		}
		cout << "\nPatient was deleted successfully\n";
	}
	else {
		cout << "\nPatient doesn't exit\n";
	}
}
void updateInvoice(Node** headPtr) {

	if (*headPtr == NULL) {
		return;
	}
	Node* temp = *headPtr;
	while (temp != NULL) {
		if (temp->invoice > 100) {
			temp->invoice += (temp->invoice * .15);
		}
		else if (temp->invoice < 10) {
			temp->invoice = 0;
		}
		temp = temp->next;
	}
	cout << "\nRecords updated\n";
}
void updatePatient(Node** headPtr, int ID) {
	if (checkRecord(headPtr, ID)) {

		string name2, phone_number2, address2;
		float invoice2;
		int choose;
		Node* temp = *headPtr;
		cout << "Please choose number from the following menu: " << endl;
		cout << "1: to update name\n2: to update address\n3: to update phone number\n4: to update invoice\n5: to update all of patient data" << endl;
		cout << "Your choice is: ";
		cin >> choose;

		while (choose < 1 || choose > 5) {
			cout << "\ninvalid number!!\n";
			cin >> choose;

		}
		switch (choose)
		{
		case 1:
		while (temp!= NULL) {
		    if(temp->id == ID){
				break;
		    }else
				temp=temp->next;
			}
			cout << "please enter patient name:";
			cin >> temp->name;
			
			break;
		case 2:
		while (temp != NULL) {
				if(temp->id == ID){
				break;
		    }else
				temp=temp->next;
			}
			
			cout << "please enter patient Address:";
			cin >> temp->address;
			
			break;
		case 3:
		while (temp != NULL) {
				if(temp->id == ID){
				break;
		    }else
				temp=temp->next;
			}
			cout << "please enter patient Phone:";
			cin >> temp->phone_number;
			
			break;
		case 4:
		while (temp != NULL) {
				if(temp->id == ID){
				break;
		    }else
				temp=temp->next;
			}
			cout << "please enter patient invoice:";
			cin >> temp->invoice;
			
			break;
		case 5:
		while (temp != NULL) {
				if(temp->id == ID){
				break;
		    }else
				temp=temp->next;
			}
			
			cout << "please enter patient name:";
			cin >> temp->name;
			cout << "please enter patient Address:";
			cin >> temp->address;
			cout << "please enter patient Phone:";
			cin >> temp->phone_number;
			cout << "please enter patient invoice:";
			cin >> temp->invoice;

			break;
		default:
			cout << "\ninvalid number!!\n";
			break;
		}


		cout << "\nPatient Data Udated\n";
        

	}
	else {
		cout << "\nPatient doesn't exit\n";
	}
}
void showRecord(Node** headPtr) {
	Node* temp = *headPtr;
	int choose;
	cout << "Please choose number from the following menu: " << endl;
	cout << "1: to show one patient record \n2: to show all the records" << endl;
	cout << "Your choice is: ";
	cin >> choose;
	while (choose != 1 && choose != 2) {
		cout << "\ninvalid number!!\n";
		cin >> choose;

	}
	if(*headPtr==NULL){
	    cout << "\nthere is no record yet\n";
	}
	switch (choose)
	{
	case 1:
		int Id;
		cout << "Please enter patient id" << endl;
		cin >> Id;
		if (checkRecord(headPtr, Id)) {
			while (temp != NULL) {
				if (temp->id == Id) {
					cout << "Patients record:\n- ID:" << temp->id << "\n- Name:" << temp->name << "\n- Phone number: " << temp->phone_number << "\n- Address :" << temp->address << "\n- Invoice: " << temp->invoice << endl;
				}
				temp = temp->next;
			}
		}
		else {
			cout << "\nPatient doesn't exist";
		}
		break;
	case 2:
		while (temp != NULL) {
			cout << "Patients record:\n- ID:" << temp->id << "\n- Name:" << temp->name << "\n- Phone number: " << temp->phone_number << "\n- Address :" << temp->address << "\n- Invoice: " << temp->invoice << endl;
			temp = temp->next;
		}
		break;
	default:
		cout << "\ninvalid number!!\n";
		break;
	}


}
int main() {

	Node* head = NULL;
	string name, phone_number, address;
	int choose, id;
	float invoice;
	bool flag = true;

	do
	{
		cout << "\nPlease choose number from the following menu: " << endl;
		cout << "1: to insert patient record\n2: to delete patient record\n3: to update patient record\n4: to show patient record\n5: to search data in patient invoice\n6: to update invoice\n7: to exit\n";
		cout << "Your choice is: ";
		cin >> choose;
		switch (choose) {
		case 1:
			cout << "please enter patient name:";
			cin >> name;
			cout << "please enter patient ID:";
			cin >> id;
			cout << "please enter patient Address:";
			cin >> address;
			cout << "please enter patient Phone:";
			cin >> phone_number;
			cout << "please enter patient invoice:";
			cin >> invoice;
			insertPatient(&head, name, id, phone_number, address, invoice);
			break;
		case 2:
			cout << "please enter patinet id to delete";
			cin >> id;
			deletePatient(&head, id);
			break;
		case 3:
			cout << "please enter patinet id to update";
			cin >> id;
			updatePatient(&head, id);
			break;
		case 4:
			showRecord(&head);
			break;
		case 5:
			cout << "please enter patient id to search :";
			cin >> id;
			search(&head, id);
			break;
		case 6:
			updateInvoice(&head);
			break;
		case 7:
			flag = false;
			break;
		default:
			cout << "\ninvalid number!!\n";
		}
	} while (flag);

}