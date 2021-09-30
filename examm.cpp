#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct song
{
	char name[25];
	char author[25];
	int year;
	string text_song;
};
song Fill();
song* Add(song* list, int data_size);
song* Delete(song* data, int data_size, int index);
void ASearch(song data_array, int data_size, char choice[]);
void WSearch(song data_array, int data_size, char choice[]);
song* Edit(song* data, int data_size, int index);


int main() {
	song* data = nullptr;
	int data_size = 0;
	string command;
	cout << "Command list: author(search), word(search), add, delete, show, edit, save(song in file), end.\n";
	cin >> command;
	while (command != "end") {
		if (command == "add") {
			++data_size;
			data = Add(data, data_size);
		}
		if (command == "delete") {
			int index;
			cout << "Enter index" << endl;
			cin >> index;
			data = Delete(data, data_size, index);
		}
		if (command == "edit") {
			int index;
			cout << "Enter index" << endl;
			cin >> index;
			data = Edit(data, data_size, index);
		}
		if (command == "save") {
			int i = 0;
			string name_file;
			cout << "Enter way to file" << endl;
			cin >> name_file;
			ofstream output(name_file);
			output << data_size << endl;
			for (int i = 0; i < data_size; ++i) {
				output << data[i].text_song << endl;
			}
		}
		if (command == "show") {
			for (int i = 0; i < data_size; i++)
			{
				cout << "Name - " << data[i].name << ", author - " << data[i].author << ", year - " << data[i].year << ", song - " << data[i].text_song << "\n\n";
			}
			cout << endl;
		}
		if (command == "author") {
			char choice[25];
			cout << "Enter author: ";
			cin >> choice;
			for (int i = 0; i < data_size; i++)
			{
				ASearch(data[i], data_size, choice);
			}
			cout << endl;
		}
		if (command == "word") {
			char choice[15];
			cout << "Enter word: ";
			cin >> choice;
			for (int i = 0; i < data_size; i++)
			{
				WSearch(data[i], data_size, choice);
			}
			cout << endl;
		}
		cin >> command;
	}
	return 0;
}









song Fill() {
	song thing;
	cout << "Name - ";
	cin >> thing.name;
	cout << "Author - ";
	cin >> thing.author;
	cout << "Year - ";
	cin >> thing.year;
	if (thing.year > 2021 || thing.year < 1931) {
		cout << "Error" << endl;
		cout << "Year - ";
		cin >> thing.year;
	}
	cout << "How you enter text of song, from 'keyboard' or 'file'?" << endl;
	string command1;
	cin >> command1;
	if (command1 == "keyboard") {
		cout << "Go: ";
		cin >> thing.text_song;
	}
	else if (command1 == "file") {
		string name_file;
		cout << "Enter way to file" << endl;
		cin >> name_file;
		ifstream input(name_file);
		while (getline(input, thing.text_song)) {
			cout << thing.text_song << endl;
		}
	}
	return thing;
}
song* Edit(song* data, int data_size, int index) {
	cout << "What you want change?(name,author,year,text) end - exit" << endl;
	string tmp;
	cin >> tmp;
	while (tmp == "end") {
		if (tmp == "name") {
			cin >> data[index].name;
		}
		else if (tmp == "author") {
			cin >> data[index].author;
		}
		else if (tmp == "year") {
			cin >> data[index].year;
		}
		else if (tmp == "text") {
			cin >> data[index].text_song;
		}
	}
	return data;
}
song* Add(song* data_array, int data_size) {
	song* tmp = new song[data_size];
	for (int i = 0; i < data_size - 1; ++i) {
		tmp[i] = data_array[i];
	}
	tmp[data_size - 1] = Fill();
	return tmp;
}
song* Delete(song* data, int data_size, int index) {
	--data_size;
	int j = 0;
	song* new_data = new song[data_size];
	for (int i = 0; i < data_size + 1; ++i) {
		if (index == i) continue;
		new_data[j] = data[i];
		++j;
	}
	return new_data;
}
void ASearch(song data_array, int data_size, char choice[])
{
	for (int i = 0; i < data_size; ++i) {
		if (strstr(data_array.author, choice) != NULL)
		{
			cout << "Song - " << data_array.text_song << "\n\n";
		}
	}
}
void WSearch(song data_array, int data_size, char choice[])
{
	for (int i = 0; i < data_size; ++i) {
		if (data_array.text_song == choice)
		{
			cout << "Song - " << data_array.text_song << "\n\n";
		}
	}
}