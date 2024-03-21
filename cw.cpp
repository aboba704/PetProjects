#include <iostream>
#include <time.h>

using namespace std;

class Person
{
public:
	virtual void displayData() = 0;
};

class Account : public Person
{
private:
	string customerName;
	string residence;
	string socialStatus;
	int accountNumber;
	char accountType;

public:
	void inputAccountDetails()
	{
		cout << "\nEnter customer name: ";
		cin >> customerName;
		cout << "Enter area of residence: ";
		cin >> residence;
		cout << "Enter social status: ";
		cin >> socialStatus;
		if (!accountType)
		{
			cout << "Enter account type: ";
			cin >> accountType;
		}
	}
	void displayData()
	{
		cout << "\nCustomer name: " << customerName << endl;
		cout << "Area of residence: " << residence << endl;
		cout << "Social status: " << socialStatus << endl;
		cout << "Account number: " << accountNumber << endl;
		cout << "Account type: " << accountType << endl;
	}
	Account() : accountType{'\0'}, accountNumber{0}
	{
		cout << "Сработал конструктор Account без параметров" << endl;
	}
	Account(char type, int num) : accountType{type}, accountNumber{num}
	{
		cout << "Сработал конструктор Account c параметрами" << endl;
	}
	virtual ~Account()
	{
		cout << "Сработал деструктор Account" << endl;
		customerName.erase();
		residence.erase();
		socialStatus.erase();
		int accountNumber = 0;
		accountType = '\0';
	}
};

class CurrentAccount : public Account
{
private:
	float balance;

public:
	void displayData()
	{
		cout << "\nBalance: " << balance;
	}
	void makeDeposit()
	{
		float deposit;
		cout << "\nEnter amout to deposit: ";
		cin >> deposit;
		balance += deposit;
	}
	void makeWithdrawal()
	{
		float withdraw;
		cout << "\nBalance :" << balance << endl;
		cout << "Enter amount to be withdraw: ";
		cin >> withdraw;
		if (balance > 1000)
		{
			balance -= withdraw;
			cout << "Balance amount after withdrawal: " << balance << endl;
		}
		else
			cout << "Insufficient balance" << endl;
	}
	CurrentAccount() : Account(), balance{0}
	{
		cout << "Сработал конструктор CurrentAccount без параметров" << endl;
	}
	CurrentAccount(char type, int num) : Account(type, num), balance{0}
	{
		cout << "Сработал конструктор CurrentAccount с параметрами" << endl;
	}
	virtual ~CurrentAccount()
	{
		cout << "Сработал деструктор CurrentAccount" << endl;
		balance = 0;
	}
};

class SavingAccount : public Account
{
private:
	int balance;

public:
	void displayData()
	{
		cout << "\nBalance: " << balance << endl;
	}
	void makeDeposit()
	{
		float deposit, interest;
		cout << "\nEnter amount to deposit: ";
		cin >> deposit;
		balance += deposit;
		interest = (balance * 2) / 100;
		balance += interest;
	}
	void makeWithdrawal()
	{
		float withdraw;
		cout << "\nBalance: " << balance << endl;
		cout << "Enter amount to be withdraw: ";
		cin >> withdraw;
		if (balance > 500)
		{
			balance -= withdraw;
			cout << "Balance amount after withdrawal: " << balance << endl;
		}
		else
			cout << "Insufficient balance" << endl;
	}
	SavingAccount() : Account(), balance{0}
	{
		cout << "Сработал конструктор SavingAccount без параметров" << endl;
	}
	SavingAccount(char type, int num) : Account(type, num), balance{0}
	{
		cout << "Сработал конструктор SavingAccount с параметрами" << endl;
	}
	virtual ~SavingAccount()
	{
		cout << "Сработал деструктор SavingAccount" << endl;
		balance = 0;
	}
};

int main()
{
	char type;
	int choice, num;

	srand(time(NULL));
	num = 1000 + rand() % (9999 - 1000 + 1);
	cout << "Enter S for saving customer and C for current customer: ";
	cin >> type;
	cout << endl;

	if (type == 's' || type == 'S')
	{
		SavingAccount s1(type, num);
		s1.Account::inputAccountDetails();
		while (1)
		{
			cout << "\nChoose your choice:" << endl;
			cout << "1) Deposit" << endl;
			cout << "2) Withdraw" << endl;
			cout << "3) Display balance" << endl;
			cout << "4) Display with full details" << endl;
			cout << "5) Exit" << endl;
			cout << "Enter Your choice: ";
			cin >> choice;
			switch (choice)
			{
			case 1:
				s1.makeDeposit();
				break;
			case 2:
				s1.makeWithdrawal();
				break;
			case 3:
				s1.displayData();
				break;
			case 4:
				s1.displayData();
				s1.Account::displayData();
				break;
			case 5:
				goto end;
			default:
				cout << "\nEntered choice is invalid, try again!\n";
			}
		}
	}
	else if (type == 'c' || type == 'C')
	{
		CurrentAccount c1(type, num);
		c1.Account::inputAccountDetails();
		while (1)
		{
			cout << "\nChoose your choice" << endl;
			cout << "1) Deposit" << endl;
			cout << "2) Withdraw" << endl;
			cout << "3) Display balance" << endl;
			cout << "4) Display with full details" << endl;
			cout << "5) Exit" << endl;
			cout << "Enter Your choice: ";
			cin >> choice;
			switch (choice)
			{
			case 1:
				c1.makeDeposit();
				break;
			case 2:
				c1.makeWithdrawal();
				break;
			case 3:
				c1.displayData();
				break;
			case 4:
				c1.displayData();
				c1.Account::displayData();
				break;
			case 5:
				goto end;
			default:
				cout << "\n\nEntered choice is invalid,\"TRY AGAIN\"";
			}
		}
	}
	else
		cout << "\nInvalid account selection";
end:
	cout << "\nThank You for banking with us..." << endl;
	return 0;
}