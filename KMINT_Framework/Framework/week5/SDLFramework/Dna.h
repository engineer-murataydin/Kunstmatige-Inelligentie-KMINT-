#pragma once
#include <vector>

using namespace std;

class Dna
{
public:
	Dna(int flee, int pill, int hide, int weapon);
	Dna();
	~Dna();

	int getFlee() const;
	int	getPill() const;
	int	getHide() const;
	int	getWeapon() const;

	void mate(Dna* one, Dna* two, Dna* childOne, Dna* childTwo);

private:
	void normalize(int flee, int pill, int hide, int weapon);
	vector<int> toArray();

	int flee;
	int pill;
	int hide;
	int weapon;
};

