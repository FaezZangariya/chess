#include <iostream>
#include <string>
#include <stdlib.h>
#include <sstream>
#include "WhitePlayer.h"
#include "BlackPlayer.h"
using namespace std;


bool castling(Position* cast,int k,int j,WhitePlayer& wp,BlackPlayer bp){
	if(j>cast->getcol()){
		if(wp.find(k,j+1)!=-1 || wp.find(k,j+2)!=-1){
			return false;
		}
		if(bp.find(k,j+1)!=-1 || bp.find(k,j+2)!=-1){
			return false;
		}
		if(bp.find(k,j+3)!=-1)
			return false;
		else if(wp.find(k,j+3)!=-1 && wp.getplayer(wp.find(k,j+3))->getmovementindex()==0){
			Position* curr=wp.getplayer(wp.find(k,j+3));
			cast->setposition(k,j+2);
			curr->setposition(k,j+1);
			return true;
		}
	}
	if(j<cast->getcol()){
		if(wp.find(k,j-1)!=-1 || wp.find(k,j-2)!=-1){
			return false;
		}
		if(bp.find(k,j-1)!=-1 || bp.find(k,j-2)!=-1){
			return false;
		}
		if(bp.find(k,j-3)!=-1)
			return false;
		else if(wp.find(k,j-3)!=-1 && wp.getplayer(wp.find(k,j-3))->getmovementindex()==0){
			Position* curr=wp.getplayer(wp.find(k,j-3));
			cast->setposition(k,j-2);
			curr->setposition(k,j-1);
			return true;
		}
	}
	return false;
}






