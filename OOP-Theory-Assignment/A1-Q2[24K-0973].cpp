#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class Ball {
private:
	int x_coordinate;
	int y_coordinate;
public:
	Ball() {
		x_coordinate = 0;
		y_coordinate = 0;
	}

    int GetX() 
	{
		return x_coordinate;
	}
    int GetY() 
	{
		return y_coordinate;
	}
	int& GetXbyref() 
	{
		return x_coordinate;
	}
    int& GetYbyref() 
	{
		return y_coordinate;
	}
	void SetX(int x) 
	{
		x_coordinate = x;
	}
	void SetY(int y) 
	{
		y_coordinate = y;
	}

	void displayPosition() 
	{
		cout << "Ball Position: (" << x_coordinate << ", " << y_coordinate << ")" << endl;
	}

	 void move(int dx, int dy) 
	 {
	 	int newX = x_coordinate + dx;
	 	int newY = y_coordinate + dy;
	 	if(newX < 0 || newX > 3 || newY < 0 || newY > 3) 
		{
	 		cout << "Ball cannot move outside the field boundaries!" << endl;
	 	} 
		else 
		{
	 		x_coordinate = newX; 
	 		y_coordinate = newY;
	 	}
	 }

	void getPosition()
	{
		cout << "The position of the ball: (" << x_coordinate << ", " << y_coordinate << ")" << endl;
	}
};

class Robot
{
private:
	string name;
	int hits;
public:
	Robot() 
	{
		name = "unknown";
		hits = 0;
	}
	Robot(string n, int h) 
	{
		name = n;
		hits = h;
	}

	void hitBall(int &ballX, int &ballY, const string &direction) 
	{
		string d = (direction);
		cout << "Robot " << name << " is hitting the ball " << d << "!" << endl;

		if (d == "up") {
			if (ballY == 3) 
			{
				cout << "Cannot move up. Reached end of field." << endl;;
			} 
			else 
			{
				cout << "Moving Up!" << endl;
				ballY++;
				hits++;
			}
		}
		else if (d == "down") 
		{
			if (ballY == 0) 
			{
				cout << "Cannot move down. Reached end of field." << endl;
			} 
			else 
			{
				cout << "Moving Down!" << endl;
 				ballY--;
				hits++;
			}
		}
		else if (d == "left") 
		{
			if (ballX == 0) 
			{
				cout << "Cannot move left. Reached end of field." << endl;
			} 
			else 
			{
				cout << "Moving Left!" << endl;
				ballX--;
				hits++;
			}
		}
		else if (d == "right")
		{
			if (ballX == 3) 
			{
				cout << "Cannot move right. Reached end of field." << endl;
			} 
			else 
			{
				cout << "Moving Right!" << endl;
				ballX++;
				hits++;
			}
		}
		else 
		{
			cout << "Invalid direction!" << endl;
		}
	}

	int gethits() 
	{
		return hits;
	}
};

class Team 
{
private:

	string Name;
	Robot *r;
public:

	Team(string n, string robotName) 
	{
		Name = n;
		r = new Robot(robotName, 0);
	}
	string getname() 
	{
		return Name;
	}

	~Team() 
	{
		delete r;
	}
	Robot* getRobot() 
	{
		return r;
	}
};

class Goal 
{
	private:
	int x, y;

	public:

	Goal() 
	{
		x = 3;
		y = 3;
	}

	bool isGoalReached(int ballX, int ballY) 
	{
		return ballX == x && ballY == y;
	}
};

class Game 
{
	private:
	Team* teamOne;
	Team* teamTwo;
	Ball* ball;
	Goal* goal;

	public:
	Game(Team* t1, Team* t2, Ball* b, Goal* g) 
	{
		teamOne = t1;
		teamTwo = t2;
		ball = b;
		goal = g;
	}

	void play(Team* team) 
	{
		while (!goal->isGoalReached(ball->GetX(), ball->GetY()))
		{
			string direction;
			cout << "Enter direction (up, down, left, right) for " << team->getname() << ": ";
			cin >> direction;
            int& ballX = ball->GetXbyref();
            int& ballY = ball->GetYbyref();
			team->getRobot()->hitBall(ballX, ballY, direction);
			ball->displayPosition();
		}
		cout << team->getname() << " reached the goal in " << team->getRobot()->gethits() << " hits." << endl;
		ball->SetX(0);
		ball->SetY(0);
	}

	void declareWinner() 
	{
		int hits1 = teamOne->getRobot()->gethits();
		int hits2 = teamTwo->getRobot()->gethits();

		if (hits1 < hits2) {
			cout << teamOne->getname() << " wins!" << endl;
		} else if (hits1 > hits2) {
			cout << teamTwo->getname() << " wins!" << endl;
		} else {
			cout << "It's a tie!" << endl;
		}
	}

	void startGame() 
	{
		play(teamOne);
		play(teamTwo);
		declareWinner();
	}

};

int main() 
{
    
	cout << "Name: Talha Mirza" << endl;
	cout << "24K-0973\n" << endl;

	cout << "\n----- GAME BEGINS -----" << endl;

    Team t1("Team Fast", "Ronaldo");
    Team t2("Team IBA", "Shaheen Afridi");
    Ball ball;
    Goal goal;
    Game game(&t1, &t2, &ball, &goal);
    game.startGame();

	cout << "----- GAME ENDS -----" << endl;

    return 0;
}