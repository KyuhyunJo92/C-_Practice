#pragma once
#include "Common.h"

class Image
{
public:
	virtual void displayImage() = 0;
};

class Real_Image : public Image
{
private:
	string fileName;

	//private Methode loadFromDisk()
	//directly access to Disk, and load the Target File.
	void loadFromDisk(string _fileName)
	{
		cout << "Loading" << _fileName<<endl;
	}
public:

	//when Real_Image object is generated, 
	//only once loadFromDisk(fileName) is executed.
	Real_Image(string _fileName)
	{
		this->fileName = _fileName;
		loadFromDisk(fileName);
	}

	//display the image directly
	void displayImage() override
	{
		cout << "Displaying" << fileName << endl;
	}
};

class Proxy_Image : public Image
{
private:
	//make a Real_Image* object.
	Image* realImage;//before code : Real_Image* realImage; 
	string fileName;

public:
	Proxy_Image(string _fileName)
	{
		this->fileName = _fileName;
	}

	//Proxy_Image* -> displayImage()
	//construct to Real_Image* objekt. 
	//realImage = new Real_Image(fileName);
	//use Real_Image* -> displayImage()
	void displayImage() override
	{
		if (realImage == NULL)
		{
			realImage = new Real_Image(fileName);
		}
		realImage->displayImage();
	}
};