bool legal_move_Black(int rowfind,int colfind,int k , int j,WhitePlayer& bp,BlackPlayer& blackP,bool dont){
	Position* found=blackP.getplayer(blackP.find(rowfind,colfind));
	if(k<0 || j<0 || k>7 || j>7)
		return false;
	//move blackking
	if(found->getname()=='K'){
		if(((k==found->getrow() && j==found->getcol()+2) || (k==found->getrow() && j==found->getcol()-2)) &&
				found->getmovementindex()==0){
				return castling(found,k,j,bp,blackP);
		}
		if((k==found->getrow()+1 && j==found->getcol()+1) || (k==found->getrow()-1 && j==found->getcol()+1)
			|| (k==found->getrow()+1 && j==found->getcol()-1) || (k==found->getrow()-1 && j==found->getcol()-1)
			|| k==found->getrow()+1 || k==found->getrow()-1 || j==found->getcol()+1 || j==found->getcol()-1){
			if(blackP.find(k,j)!=-1)
				return false;
			if(bp.find(k,j)!=-1){
				if(bp.getplayer(bp.find(k,j))->getname()=='k')
					return true;
				if(dont==false)
					bp.remove(bp.find(k,j));
				return true;
			}
			if(bp.find(k,j)==-1 && blackP.find(k,j)==-1){
				return true;
			}
			else return false;
		}
		return false;
	}
	if(found->getname()=='Q'){
		//same row move queen right
		if(k==found->getrow() && j>found->getcol()){
			for(int i=found->getcol() ; i<j ; i++){
				if(blackP.find(k,i)!=-1 || bp.find(j,i)!=-1){
					return false;
				}
			}
			if(blackP.find(k,j)!=-1)
				return false;
			if(bp.find(k,j)!=-1){
				if(bp.getplayer(bp.find(k,j))->getname()=='k')
					return true;
				if(dont==false)
					bp.remove(bp.find(k,j));
				return true;
			}
			if(bp.find(k,j)==-1 && blackP.find(k,j)==-1){
				return true;
			}
			else return false;
		}
		//same row move queen left
		if(k==found->getrow() && j<found->getcol()){
			for(int i=found->getcol()-1 ; i>j ; i--){
				if(blackP.find(k,i)!=-1 || bp.find(j,i)!=-1){
					return false;
				}
			}
			if(blackP.find(k,j)!=-1)
				return false;
			if(bp.find(k,j)!=-1){
				if(bp.getplayer(bp.find(k,j))->getname()=='k')
					return true;
				if(dont==false)
					bp.remove(bp.find(k,j));
				return true;
			}
			if(bp.find(k,j)==-1 && blackP.find(k,j)==-1){
				return true;
			}
			else return false;
		}
		//moving queen up same column
		if(k>found->getrow() && j==found->getcol()){
			for(int i=found->getrow()+1 ; i<k ; i++){
				if(blackP.find(i,j)!=-1 || bp.find(i,j)!=-1){
					return false;
				}
			}
			if(blackP.find(k,j)!=-1)
				return false;
			if(bp.find(k,j)!=-1){
				if(bp.getplayer(bp.find(k,j))->getname()=='k')
					return true;
				if(dont==false)
					bp.remove(bp.find(k,j));
				return true;
			}
			if(bp.find(k,j)==-1 && blackP.find(k,j)==-1){
				return true;
			}
			else return false;
		}
		//moving queen down same column
		if(k<found->getrow() && j==found->getcol()){
			for(int i=found->getrow()-1 ; i>k ; i--){
				if(blackP.find(i,j)!=-1 || bp.find(i,j)!=-1){
					return false;
				}
			}
			if(blackP.find(k,j)!=-1)
				return false;
			if(bp.find(k,j)!=-1){
				if(bp.getplayer(bp.find(k,j))->getname()=='k')
					return true;
				if(dont==false)
					bp.remove(bp.find(k,j));
				return true;
			}
			if(bp.find(k,j)==-1 && blackP.find(k,j)==-1){
				return true;
			}
			else return false;
		}
		//moving queen up diagonaly to the right
		if(k>found->getrow() && j>found->getcol()){
			int i,col=found->getcol()+1;
			for(i=found->getrow()+1 ; i<k && col<j ; i++){
				if(blackP.find(i,col)!=-1 || bp.find(i,col)!=-1)
					return false;
				col++;
			}
			if(i<k || col<j)
				return false;
			if(blackP.find(k,j)!=-1)
				return false;
			if(bp.find(k,j)!=-1){
				if(bp.getplayer(bp.find(k,j))->getname()=='k')
					return true;
				if(dont==false)
					bp.remove(bp.find(k,j));
				return true;
			}
			if(bp.find(k,j)==-1 && blackP.find(k,j)==-1){
				return true;
			}
			else return false;
		}
		//moving queen up diagonaly to the left
		if(k>found->getrow() && j<found->getcol()){
			int i,col=found->getcol()-1;
			for(i=found->getrow()+1 ; i<k && col>j ; i++){
				if(blackP.find(i,col)!=-1 || bp.find(i,col)!=-1)
					return false;
				col--;
			}
			if(i<k || col>j)
				return false;
			if(blackP.find(k,j)!=-1)
				return false;
			if(bp.find(k,j)!=-1){
				if(bp.getplayer(bp.find(k,j))->getname()=='k')
					return true;
				if(dont==false)
					bp.remove(bp.find(k,j));
				return true;
			}
			if(bp.find(k,j)==-1 && blackP.find(k,j)==-1){
				return true;
			}
			else return false;
		}
		//moving queen down diagonaly to the left
		if(k<found->getrow() && j<found->getcol()){
			int i,col=found->getcol()-1;
			for(i=found->getrow()-1 ; i>k && col>j ; i--){
				if(blackP.find(i,col)!=-1 || bp.find(i,col)!=-1)
					return false;
				col--;
			}
			if(i>k || col>j)
				return false;
			if(blackP.find(k,j)!=-1)
				return false;
			if(bp.find(k,j)!=-1){
				if(bp.getplayer(bp.find(k,j))->getname()=='k')
					return true;
				if(dont==false)
					bp.remove(bp.find(k,j));
				return true;
			}
			if(bp.find(k,j)==-1 && blackP.find(k,j)==-1){
				return true;
			}
			else return false;
		}
		//moving queen down diagonaly to the right
		if(k<found->getrow() && j>found->getcol()){
			int i,col=found->getcol()+1;
			for(i=found->getrow()-1 ; i>k && col<j ; i--){
				if(blackP.find(i,col)!=-1 || bp.find(i,col)!=-1)
					return false;
				col++;
			}
			if(i>k || col<j)
				return false;
			if(blackP.find(k,j)!=-1)
				return false;
			if(bp.find(k,j)!=-1){
				if(bp.getplayer(bp.find(k,j))->getname()=='k')
					return true;
				if(dont==false)
					bp.remove(bp.find(k,j));
				return true;
			}
			if(bp.find(k,j)==-1 && blackP.find(k,j)==-1){
				return true;
			}
			else return false;
		}
		return false;
	}
	if(found->getname()=='R'){
		//move rook to the right same row
		if(k==found->getrow() && j>found->getcol()){
			for(int i=found->getcol()+1 ; i<j ; i++){
				if(blackP.find(k,i)!=-1 || bp.find(j,i)!=-1){
					return false;
				}
			}
			if(blackP.find(k,j)!=-1)
				return false;
			if(bp.find(k,j)!=-1){
				if(bp.getplayer(bp.find(k,j))->getname()=='k')
					return true;
				if(dont==false)
					bp.remove(bp.find(k,j));
				return true;
			}
			if(bp.find(k,j)==-1 && blackP.find(k,j)==-1){
				return true;
			}
			else return false;
		}

		//move rook to the left same row
		if(k==found->getrow() && j<found->getcol()){
			for(int i=found->getcol()-1 ; i>j ; i--){
				if(blackP.find(k,i)!=-1 || bp.find(j,i)!=-1){
					return false;
				}
			}
			if(blackP.find(k,j)!=-1)
				return false;
			if(bp.find(k,j)!=-1){
				if(bp.getplayer(bp.find(k,j))->getname()=='k')
					return true;
				if(dont==false)
					bp.remove(bp.find(k,j));
				return true;
			}
			if(bp.find(k,j)==-1 && blackP.find(k,j)==-1){
				return true;
			}
			else return false;
		}

		//move rook up same column
		if(k>found->getrow() && j==found->getcol()){
			for(int i=found->getrow()+1 ; i<k ; i++){
				if(blackP.find(i,j)!=-1 || bp.find(i,j)!=-1){
					return false;
				}
			}
			if(blackP.find(k,j)!=-1)
				return false;
			if(bp.find(k,j)!=-1){
				if(bp.getplayer(bp.find(k,j))->getname()=='k')
					return true;
				if(dont==false)
					bp.remove(bp.find(k,j));
				return true;
			}
			if(bp.find(k,j)==-1 && blackP.find(k,j)==-1){
				return true;
			}
			else return false;
		}

		//move rook down same column
		if(k<found->getrow() && j==found->getcol()){
			for(int i=found->getrow()-1 ; i>k ; i--){
				if(blackP.find(i,j)!=-1 || bp.find(i,j)!=-1){
					return false;
				}
			}
			if(blackP.find(k,j)!=-1)
				return false;
			if(bp.find(k,j)!=-1){
				if(bp.getplayer(bp.find(k,j))->getname()=='k')
					return true;
				if(dont==false)
					bp.remove(bp.find(k,j));
				return true;
			}
			if(bp.find(k,j)==-1 && blackP.find(k,j)==-1){
				return true;
			}
			else return false;
		}
		return false;
	}
	if(found->getname()=='B'){
		//moving bishop up diagonaly to the right
		if(k>found->getrow() && j>found->getcol()){
			int i,col=found->getcol()+1;
			for(i=found->getrow()+1 ; i<k && col<j ; i++){
				if(blackP.find(i,col)!=-1 || bp.find(i,col)!=-1)
					return false;
				col++;
			}
			if(i<k || col<j)
				return false;
			if(blackP.find(k,j)!=-1)
				return false;
			if(bp.find(k,j)!=-1){
				if(bp.getplayer(bp.find(k,j))->getname()=='k')
					return true;
				if(dont==false)
					bp.remove(bp.find(k,j));
				return true;
			}
			if(bp.find(k,j)==-1 && blackP.find(k,j)==-1){
				return true;
			}
			else return false;
		}
		//moving bishop up diagonaly to the left
		if(k>found->getrow() && j<found->getcol()){
			int i,col=found->getcol()-1;
			for(i=found->getrow()+1 ; i<k && col>j ; i++){
				if(blackP.find(i,col)!=-1 || bp.find(i,col)!=-1)
					return false;
				col--;
			}
			if(i<k || col>j)
				return false;
			if(blackP.find(k,j)!=-1)
				return false;
			if(bp.find(k,j)!=-1){
				if(bp.getplayer(bp.find(k,j))->getname()=='k')
					return true;
				if(dont==false)
					bp.remove(bp.find(k,j));
				return true;
			}
			if(bp.find(k,j)==-1 && blackP.find(k,j)==-1){
				return true;
			}
			else return false;
		}
		//moving bishop down diagonaly to the left
		if(k<found->getrow() && j<found->getcol()){
			int i,col=found->getcol()-1;
			for(i=found->getrow()-1 ; i>k && col>j ; i--){
				if(blackP.find(i,col)!=-1 || bp.find(i,col)!=-1)
					return false;
				col--;
			}
			if(i>k || col>j)
				return false;
			if(blackP.find(k,j)!=-1)
				return false;
			if(bp.find(k,j)!=-1){
				if(bp.getplayer(bp.find(k,j))->getname()=='k')
					return true;
				if(dont==false)
					bp.remove(bp.find(k,j));
				return true;
			}
			if(bp.find(k,j)==-1 && blackP.find(k,j)==-1){
				return true;
			}
			else return false;
		}
		//moving bishop down diagonaly to the right
		if(k<found->getrow() && j>found->getcol()){
			int i,col=found->getcol()+1;
			for(i=found->getrow()-1 ; i>k && col<j ; i--){
				if(blackP.find(i,col)!=-1 || bp.find(i,col)!=-1)
					return false;
				col++;
			}
			if(i>k || col<j)
				return false;
			if(blackP.find(k,j)!=-1)
				return false;
			if(bp.find(k,j)!=-1){
				if(bp.getplayer(bp.find(k,j))->getname()=='k')
					return true;
				if(dont==false)
					bp.remove(bp.find(k,j));
				return true;
			}
			if(bp.find(k,j)==-1 && blackP.find(k,j)==-1){
				return true;
			}
			else return false;
		}
		return false;
	}
	//move blackknight
	if(found->getname()=='N'){
		if((k==found->getrow()+2 && j==found->getcol()+1) || (k==found->getrow()+2 && j==found->getcol()-1)
				|| (k==found->getrow()+1 && j==found->getcol()+2) || (k==found->getrow()-1 && j==found->getcol()+2)
				|| (k==found->getrow()+1 && j==found->getcol()-2) || (k==found->getrow()-1 && j==found->getcol()-2)
				|| (k==found->getrow()-2 && j==found->getcol()+1) || (k==found->getrow()-2 && j==found->getcol()-1)){
			if(blackP.find(k,j)!=-1)
				return false;
			if(bp.find(k,j)!=-1){
				if(bp.getplayer(bp.find(k,j))->getname()=='k')
					return true;
				if(dont==false)
					bp.remove(bp.find(k,j));
				return true;
			}
			if(bp.find(k,j)==-1 && blackP.find(k,j)==-1){
				return true;
			}
			else return false;
		}
		else return false;
	}
	//move blackpawn
	if(found->getname()=='P'){
		if(found->getmovementindex()>0){
			if((k==found->getrow()-1 && j==found->getcol()-1) || (k==found->getrow()-1 && j==found->getcol()+1)
					|| (k==found->getrow()-1 && j==found->getcol())){
				if(blackP.find(k,j)!=-1)
					return false;
				if(bp.find(k,j)!=-1){
					if(bp.getplayer(bp.find(k,j))->getname()=='k')
						return true;
					if(dont==false)
						bp.remove(bp.find(k,j));
					return true;
				}
				if(bp.find(k,j)==-1 && blackP.find(k,j)==-1){
					return true;
				}
				else return false;
			}
		}
		else{
			if((k==found->getrow()-1 && j==found->getcol()-1) || (k==found->getrow()-1 && j==found->getcol()+1)
					|| (k==found->getrow()-1 && j==found->getcol())){
				if(blackP.find(k,j)!=-1)
					return false;
				if(bp.find(k,j)!=-1){
					//do En Passant
					if(bp.find(k+1,j)!=-1 && bp.getplayer(bp.find(k+1,j))->getname()=='p' && bp.getplayer(bp.find(k+1,j))->getmovementindex()==1)
						bp.remove(bp.find(k+1,j));
					if(bp.getplayer(bp.find(k,j))->getname()=='k')
						return true;
					if(dont==false)
						bp.remove(bp.find(k,j));
					return true;
				}
				if(bp.find(k,j)==-1 && blackP.find(k,j)==-1){
					return true;
				}
				else return false;
			}
			if(k==found->getrow()-2 && j==found->getcol()){
				if(blackP.find(k-1,j)!=-1)
					return false;
				if(blackP.find(k,j)!=-1)
					return false;
				if(bp.find(k,j)!=-1){
					if(bp.getplayer(bp.find(k,j))->getname()=='k')
						return true;
					if(dont==false)
						bp.remove(bp.find(k,j));
					return true;
				}
				if(bp.find(k,j)==-1 && blackP.find(k,j)==-1){
					return true;
				}
				else return false;
			}
		}
	}
	return false;
}








