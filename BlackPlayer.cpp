
#include "BlackPlayer.h"
BlackPlayer::BlackPlayer():
myplayers(new Position*[16]),size(16){
	for(int i=0 ; i<16 ; i++){
		myplayers[i]=new Position();
	}
	//setup materials in first row for black player
	myplayers[0]->setrow(7);
	myplayers[0]->setcol(0);
	myplayers[0]->setname('R');
	myplayers[0]->setcolor(false);
	myplayers[0]->setmovementindex(0);
	myplayers[1]->setrow(7);
	myplayers[1]->setcol(1);
	myplayers[1]->setname('N');
	myplayers[1]->setcolor(false);
	myplayers[1]->setmovementindex(0);
	myplayers[2]->setrow(7);
	myplayers[2]->setcol(2);
	myplayers[2]->setname('B');
	myplayers[2]->setcolor(false);
	myplayers[2]->setmovementindex(0);
	myplayers[3]->setrow(7);
	myplayers[3]->setcol(3);
	myplayers[3]->setname('Q');
	myplayers[3]->setcolor(false);
	myplayers[3]->setmovementindex(0);
	myplayers[4]->setrow(7);
	myplayers[4]->setcol(4);
	myplayers[4]->setname('K');
	myplayers[4]->setcolor(false);
	myplayers[4]->setmovementindex(0);
	myplayers[5]->setrow(7);
	myplayers[5]->setcol(5);
	myplayers[5]->setname('B');
	myplayers[5]->setcolor(false);
	myplayers[5]->setmovementindex(0);
	myplayers[6]->setrow(7);
	myplayers[6]->setcol(6);
	myplayers[6]->setname('N');
	myplayers[6]->setcolor(false);
	myplayers[6]->setmovementindex(0);
	myplayers[7]->setrow(7);
	myplayers[7]->setcol(7);
	myplayers[7]->setname('R');
	myplayers[7]->setcolor(false);
	myplayers[7]->setmovementindex(0);

	//setup materials in second row for black player (Pawns)
	for(int i=8 ; i<16 ; i++){
		myplayers[i]->setrow(6);
		myplayers[i]->setcol(i-8);
		myplayers[i]->setname('P');
		myplayers[i]->setcolor(false);
		myplayers[i]->setmovementindex(0);
	}
}



BlackPlayer::~BlackPlayer(){
	for(int i=0 ; i<16 ;i++){
		myplayers[i]->~Position();
	}
	delete this;
}

int BlackPlayer::find(int k, int j) const{
	for(int i=0 ; i<16 ;i++){
		if(myplayers[i]->getrow()==k && myplayers[i]->getcol()==j){
			return i;
		}
	}
	return -1;
}


void BlackPlayer::remove(int i){
	for(int j=i ; j<16-1 ;j++){
		myplayers[j]=myplayers[j+1];
	}
	size--;
}

