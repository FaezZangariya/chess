
#include "Position.h"




Position::Position():
	row(0),col(0),name(0),color(true),movementindex(0){
	}


Position::~Position(){
	delete this;
}


void Position::setposition(int r,int col){
	row=r;
	this->col=col;
}