bool legal_move_White(int rowfind,int colfind,int k , int j,BlackPlayer& bp,WhitePlayer& WhiteP,bool dont){
	Position* found=WhiteP.getplayer(WhiteP.find(rowfind,colfind));
	if(k<0 || j<0 || k>7 || j>7)
		return false;
	//move whiteking
	if(found->getname()=='k'){
		if(((k==found->getrow() && j==found->getcol()+2) || (k==found->getrow() && j==found->getcol()-2)) &&
			found->getmovementindex()==0){
			return castling(found,k,j,WhiteP,bp);
		}
		if((k==found->getrow()+1 && j==found->getcol()+1) || (k==found->getrow()-1 && j==found->getcol()+1)
			|| (k==found->getrow()+1 && j==found->getcol()-1) || (k==found->getrow()-1 && j==found->getcol()-1)
			|| k==found->getrow()+1 || k==found->getrow()-1 || j==found->getcol()+1 || j==found->getcol()-1){
			if(WhiteP.find(k,j)!=-1)
				return false;
			if(bp.find(k,j)!=-1){
				if(bp.getplayer(bp.find(k,j))->getname()=='K')
					return true;
				if(dont==false)
					bp.remove(bp.find(k,j));
				return true;
			}
			if(bp.find(k,j)==-1 && WhiteP.find(k,j)==-1){
				return true;
			}
			else return false;
		}
		return false;
	}
	if(found->getname()=='q'){
		//same row move queen right
		if(k==found->getrow() && j>found->getcol()){
			for(int i=found->getcol()+1 ; i<j ; i++){
				if(WhiteP.find(k,i)!=-1 || bp.find(j,i)!=-1){
					return false;
				}
			}
			if(WhiteP.find(k,j)!=-1)
				return false;
			if(bp.find(k,j)!=-1){
				if(bp.getplayer(bp.find(k,j))->getname()=='K')
					return true;
				if(dont==false)
					bp.remove(bp.find(k,j));
				return true;
			}
			if(bp.find(k,j)==-1 && WhiteP.find(k,j)==-1){
				return true;
			}
			else return false;
		}
		//same row move queen left
		if(k==found->getrow() && j<found->getcol()){
			for(int i=found->getcol()-1 ; i>j ; i--){
				if(WhiteP.find(k,i)!=-1 || bp.find(j,i)!=-1){
					return false;
				}
			}
			if(WhiteP.find(k,j)!=-1)
				return false;
			if(bp.find(k,j)!=-1){
				if(bp.getplayer(bp.find(k,j))->getname()=='K')
					return true;
				if(dont==false)
					bp.remove(bp.find(k,j));
				return true;
			}
			if(bp.find(k,j)==-1 && WhiteP.find(k,j)==-1){
				return true;
			}
			else return false;
		}
		//moving queen up same column
		if(k>found->getrow() && j==found->getcol()){
			for(int i=found->getrow()+1 ; i<k ; i++){
				if(WhiteP.find(i,j)!=-1 || bp.find(i,j)!=-1){
					return false;
				}
			}
			if(WhiteP.find(k,j)!=-1)
				return false;
			if(bp.find(k,j)!=-1){
				if(bp.getplayer(bp.find(k,j))->getname()=='K')
					return true;
				if(dont==false)
					bp.remove(bp.find(k,j));
				return true;
			}
			if(bp.find(k,j)==-1 && WhiteP.find(k,j)==-1){
				return true;
			}
			else return false;
		}
		//moving queen down same column
		if(k<found->getrow() && j==found->getcol()){
			for(int i=found->getrow()-1 ; i>k ; i--){
				if(WhiteP.find(i,j)!=-1 || bp.find(i,j)!=-1){
					return false;
				}
			}
			if(WhiteP.find(k,j)!=-1)
				return false;
			if(bp.find(k,j)!=-1){
				if(bp.getplayer(bp.find(k,j))->getname()=='K')
					return true;
				if(dont==false)
					bp.remove(bp.find(k,j));
				return true;
			}
			if(bp.find(k,j)==-1 && WhiteP.find(k,j)==-1){
				return true;
			}
			else return false;
		}
		//moving queen up diagonaly to the right
		if(k>found->getrow() && j>found->getcol()){
			int i,col=found->getcol()+1;
			for(i=found->getrow()+1 ; i<k && col<j ; i++){
				if(WhiteP.find(i,col)!=-1 || bp.find(i,col)!=-1)
					return false;
				col++;
			}
			if(i<k || col<j)
				return false;
			if(WhiteP.find(k,j)!=-1)
				return false;
			if(bp.find(k,j)!=-1){
				if(bp.getplayer(bp.find(k,j))->getname()=='K')
					return true;
				if(dont==false)
					bp.remove(bp.find(k,j));
				return true;
			}
			if(bp.find(k,j)==-1 && WhiteP.find(k,j)==-1){
				return true;
			}
			else return false;
		}
		//moving queen up diagonaly to the left
		if(k>found->getrow() && j<found->getcol()){
			int i,col=found->getcol()-1;
			for(i=found->getrow()+1 ; i<k && col>j ; i++){
				if(WhiteP.find(i,col)!=-1 || bp.find(i,col)!=-1)
					return false;
				col--;
			}
			if(i<k || col>j)
				return false;
			if(WhiteP.find(k,j)!=-1)
				return false;
			if(bp.find(k,j)!=-1){
				if(bp.getplayer(bp.find(k,j))->getname()=='K')
					return true;
				if(dont==false)
					bp.remove(bp.find(k,j));
				return true;
			}
			if(bp.find(k,j)==-1 && WhiteP.find(k,j)==-1){
				return true;
			}
			else return false;
		}
		//moving queen down diagonaly to the left
		if(k<found->getrow() && j<found->getcol()){
			int i,col=found->getcol()-1;
			for(i=found->getrow()-1 ; i>k && col>j ; i--){
				if(WhiteP.find(i,col)!=-1 || bp.find(i,col)!=-1)
					return false;
				col--;
			}
			if(i>k || col>j)
				return false;
			if(WhiteP.find(k,j)!=-1)
				return false;
			if(bp.find(k,j)!=-1){
				if(bp.getplayer(bp.find(k,j))->getname()=='K')
					return true;
				if(dont==false)
					bp.remove(bp.find(k,j));
				return true;
			}
			if(bp.find(k,j)==-1 && WhiteP.find(k,j)==-1){
				return true;
			}
			else return false;
		}
		//moving queen down diagonaly to the right
		if(k<found->getrow() && j>found->getcol()){
			int i,col=found->getcol()+1;
			for(i=found->getrow()-1 ; i>k && col<j ; i--){
				if(WhiteP.find(i,col)!=-1 || bp.find(i,col)!=-1)
					return false;
				col++;
			}
			if(i>k || col<j)
				return false;
			if(WhiteP.find(k,j)!=-1)
				return false;
			if(bp.find(k,j)!=-1){
				if(bp.getplayer(bp.find(k,j))->getname()=='K')
					return true;
				if(dont==false)
					bp.remove(bp.find(k,j));
				return true;
			}
			if(bp.find(k,j)==-1 && WhiteP.find(k,j)==-1){
				return true;
			}
			else return false;
		}
		return false;
	}
	if(found->getname()=='r'){
		//move rook to the right same row
		if(k==found->getrow() && j>found->getcol()){
			for(int i=found->getcol()+1 ; i<j ; i++){
				if(WhiteP.find(k,i)!=-1 || bp.find(j,i)!=-1){
					return false;
				}
			}
			if(WhiteP.find(k,j)!=-1)
				return false;
			if(bp.find(k,j)!=-1){
				if(bp.getplayer(bp.find(k,j))->getname()=='K')
					return true;
				if(dont==false)
					bp.remove(bp.find(k,j));
				return true;
			}
			if(bp.find(k,j)==-1 && WhiteP.find(k,j)==-1){
				return true;
			}
			else return false;
		}
		//move rook to the left same row
		if(k==found->getrow() && j<found->getcol()){
			for(int i=found->getcol()-1 ; i>j ; i--){
				if(WhiteP.find(k,i)!=-1 || bp.find(j,i)!=-1){
					return false;
				}
			}
			if(WhiteP.find(k,j)!=-1)
				return false;
			if(bp.find(k,j)!=-1){
				if(bp.getplayer(bp.find(k,j))->getname()=='K')
					return true;
				if(dont==false)
					bp.remove(bp.find(k,j));
				return true;
			}
			if(bp.find(k,j)==-1 && WhiteP.find(k,j)==-1){
				return true;
			}
			else return false;
		}
		//move rook up same column
		if(k>found->getrow() && j==found->getcol()){
			for(int i=found->getrow()+1 ; i<k ; i++){
				if(WhiteP.find(i,j)!=-1 || bp.find(i,j)!=-1){
					return false;
				}
			}
			if(WhiteP.find(k,j)!=-1)
				return false;
			if(bp.find(k,j)!=-1){
				if(bp.getplayer(bp.find(k,j))->getname()=='K')
					return true;
				if(dont==false)
					bp.remove(bp.find(k,j));
				return true;
			}
			if(bp.find(k,j)==-1 && WhiteP.find(k,j)==-1){
				return true;
			}
			else return false;
		}
		//move rook down same column
		if(k<found->getrow() && j==found->getcol()){
			for(int i=found->getrow()-1 ; i>k ; i--){
				if(WhiteP.find(i,j)!=-1 || bp.find(i,j)!=-1){
					return false;
				}
			}
			if(WhiteP.find(k,j)!=-1)
				return false;
			if(bp.find(k,j)!=-1){
				if(bp.getplayer(bp.find(k,j))->getname()=='K')
					return true;
				if(dont==false)
					bp.remove(bp.find(k,j));
				return true;
			}
			if(bp.find(k,j)==-1 && WhiteP.find(k,j)==-1){
				return true;
			}
			else return false;
		}
		return false;
	}
	if(found->getname()=='b'){
		//moving bishop up diagonaly to the right
		if(k>found->getrow() && j>found->getcol()){
			int i,col=found->getcol()+1;
			for(i=found->getrow()+1 ; i<k && col<j ; i++){
				if(WhiteP.find(i,col)!=-1 || bp.find(i,col)!=-1)
					return false;
				col++;
			}
			if(i<k || col<j)
				return false;
			if(WhiteP.find(k,j)!=-1)
				return false;
			if(bp.find(k,j)!=-1){
				if(bp.getplayer(bp.find(k,j))->getname()=='K')
					return true;
				if(dont==false)
					bp.remove(bp.find(k,j));
				return true;
			}
			if(bp.find(k,j)==-1 && WhiteP.find(k,j)==-1){
				return true;
			}
			else return false;
		}
		//moving bishop up diagonaly to the left
		if(k>found->getrow() && j<found->getcol()){
			int i,col=found->getcol()-1;
			for(i=found->getrow()+1 ; i<k && col>j ; i++){
				if(WhiteP.find(i,col)!=-1 || bp.find(i,col)!=-1)
					return false;
				col--;
			}
			if(i<k || col>j)
				return false;
			if(WhiteP.find(k,j)!=-1)
				return false;
			if(bp.find(k,j)!=-1){
				if(bp.getplayer(bp.find(k,j))->getname()=='K')
					return true;
				if(dont==false)
					bp.remove(bp.find(k,j));
				return true;
			}
			if(bp.find(k,j)==-1 && WhiteP.find(k,j)==-1){
				return true;
			}
			else return false;
		}
		//moving bishop down diagonaly to the left
		if(k<found->getrow() && j<found->getcol()){
			int i,col=found->getcol()-1;
			for(i=found->getrow()-1 ; i>k && col>j ; i--){
				if(WhiteP.find(i,col)!=-1 || bp.find(i,col)!=-1)
					return false;
				col--;
			}
			if(i>k || col>j)
				return false;
			if(WhiteP.find(k,j)!=-1)
				return false;
			if(bp.find(k,j)!=-1){
				if(bp.getplayer(bp.find(k,j))->getname()=='K')
					return true;
				if(dont==false)
					bp.remove(bp.find(k,j));
				return true;
			}
			if(bp.find(k,j)==-1 && WhiteP.find(k,j)==-1){
				return true;
			}
			else return false;
		}
		//moving bishop down diagonaly to the right
		if(k<found->getrow() && j>found->getcol()){
			int i,col=found->getcol()+1;
			for(i=found->getrow()-1 ; i>k && col<j ; i--){
				if(WhiteP.find(i,col)!=-1 || bp.find(i,col)!=-1)
					return false;
				col++;
			}
			if(i>k || col<j)
				return false;
			if(WhiteP.find(k,j)!=-1)
				return false;
			if(bp.find(k,j)!=-1){
				if(bp.getplayer(bp.find(k,j))->getname()=='K')
					return true;
				if(dont==false)
					bp.remove(bp.find(k,j));
				return true;
			}
			if(bp.find(k,j)==-1 && WhiteP.find(k,j)==-1){
				return true;
			}
			else return false;
		}
		return false;
	}
	//move whiteknight
	if(found->getname()=='n'){
		if((k==found->getrow()+2 && j==found->getcol()+1) || (k==found->getrow()+2 && j==found->getcol()-1)
				|| (k==found->getrow()+1 && j==found->getcol()+2) || (k==found->getrow()-1 && j==found->getcol()+2)
				|| (k==found->getrow()+1 && j==found->getcol()-2) || (k==found->getrow()-1 && j==found->getcol()-2)
				|| (k==found->getrow()-2 && j==found->getcol()+1) || (k==found->getrow()-2 && j==found->getcol()-1)){
			if(WhiteP.find(k,j)!=-1)
				return false;
			if(bp.find(k,j)!=-1){
				if(bp.getplayer(bp.find(k,j))->getname()=='K')
					return true;
				if(dont==false)
					bp.remove(bp.find(k,j));
				return true;
			}
			if(bp.find(k,j)==-1 && WhiteP.find(k,j)==-1){
				return true;
			}
			else return false;
		}
		else return false;
	}
	//move whitepawn
	if(found->getname()=='p'){
		if(found->getmovementindex()>0){
			if((k==found->getrow()+1 && j==found->getcol()+1) || (k==found->getrow()+1 && j==found->getcol()-1)
					|| (k==found->getrow()+1 && j==found->getcol())){
				if(WhiteP.find(k,j)!=-1)
					return false;
				if(bp.find(k,j)!=-1){
					if(bp.getplayer(bp.find(k,j))->getname()=='K')
						return true;
					if(dont==false)
						bp.remove(bp.find(k,j));
					return true;
				}
				if(bp.find(k,j)==-1 && WhiteP.find(k,j)==-1){
					return true;
				}
				else return false;
			}
		}
		else{
			if((k==found->getrow()+1 && j==found->getcol()+1) || (k==found->getrow()+1 && j==found->getcol()-1)
					|| (k==found->getrow()+1 && j==found->getcol())){
				if(WhiteP.find(k,j)!=-1)
					return false;
				if(bp.find(k,j)!=-1){
					if(bp.find(k-1,j)!=-1 && bp.getplayer(bp.find(k-1,j))->getname()=='p' && bp.getplayer(bp.find(k-1,j))->getmovementindex()==1)
						bp.remove(bp.find(k-1,j));
					if(bp.getplayer(bp.find(k,j))->getname()=='K')
						return true;
					if(dont==false)
						bp.remove(bp.find(k,j));
					return true;
				}
				if(bp.find(k,j)==-1 && WhiteP.find(k,j)==-1){
					return true;
				}
				else return false;
			}
			if(k==found->getrow()+2 && j==found->getcol()){
				if(WhiteP.find(k-1,j)!=-1)
					return false;
				if(WhiteP.find(k,j)!=-1)
					return false;
				if(bp.find(k,j)!=-1){
					if(bp.getplayer(bp.find(k,j))->getname()=='K')
						return true;
					if(dont==false)
						bp.remove(bp.find(k,j));
					return true;
				}
				if(bp.find(k,j)==-1 && WhiteP.find(k,j)==-1)
					return true;
				else return false;
			}
		}
	}
	return false;
}




