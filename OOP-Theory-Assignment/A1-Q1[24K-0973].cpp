#include <iostream>
#include <string>
using namespace std;

class Student;
class Mentor;
class Sport;
class Skill;


class Skill 
{
	private:
	int ID;
	string name;
	string description;

	public:

	Skill() {}

	Skill(int ID, string name, string d) 
	{ 
		this->ID = ID;
		this->name = name;
		this->description = d;
	}

	void showSkillDetails()
	{
		cout << "\nSkill ID: " << ID << endl;
		cout << "Skill Name: " << name << endl;
		cout << "Description: " << description << endl;
	}

	void updateSkillDescription(string d) 
	{
		description = d;
		cout << "\nSkill description updated.\n";
	}

	int getSkillID() 
	{
		return ID;
	}

	string getName() 
	{
		return name;
	}

	string getDescription() 
	{
		return description;
	}
};

class Sport 
{
private:
	int ID;
	string name;
	string description;
	Skill requiredSkills[3];
	int skillCount;

public:

	Sport(int id, string n, string d) 
	{
		ID = id;
		name = n;
		description = d;
		skillCount = 0;
	}

	Sport() {}

	string get_name() 
	{
		return name;
	}

	void addSkill(Skill s) 
	{
		if (skillCount < 3) {
			requiredSkills[skillCount] = s;
			skillCount++;
			cout << "\nSkill added to " << name << endl;
		} else {
			cout << "\nCannot add more skills" << endl; 
		}
	}

	void removeSkill(int sID) 
	{
		for (int i = 0; i < skillCount; i++) 
		{
			if (requiredSkills[i].getSkillID() == sID) 
			{
				for (int j = i; j < skillCount - 1; j++) 
				{
					requiredSkills[j] = requiredSkills[j + 1];
				}
				skillCount--;
				cout << "Skill removed." << endl;
				return;
			}
		}
		cout << "\nSkill not found." << endl;
	}

	void showSportDetails() 
	{
		cout << "\nSport ID: " << ID << endl;
		cout << "Name: " << name << endl;
		cout << "Description: " << description << endl;
		cout << "Required Skills: " << endl;
		for (int i = 0; i < skillCount; i++) 
		{
			requiredSkills[i].showSkillDetails();
		}
	}

	int getSportID() 
	{
		return ID;
	}
};

class Mentor 
{
private:
	int mentorID;
	string name;
	Sport sportsExpertise[3];
	int expertiseCount;
	int maxLearners;
	Student* assignedLearners[5];
	int learnerCount;

public:
	Mentor() {
		mentorID = 0;
		name = "Unknown Mentor";
		maxLearners = 5;
		learnerCount = 0;
		expertiseCount = 0;
		for (int i = 0; i < 5; i++) 
		{
			assignedLearners[i] = 0;
		}
	}

	Mentor(int id, string N, Sport expertise[], int max, int e, int l) 
	{
		mentorID = id;
		name = N;
		maxLearners = max;
		learnerCount = l;
		expertiseCount = e;
		for (int i = 0; i < expertiseCount; i++) 
		{
			sportsExpertise[i] = expertise[i];
		}
		for (int i = 0; i < learnerCount; i++) 
		{
			assignedLearners[i] = 0;
		}
	}

	void display()
	{
		cout << "\nMentor Id: " << mentorID << endl << "Mentor Name: " << name << endl;
		for (int i = 0; i < expertiseCount; i++) 
		{
			cout << "Mentor expertise " << i + 1 << ":" << sportsExpertise[i].get_name() << endl;
		}
	}
	void assignLearner(Student* s) 
	{
		if (learnerCount < maxLearners) 
		{
			assignedLearners[learnerCount++] = s;
			cout << "Student assigned to mentor." << endl;
		}
		else 
		{
			cout << "Cannot assign more learners." << endl;
		}
    }

