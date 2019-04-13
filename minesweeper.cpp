#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <iomanip>
#include <time.h>

using namespace std;

const int WIDTH = 9, HEIGHT = 9, BOM = 9;
const int WW = WIDTH+2, HH = HEIGHT+2;
int x = 0, y = 0;

void setcolor(unsigned short color){
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hCon,color);
}

void gotoxy(int x, int y){
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord;
	coord.X=x;
	coord.Y=y;
	SetConsoleCursorPosition(hCon, coord);
}

void setBom();
void setAngka(int peta[HEIGHT][WIDTH]);
void tampilin(int peta[HEIGHT][WIDTH]);

int main(){
	srand(time(0));
	bool w, a, s, d;
	
	setBom();
	
	while(!(GetKeyState(VK_ESCAPE) & 0x8000)){
	    if((GetKeyState('W') & 0x8000) && !w) {
			if((y <= HEIGHT-1) && (y > 0)) y--;
			w = 1;
	    }
	    if((GetKeyState('A') & 0x8000) && !a) {
			if((x <= WIDTH-1) && (x > 0)) x--;
			a = 1;
	    }
	    if((GetKeyState('S') & 0x8000) && !s) {
			if((y < HEIGHT-1) && (y >= 0)) y++;
			s = 1;
	    }
	    if((GetKeyState('D') & 0x8000) && !d) {
			if((x < WIDTH-1) && (x >= 0)) x++;
			d = 1;
	    }
	    
	    gotoxy(x, y);
	    
	    if(!(GetKeyState('W') & 0x8000)) {
			w = 0;
	    }
	    if(!(GetKeyState('A') & 0x8000)) {
			a = 0;
	    }
	    if(!(GetKeyState('S') & 0x8000)) {
			s = 0;
	    }
	    if(!(GetKeyState('D') & 0x8000)) {
			d = 0;
	    }
	}
	
	return 0;
}

void setBom(){
	int peta[HEIGHT][WIDTH] = {0};
	int xRand, yRand;
	
	for(int i = 0; i < BOM; i++){
		xRand = (rand()%(HEIGHT-2))+1;
		yRand = (rand()%(WIDTH-2))+1;
		if(peta[xRand][yRand] != 9){
			peta[xRand][yRand] = 9;
		}
	}
	
	setAngka(peta);
}

void setAngka(int peta[HEIGHT][WIDTH]){
	for(int i = 0; i < HEIGHT; i++){
		for(int j = 0; j < WIDTH; j++){
			if(peta[i][j] != 9){ //cek bukan bom
				if(peta[i+1][j] == 9){
					peta[i][j]++;
				}
				if(peta[i-1][j] == 9){
					peta[i][j]++;
				}
				if(peta[i][j+1] == 9){
					peta[i][j]++;
				}
				if(peta[i][j-1] == 9){
					peta[i][j]++;
				}
				if(peta[i+1][j+1] == 9){
					peta[i][j]++;
				}
				if(peta[i+1][j-1] == 9){
					peta[i][j]++;
				}
				if(peta[i-1][j+1] == 9){
					peta[i][j]++;
				}
				if(peta[i-1][j-1] == 9){
					peta[i][j]++;
				}
				
				//vertikal
				/*
				if(i == 0){
					if(peta[i+1][j] == 9){
						peta[i][j]++;
					}
				} else if(i == HEIGHT-1){
					if(peta[i-1][j] == 9){
						peta[i][j]++;
					}
				} else {
					if(peta[i+1][j] == 9){
						peta[i][j]++;
					}
					if(peta[i-1][j] == 9){
						peta[i][j]++;
					}
				}
				*/
				
				//horizontal
				/*
				if(j == 0){
					if(peta[i][j+1] == 9){
						peta[i][j]++;
					}
				} else if(j == WIDTH-1){
					if(peta[i][j-1] == 9){
						peta[i][j]++;
					}
				} else {
					if(peta[i][j+1] == 9){
						peta[i][j]++;
					}
					if(peta[i][j-1] == 9){
						peta[i][j]++;
					}
				}
				*/
			}
		}
	}
	
	tampilin(peta);
}

void tampilin(int peta[HEIGHT][WIDTH]){
	for(int i = 0; i < HEIGHT; i++){
		for(int j = 0; j < WIDTH; j++){
			if(peta[i][j] == 9) cout<<"*";
			else cout<<peta[i][j];
		}
		cout<<endl;
	}
	gotoxy(x, y);
}