//print the board
void printBoard(BlackPlayer& bp,WhitePlayer& wp){
	int foundblack,foundwhite;
	for(int i=8 ; i>0 ; i--){
		cout << i << " ";
		for (int j=0 ; j<8 ; j++){
			foundblack=bp.find(i-1,j);
			foundwhite=wp.find(i-1,j);
			if(foundblack!=-1){
				cout << bp.getplayer(foundblack)->getname() << " ";
			}
			else if(foundwhite!=-1){
				cout << wp.getplayer(foundwhite)->getname() << " ";
			}
			else
				cout << ". ";
		}
		cout << endl;
	}
	cout << "  ";
	char curr='A';
	for(int i=0 ; i<8 ; i++){
		cout << curr << " ";
		curr++;
	}
	cout << endl;
}


//check if black king is targeted
bool checkmatepossible_black(BlackPlayer& bp,WhitePlayer& wp, int& attacker , int& king){
	for(int i=0 ; i<bp.getsize(); i++){
		if(bp.getplayer(i)->getname()=='K')
			king=i;
	}
	for(int i=0 ; i<wp.getsize(); i++){
		if(legal_move_White(wp.getplayer(i)->getrow(),wp.getplayer(i)->getcol(),bp.getplayer(king)->getrow(),bp.getplayer(king)->getcol(),bp,wp,true)==true){
			attacker=i;
			return true;
		}
	}
	return false;
}


