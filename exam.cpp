#include <iostream>
#include<string.h>
using namespace std;
struct list
{
	char name[20];
	int priority;
	char description[50];
	int day;
	int month;
	int year;
};
list Fill();
list* Add(list* list, int data_size);
list* Delete(list* data, int data_size, int index);
list* Edit(list* data, int data_size, int index);
void Show(list data_array, int data_size);
void NameSearch(list data_array, char choice[]);
void PrSearch(list data_array, int choice);
void DesSearch(list data_array, char choice[]);
void DateSearch(list data_array, int choice);
list* Sort(list* data, int data_size);




int main() {
	list* data = nullptr;
	int data_size = 0;
	string command;
	cout << "Command list: name(search), priority(search), description(search), date(search), add, delete, show, sort, end.\n";
	cin >> command;
	while (command != "end") {
		if (command == "name") {
			char choice[20];
			cout << "Enter name: ";
			cin >> choice;
			for (int i = 0; i < data_size; i++)
			{
				NameSearch(data[i], choice);
			}
			cout << endl;
		}
		if (command == "priority") {
			int choice;
			cout << "Enter priority: ";
			cin >> choice;
			for (int i = 0; i < data_size; i++)
			{
				PrSearch(data[i], choice);
			}
			cout << endl;
		}
		if (command == "description") {
			char choice[20];
			cout << "Enter description: ";
			cin >> choice;
			for (int i = 0; i < data_size; i++)
			{
				DesSearch(data[i], choice);
			}
			cout << endl;
		}
		if (command == "date") {
			int choice;
			cout << "Enter date: ";
			cin >> choice;
			for (int i = 0; i < data_size; i++)
			{
				DateSearch(data[i], choice);
			}
			cout << endl;
		}
		if (command == "add") {
			++data_size;
			data = Add(data, data_size);
		}
		if (command == "delete") {
			int index;
			cout << "Enter name" << endl;
			cin >> index;
			data = Delete(data, data_size, index);
		}
		if (command == "edit") {
			int index;
			cout << "Enter index" << endl;
			cin >> index;
			data = Edit(data, data_size, index);
		}
		if (command == "sort") {
			data = Sort(data, data_size);
		}
		if (command == "show") {
			int choice;
			string choice_sort;
			cout << "Enter date" << endl;
			cin >> choice;
			for (int i = 0; i < data_size; i++)
			{
				Show(data[i], choice);
			}
			cout << endl;
		}
		cin >> command;
	}
	return 0;
}




template <class T>
list* Sort(list* data, int data_size) {
	string command;
	cout << "How you wont sort? (priority,date)" << endl;
	cin >> command;
	if (command == "priority") {
		long i, j;
		T x;
		for (i = 0; i < data_size; i++) {
			for (j = data_size - 1; j > i; j--) {
				if (data.priority[j - 1] > data.priority[j]) {
					x = data.priority[j - 1];
					data.priority[j - 1] = data.priority[j];
					data.priority[j] = x;
				}
			}
		}
		return x;
	}
	if (command == "date") {
		string command1;
		cout << "day,month or year?" << endl;
		cin >> command1;
		if (command1 == "day") {
			long i, j;
			T x;
			for (i = 0; i < data_size; i++) {
				for (j = data_size - 1; j > i; j--) {
					if (data.day[j - 1] > data.day[j]) {
						x = data.day[j - 1];
						data.day[j - 1] = data.day[j];
						data.day[j] = x;
					}
				}
			}
			return x;
		}
		if (command1 == "month") {
			long i, j;
			T x;
			for (i = 0; i < data_size; i++) {
				for (j = data_size - 1; j > i; j--) {
					if (data.month[j - 1] > data.month[j]) {
						x = data.month[j - 1];
						data.month[j - 1] = data.month[j];
						data.month[j] = x;
					}
				}
			}
			return x;
		}
		if (command1 == "year") {
			long i, j;
			T x;
			for (i = 0; i < data_size; i++) {
				for (j = data_size - 1; j > i; j--) {
					if (data.year[j - 1] > data.year[j]) {
						x = data.year[j - 1];
						data.year[j - 1] = data.year[j];
						data.year[j] = x;
					}
				}
			}
			return x;
		}
	}
	
}




list Fill() {
	list thing;
	cout << "Name - ";
	cin >> thing.name;
	cout << "Priority(1,2...) - ";
	cin >> thing.priority;
	cout << "Description - ";
	cin >> thing.description;
	cout << "Day - ";
	cin >> thing.day;
	cout << "Month - ";
	cin >> thing.month;
	if (thing.month > 12) {
		cout << "Error" << endl;
		cout << "Month - ";
		cin >> thing.month;
	}
	cout << "Year - ";
	cin >> thing.year;
	if (thing.year > 2021 || thing.year < 1931) {
		cout << "Error" << endl;
		cout << "Year - ";
		cin >> thing.year;
	}
	return thing;
}

