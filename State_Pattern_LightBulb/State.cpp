#include "stdafx.h"
#include "Common.h"

LightContext::LightContext()
{
	onState = new OnState(this);
	offState = new OffState(this);
	state = offState;
}

void LightContext::setState(State* newState)
{
	this->state = newState;
}

OnState* LightContext::getOnState()
{
	return onState;
}
OffState* LightContext::getOffState()
{
	return offState;
}

void LightContext::onPushedRequest()
{
	state->OnPushedHandle();
}
void LightContext::offPushedRequest()
{
	state->OffPushedHandle();
}

void OffState::OnPushedHandle()
{
	cout << "Turn On the light" << endl;
	lightContext->setState(lightContext->getOnState());
}
void OffState::OffPushedHandle()
{
	cout << "Already Off" << endl;
}

void OnState::OnPushedHandle()
{
	cout << "Already On" << endl;
}
void OnState::OffPushedHandle()
{
	cout << "Turn Off the light" << endl;
	lightContext->setState(lightContext->getOffState());
}
