#include<string>
#include<iostream>
#include "time.h"

class MobilePhone
{
private:

	std::string firm;
	int size, weight, melodies, price;
	bool colorDisplay, vibratingAlert, notebook;
	

public:
	MobilePhone* Next;
	int key = 0;
	MobilePhone();
	MobilePhone(std::string firm, int size, int weight, int melodies, int price, bool colorDisplay, bool vibratingAlert, bool notebook);
	MobilePhone(MobilePhone& P);
	friend std::ostream& operator << (std::ostream& out, MobilePhone& P);
	friend std::istream& operator >> (std::istream& in, MobilePhone& P);
	std::string getFirm();
	int getSize();
	int getWeight();
	int getMelodies();
	int getPrice();
	int getKey();
	std::string getColorDisplay();
	std::string getVibratingAlert();
	std::string getNotebook();
	void setFirm(std::string firm);
	void setSize(int size);
	void setKey(int key);
	void setWeight(int weight);
	void setMelodies(int melodies);
	void setPrice(int price);
	void setColorDisplay(bool colorDisplay);
	void setVibratingAlert(bool vibratingAlert);
	void setNotebook(bool notebook);
	void setRangomObject();

};

int Random()
{
	const int UP_BOUND = 1000;
	const int LOW_BOUND = 0;
	//srand(time(0));
	return (rand() % (LOW_BOUND - UP_BOUND + 1) + LOW_BOUND);
}

MobilePhone::MobilePhone()
{
	firm = "firm";
	size = 0;
	weight = 0;
	melodies = 0;
	price = 0;
	colorDisplay = false;
	vibratingAlert = false;
	notebook = false;
	Next = nullptr;
}

MobilePhone::MobilePhone(std::string firm, int size, int weight, int melodies, int price, bool colorDisplay, bool vibratingAlert, bool notebook)
{
	setFirm(firm);
	setSize(size);
	setWeight(weight);
	setMelodies(melodies);
	setPrice(price);
	setColorDisplay(colorDisplay);
	setVibratingAlert(vibratingAlert);
	setNotebook(notebook);
}

MobilePhone::MobilePhone(MobilePhone& P)
{
	setFirm(P.firm);
	setSize(P.size);
	setKey(P.key);
	setWeight(P.weight);
	setMelodies(P.melodies);
	setPrice(P.price);
	setColorDisplay(P.colorDisplay);
	setVibratingAlert(P.vibratingAlert);
	setNotebook(P.notebook);
	Next = nullptr;

}

std::string MobilePhone::getFirm()
{
	return std::string(firm);
}

int MobilePhone::getSize()
{
	return (size);
}

int MobilePhone::getWeight()
{
	return (weight);
}

int MobilePhone::getMelodies()
{
	return (melodies);
}

int MobilePhone::getPrice()
{
	return (price);
}

int MobilePhone::getKey()
{
	return (key);
}

std::string MobilePhone::getColorDisplay()
{
	if (colorDisplay == true)
		return("color");
	else
		return("mono");
}

std::string MobilePhone::getVibratingAlert()
{
	if (vibratingAlert == true)
		return ("+");
	else
		return ("-");
}

std::string MobilePhone::getNotebook()
{
	if (notebook == true)
		return ("+");
	else
		return ("-");
}

void MobilePhone::setFirm(std::string firm)
{
	this->firm = firm;
	this->key += std::atoi(firm.c_str());
}

void MobilePhone::setSize(int size)
{
	this->size = size;
	this->key += size;
}

void MobilePhone::setKey(int key)
{
	this->key = key;
}

void MobilePhone::setWeight(int weight)
{
	this->weight = weight;
	this->key += weight;
}

void MobilePhone::setMelodies(int melodies)
{
	this->melodies = melodies;
	this->key += melodies;
}

void MobilePhone::setPrice(int price)
{
	this->price = price;
	this->key += price;
}

void MobilePhone::setColorDisplay(bool colorDisplay)
{
	this->colorDisplay = colorDisplay;
}

void MobilePhone::setVibratingAlert(bool vibratingAlert)
{
	this->vibratingAlert = vibratingAlert;
}

void MobilePhone::setNotebook(bool notebook)
{
	this->notebook = notebook;
}

void MobilePhone::setRangomObject()
{
	std::string firms[5] = { "apple", "samsung", "honor", "oneplus", "huawei" };
	int sizes[4] = { 6, 7, 8, 9 };
	int weights[5] = { 100, 105, 110, 115, 120 };
	int melodiess[5] = { 15, 17, 20, 22, 25 };
	int prices[5] = { 300, 400, 500, 600 };
	setFirm(firms[Random() % 5]);
	setSize(sizes[Random() % 4]);
	setWeight(weights[Random() % 5]);
	setMelodies(melodiess[Random() % 5]);
	setPrice(prices[Random() % 5]);
	setColorDisplay(Random() % 2);
	setVibratingAlert(Random() % 2);
	setNotebook(Random() % 2);
}