//check if white king is targeted
bool checkmatepossible_white(BlackPlayer& bp,WhitePlayer& wp, int& attacker , int& king){
	for(int i=0 ; i<wp.getsize(); i++){
		if(wp.getplayer(i)->getname()=='k')
			king=i;
	}
	for(int i=0 ; i<bp.getsize(); i++){
		if(legal_move_Black(bp.getplayer(i)->getrow(),bp.getplayer(i)->getcol(),wp.getplayer(king)->getrow(),wp.getplayer(king)->getcol(),wp,bp,true)==true){
			attacker=i;
			return true;
		}
	}
	return false;
}

//check if black king can be saved
bool block_whitecheckmate(BlackPlayer& bp,WhitePlayer& wp, int& attacker , int& king){
	Position* found=bp.getplayer(attacker);
	int k,j;
	k=wp.getplayer(king)->getrow();
	j=wp.getplayer(king)->getcol();
	if(found->getname()=='K')
		return false;
	if(found->getname()=='Q'){
		//same row move queen right
		if(k==found->getrow() && j>found->getcol()){
			for(int i=found->getcol() ; i<j ; i++){
				for(int l=0 ; l<wp.getsize(); l++){
					if(wp.getplayer(l)->getname()!='k' && legal_move_White(wp.getplayer(l)->getrow(),wp.getplayer(l)->getcol(),k,i,bp,wp,true)==true){
						return true;
					}
				}
			}
			return false;
		}
		//same row move queen left
		if(k==found->getrow() && j<found->getcol()){
			for(int i=found->getcol() ; i>j ; i++){
				for(int l=0 ; l<wp.getsize(); l++){
					if(wp.getplayer(l)->getname()!='k' && legal_move_White(wp.getplayer(l)->getrow(),wp.getplayer(l)->getcol(),k,i,bp,wp,true)==true){
						return true;
					}
				}
			}
			return false;
		}
		//moving queen up same column
		if(k>found->getrow() && j==found->getcol()){
			for(int i=found->getrow() ; i<k ; i++){
				for(int l=0 ; l<wp.getsize(); l++){
					if(wp.getplayer(l)->getname()!='k' && legal_move_White(wp.getplayer(l)->getrow(),wp.getplayer(l)->getcol(),i,j,bp,wp,true)==true){
						return true;
					}
				}
			}
			return false;
		}
		//moving queen down same column
		if(k<found->getrow() && j==found->getcol()){
			for(int i=found->getrow() ; i>k ; i++){
				for(int l=0 ; l<wp.getsize(); l++){
					if(wp.getplayer(l)->getname()!='k' && legal_move_White(wp.getplayer(l)->getrow(),wp.getplayer(l)->getcol(),i,j,bp,wp,true)==true){
						return true;
					}
				}
			}
			return false;
		}
		//moving queen up diagonaly to the right
		if(k>found->getrow() && j>found->getcol()){
			int col=found->getcol();
			for(int i=found->getrow() ; i<k && col<j ; i++){
				for(int l=0 ; l<wp.getsize(); l++){
					if(wp.getplayer(l)->getname()!='k' && legal_move_White(wp.getplayer(l)->getrow(),wp.getplayer(l)->getcol(),i,col,bp,wp,true)==true){
						return true;
					}
				}
				col++;
			}
			return false;
		}
			//moving queen up diagonaly to the left
		if(k>found->getrow() && j<found->getcol()){
			int col=found->getcol();
			for(int i=found->getrow() ; i<k && col>j ; i++){
				for(int l=0 ; l<wp.getsize(); l++){
					if(wp.getplayer(l)->getname()!='k' && legal_move_White(wp.getplayer(l)->getrow(),wp.getplayer(l)->getcol(),i,col,bp,wp,true)==true){
						return true;
					}
				}
				col--;
			}
			return false;
		}
		//moving queen down diagonaly to the left
		if(k<found->getrow() && j<found->getcol()){
			int col=found->getcol();
			for(int i=found->getrow() ; i>k && col>j ; i--){
				for(int l=0 ; l<wp.getsize(); l++){
					if(wp.getplayer(l)->getname()!='k' && legal_move_White(wp.getplayer(l)->getrow(),wp.getplayer(l)->getcol(),i,col,bp,wp,true)==true){
						return true;
					}
				}
				col--;
			}
			return false;
		}
		//moving queen down diagonaly to the right
		if(k<found->getrow() && j>found->getcol()){
			int col=found->getcol();
			for(int i=found->getrow() ; i>k && col<j ; i--){
				for(int l=0 ; l<wp.getsize(); l++){
					if(wp.getplayer(l)->getname()!='k' && legal_move_White(wp.getplayer(l)->getrow(),wp.getplayer(l)->getcol(),i,col,bp,wp,true)==true){
						return true;
					}
				}
				col++;
			}
			return false;
		}
	}
	if(found->getname()=='R'){
		//move rook to the right same row
		if(k==found->getrow() && j>found->getcol()){
			for(int i=found->getcol() ; i<j ; i++){
				for(int l=0 ; l<wp.getsize(); l++){
					if(wp.getplayer(l)->getname()!='k' && legal_move_White(wp.getplayer(l)->getrow(),wp.getplayer(l)->getcol(),k,i,bp,wp,true)==true){
						return true;
					}
				}
			}
			return false;
		}
		//move rook to the left same row
		if(k==found->getrow() && j<found->getcol()){
			for(int i=found->getcol() ; i>j ; i--){
				for(int l=0 ; l<wp.getsize() ; l++){
					if(wp.getplayer(l)->getname()!='k' && legal_move_White(wp.getplayer(l)->getrow(),wp.getplayer(l)->getcol(),k,i,bp,wp,true)==true){
						return true;
					}
				}
			}
			return false;
		}
		//move rook up same column
		if(k>found->getrow() && j==found->getcol()){
			for(int i=found->getrow() ; i<k ; i++){
				for(int l=0 ; l<wp.getsize(); l++){
					if(wp.getplayer(l)->getname()!='k' && legal_move_White(wp.getplayer(l)->getrow(),wp.getplayer(l)->getcol(),i,j,bp,wp,true)==true){
						return true;
					}
				}
			}
			return false;
		}
		//move rook down same column
		if(k<found->getrow() && j==found->getcol()){
			for(int i=found->getrow() ; i>k ; i--){
				for(int l=0 ; l<wp.getsize(); l++){
					if(wp.getplayer(l)->getname()!='k' && legal_move_White(wp.getplayer(l)->getrow(),wp.getplayer(l)->getcol(),i,j,bp,wp,true)==true){
						return true;
					}
				}
			}
			return false;
		}
	}
	if(found->getname()=='B'){
		//moving bishop up diagonaly to the right
		if(k>found->getrow() && j>found->getcol()){
			int col=found->getcol();
			for(int i=found->getrow() ; i<k && col<j ; i++){
				for(int l=0 ; l<wp.getsize(); l++){
					if(wp.getplayer(l)->getname()!='k' && legal_move_White(wp.getplayer(l)->getrow(),wp.getplayer(l)->getcol(),i,col,bp,wp,true)==true){
						return true;
					}
				}
				col++;
			}
			return false;
		}
		//moving bishop up diagonaly to the left
		if(k>found->getrow() && j<found->getcol()){
			int col=found->getcol();
			for(int i=found->getrow() ; i<k && col>j ; i++){
				for(int l=0 ; l<wp.getsize() ; l++){
					if(wp.getplayer(l)->getname()!='k' && legal_move_White(wp.getplayer(l)->getrow(),wp.getplayer(l)->getcol(),i,col,bp,wp,true)==true){
						return true;
					}
				}
				col--;
			}
			return false;
		}
		//moving bishop down diagonaly to the left
		if(k<found->getrow() && j<found->getcol()){
			int col=found->getcol();
			for(int i=found->getrow() ; i>k && col>j ; i--){
				for(int l=0 ; l<wp.getsize(); l++){
					if(wp.getplayer(l)->getname()!='k' && legal_move_White(wp.getplayer(l)->getrow(),wp.getplayer(l)->getcol(),i,col,bp,wp,true)==true){
						return true;
					}
				}
				col--;
			}
			return false;
		}
				//moving bishop down diagonaly to the right
		if(k<found->getrow() && j>found->getcol()){
			int col=found->getcol()+1;
			for(int i=found->getrow() ; i>k && col<j ; i--){
				for(int l=0 ; l<wp.getsize(); l++){
					if(wp.getplayer(l)->getname()!='k' && legal_move_White(wp.getplayer(l)->getrow(),wp.getplayer(l)->getcol(),i,col,bp,wp,true)==true){
						return true;
					}
				}
				col++;
			}
			return false;
		}
	}
	if(found->getname()=='P'){
		for(int l=0 ; l<wp.getsize(); l++){
			if(wp.getplayer(l)->getname()!='k' && legal_move_White(wp.getplayer(l)->getrow(),wp.getplayer(l)->getcol(),k,j,bp,wp,true)==true){
				return true;
			}
		}
		return false;
	}
	return false;
}

