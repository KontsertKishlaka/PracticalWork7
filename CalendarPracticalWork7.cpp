#include <iostream>
#include <map>

using namespace std;

enum Month
{
	January = 1,
	February,
	March,
	April,
	May,
	June,
	July,
	August,
	September,
	October,
	November,
	December
};

map<Month, string> _coloredMonths 
{ 
	{January, "\x1b[94mЯнварь\x1b[0m\n"},
	{February, "\x1b[94mФевраль\x1b[0m\n"},
	{March, "\x1b[92mМарт\x1b[0m\n"},
	{April, "\x1b[92mАпрель\x1b[0m\n"},
	{May, "\x1b[92mМай\x1b[0m\n"},
	{June, "\x1b[91mИюнь\x1b[0m\n"},
	{July, "\x1b[91mИюль\x1b[0m\n"},
	{August, "\x1b[91mАвгуст\x1b[0m\n"},
	{September, "\x1b[93mСентябрь\x1b[0m\n"},
	{October, "\x1b[93mОктябрь\x1b[0m\n"},
	{November, "\x1b[93mНоябрь\x1b[0m\n"},
	{December, "\x1b[94mДекабрь\x1b[0m\n"}
};

string getSelectedMonth(short monthIndex);
short getSelectedDay(short monthIndex, short dayIndex);


void printStartInterface() {
	for (const auto& month : _coloredMonths)
		cout << "[" << (short)month.first << "] " << month.second;
}


void userInput() {
	short monthIndex;
	short dayIndex;

	cout << "\nВыберете номер месяца (от 1 до 12): ";
	cin >> monthIndex;
	
	if (monthIndex < 1 || monthIndex > 12) {
		cout << "\x1b[31mНе правильно введен номер месяца!\x1b[0m\n";
		return;
	}

	string selectedMonthString = getSelectedMonth(monthIndex);

	cout << "\n[+] Выбран месяц - " << selectedMonthString;

	cout << "\nВыберете день месяца: ";
	cin >> dayIndex;

	short selectedDayString = getSelectedDay(monthIndex, dayIndex);

	system("cls");

	cout << "\n[+] Календарь: " << selectedDayString << " " << selectedMonthString;
}


string getSelectedMonth(short monthIndex) {
	switch (monthIndex)
	{
	case Month::January:
		return _coloredMonths[January];
	case Month::February:
		return _coloredMonths[February];
	case Month::March:
		return _coloredMonths[March];
	case Month::April:
		return _coloredMonths[April];
	case Month::May:
		return _coloredMonths[May];
	case Month::June:
		return _coloredMonths[June];
	case Month::July:
		return _coloredMonths[July];
	case Month::August:
		return _coloredMonths[August];
	case Month::September:
		return _coloredMonths[September];
	case Month::October:
		return _coloredMonths[October];
	case Month::November:
		return _coloredMonths[November];
	case Month::December:
		return _coloredMonths[December];
	}

	return "";
}


short getSelectedDay(short monthIndex, short dayIndex) {
	switch (monthIndex) {
	case Month::January:
		if (dayIndex > 0 && dayIndex < 32)
			return dayIndex;
		else {
			cout << "\nВведите число от 1 до 31";
			break;
		}
	case Month::February:
		if (dayIndex > 0 && dayIndex < 29)
			return dayIndex;
		else {
			cout << "\nВведите число от 1 до 28";
			break;
		}
	case Month::March:
		if (dayIndex > 0 && dayIndex < 32)
			return dayIndex;
		else {
			cout << "\nВведите число от 1 до 31";
			break;
		}
	case Month::April:
		if (dayIndex > 0 && dayIndex < 31)
			return dayIndex;
		else {
			cout << "\nВведите число от 1 до 30";
			break;
		}
	case Month::May:
		if (dayIndex > 0 && dayIndex < 32)
			return dayIndex;
		else {
			cout << "\nВведите число от 1 до 31";
			break;
		}
	case Month::June:
		if (dayIndex > 0 && dayIndex < 31)
			return dayIndex;
		else {
			cout << "\nВведите число от 1 до 30";
			break;
		}
	case Month::July:
		if (dayIndex > 0 && dayIndex < 32)
			return dayIndex;
		else {
			cout << "\nВведите число от 1 до 31";
			break;
		}
	case Month::August:
		if (dayIndex > 0 && dayIndex < 32)
			return dayIndex;
		else {
			cout << "\nВведите число от 1 до 31";
			break;
		}
	case Month::September:
		if (dayIndex > 0 && dayIndex < 31)
			return dayIndex;
		else {
			cout << "\nВведите число от 1 до 30";
			break;
		}
	case Month::October:
		if (dayIndex > 0 && dayIndex < 32)
			return dayIndex;
		else {
			cout << "\nВведите число от 1 до 31";
			break;
		}
	case Month::November:
		if (dayIndex > 0 && dayIndex < 31)
			return dayIndex;
		else {
			cout << "\nВведите число от 1 до 30";
			break;
		}
	case Month::December:
		if (dayIndex > 0 && dayIndex < 32)
			return dayIndex;
		else {
			cout << "\nВведите число от 1 до 31";
			break;
		}
	}

	return 0;
}


bool checkStopUserInput() {
	cout << "\nВведите \x1b[91m\"+\"\x1b[0m, чтобы перезапустить календарь или \x1b[91m\"-\"\x1b[0m, чтобы завершить программу.\n";

	char userInpuntChar;
	cin >> userInpuntChar;

	while (userInpuntChar == '+' || userInpuntChar == '-') {
		switch (userInpuntChar) {
		case '+':
			system("cls");
			return true;
		case '-':
			return false;
		default:
			cout << "\nВведён некорректный символ, повторите ввод.";
			break;
		}
	}

	return true;
}


int main() {
	setlocale(0, "");

	do {
		printStartInterface(); 
		userInput();
	} while (checkStopUserInput());

	return 0;
}