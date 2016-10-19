#include <iostream>
#include <string>
using namespace std;

struct node
{
	string album;
	int year;
	node* next;
};

node* head = NULL;

void AddNodeBeg(string, int);
void AddNodeEnd(string, int);
void InsertNode(string, int, int);
void DeleteNode(int);
void ReverseList();
bool SearchList(string);
void PrintList();

int main()
{
	
	int amount, released, case_choice, pos;
	char again;
	string project_name;

	cout << "How Many albums are you adding to your list? ";
	cin >> amount;

	for (int i = 0; i < amount; i++)
	{
		cout << "Enter a Album Name: ";
		cin.ignore();
		getline(cin, project_name);
		cout << "Enter a Year: ";
		cin >> released;

		if (i == 0)
			AddNodeEnd(project_name, released);
		else
		{
			int BegOrEnd;
			cout << "Add to (1)beginning or (2)end: ";
			cin >> BegOrEnd;
			while (BegOrEnd < 1 || BegOrEnd > 2)
			{
				cout << "Enter 1 to add to beginning of list" << endl
					<< "Enter 2 to add to end of list " << endl;
				cin >> BegOrEnd;
			}
			switch (BegOrEnd)
			{
			case 1:
				AddNodeBeg(project_name, released);
				break;
			case 2:
				AddNodeEnd(project_name, released);
			}
		}
	}
	PrintList();

	cout << "What would you Like to do now?" << endl;

	do
	{
		cout<< "1. Insert An Album" << endl
			<< "2. Delete and Album" << endl
			<< "3. Reverse Your List" << endl
			<< "4. Search For An Album" << endl
			<< "5. Quit" << endl
			<< "Please make a choice (1-5): ";
		cin >> case_choice;
		while (case_choice < 1 || case_choice > 5)
		{
			cout << "invalid choice, Try again" << endl;
			cin >> case_choice;
		}

		switch (case_choice)
		{
		case 1:
			cout << "Enter a Album Name: ";
			cin.ignore();
			getline(cin, project_name);
			cout << "Enter a Year: ";
			cin >> released;
			cout << "Which Position would you like to insert it at: ";
			cin >> pos;
			InsertNode(project_name, released, pos);
			PrintList();
			break;
		case 2:
			cout << "Which Position would you like to delete: ";
			cin >> pos;
			DeleteNode(pos);
			PrintList();
			break;
		case 3:
			ReverseList();
			cout << "Here is Your List, Reversed: " << endl;
			PrintList();
			break;
		case 4:
			cout << "Enter An Album Name: ";
			cin.ignore();
			getline(cin, project_name);
			if (SearchList(project_name) == true)
			{
				cout << "That Album is on the list" << endl;
			}
			else
			{
				cout << "That Album is NOT on the list" << endl;
			}
			break;
		case 5:
			break;
		}

		cout << "Would you like to try something else? (Y/N)" << endl;
		cin >> again;
	} while (again == 'Y' || again == 'y');

	cout << endl;

	return 0;
}

void AddNodeEnd(string project, int release_yr)
{
	node* temp = new node();
	temp->album = project;
	temp->year = release_yr;
	temp->next = NULL; 
	if (head == NULL)
	{
		head = temp; 
	}
	else
	{
		node* temp2 = head; 
		while (temp2->next != NULL)
		{
			temp2 = temp2->next; 
		}
		temp2->next = temp; 
	}

}

void AddNodeBeg(string project, int release_yr)
{
	node* temp = new node();
	temp->album = project;
	temp->year = release_yr;
	temp->next = head; 
	head = temp; 

	
	return;
}

void InsertNode(string project, int release_yr, int place)
{
	node* temp1 = new node();
	temp1->album = project;
	temp1->year = release_yr;
	temp1->next = NULL;

	if (place == 1)
	{
		temp1->next = head;
		head = temp1; 
		return;
	}

	node* temp2 = head; 
	for (int i = 1; i < place - 1; i++)
	{
		temp2 = temp2->next;
	}
	temp1->next = temp2->next;
	temp2->next = temp1;

}

void DeleteNode(int place)
{
	node* temp1 = head;

	if (place == 1)
	{
		head = temp1->next; 
		delete temp1;
		return;
	}

	for (int i = 1; i < place - 1; i++)
	{
		temp1 = temp1->next;
	}
	node* temp2 = temp1->next; 
	temp1->next = temp2->next; 
	delete temp2;

}

void ReverseList()
{
	node *current, *prev, *next;
	current = head; 
	prev = NULL;
	while (current != NULL)
	{
		next = current->next; 
		current->next = prev; 
		prev = current; 
		current = next; 
	}

	head = prev;

}

bool SearchList(string project)
{
	node* temp = head;

	while (temp != NULL)
	{
		if (temp->album == project)
			return true;
		temp = temp->next;
	}
	return false;
}

void PrintList()
{
	node* temp = head;
	while (temp != NULL)
	{
		cout << "Album: " << temp->album << endl
			<< "Released: " << temp->year << endl
			<< endl;
		temp = temp->next;
	}
	cout << endl;
}