//check if white can be saved
bool block_blackcheckmate(BlackPlayer& bp,WhitePlayer& wp, int& attacker , int& king){
	Position* found=wp.getplayer(attacker);
	int k,j;
	k=bp.getplayer(king)->getrow();
	j=bp.getplayer(king)->getcol();
	if(found->getname()=='k')
		return false;
	if(found->getname()=='q'){
		//same row move queen right
		if(k==found->getrow() && j>found->getcol()){
			for(int i=found->getcol() ; i<j ; i++){
				for(int l=0 ; l<bp.getsize(); l++){
					if(wp.getplayer(l)->getname()!='K' && legal_move_Black(bp.getplayer(l)->getrow(),bp.getplayer(l)->getcol(),k,i,wp,bp,true)==true){
						return true;
					}
				}
			}
			return false;
		}
		//same row move queen left
		if(k==found->getrow() && j<found->getcol()){
			for(int i=found->getcol() ; i>j ; i++){
				for(int l=0 ; l<bp.getsize(); l++){
					if(wp.getplayer(l)->getname()!='K' && legal_move_Black(bp.getplayer(l)->getrow(),bp.getplayer(l)->getcol(),k,i,wp,bp,true)==true){
						return true;
					}
				}
			}
			return false;
		}
		//moving queen up same column
		if(k>found->getrow() && j==found->getcol()){
			for(int i=found->getrow() ; i<k ; i++){
				for(int l=0 ; l<bp.getsize(); l++){
					if(wp.getplayer(l)->getname()!='K' && legal_move_Black(bp.getplayer(l)->getrow(),bp.getplayer(l)->getcol(),i,j,wp,bp,true)==true){
						return true;
					}
				}
			}
			return false;
		}
		//moving queen down same column
		if(k<found->getrow() && j==found->getcol()){
			for(int i=found->getrow() ; i>k ; i++){
				for(int l=0 ; l<bp.getsize(); l++){
					if(wp.getplayer(l)->getname()!='K' && legal_move_Black(bp.getplayer(l)->getrow(),bp.getplayer(l)->getcol(),i,j,wp,bp,true)==true){
						return true;
					}
				}
			}
			return false;
		}
		//moving queen up diagonaly to the right
		if(k>found->getrow() && j>found->getcol()){
			int col=found->getcol();
			for(int i=found->getrow() ; i<k && col<j ; i++){
				for(int l=0 ; l<bp.getsize(); l++){
					if(wp.getplayer(l)->getname()!='K' && legal_move_Black(bp.getplayer(l)->getrow(),bp.getplayer(l)->getcol(),i,col,wp,bp,true)==true){
						return true;
					}
				}
				col++;
			}
			return false;
		}
			//moving queen up diagonaly to the left
		if(k>found->getrow() && j<found->getcol()){
			int col=found->getcol();
			for(int i=found->getrow() ; i<k && col>j ; i++){
				for(int l=0 ; l<bp.getsize(); l++){
					if(wp.getplayer(l)->getname()!='K' && legal_move_Black(bp.getplayer(l)->getrow(),bp.getplayer(l)->getcol(),i,col,wp,bp,true)==true){
						return true;
					}
				}
				col--;
			}
			return false;
		}
		//moving queen down diagonaly to the left
		if(k<found->getrow() && j<found->getcol()){
			int col=found->getcol();
			for(int i=found->getrow() ; i>k && col>j ; i--){
				for(int l=0 ; l<bp.getsize(); l++){
					if(wp.getplayer(l)->getname()!='K' && legal_move_Black(bp.getplayer(l)->getrow(),bp.getplayer(l)->getcol(),i,col,wp,bp,true)==true){
						return true;
					}
				}
				col--;
			}
			return false;
		}
		//moving queen down diagonaly to the right
		if(k<found->getrow() && j>found->getcol()){
			int col=found->getcol();
			for(int i=found->getrow() ; i>k && col<j ; i--){
				for(int l=0 ; l<bp.getsize(); l++){
					if(wp.getplayer(l)->getname()!='K' && legal_move_Black(bp.getplayer(l)->getrow(),bp.getplayer(l)->getcol(),i,col,wp,bp,true)==true){
						return true;
					}
				}
				col++;
			}
			return false;
		}
	}
	if(found->getname()=='r'){
		//move rook to the right same row
		if(k==found->getrow() && j>found->getcol()){
			for(int i=found->getcol() ; i<j ; i++){
				for(int l=0 ; l<bp.getsize(); l++){
					if(wp.getplayer(l)->getname()!='K' && legal_move_Black(bp.getplayer(l)->getrow(),bp.getplayer(l)->getcol(),k,i,wp,bp,true)==true){
						return true;
					}
				}
			}
			return false;
		}
		//move rook to the left same row
		if(k==found->getrow() && j<found->getcol()){
			for(int i=found->getcol() ; i>j ; i--){
				for(int l=0 ; l<bp.getsize(); l++){
					if(wp.getplayer(l)->getname()!='K' && legal_move_Black(bp.getplayer(l)->getrow(),bp.getplayer(l)->getcol(),k,i,wp,bp,true)==true){
						return true;
					}
				}
			}
			return false;
		}
		//move rook up same column
		if(k>found->getrow() && j==found->getcol()){
			for(int i=found->getrow() ; i<k ; i++){
				for(int l=0 ; l<bp.getsize(); j++){
					if(wp.getplayer(l)->getname()!='K' && legal_move_Black(bp.getplayer(l)->getrow(),bp.getplayer(l)->getcol(),i,j,wp,bp,true)==true){
						return true;
					}
				}
			}
			return false;
		}
		//move rook down same column
		if(k<found->getrow() && j==found->getcol()){
			for(int i=found->getrow() ; i>k ; i--){
				for(int l=0 ; l<bp.getsize(); l++){
					if(wp.getplayer(l)->getname()!='K' && legal_move_Black(bp.getplayer(l)->getrow(),bp.getplayer(l)->getcol(),i,j,wp,bp,true)==true){
						return true;
					}
				}
			}
			return false;
		}
	}
	if(found->getname()=='b'){
		//moving bishop up diagonaly to the right
		if(k>found->getrow() && j>found->getcol()){
			int col=found->getcol();
			for(int i=found->getrow() ; i<k && col<j ; i++){
				for(int l=0 ; l<bp.getsize(); l++){
					if(wp.getplayer(l)->getname()!='K' && legal_move_Black(bp.getplayer(l)->getrow(),bp.getplayer(l)->getcol(),i,col,wp,bp,true)==true){
						return true;
					}
				}
				col++;
			}
			return false;
		}
		//moving bishop up diagonaly to the left
		if(k>found->getrow() && j<found->getcol()){
			int col=found->getcol();
			for(int i=found->getrow() ; i<k && col>j ; i++){
				for(int l=0 ; l<bp.getsize(); l++){
					if(wp.getplayer(l)->getname()!='K' && legal_move_Black(bp.getplayer(l)->getrow(),bp.getplayer(l)->getcol(),i,col,wp,bp,true)==true){
						return true;
					}
				}
				col--;
			}
			return false;
		}
		//moving bishop down diagonaly to the left
		if(k<found->getrow() && j<found->getcol()){
			int col=found->getcol();
			for(int i=found->getrow() ; i>k && col>j ; i--){
				for(int l=0 ; l<bp.getsize(); l++){
					if(wp.getplayer(l)->getname()!='K' && legal_move_Black(bp.getplayer(l)->getrow(),bp.getplayer(l)->getcol(),i,col,wp,bp,true)==true){
						return true;
					}
				}
					col--;
			}
			return false;
		}
				//moving bishop down diagonaly to the right
		if(k<found->getrow() && j>found->getcol()){
			int col=found->getcol();
			for(int i=found->getrow() ; i>k && col<j ; i--){
				for(int l=0 ; l<bp.getsize(); l++){
					if(wp.getplayer(l)->getname()!='K' && legal_move_Black(bp.getplayer(l)->getrow(),bp.getplayer(l)->getcol(),i,col,wp,bp,true)==true){
						return true;
					}
				}
				col++;
			}
			return false;
		}
	}
	if(found->getname()=='p'){
		for(int l=0 ; l<bp.getsize() ; l++){
			if(wp.getplayer(l)->getname()!='K' && legal_move_Black(bp.getplayer(l)->getrow(),wp.getplayer(l)->getcol(),k,j,wp,bp,true)==true){
				return true;
			}
		}
		return false;
	}
	return false;
}


