#include <iostream>
#include <vector>
using namespace std;

class Pizza
{
public:
	virtual void info() = 0;
	virtual ~Pizza() {}
};

class Dough : public Pizza {
public:
	void info() {
		cout << "Тесто" << endl;
	};
};

class Sauce : public Pizza
{
public:
	void info() {
		cout << "Соус" << endl;
	};
};

class Cheeses : public Pizza
{
public:
	void info() {
		cout << "Сыр" << endl;
	};
};

class Pepperoni : public Pizza
{
public:
	void info() {
		cout << "Пепперони" << endl;
	};
};

class Tomato : public Pizza
{
public:
	void info() {
		cout << "Помидор" << endl;
	};
};

class Meat : public Pizza {
public:
	void info() {
		cout << "Мясо" << endl;
	};
};

class Chicken : public Pizza {
public:
	void info() {
		cout << "Курица" << endl;
	}
};

class Pineapples : public Pizza {
public:
	void info() {
		cout << "Ананас" << endl;
	}
};

// Фабрики объектов
class Factory
{
public:
	virtual Pizza* createPizza() = 0;
	virtual ~Factory() {}
};

class DoughFactory : public Factory {
public:
	Pizza* createPizza() {
		return new Dough;
	};
};

class SauceFactory : public Factory {
public:
	Pizza* createPizza() {
		return new Sauce;
	}
};

class CheesesFactory : public Factory
{
public:
	Pizza* createPizza() {
		return new Cheeses;
	}
};

class PepperoniFactory : public Factory
{
public:
	Pizza* createPizza() {
		return new Pepperoni;
	}
};

class TomatoFactory : public Factory
{
public:
	Pizza* createPizza() {
		return new Tomato;
	}
};

class MeatFactory : public Factory
{
public:
	Pizza* createPizza() {
		return new Meat;
	}
};

class ChickenFactory : public Factory
{
public:
	Pizza* createPizza() {
		return new Chicken;
	}
};

class PineapplesFactory : public Factory
{
public:
	Pizza* createPizza() {
		return new Pineapples;
	}
};
// Создание объектов при помощи фабрик объектов
int main()
{
	setlocale(LC_ALL, "rus");
	DoughFactory* dough_factory = new DoughFactory;
	SauceFactory* sause_factory = new SauceFactory;
	CheesesFactory* cheeses_factory = new CheesesFactory;
	PepperoniFactory* pepperoni_factory = new PepperoniFactory;
	TomatoFactory* tomato_factory = new TomatoFactory;
	MeatFactory* meat_factory = new MeatFactory;
	ChickenFactory* chicken_factory = new ChickenFactory;
	PineapplesFactory* pineapples_factory = new PineapplesFactory;

	vector<Pizza*> village_pizza;
	village_pizza.push_back(dough_factory->createPizza());
	village_pizza.push_back(sause_factory->createPizza());
	village_pizza.push_back(meat_factory->createPizza());
	village_pizza.push_back(cheeses_factory->createPizza());
	village_pizza.push_back(pepperoni_factory->createPizza());
	village_pizza.push_back(tomato_factory->createPizza());
	village_pizza.push_back(chicken_factory->createPizza());

	vector<Pizza*> margo_pizza;
	margo_pizza.push_back(dough_factory->createPizza());
	margo_pizza.push_back(sause_factory->createPizza());
	margo_pizza.push_back(cheeses_factory->createPizza());
	margo_pizza.push_back(tomato_factory->createPizza());

	vector<Pizza*> peppi_pizza;
	peppi_pizza.push_back(dough_factory->createPizza());
	peppi_pizza.push_back(sause_factory->createPizza());
	peppi_pizza.push_back(cheeses_factory->createPizza());
	peppi_pizza.push_back(pepperoni_factory->createPizza());

	vector<Pizza*> hawaiian_pizza;
	hawaiian_pizza.push_back(dough_factory->createPizza());
	hawaiian_pizza.push_back(sause_factory->createPizza());
	hawaiian_pizza.push_back(cheeses_factory->createPizza());
	hawaiian_pizza.push_back(chicken_factory->createPizza());
	hawaiian_pizza.push_back(pineapples_factory->createPizza());

	cout << "Добрый день! Мы рады видеть Вас в нашей пиццерии!\n Какую пиццу вы предпочетаете?\n";
	while (true) {
		
		cout << "1. Деревенская;\n2. Маргарита;\n3. Пепперони;\n4. Гавайская.\n";
		int pos = 0;
		cin >> pos;

		switch (pos) {
			case 1: {
				cout << "Отличный выбор!!!\nСостав Деревенской пиццы:\n";
				for (int i = 0; i < village_pizza.size(); i++)
					village_pizza[i]->info();
				break;
			}
			case 2: {
				cout << "Отличный выбор!!!\nСостав пиццы Маргарита:\n";
				for (int i = 0; i < margo_pizza.size(); i++)
					margo_pizza[i]->info();
				break;
		    }
			case 3: {
				cout << "Отличный выбор!!!\nСостав пиццы Пеппирони:\n";
				for (int i = 0; i < peppi_pizza.size(); i++)
					peppi_pizza[i]->info();
				break;
			}
			case 4: {
				cout << "Отличный выбор!!!\nСостав Гавайской пиццы:\n";
				for (int i = 0; i < hawaiian_pizza.size(); i++)
					hawaiian_pizza[i]->info();
				break;
			}

			default: {
				cout << "К сожалению, такой пиццы у нас нет. Выберите снова.";
				continue; 
			}
		}
	}
}


