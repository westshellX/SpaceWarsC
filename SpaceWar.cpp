#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <iomanip>



using namespace std;
void printScreen(char table[25][80],unsigned int x=0,unsigned int y=0,bool showNum=false);
void playerMove(struct JUGADOR *player, struct PROYECTIL pList[10], char table[20][80]);
void shotFired(struct JUGADOR *player, struct PROYECTIL pList[10], int d);
void createObstaculosEnemies(struct ENEMIGO eList[10], struct OBSTACULO oList[10]);
void setScreenBorders(char table[20][80]);
void obstacleMove(struct OBSTACULO *obs);
void proyectilMove(struct PROYECTIL *proyectil);
void refreshTable(struct JUGADOR *player, struct PROYECTIL pList[10], struct ENEMIGO eList[10], struct OBSTACULO oList[10], bool *gameOver, char table[25][80]);
bool menu(char table[25][80], bool* gameOver);
void clearTable(char table[25][80]);


struct JUGADOR {
	
	int x=12,y=40;
	
	char s='A';
	
	int shotsFired=0;
	
	
		
};

struct ENEMIGO {
	
	int x,y;
	
	bool visible = true;
	
	char s = '#';
	
	
};

//Œ˜∞‡—¿”Ô£∫…‰µØ
struct PROYECTIL {
	
	int x,y, dir;
	
	bool visible = false;
	
	char s ='*';
	
};

struct OBSTACULO {
	
	int x,y, increment=1, dir;
	
	bool visible=true;
	
	char s='|';
	
	
	
};


void main(){
	
	struct JUGADOR player;
	
	struct ENEMIGO eList[10];
	
	struct OBSTACULO oList[10];
	
	struct PROYECTIL pList[10];
	
	bool gameOver=false, seJuega=true;
	
	unsigned int tableX = 10, tableY = 10;
	char table[25][80]={{" "}};

	

	

/*
    if (err)
    {
        printf("An error occured: %d", err);
        return 1;
    }
    */
	
	
	while(seJuega){
		
		setScreenBorders(table);
	
		createObstaculosEnemies(eList, oList);
		
		player.x=12;
		
		player.y=40;
		
	
		
		while(!gameOver){
			
			
		/*	thread getUserInputThread{playerMove, &player, pList, table};
			
			sleep(200);
			
			getUserInputThread.join();*/
			
		
			playerMove(&player, pList, table);
		
			refreshTable(&player, pList, eList, oList, &gameOver, table);
			
			printScreen(table,tableX,tableY,true);
			
			
		}
		
		cout<<"GAMEOVER"<<endl;
		
		seJuega=menu(table, &gameOver);
		
	}	
	
}

void gameOver(){
	
	
	
	
}

void waiting(){
	
	
	
}

bool menu(char table[25][80], bool* gameOver){
	
	char opcion;
	
	
	do{
		//Œ˜∞‡—¿”Ô£∫"‘ŸÕÊ“ª¥Œ£ø"
		cout<<"Desea jugar nuevamente?";
		cin>>opcion;
		
		while(cin.fail()){
			cin.clear();
			cin.ignore(INT_MAX,'\n');
			cout<<"Desea jugar nuevamente?";
			cin>>opcion;
		}
		
	
	} while (opcion!='n'&&opcion!='s');
	
	
	if(opcion=='s'){
		
		*gameOver=false;
		return true;
		
	} else return false;
	

}

void clearTable(char table[25][80]){
	
	int i,z;
	
	for(i=0; i<25; i++){
		for(z=0; z<80; z++){
			
			table[i][z]=' ';
			
		}
	}
	
}

void refreshTable(struct JUGADOR *player, struct PROYECTIL pList[10], struct ENEMIGO eList[10], struct OBSTACULO oList[10], bool *gameOver, char table[25][80]){
	
	int i,z;
	
	//table[player->x][player->y]=player->s;

	
	for(i=0; i<25; i++){
		for(z=0; z<80; z++){
			
			table[i][z]=' ';
			
		}
	}
	
	
	setScreenBorders(table);
	
		
	for(i=0; i<10; i++){
		
		if((oList[i].x==player->x&&oList[i].y==player->y)||(eList[i].x==player->x&&eList[i].y==player->y)){
			
			*gameOver=true;
			break;
			
		}
		
		if(pList[i].visible){
			
			proyectilMove(&pList[i]);
			
			for(z=0; z<10; z++){
				
				if(eList[z].visible&&pList[i].x==eList[z].x&&pList[i].y==eList[z].y){
					
					eList[z].visible=false;
					pList[i].visible=false;
					break;
										
				}
			}
				
		}
		
	
		if(pList[i].visible)table[pList[i].x][pList[i].y]=pList[i].s;
		if(eList[i].visible)table[eList[i].x][eList[i].y]=eList[i].s;
		if(oList[i].visible){
			
			obstacleMove(&oList[i]);
			table[oList[i].x][oList[i].y]=oList[i].s;
				
		}
		
		
	}
	
	table[player->x][player->y]=player->s;
	
	
	
	
}