list* Add(list* data_array, int data_size) {
	list* tmp = new list[data_size];
	for (int i = 0; i < data_size - 1; ++i) {
		tmp[i] = data_array[i];
	}
	tmp[data_size - 1] = Fill();
	return tmp;
}
list* Delete(list* data, int data_size, int index) {
	--data_size;
	int j = 0;
	list* new_data = new list[data_size];
	for (int i = 0; i < data_size + 1; ++i) {
		if (index == i) continue;
		new_data[i] = data[i];
		++j;
	}
	return new_data;
}
list* Edit(list* data, int data_size, int index) {
	cout << "What you want change?(name,priority,description,day,month,year) end - exit" << endl;
	string tmp;
	cin >> tmp;
	while (tmp == "end") {
		if (tmp == "name") {
			cin >> data[index].name;
		}
		else if (tmp == "priority") {
			cin >> data[index].priority;
		}
		else if (tmp == "description") {
			cin >> data[index].description;
		}
		else if (tmp == "day") {
			cin >> data[index].day;
		}
		else if (tmp == "month") {
			cin >> data[index].month;
		}
		else if (tmp == "year") {
			cin >> data[index].year;
		}
	}
	return data;
}
void Show(list data_array, int choice) {
	string choice_from_choice;
	cout << "Search from day, week(1-4) or month?";
	cin >> choice_from_choice;
	while (choice_from_choice == "end") {
		cout << "If you want exit write - end" << endl;
		if (choice_from_choice == "day") {
			if (data_array.day == choice)
			{
				cout << data_array.name << " " << data_array.priority << " " << data_array.description << " ";
			}
		}
		else if (choice_from_choice == "week") {
			if (choice == 1) {
				for (int i = 0; i < 8; i++) {
					cout << data_array.name << " " << data_array.priority << " " << data_array.description << " ";
				}
			}
			else if (choice == 2) {
				for (int i = 8; i < 16; i++) {
					cout << data_array.name << " " << data_array.priority << " " << data_array.description << " ";
				}
			}
			else if (choice == 3) {
				for (int i = 16; i < 24; i++) {
					cout << data_array.name << " " << data_array.priority << " " << data_array.description << " ";
				}
			}
			else if (choice == 4) {
				for (int i = 24; i < 32; i++) {
					cout << data_array.name << " " << data_array.priority << " " << data_array.description << " ";
				}
			}
		}
		else if (choice_from_choice == "month") {
			if (data_array.month == choice)
			{
				cout << data_array.name << " " << data_array.priority << " " << data_array.description << " ";
			}
		}
	}
}




void NameSearch(list data_array, char choice[])
{
	if (strstr(data_array.name, choice) != NULL)
	{
		cout << "Name - " << data_array.name << ", priority -  " << data_array.priority << ", description -  " << data_array.description << ", date - " << data_array.day << "." << data_array.month << "." << data_array.year << "\n\n";
	}
}
void PrSearch(list data_array, int choice)
{
	if (data_array.priority == choice)
	{
		cout << "Name - " << data_array.name << ", priority -  " << data_array.priority << ", description -  " << data_array.description << ", date - " << data_array.day << "." << data_array.month << "." << data_array.year << "\n\n";
	}
}
void DesSearch(list data_array, char choice[])
{
	if (strstr(data_array.description, choice) != NULL)
	{
		cout << "Name - " << data_array.name << ", priority -  " << data_array.priority << ", description -  " << data_array.description << ", date - " << data_array.day << "." << data_array.month << "." << data_array.year << "\n\n";
	}
}
void DateSearch(list data_array, int choice)
{
	string choice_from_choice;
	cout << "Search from day, month or year?";
	cin >> choice_from_choice;
	while (choice_from_choice == "end") {
		cout << "If you want exit write - end" << endl;
		if (choice_from_choice == "day") {
			if (data_array.day == choice)
			{
				cout << data_array.name << " " << data_array.priority << " " << data_array.description << " ";
			}
		}
		else if (choice_from_choice == "month") {
			if (data_array.month == choice)
			{
				cout << data_array.name << " " << data_array.priority << " " << data_array.description << " ";
			}
		}
		else if (choice_from_choice == "year") {
			if (data_array.year == choice)
			{
				cout << data_array.name << " " << data_array.priority << " " << data_array.description << " ";
			}
		}
	}
}