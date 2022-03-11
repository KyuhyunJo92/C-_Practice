// Proxy_Pattern_Image.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//
#include "stdafx.h"
#include "Image.h"

int main() 
{
	Image* image1 = new Proxy_Image("test1.png");
	Image* image2 = new Proxy_Image("test2.png");

	image1->displayImage();
	image2->displayImage();
}