//check if there insufficent materials for both parties to finish the game
bool insufficentDraw(BlackPlayer& bp,WhitePlayer& wp){
	int blackqueens=0,blackrooks=0,blackbishops=0,blackknights=0,blackpawns=0;
	int whitequeens=0,whiterooks=0,whitebishops=0,whiteknights=0,whitepawns=0;
	for(int i=0 ; i<16 && bp.getplayer(i)!=NULL ; i++){
		if(bp.getplayer(i)->getname()=='Q')
			blackqueens++;
		if(bp.getplayer(i)->getname()=='R')
			blackrooks++;
		if(bp.getplayer(i)->getname()=='B')
			blackbishops++;
		if(bp.getplayer(i)->getname()=='N')
			blackknights++;
		if(bp.getplayer(i)->getname()=='P')
			blackpawns++;
		if(bp.getplayer(i)->getname()=='q')
			whitequeens++;
		if(bp.getplayer(i)->getname()=='r')
			whiterooks++;
		if(bp.getplayer(i)->getname()=='b')
			whitebishops++;
		if(bp.getplayer(i)->getname()=='n')
			whiteknights++;
		if(bp.getplayer(i)->getname()=='p')
			whitepawns++;
	}
	if((blackqueens==0 && blackrooks==0 && blackbishops==0 && blackknights==0 && blackpawns==0 &&
	whitequeens==0 && whiterooks==0 && whitebishops==0 && whiteknights==0 && whitepawns==0)
	|| (blackqueens==0 && blackrooks==0 && blackbishops==0 && blackknights==0 && blackpawns==0 &&
	whitequeens==0 && whiterooks==0 && whitebishops==1 && whiteknights==0 && whitepawns==0)
	|| (blackqueens==0 && blackrooks==0 && blackbishops==0 && blackknights==0 && blackpawns==0 &&
	whitequeens==0 && whiterooks==0 && whitebishops==0 && whiteknights==1 && whitepawns==0)
	|| (blackqueens==0 && blackrooks==0 && blackbishops==1 && blackknights==0 && blackpawns==0 &&
	whitequeens==0 && whiterooks==0 && whitebishops==0 && whiteknights==0 && whitepawns==0)
	|| (blackqueens==0 && blackrooks==0 && blackbishops==0 && blackknights==1 && blackpawns==0 &&
	whitequeens==0 && whiterooks==0 && whitebishops==0 && whiteknights==0 && whitepawns==0)
	|| (blackqueens==0 && blackrooks==0 && blackbishops==1 && blackknights==0 && blackpawns==0 &&
	whitequeens==0 && whiterooks==0 && whitebishops==1 && whiteknights==0 && whitepawns==0)
	|| (blackqueens==0 && blackrooks==0 && blackbishops==1 && blackknights==0 && blackpawns==0 &&
	whitequeens==0 && whiterooks==0 && whitebishops==0 && whiteknights==1 && whitepawns==0)
	|| (blackqueens==0 && blackrooks==0 && blackbishops==0 && blackknights==1 && blackpawns==0 &&
	whitequeens==0 && whiterooks==0 && whitebishops==1 && whiteknights==0 && whitepawns==0)){
		return true;
	}
	return false;
}












