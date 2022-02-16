#ifndef BlackPlayer_H
#define BlackPlayer_H

#include "Position.h"


class BlackPlayer{
public:
	BlackPlayer();
	int find(int k ,int j) const;
	void remove(int i);
	Position* getplayer(int i){return myplayers[i];}
	~BlackPlayer();
	int getsize(){return size;}





private:
	Position** myplayers;
	int size;
};





#endif /* BlackPlayer_H */
