#include "dynamicArray.h"
#include <iostream>
#include <stdexcept>

using namespace std;

DynamicArray::DynamicArray()
{
	capacite = 100;
	tabElements = new int[capacite];
	for (int i = 0;i < capacite;i++)
	{
		tabElements[i] = 0;
	}
}

DynamicArray::DynamicArray(int _capacite)
{
	if (_capacite < 1)
	{
		throw invalid_argument("The argument is invalid");
	}
	capacite = _capacite;
	tabElements = new int[capacite];
	for (int i = 0; i < capacite; i++)
	{
		tabElements[i] = 0;
	}
}

DynamicArray::DynamicArray(const DynamicArray & _source)
:capacite(_source.capacite), tabElements(new int[_source.capacite])
{
	for (unsigned int i = 0; i < capacite; i++)
	{
		tabElements[i] = _source.tabElements[i];
	}
}

DynamicArray::~DynamicArray()
{

}

DynamicArray& DynamicArray::operator=(const DynamicArray & _source)
{
	if (&_source != this)
	{
		delete[] tabElements;
		capacite = _source.capacite;
		tabElements = new int[capacite];
		for (unsigned int i = 0; i < capacite; i++)
		{
			tabElements[i] = _source.tabElements[i];
		}
	}
	return *this;
}

bool DynamicArray::operator==(const DynamicArray & _source)
{
	if (tabElements = _source.tabElements)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void DynamicArray::setElement(unsigned int _index, int _valeur)
{
	if (_index > capacite)
	{
		setCapacite(_index + 1);
		tabElements[_index] = _valeur;
	}
	else
	{
		tabElements[_index] = _valeur;
	}
}

int DynamicArray::getElement(unsigned int _index)
{
	if (_index > capacite)
	{
		throw out_of_range("The index is out of range");
	}
	return tabElements[_index];
}

unsigned int DynamicArray::getCapacite()
{
	return capacite;
}

void DynamicArray::setCapacite(unsigned int _capacite)
{
	if (_capacite < 1)
	{
		throw invalid_argument("The argument is invalid.");
	}
	else
	{
		int* newTabElements = new int[_capacite];
		for (int i = 0; i < _capacite; i++)
		{
			if (i >= capacite)
			{
				newTabElements[i] = 0;
			}
			else
			{
				newTabElements[i] = tabElements[i];
			}
		}
		capacite = _capacite;
		int* tempTabElements = tabElements;
		tabElements = newTabElements;
		delete tempTabElements;
	}
}