int main(){
	BlackPlayer blackP=BlackPlayer();
	WhitePlayer whiteP=WhitePlayer();
	int whitekingattacker=0,whiteking=0,blackkingattacker=0,blackking=0;
	string buffer;
	istringstream iss(buffer);
	string from,to,promo;
	int playcounter=1;
	while(true){
		printBoard(blackP,whiteP);
		if(insufficentDraw(blackP,whiteP)==true){
			cout << "The game is drawn due to insufficient material!" << endl;
		}
		if(playcounter%2!=0){
			cout << playcounter << ") white`s turn, please enter a move:";
		}
		if(playcounter%2==0){
			cout << playcounter << ") black`s turn, please enter a move:";
		}
		rerun:
		getline(cin,buffer);
		//if a third input slot is been intered and there is no promotion
		if(buffer[4]-'1'!=0 || buffer[4]-'1'!=7){
			if(buffer[6]){
				cerr << "Invalid input; please enter a move" <<endl;
				goto rerun;
			}
		}
		//check if input is valid
		if(buffer[0]>'H' || buffer[0]<'A' || buffer[1]<'1' || buffer[1]>'8'|| buffer[3]>'H' || buffer[3]<'A' || buffer[4]<'1' || buffer[4]>'8' || buffer[2]!=' '){
			cerr << "Invalid input; please enter a move" <<endl;
			goto rerun;
		}
		//enter if current player is white
		if(playcounter%2!=0){
			if(whiteP.find(buffer[1]-'1',buffer[0]-'A')==-1){
				cerr << "Illegal move; please enter a move" <<endl;
				goto rerun;
			}
			if(legal_move_White(buffer[1]-'1',buffer[0]-'A',buffer[4]-'1',buffer[3]-'A',blackP,whiteP,false)){
				whiteP.getplayer(whiteP.find(buffer[1]-'1',buffer[0]-'A'))->setmovementindex(whiteP.getplayer(whiteP.find(buffer[1]-'1',buffer[0]-'A'))->getmovementindex()+1);
				whiteP.getplayer(whiteP.find(buffer[1]-'1',buffer[0]-'A'))->setposition(buffer[4]-'1',buffer[3]-'A');

			}
			else{
				cerr << "Illegal move; please enter a move" <<endl;
				goto rerun;
			}
			//check if we reach promotion slot
			if(buffer[4]-'1'==7){
				if(buffer[6]=='q' || buffer[6]=='r' || buffer[6]=='b' || buffer[6]=='n'){
					whiteP.getplayer(whiteP.find(buffer[4]-'1',buffer[3]-'A'))->setname(buffer[6]);
				}
				else{
					cerr << "Invalid input; please enter a move" <<endl;
					goto rerun;
				}
			}
			//check if black is checkmate
			if(checkmatepossible_black(blackP,whiteP,blackkingattacker,blackking)==true){
				if(block_blackcheckmate(blackP,whiteP,blackkingattacker,blackking)==false){
					printBoard(blackP,whiteP);
					cout << "White wins with checkmate!" << endl;
					return 0;
				}
			}

		}
		//enter if current player is black
		if(playcounter%2==0){
			if(blackP.find(buffer[1]-'1',buffer[0]-'A')==-1){
				cerr << "Illegal move; please enter a move" <<endl;
				goto rerun;
			}
			if(legal_move_Black(buffer[1]-'1',buffer[0]-'A',buffer[4]-'1',buffer[3]-'A',whiteP,blackP,false)){
				blackP.getplayer(blackP.find(buffer[1]-'1',buffer[0]-'A'))->setmovementindex(blackP.getplayer(blackP.find(buffer[1]-'1',buffer[0]-'A'))->getmovementindex()+1);
				blackP.getplayer(blackP.find(buffer[1]-'1',buffer[0]-'A'))->setposition(buffer[4]-'1',buffer[3]-'A');

			}
			else{
				cerr << "Illegal move; please enter a move" <<endl;
				goto rerun;
			}
			//check if we reach promotion slot
			if(buffer[4]-'1'==0){
				if(buffer[6]=='Q' || buffer[6]=='R' || buffer[6]=='B' || buffer[6]=='N'){
					blackP.getplayer(blackP.find(buffer[4]-'1',buffer[3]-'A'))->setname(buffer[6]);
				}
				else{
					cerr << "Invalid input; please enter a move" <<endl;
					goto rerun;
				}
			}
			//check if white is checkmate
			if(checkmatepossible_white(blackP,whiteP,whitekingattacker,whiteking)==true){
				if(block_whitecheckmate(blackP,whiteP,whitekingattacker,whiteking)==false){
					printBoard(blackP,whiteP);
					cout << "Black wins with checkmate!" << endl;
					return 0;
				}
			}
		}
		playcounter++;
	}

}
