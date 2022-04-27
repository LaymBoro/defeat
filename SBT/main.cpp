#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <string>
#include "time.h"

class MobilePhone
{
private:

	std::string firm;
	int size, weight, melodies, price;
	bool colorDisplay, vibratingAlert, notebook;


public:
	MobilePhone* left;
	MobilePhone* right;
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
	std::string getColorDisplay();
	std::string getVibratingAlert();
	std::string getNotebook();
	void setFirm(std::string firm);
	void setSize(int size);
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
	setWeight(P.weight);
	setMelodies(P.melodies);
	setPrice(P.price);
	setColorDisplay(P.colorDisplay);
	setVibratingAlert(P.vibratingAlert);
	setNotebook(P.notebook);

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
}

void MobilePhone::setSize(int size)
{
	this->size = size;
}

void MobilePhone::setWeight(int weight)
{
	this->weight = weight;
}

void MobilePhone::setMelodies(int melodies)
{
	this->melodies = melodies;
}

void MobilePhone::setPrice(int price)
{
	this->price = price;
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
	std::cout << P.getFirm() << " " << P.getSize() << " " << P.getWeight() << " " << P.getColorDisplay() << " " << P.getVibratingAlert() << " " << P.getMelodies() << " " << P.getNotebook() << " " << P.getPrice() << " " <<  "\n";

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

using namespace std;

class SBT
{
private:
	
public:
	class Node
	{
	public:
		MobilePhone data;
		Node* left;
		Node* right;
		Node()
		{
			data;
			left = nullptr;
			right = nullptr;
		}
	};
	Node* head = nullptr;

	void pushNode(Node*& head)
	{
		Node* node = new Node;
		if (head == nullptr)
		{
			cin >> node->data;
			head = node;
		}
		else
		{
			if (atoi(node->data.getFirm().c_str()) < atoi(head->data.getFirm().c_str()))
			{
				pushNode(head->left);
			}
			else
			{
				if (atoi(node->data.getFirm().c_str()) < atoi(head->data.getFirm().c_str()))
				{
					pushNode(head->right);
				}
			}
		}
		
	}
	void pushRandomNode(Node*& head)
	{
		Node* node = new Node;
		if (head == nullptr)
		{
			node->data.setRangomObject();
			head = node;
		}
		else
		{
			if (atoi(node->data.getFirm().c_str()) < atoi(head->data.getFirm().c_str()))
			{
				pushRandomNode(head->left);
			}
			else
			{
				if (atoi(node->data.getFirm().c_str()) < atoi(head->data.getFirm().c_str()))
				{
					pushRandomNode(head->right);
				}
			}
		}
	}
	void printNormal(Node*& head)
	{
		if (head != nullptr)
		{
			cout << head->data << "\n";
			printNormal(head->left);
			printNormal(head->right);
		}
	}
	void printReverse(Node*& head)
	{
		if (head != nullptr)
		{
			printReverse(head->left);
			printReverse(head->right);
			cout << head->data << "\n";
		}
	}
	void printMid(Node*& head)
	{
		if (head != nullptr)
		{
			printMid(head->left);
			cout << head->data << "\n";
			printMid(head->right);
		}
	}

	void deleteNode(string key, Node*& head)
	{
		if (head == nullptr)
		{
			cout << "element not found\n";
		}
		else
		{
			if (atoi(key.c_str()) < atoi(head->data.getFirm().c_str()))
			{
				deleteNode(key, head->left);
			}
			else
			{
				if (atoi(key.c_str()) > atoi(head->data.getFirm().c_str()))
				{
					deleteNode(key, head->right);
				}
				else
				{
					Node* currentNode = head;
					if (currentNode->right == nullptr)
					{
						head = currentNode->left;
					}
					else
					{
						if (currentNode->left == nullptr)
						{
							head = currentNode->right;
						}
						else delete(currentNode->left);
					}
					delete currentNode;
				}
			}
		}
	}
	void search(string key, Node*& head)
	{
		if (head == nullptr)
		{
			cout << "Tree is empty\n";
		}
		else
		{
			while (head != nullptr && head->data.getFirm() != key)
			{
				if (atoi(head->data.getFirm().c_str()) < atoi(key.c_str()))
				{
					head = head->right;
				}
				else
				{
					head = head->left;
				}
			}
			if (head == nullptr)
			{
				std::cout << "element not found\n";
			}
			else
			{
				std::cout << head->data << "\n";
				
			}
		}
	}
	void Erase(Node*& head)
	{
		Node* current;
		current = head;
		if (head != nullptr)
		{
			Erase(head->left);
			Erase(head->right);
			delete head;
		}
	}
};
int main()
{
	
	SBT* tree = new SBT;
	MobilePhone obj;
	string key;

	int menu;
	bool While = true;

	while (While)
	{
		menu = 0;
		cout << "1)Push by key \n"
			<< "2)Normal output \n"
			<< "3)Reverse output \n"
			<< "4)Symmetric output \n"
			<< "5)Delete by key \n"
			<< "6)Find by key \n"
			<< "7)Delete by key \n"
			<< "8)Push back random object \n"
			<< "9)Exit \n";
		cin >> menu;

		switch (menu)
		{
		case 1:
		{
			cout << "Push by key\n";
			tree->pushNode(tree->head);
			break;
		}
		case 2:
		{
			cout << "Normal output: \n";
			tree->printNormal(tree->head);
			break;
		}
		case 3:
		{
			cout << "Reverse output: \n";
			tree->printReverse(tree->head);
			break;
		}
		case 4:
		{
			cout << "Symmetric output: \n";
			tree->printMid(tree->head);
			break;
		}
		case 5:
		{
			cout << "Input firm: ";
			cin >> key;
			tree->deleteNode(key, tree->head);

			cout << "New tree: \n";
			tree->printNormal(tree->head);
			break;
		}
		case 6:
		{
			cout << "Input firm: ";
			cin >> key;
			tree->search(key, tree->head);
			break;
		}
		case 7:
		{
			tree->Erase(tree->head);
			break;
		}
		case 8:
		{
			tree->pushRandomNode(tree->head);
			break;
		}
		case 9:
		{
			exit(EXIT_SUCCESS);
			break;
		}
		default:
			break;
		}
	}
	return 0;
}


