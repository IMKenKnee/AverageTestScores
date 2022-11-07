//Kenny Hedlund
//Sort a dynamic array of names and test scores using a structure

#include <iostream>
#include <string>
using std::string;

struct Data
{
	string name;
	double score;
};

class Dyno
{
private:
	int numStudents;			//number of students
	Data* studentData;			//pointer to dynamic array
	double avg;					//calculated average

	void userPrompt();
	void allocate();
	void populate();
	void validate();
	void display();

public:
	void driver();
};

/****************************************methods****************************************/

//Dyno: userPrompt
//prompt the user for the number of students
void Dyno::userPrompt()
{
	using std::cout;
	using std::endl;
	using std::cin;

	cout << "Enter the number of the students: ";
	cin >> numStudents;

	//validate
	validate();
}

//Dyno: validate
//validate user input
void Dyno::validate()
{
	using std::cout;
	using std::cin;
	using std::endl;

	while (!cin || numStudents <= 0)
	{
		cout << "invalid input, positive integers only: ";
		fseek(stdin, 0, SEEK_END);			//clear buffer
		cin.clear();						//reset to a good read
		cin >> numStudents;
	}
}

//Dyno: allocate
//dynamically allocate an array with with numStudents number of students
void Dyno::allocate()
{
	studentData = new Data[numStudents];
}

//Dyno: populate
//populate the dynamic array
void Dyno::populate()
{
	using std::cout;
	using std::cin;
	using std::endl;

	Data* p = studentData;

	for (int i = 0; i < numStudents; i++)
	{
		cout << "Enter a name: ";
		getline(cin, p->name);

		//validate
		while (p->name.length() == 0)
		{
			cout << "You must enter a name: ";
			getline(cin, p->name);
		}

		//get student's  score
		cout << "Enter the student's score: ";
			cin >> p->score;

		//increment the pointer
		p++;
	}
}


//Dyno: display
//display the array
void Dyno::display()
{
	using std::cout;
	using std::endl;
	int studentSum = 0;
	int studentAmt = 0;
	double avg = 0;

	Data* p = studentData;

	for (int i = 0; i < numStudents; i++)
	{
		cout << endl << "Name = " << p->name << endl;
		cout << "score = " << p->score << endl;

		studentSum += p->score;

		//increment the pointer
		p++;

		studentAmt++;

		avg = studentSum / studentAmt;
	}

	cout << endl << "//////////////////////////////////////////////" << endl
		 << "The average testing score for the class is %" << avg << "." << endl
		 << "//////////////////////////////////////////////" << endl;
}

//Dyno: driver
//order of execution
void Dyno::driver()
{
	userPrompt();
	allocate();
	populate();
	display();
}

/*************************************main*************************************/
int main()
{
	Dyno dynoObj;

	dynoObj.driver();

	return 0;
}