    void removeLearner(Student* s) 
	{
        for (int i = 0; i < learnerCount; i++) 
		{
            if (assignedLearners[i] == s) 
			{
                for (int j = i; j < learnerCount - 1; j++) 
				{
                    assignedLearners[j] = assignedLearners[j+1];
                }
                learnerCount--;
                cout << "Student removed!" << endl;
                return;
            }
        }
        cout << "Student not found!" << endl;
    }

	void provideGuidance() 
	{

        cout << "Mentor " << name << " provides guidance." << endl;

    }

	string get_name() 
	{
		return name;
	}

	void viewLearners();
};

class Student 
{

	private:
	int studentID;
	string name;
	int age;
	Sport sportsInterest[3];
	int interestCount;
	Mentor* mentorAssigned;

	public:
	Student() 
	{
		studentID = 0;
		name = "Unknown Student";
		age = 0;
		interestCount = 0;
		for (int i = 0; i < 3; i++)
		{
			sportsInterest[i] = Sport();
		}
	}

	Student(int id, string n, int a, int c, Mentor *m) 
	{
		studentID = id;
		name = n;
		age = a;
		interestCount = c;
		mentorAssigned = m;
		for (int i = 0; i < interestCount; i++) 
		{
			sportsInterest[i] = Sport();
		}
	}


    void display()
	{
        cout << "\nStudent's ID: " << studentID << endl;
        cout << "Student's Name: " << name << endl;
        cout << "Age: " << age << endl;
    }

	void registerForMentorship(Mentor *m) 
	{
		cout << "registering for mentorship under " << m->get_name() << endl;
		mentorAssigned = m;
	}
	void viewMentorDetails() 
	{

		mentorAssigned->display();

	}

    string getName()
    {
        return name;
    }
};

void Mentor::viewLearners() 
{
    if (learnerCount == 0) 
	{
        cout << "No learners assigned." << endl;
        return;
    }
    for (int i = 0; i < learnerCount; i++) 
	{
        if (assignedLearners[i] != nullptr) 
		{
            assignedLearners[i]->display();
        } 
		else
		{
            cout << "Learner at index " << i << " is nullptr." << endl;
        }
    }
}

int main() 
{
	cout << "\nName: Talha Mirza" << endl;
	cout << "24K-0973\n" << endl;

    Skill skill1(101, "Dribbling", "Essential for basketball.");
    Skill skill2(102, "Running", "Improves endurance.");
    Skill skill3(103, "Passing", "Important in team games.");

    cout << "Skills created." << endl;
    skill1.showSkillDetails();
    skill2.showSkillDetails();
    skill3.showSkillDetails();

    Sport basketball(1, "Basketball", "A team sport played with a ball.");
    Sport football(2, "Football", "A game played with a round ball.");
    Sport tennis(3, "Tennis", "A sport played with rackets and a ball.");

    cout << "\nSports created." << endl;
    basketball.showSportDetails();
    football.showSportDetails();
    tennis.showSportDetails();

    basketball.addSkill(skill1);
    basketball.addSkill(skill2);
    football.addSkill(skill2);
    football.addSkill(skill3);

    cout << "\nUpdated Sports Details:" << endl;
    basketball.showSportDetails();
    football.showSportDetails();

    Sport mentorExpertise[] = {basketball, football};
    Mentor mentor1(201, "Coach Ali", mentorExpertise, 5, 2, 0);
    Mentor mentor2(202, "Coach Sara", mentorExpertise, 5, 2, 0);

    cout << "\nMentors created: " << endl;
    mentor1.display();
    mentor2.display();

    Student student1(301, "Sami", 18, 2, &mentor1);
    Student student2(302, "Nusrat", 19, 1, &mentor2);

    cout << "\nStudents created: " << endl;
    student1.display();
    student2.display();

    mentor1.assignLearner(&student1);
    mentor2.assignLearner(&student2);

    mentor1.viewLearners();
    mentor2.viewLearners();

    student1.registerForMentorship(&mentor2);
    student2.registerForMentorship(&mentor1);

    cout << "\nViewing mentor details from students: " << endl;
	
    student1.viewMentorDetails();
    student2.viewMentorDetails();

    return 0;
}


