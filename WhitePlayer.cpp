
#include "WhitePlayer.h"
WhitePlayer::WhitePlayer():
myplayers(new Position*[16]),size(16){
	for(int i=0 ; i<16 ; i++){
		myplayers[i]=new Position();
	}
	//setup materials in first row for white player
	myplayers[0]->setrow(0);
	myplayers[0]->setcol(0);
	myplayers[0]->setname('r');
	myplayers[0]->setcolor(true);
	myplayers[0]->setmovementindex(0);
	myplayers[1]->setrow(0);
	myplayers[1]->setcol(1);
	myplayers[1]->setname('n');
	myplayers[1]->setcolor(true);
	myplayers[1]->setmovementindex(0);
	myplayers[2]->setrow(0);
	myplayers[2]->setcol(2);
	myplayers[2]->setname('b');
	myplayers[2]->setcolor(true);
	myplayers[2]->setmovementindex(0);
	myplayers[3]->setrow(0);
	myplayers[3]->setcol(3);
	myplayers[3]->setname('q');
	myplayers[3]->setcolor(true);
	myplayers[3]->setmovementindex(0);
	myplayers[4]->setrow(0);
	myplayers[4]->setcol(4);
	myplayers[4]->setname('k');
	myplayers[4]->setcolor(true);
	myplayers[4]->setmovementindex(0);
	myplayers[5]->setrow(0);
	myplayers[5]->setcol(5);
	myplayers[5]->setname('b');
	myplayers[5]->setcolor(true);
	myplayers[5]->setmovementindex(0);
	myplayers[6]->setrow(0);
	myplayers[6]->setcol(6);
	myplayers[6]->setname('n');
	myplayers[6]->setcolor(true);
	myplayers[6]->setmovementindex(0);
	myplayers[7]->setrow(0);
	myplayers[7]->setcol(7);
	myplayers[7]->setname('r');
	myplayers[7]->setcolor(true);
	myplayers[7]->setmovementindex(0);

	//setup materials in second row for white player (Pawns)
	for(int i=8 ; i<16 ; i++){
		myplayers[i]->setrow(1);
		myplayers[i]->setcol(i-8);
		myplayers[i]->setname('p');
		myplayers[i]->setcolor(true);
		myplayers[i]->setmovementindex(0);
	}
}



WhitePlayer::~WhitePlayer(){
	for(int i=0 ; i<16 ;i++){
		myplayers[i]->~Position();
	}
	delete this;
}

int WhitePlayer::find(int k,int j) const{
	for(int i=0 ; i<16 ;i++){
		if(myplayers[i]->getrow()==k && myplayers[i]->getcol()==j){
			return i;
		}
	}
	return -1;
}


void WhitePlayer::remove(int i){
	for(int j=i ; j<16-1 ;j++){
		myplayers[j]=myplayers[j+1];
	}
	size--;
}
