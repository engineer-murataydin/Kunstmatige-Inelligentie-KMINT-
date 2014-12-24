#include "Dna.h"
#include "FWApplication.h"
#include <random>

using namespace std;

Dna::Dna(int flee, int pill, int hide, int weapon)
{
	normalize(flee, pill, hide, weapon);
}

Dna::Dna()
{
	uniform_int_distribution<int> dist(10, 30);
	default_random_engine dre = FWApplication::GetInstance()->dre;
	normalize(dist(dre), dist(dre), dist(dre), dist(dre));
}

Dna::~Dna()
{
}

void Dna::normalize(int flee, int pill, int hide, int weapon)
{
	int total = flee + pill + hide + weapon;
	this->flee = flee / total * 100;
	this->pill = pill / total * 100;
	this->hide = hide / total * 100;
	this->weapon = weapon / total * 100;
}

int Dna::getFlee() const
{
	return flee;
}

int Dna::getPill() const
{
	return pill;
}

int Dna::getHide() const
{
	return hide;
}

int Dna::getWeapon() const
{
	return weapon;
}

void Dna::mate(Dna* one, Dna* two, Dna* childOne, Dna* childTwo)
{
	uniform_int_distribution<int> dist(1, 3);
	uniform_int_distribution<int> mutation(1, 1000);//TODO mutate

	int pos = dist(FWApplication::GetInstance()->dre);

	vector<int> DnaOne = one->toArray();
	vector<int> DnaTwo = two->toArray();

	vector<int> childOneList;
	vector<int> childTwoList;
	for (size_t i = 0; i < DnaOne.size(); i++)
	{
		if (i == pos)
		{
			vector<int> temp = DnaOne;
			DnaOne = DnaTwo;
			DnaTwo = temp;
		}
		childOneList.push_back(DnaOne[i]);
		childTwoList.push_back(DnaTwo[i]);
	}
	childOne = new Dna(childOneList[0], childOneList[1], childOneList[2], childOneList[3]);
	childTwo = new Dna(childTwoList[0], childTwoList[1], childTwoList[2], childTwoList[3]);
}

vector<int> Dna::toArray()
{
	vector<int> list;
	list.push_back(flee);
	list.push_back(pill);
	list.push_back(hide);
	list.push_back(weapon);

	return list;
}