void checkCollision(struct OBSTACULO *oList[10], struct ENEMIGO *eList[10], struct JUGADOR *player, struct PROYECTIL *pList[10]){
	
	int i;
	
	for(i=0; i<10; i++){
		
		
		
	}
	
	
}

void obstacleMove(struct OBSTACULO *obs){
	
	int i;
	
	if(obs->dir!=0){
		
		if(obs->x==1||obs->x==24)obs->increment*=-1;
		obs->x+=obs->increment;

		
	} else {
		
		if(obs->y==1||obs->y==79)obs->increment*=-1;
		obs->y+=obs->increment;
		
	}
	
}

void proyectilMove(struct PROYECTIL *proyectil){
	
	switch (proyectil->dir){
		
		case 1: if(proyectil->x!=1) proyectil->x--;
				else proyectil->visible=false;
			
			break;
			
		case 2: if(proyectil->x!=24) proyectil->x++;
				else proyectil->visible=false;
			
			break;
			
		case 3: if(proyectil->y!=1) proyectil->y++;
				else proyectil->visible=false;
			
			break;
			
		case 4: if(proyectil->y!=79) proyectil->y--;
				else proyectil->visible=false;
			
			break;
				
		
	}
	
	
}

void shotFired(struct JUGADOR *player, struct PROYECTIL pList[10], int d){
	
	int i;
	
	for(i=0; i<10; i++){
		
		if(!pList[i].visible){
			
			pList[i].visible=true;			
			pList[i].x= player->x;
			pList[i].y= player->y;			
			pList[i].dir=d;
			
			break;
			
		}
		
	}
	
	
}

void createObstaculosEnemies(struct ENEMIGO eList[10], struct OBSTACULO oList[10]){
	
	int i;
	
	srand(time(NULL));
	
	for(i=0; i<10; i++){
		
		eList[i].x=rand()%23+1;
		eList[i].y=rand()%78+1;
		
		oList[i].x=rand()%23+1;
		oList[i].y=rand()%78+1;
		oList[i].dir=i%2;
				
		
	}
	
}

void playerMove(struct JUGADOR *player, struct PROYECTIL pList[10], char table[25][80]){
	

	//(72 up, 80 down, 77 right, 75 left)
	
	//table[player->x][player->y]=' ';
	
	
	
	switch (_getch()){
		
		case 75: if(player->y!=1)player->y--;
		break;
		
		case 77: if(player->y!=78)player->y++;
		break;
		
		case 72: if(player->x!=1)player->x--;
		break;
		
		case 80: if(player->x!=24)player->x++;
		break;
		
		case 'w': if(player->x!=1)shotFired(player, pList, 1);
		break;
		
		case 's': if(player->x!=24)shotFired(player, pList, 2);
		break;
	
		case 'd': if(player->y!=1)shotFired(player, pList, 3);
		break;
		
		case 'a': if(player->y!=78)shotFired(player, pList, 4);
		break;
		
	}
	
	//table[player->x][player->y]=player->s;
	
	
}

void setScreenBorders(char table[25][80]){
	
	int i;
	
	for(i=1; i<25; i++){
		
		table[i][0]='|';
		table[i][79]='|';
		
	}
	
	
	for(i=1; i<79;i++){
			
		table[0][i]='_';
		table[24][i]='_';
			
	}
	
	
}

void printScreen(char table[25][80],unsigned int x,unsigned int y,bool showNum){
	
	
	int i, z;
	
	system("cls");

	for (unsigned int rowIndex = 0; rowIndex < y - 1; ++rowIndex)
		std::cout << std::endl;
	for (unsigned int colIndex = 0; colIndex < x; ++colIndex)
		std::cout << ' ';
	if (showNum)
	{
		for (unsigned int colIndex = 0; showNum && colIndex < 80; ++colIndex)
			std::cout << 'c';
	}
	std::cout << std::endl;

	for(i=0; i<25; i++){
		for (unsigned int colIndex = 0; colIndex < x; ++colIndex)
		{
			if (showNum&&x >= 1 && colIndex == x - 1)
				std::cout << std::setw(2)<<i;
			else
				std::cout << ' ';
		}

		for(z=0; z<80; z++){
			
			cout<<table[i][z];
			
		}
		cout<<endl;
	}
	
	
}


