#ifndef WhitePlayer_H
#define WhitePlayer_H

#include "Position.h"

class WhitePlayer{
public:
	WhitePlayer();
	~WhitePlayer();
	int find(int k,int j) const;
	void remove(int i);
	Position* getplayer(int i){return myplayers[i];}
	int getsize(){return size;}



private:
	Position** myplayers;
	int size;
};




#endif /* WhitePlayer_H */
