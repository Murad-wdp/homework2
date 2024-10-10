#include <iostream>
#include <string>

using namespace std;

class User {
private:
	string _fullName;
	string _email;
	int _age;
	float _height;

public:
	User() {};

	User(string fullName, string email, int age, float height) {
		SetFullName(fullName);
		SetEmail(email);
		SetAge(age);
		SetHeight(height);
	}

	void SetFullName(const string fullName) {
		_fullName = fullName;
	}

	void SetEmail(const string email) {
		_email = email;
	}

	void SetAge(int age) {
		if (age >= 0) {
			_age = age;
		}
		else {
			cout << "Yaþ 0 dan boyuk olmalidir." << endl;
		}
	}

	void SetHeight(float height) {
		_height = height;
	}

	string GetFullName() const {
		return _fullName;
	}

	string GetEmail() const {
		return _email;
	}

	int GetAge() const {
		return _age;
	}

	float GetHeight() const {
		return _height;
	}

	void ShowUser() const {
		cout << "Adi: " << _fullName << endl;
		cout << "Mail: " << _email << endl;
		cout << "Yas: " << _age << endl;
		cout << "Boy: " << _height << endl;
	}

	static void ManageUsers(User** users, int userCount) {
		int choice;
		do {
			cout << "1. Useri elave et\n2. Useri Goster\n3. Useri Sil\n4. Cixis\nSeciminiz: ";
			cin >> choice;

			switch (choice) {
			case 1: {
				string fullName, email;
				int age;
				float height;

				cout << "Adi: ";
				cin.ignore();
				getline(cin, fullName);
				cout << "Mail: ";
				cin >> email;
				cout << "Yas: ";
				cin >> age;
				cout << "Boy: ";
				cin >> height;

				users[userCount++] = new User(fullName, email, age, height);
				cout << "User elave olundu.\n";
				break;
			}
			case 2:
				for (int i = 0; i < userCount; i++) {
					users[i]->ShowUser();
					cout << "--------------------------\n";
				}
				break;
			case 3: {
				string fullName;
				cout << "Silinecek userin adi: ";
				cin.ignore();
				getline(cin, fullName);
				for (int i = 0; i < userCount; i++) {
					if (users[i]->GetFullName() == fullName) {
						delete users[i];
						users[i] = users[userCount - 1];
						userCount--;
						cout << "User silindi.\n";
						break;
					}
				}
				break;
			}
			
			case 4:
				cout << "Cixis edildi..\n";
				break;
			default:
				cout << "Secimde sehvlik var\n";
			}
		} while (choice != 4);
	}
};

int main() {
	const int maxUsers = 100;
	User** users = new User * [maxUsers];
	int userCount = 0;

	User::ManageUsers(users, userCount);

	for (int i = 0; i < userCount; i++) {
		delete users[i];
	}
	delete[] users;

	return 0;
}
