#pragma once
#include <vector>
#include <string>

using namespace std;

class Dna
{
public:
	Dna(double* dna, int size);
	Dna();
	~Dna();

	static void mate(Dna* one, Dna* two, Dna* childOne, Dna* childTwo);
	double* getDna() const;

	string toString();
private:
	void normalize();

	int size;
	double* dna;
};

