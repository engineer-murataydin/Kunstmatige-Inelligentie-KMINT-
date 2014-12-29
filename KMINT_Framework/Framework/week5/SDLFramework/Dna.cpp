#include "Dna.h"
#include "FWApplication.h"
#include <random>
#include <sstream>


Dna::Dna(double* dna, int size) :size(size), dna(dna)
{
	normalize();
}

Dna::Dna() : size(4)
{
	uniform_int_distribution<int> dist(10, 30);
	dna = new double[size];
	for (int i = 0; i < size; i++)
	{
		dna[i] = dist(FWApplication::GetInstance()->dre);
	}
	normalize();

}

Dna::~Dna()
{
}

void Dna::normalize()
{
	double total = 0;

	for (int i = 0; i < size; i++)
	{
		total += dna[i];
	}

	for (int i = 0; i < size; i++)
	{
		dna[i] = dna[i] / total * 100;
	}
}


void Dna::mate(Dna* one, Dna* two, Dna* childOne, Dna* childTwo)
{
	uniform_int_distribution<int> dist(1, 3);
	uniform_int_distribution<int> mutation(1, 1000);//TODO mutate

	int pos = dist(FWApplication::GetInstance()->dre);

	double* DnaOne = one->dna;
	double* DnaTwo = two->dna;

	for (size_t i = 0; i < one->size; i++)
	{
		if (i == pos)
		{
			double* temp = DnaOne;
			DnaOne = DnaTwo;
			DnaTwo = temp;
		}
		childOne->dna[i] = DnaOne[i];
		childTwo->dna[i] = DnaTwo[i];
	}
	childOne->normalize();
	childTwo->normalize();
}


double* Dna::getDna() const
{
	return dna;
}

string Dna::toString()
{
	stringstream ss;
	for (int i = 0; i < size; i++)
	{
		ss << i + 1 << ": " << dna[i] << ", ";
	}
	return ss.str();
}
