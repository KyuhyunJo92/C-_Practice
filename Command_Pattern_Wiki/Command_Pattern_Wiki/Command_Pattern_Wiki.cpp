// Command_Pattern_Wiki.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Command
{
public :
	virtual void execute() = 0;
};
class Ingredient : public Command
{
private:
	string _amount;
	string _ingredient;

public : 
	Ingredient(string amount, string ingredient)
	{
		_amount = amount;
		_ingredient = ingredient;
	}
	void execute()
	{
		cout << " *Add" << _amount << "of" << _ingredient << endl;
	}
};
class Step : public Command
{
private : 
	string _action;
	string _time;
public :
	Step(string action, string time)
	{
		_action = action;
		_time = time;
	}
	void execute()
	{
		cout << " *" << _action << " for " << _time << endl;
	}
};

class CmdStack
{
private :
	vector<Command*> commands;
public :
	void add(Command* c)
	{
		commands.push_back(c);
	}
	void createRecipe()
	{
		for (vector<Command*>::size_type x = 0; x < commands.size(); x++)
		{
			commands[x]->execute();
		}
	}
	void undo()
	{
		if (commands.size() >= 1)
		{
			commands.pop_back();
		}
		else
		{
			cout << "Can't undo" << endl;
		}
	}
};

int main()
{
	CmdStack list;

	//Create ingredients
	Ingredient first("2 tablespoons", "vegetable oil");
	Ingredient second("3 cups", "rice");
	Ingredient third("1 bottle", "Ketchup");
	Ingredient fourth("4 ounces", "peas");
	Ingredient fifth("1 teaspoon", "soy sauce");

	//Create Step
	Step step("Stir-fry", "3-4 minutes");

	//Create Recipe
	cout << "Recipe for simple Fried Rice" << endl;
	list.add(&first);
	list.add(&second);
	list.add(&step);
	list.add(&third);
	list.undo();
	list.add(&fourth);
	list.add(&fifth);
	list.createRecipe();
	cout << "Enjoy!" << endl;

    return 0;
}

