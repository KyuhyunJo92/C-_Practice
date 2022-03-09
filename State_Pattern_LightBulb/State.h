#pragma once
class OnState;
class OffState;


class State
{
public:
	virtual void OnPushedHandle() = 0;
	virtual void OffPushedHandle() = 0;
};

class LightContext {
private:
	//make pointer objekt for each states.
	OnState*	onState;
	OffState*	offState;
	State*		state;
public:

	LightContext();

	void setState(State* newState);
	
	//those are nesessary for returning each states.
	OnState*	getOnState();	//return onState;
	OffState*	getOffState();	// return offState;

	//context class have those methodes, and they work by using the instance of each state.
	void onPushedRequest();		//state->OnPushedHandle();
	void offPushedRequest();	//state->OffPushedHandle();
};

class OffState : public State
{
private:
	//LightContext type pointer variable lightContext. 
	LightContext* lightContext;

public:
	//when a new OffState instance is constructed, 
	//in this projekt, a LightContext class has On/OffState what is taking itself(this pointer)
	//as a parameter of the constructor of class On/OffState
	//that is how the context give itself as a parameter of state constructor.
	OffState(LightContext* lightContext) : lightContext(lightContext) {};
	
	//very interesting, LightContext::on/offP-R-() give a job to class On/OffState
	//but the methods need lightContext parameter.
	void OnPushedHandle();	//lightContext->setState(lightContext->getOnState());
	void OffPushedHandle();		
};

class OnState : public State
{
private:
	LightContext* lightContext;
public:
	OnState(LightContext *lightContext) : lightContext(lightContext) {};

	void OnPushedHandle();
	void OffPushedHandle();	//lightContext->setState(lightContext->getOffState());
};
