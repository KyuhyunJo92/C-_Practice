


#include "stdafx.h"
#include <iostream>
#include <list>
#include <string>
#include <string.h>

using namespace std;

class Dough
{
public:
	virtual string getName() = 0;
};
class ThickCrustDough : public Dough
{
public :
	string getName()
	{
		return "ThickCrustDough";
	}
};
class ThinCrustDough : public Dough
{
public:
	string getName()
	{
		return "ThinCrustDough";
	}
};

class Sauce
{
public :
	virtual string getName() = 0;
};
class HotSauce:public Sauce
{
public :
	string getName()
	{
		return "HotSauce";
	}
};

class Cheese 
{
public:
	virtual string getName() = 0;
};
class CheddaCheese : public Cheese
{
public: 
	string getName()
	{
		return "CheddaCheese";
	}
};
class ParmesanCheese : public Cheese
{
public:
	string getName()
	{
		return "ParmesanCheese";
	}
};

class PizzaIngredientFactory
{
public:
	virtual Dough* createDough() = 0;
	virtual Sauce* createSauce() = 0;
	virtual Cheese* createCheese() = 0;
};
class ChicagoIngredientFactory : public PizzaIngredientFactory
{
public :
	Dough* createDough() 
	{
		return new ThickCrustDough();
	}
	Sauce* createSauce() 
	{
		return new HotSauce();
	}
	Cheese* createCheese() 
	{
		return new ParmesanCheese();
	}
};
class NewYorkIngredientFactory : public PizzaIngredientFactory
{
public :
	Dough* createDough() override
	{
		return new ThinCrustDough();
	}
	Sauce* createSauce() override
	{
		return new HotSauce();
	}
	Cheese* createCheese() override
	{
		return new CheddaCheese();
	}
};

class Pizza 
{
protected :
//name, dough, sauce, cheese have to be used in child class.
	string name;
	Dough* dough;
	Sauce* sauce;
	Cheese* cheese;
	/*list<string*> toppings ;*/


public:
	virtual void prepare() 
	{
		cout << "<default> preparing "<<name;
		cout << "<default> Tossing Dough..";
		cout << "<default> Sauces..";
		cout << "<default> toppings.. : ";
		/*for (int i = 0; i < toppings.size(); i++)
		{
			cout << " " << toppings.get(i); 
		}*/
	};
	virtual void bake()
	{
		cout << "<default> bake 25 min at 350 Grad C.";
	}
	virtual void cut()
	{
		cout << "<default> cut 8 pieces. \n";
	}
	virtual void box()
	{
		cout << "<default> pakage default size box \n";
	}
	string getName()
	{
		return this->name;
	}
	void setName(string newName)
	{
		this->name = newName;
	}
};
class CheesePizza : public Pizza
{
private:
	PizzaIngredientFactory* pizzaIngredientFactory;

public :
	CheesePizza(PizzaIngredientFactory* pizzaIngredientFactory)
	{
		this->pizzaIngredientFactory = pizzaIngredientFactory;
	}
	void prepare()
	{
		dough = pizzaIngredientFactory->createDough();
		sauce = pizzaIngredientFactory->createSauce();
		cheese = pizzaIngredientFactory->createCheese();
	}
	void cut()
	{
		cout << "cut chicago pizza with square shape.";
	}
};
class VeggiePizza :public Pizza
{
private:
	PizzaIngredientFactory* pizzaIngredientFactory;

public:
	VeggiePizza(PizzaIngredientFactory* pizzaIngredientFactory)
	{
		this->pizzaIngredientFactory = pizzaIngredientFactory;
	}
	void cut()
	{
		cout << "cut chicago pizza with square shape.";
	}
};

class PizzaStore 
{
public:
	virtual Pizza orderPizza(string type)
	{
		Pizza *pizza = createPizza(type);
		cout << "===making a " << pizza->getName() << "===\n";
		pizza->prepare();
		pizza->bake();
		pizza->cut();
		pizza->box();

		return *pizza;
	}
protected:
	virtual Pizza* createPizza(string type) = 0;//class PizzaStore is abstract class. pure virtual method.
};
class ChicagoPizzaStore : public PizzaStore 
{
	//ChicagoPizzaStore also have a method "orderPizza"(from parentClass)
protected:
	Pizza* createPizza(string type)
	{
		Pizza* chicagoPizza=nullptr;
		//for possibility of selecting more detail option.
		//before this ingredientFactory class generated, every time a new pizza menu added 
		//all code must be writed again.
		PizzaIngredientFactory* chicagoIngredientFactory = new ChicagoIngredientFactory();
		if(type=="cheese")
		{
			chicagoPizza = new CheesePizza(chicagoIngredientFactory);
			chicagoPizza->setName("ChicagoCheesePizza");
			return chicagoPizza;
		}
		else if (type == "veggie")
		{
			chicagoPizza = new VeggiePizza(chicagoIngredientFactory);
			chicagoPizza->setName("ChicagoVeggiePizza");
			return chicagoPizza;
		}
		else
		{
			cout << "There is no " << type << " pizza. sorry.";
			return nullptr;
		}
		/*
		else if (type == "pepperoni")
		{
			pizza = new PepperoniPizza()
		}
		*/
	}
};
class NewYorkPizzaStore : public PizzaStore
{
	//ChicagoPizzaStore also have a method "orderPizza"(from parentClass)
protected:
	Pizza* createPizza(string type)
	{
		Pizza* pizza = nullptr;
		//for possibility of selecting more detail option.
		//before this ingredientFactory class generated, every time a new pizza menu added 
		//all code must be writed again.
		PizzaIngredientFactory* newYorkIngredientFactory = new NewYorkIngredientFactory();
		if (type == "cheese")
		{
			pizza = new CheesePizza(newYorkIngredientFactory);
			pizza->setName("NewYorkCheesePizza");
			return pizza;
		}
		else if (type == "veggie")
		{
			pizza = new VeggiePizza(newYorkIngredientFactory);
			pizza->setName("NewYorkVeggiePizza");
			return pizza;
		}
		else
		{
			cout << "There is no " << type << " pizza. sorry.";
			return nullptr;
		}
	}
};



int main()
{
	PizzaStore* chicagoPizzaStore = new ChicagoPizzaStore();//"PizzaStore* chicagoPizzaStore = new PizzaStore();"is not working. Because class PizzaStore
	Pizza pizza = chicagoPizzaStore->orderPizza("cheese");
	cout << "your pizza is.... :"<<pizza.getName();

	return 0;
}