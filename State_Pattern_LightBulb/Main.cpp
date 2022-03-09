#include "stdafx.h"
#include "Common.h"

void main()
{
	LightContext Light1;
	Light1.onPushedRequest();
	Light1.offPushedRequest();
	Light1.onPushedRequest();
	Light1.onPushedRequest();
}
