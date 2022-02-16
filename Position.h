#ifndef Position_H
#define Position_H




class Position{
public:
	Position();
	~Position();
	void setposition(int r,int col);
	int getrow(){return row;}
	int getcol(){return col;}
	char getname(){return name;}
	bool getcolor(){return color;}
	int getmovementindex(){return movementindex;}
	void setrow(int r){row=r;}
	void setcol(int c){col=c;}
	void setname(char n){name=n;}
	void setcolor(bool co){color=co;}
	void setmovementindex(int mi){movementindex=mi;}



private:
	int row;
	int col;
	char name;
	bool color;
	int movementindex;
};




#endif /* Position_H */
