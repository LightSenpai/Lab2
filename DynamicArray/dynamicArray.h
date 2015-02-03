#ifndef DYNAMICARRAY_H_
#define DYNAMICARRAY_H_


class DynamicArray
{

public:
	DynamicArray();
	DynamicArray(int _capacite);
	DynamicArray(const DynamicArray & _source);
	~DynamicArray();
	DynamicArray& operator=(const DynamicArray & _source);
	bool operator==(const DynamicArray & _source);
	void setElement(unsigned int _index, int _valeur);
	int getElement(unsigned int _index);
	unsigned int getCapacite();
	void setCapacite(unsigned int _capacite);
private:
	int* tabElements;
	unsigned int capacite;
};


#endif //DYNAMICARRAY_H_