std::ostream& operator<<(std::ostream& out, MobilePhone& P)
{
	std::cout << P.getFirm() << " " << P.getSize() << " " << P.getWeight() << " " << P.getColorDisplay() << " " << P.getVibratingAlert() << " " << P.getMelodies() << " " << P.getNotebook() << " " << P.getPrice() << " " << "Key: " << P.getKey() << "\n";

	return out;
}

std::istream& operator>>(std::istream& in, MobilePhone& P)
{
	std::cout << "firm, size, weight, number of melodies, price, color display, vibrating alert, notebook " << "\n";
	std::cout << "firm = ";
	std::cin >> P.firm;
	std::cout << "size = ";
	std::cin >> P.size;
	std::cout << "weight = ";
	std::cin >> P.weight;
	std::cout << "number of melodies = ";
	std::cin >> P.melodies;
	std::cout << "price = ";
	std::cin >> P.price;
	std::cout << "color display = ";
	std::cin >> P.colorDisplay;
	std::cout << "vibrating alert = ";
	std::cin >> P.vibratingAlert;
	std::cout << "notebook = ";
	std::cin >> P.notebook;


	return in;
}

class List
{
public:
	size_t size;
	MobilePhone* head;
	List()
	{
		size = 0;
		head = nullptr;
	}
	void push_back(MobilePhone data)
	{
		if (head == nullptr)
		{
			head = new MobilePhone(data);
		}
		else
		{
			MobilePhone* current = this->head;

			while (current->Next != nullptr)
			{
				current = current->Next;
			}

			current->Next = new MobilePhone(data);
		}
		size++;
	}
	
	void push_key(MobilePhone data)
	{
		MobilePhone* current = this->head;
		MobilePhone* prev = this->head;
		MobilePhone* input = new MobilePhone(data);

		while (current!=nullptr)
		{
			if (current->getFirm() == input->getFirm() && current->getFirm() != head->getFirm())
			{
				input->Next = current;
				prev -> Next = input;
				break;
			}
			else if (current->getFirm() == input->getFirm() && current->getFirm() == head->getFirm())
			{
				input->Next = head;
				head = input;
				break;
			}
			

			prev = current;
			current = current->Next;
		}
		size++;
	}
	void erase(int key)
	{
		MobilePhone* current = this->head;
		MobilePhone* prev = nullptr;
		
		if (key == head->key)
		{
			head = head->Next;
			current = nullptr;
		}
		while (current != nullptr)
		{

			if (key == current->key)
			{
				prev->Next = current->Next;
			}
			prev = current;
			current = current->Next;
		}
		size--;
	}
	void findByKey(int keyToFind)
	{
		MobilePhone* current = this->head;
		
		while (current != nullptr)
		{
			if (current->key == keyToFind)
			{
				std::cout << *current;
			}

			current = current->Next;
		}
	}
	void Print()
	{
		MobilePhone* current = this->head;
		if (this->head != nullptr)
		{
			while (current != nullptr)
			{
				std::cout << *current;

				current = current->Next;
			}
		}
		else
		{
			std::cout << "list is empty \n";
		}
	}
};


using namespace std;

int main()
{
	List list;
	int menu;


	while (true)
	{
		cout << "1)Output \n"
			<< "2)Find by key \n"
			<< "3)Delete by key \n"
			<< "4)Push by key \n"
			<< "5)Push back random object \n"
			<< "6)Exit \n";

		cin >> menu;
		switch (menu)
		{

		case 1:
		{
			cout << "created list: \n";
			list.Print();
			break;
		}
		case 2:
		{
			int key;
			cout << "input key \n";
			cin >> key;
			list.findByKey(key);
			break;
		}
		case 3:
		{
			int key;
			cin >> key;
			list.erase(key);

			cout << "new list: \n";
			list.Print();
			break;
		}
		case 4:
		{
			MobilePhone data;
			cout << "input object\n";
			cin >> data;
			list.push_key(data);

			cout << "new list: \n";
			list.Print();
			break;
		}
		case 5:
		{
			MobilePhone obj;
			int i = 0;
			srand(time(0) + i);
			obj.setRangomObject();
			list.push_back(obj);
			i++;
			break;
		}
		case 6:
		{
			exit(EXIT_SUCCESS);
			break;
		}
		}
	}

	return(0);
}