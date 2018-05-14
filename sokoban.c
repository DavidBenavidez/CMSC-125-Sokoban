#include "../../sdk/dexsdk.h"
#include "../../sdk/time.h"

#define YELLOW 54
#define PALE_YELLOW 62
#define ROYAL_BLUE 1
#define DARK_BLUE 8
#define GRAY 56
#define DARK_GREEN_BLUE 24
#define DARK_GRAY 19
#define ORANGE 52
#define PINK 53
#define LIGHT_BROWN 14
#define BROWN 20
#define LIGHT_YELLOW 55
#define WHITE 63
#define YELLOW 54
#define MAROON 32
#define LIGHT_GREEN 50
#define GREEN 58

#define BLACK 0
#define start '1'
#define main_menu '2'
#define quit_game '3'

int i, j, k, l;
int playerXPos, playerYPos;
int current_level_num = 1;

char levels[10][10][10]  = { {{'w','w','w','w','w','w','w','w','w','w'},{'w','e','e','e','b','e','e','e','e','w'},{'w','e','k','e','s','e','s','e','e','w'},{'w','e','e','e','e','b','e','e','e','w'},{'w','e','b','e','b','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','w','w','w','w','w','w','w','w','w'}},
							{{'w','w','w','w','w','w','w','w','w','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','w','w','w','w','w','w','w','w','w'}},
							{{'w','w','w','w','w','w','w','w','w','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','w','w','w','w','w','w','w','w','w'}},
							{{'w','w','w','w','w','w','w','w','w','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','w','w','w','w','w','w','w','w','w'}},
							{{'w','w','w','w','w','w','w','w','w','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','w','w','w','w','w','w','w','w','w'}},
							{{'w','w','w','w','w','w','w','w','w','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','w','w','w','w','w','w','w','w','w'}},
							{{'w','w','w','w','w','w','w','w','w','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','w','w','w','w','w','w','w','w','w'}},
							{{'w','w','w','w','w','w','w','w','w','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','w','w','w','w','w','w','w','w','w'}},
							{{'w','w','w','w','w','w','w','w','w','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','w','w','w','w','w','w','w','w','w'}},
							{{'w','w','w','w','w','w','w','w','w','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','w','w','w','w','w','w','w','w','w'}}
};
char current_level[10][10];

void header(int x, int y){ //displays header
	write_text("SOKOBAN",120,40,WHITE,1); //title

	//menu options
	write_text("1 - Start",115,70,WHITE,0); 
	write_text("2 - View High Scores",60,85,WHITE,0);
	write_text("3 - Quit",118,100,WHITE,0);
}

void erase(int x, int y, int w, int h){ //basically covers an area with a black rectangle 
   int i,j;
   for (i=y;i<=(y+h);i++)
      for (j=x;j<=(x+w);j++)
         write_pixel(j,i,100);
}

void print_wall(int x, int y){
	for(i = 0; i < 17; i++) write_pixel(x + i,y,MAROON); // top		
	for(i = 0; i < 17; i++) write_pixel(x + i,y + 16,MAROON); // bottom
	for(i = 0; i < 17; i++) write_pixel(x,y + i,MAROON); // left
	for(i = 0; i < 17; i++) write_pixel(x + 16,y + i,MAROON); // right
	//print deco
	for(l = y + 3; l < y + 17; l += 3){
		for(i = 1; i < 17; i++){
			write_pixel(x + i, l, MAROON);
		}
	}
	for(l = x + 3; l < x + 16; l += 3){
		for(i = 1; i < 17; i++){
			write_pixel(l,y + i,MAROON); 
		}
	}
}

void print_floor(int x, int y){
	for(l = y; l < y + 17; l++){
		for(i = 0; i < 17; i++){
			write_pixel(x+i, l, GRAY);		
		}
	}
	// print deco
	write_pixel(x + 2, y + 1, WHITE);
	write_pixel(x + 2, y + 2, WHITE);
	write_pixel(x + 7, y + 5, WHITE);
	write_pixel(x + 3, y + 6, WHITE);
	write_pixel(x + 8, y + 7, WHITE);
	write_pixel(x + 12, y + 7, WHITE);
	write_pixel(x + 6, y + 7, WHITE);
	write_pixel(x + 2, y + 9, WHITE);
	write_pixel(x + 11, y + 10, WHITE);
	write_pixel(x + 16, y + 10, WHITE);
	write_pixel(x + 9, y + 13, WHITE);
	write_pixel(x + 4, y + 15, WHITE);
	write_pixel(x + 10, y + 15, WHITE);
}

void print_box(int x, int y){
	for(l = y; l < y + 17; l++){
		for(i = 0; i < 17; i++){
			write_pixel(x+i, l, BROWN);		
		}
	}
	for(i = 0; i < 17; i++) write_pixel(x + i,y,BLACK); // top
	for(i = 0; i < 17; i++) write_pixel(x + i,y + 16,BLACK); // bottom
	for(i = 0; i < 17; i++) write_pixel(x,y + i,BLACK); // left
	for(i = 0; i <= 17; i++) write_pixel(x + 16,y + i,BLACK); // right
	// print deco
	for(i = 0; i < 17; i++) write_pixel(x + i, y+i+1, BLACK);
	for(i = 0; i < 17; i++) write_pixel(x + 16 - i, y + i + 1, BLACK);
}

void print_box_stored(int x, int y){
	for(l = y; l < y + 17; l++){
		for(i = 0; i < 17; i++){
			write_pixel(x+i, l, GRAY);		
		}
	}
	for(i = 0; i < 17; i++) write_pixel(x + i,y,BLACK); // top
	for(i = 0; i < 17; i++) write_pixel(x + i,y + 16,BLACK); // bottom
	for(i = 0; i < 17; i++) write_pixel(x,y + i,BLACK); // left
	for(i = 0; i <= 17; i++) write_pixel(x + 16,y + i,BLACK); // right
	// print deco
	for(i = 0; i < 17; i++) write_pixel(x + i, y+i+1, BLACK);
	for(i = 0; i < 17; i++) write_pixel(x + 16 - i, y + i + 1, BLACK);
}

void print_character(int x, int y){
    for(l = y; l < y + 17; l++){
        for(i = 0; i < 17; i++){
            write_pixel(x+i, l, YELLOW);      
        }
    }
    // eyes
    write_pixel(x + 4, y + 4, BLACK);
    write_pixel(x + 4, y + 5, BLACK);
    write_pixel(x + 4, y + 6, BLACK);
    write_pixel(x + 5, y + 4, BLACK);
    write_pixel(x + 5, y + 5, BLACK);
    write_pixel(x + 5, y + 6, BLACK);
    write_pixel(x + 6, y + 4, BLACK);
    write_pixel(x + 6, y + 5, BLACK);
    write_pixel(x + 6, y + 6, BLACK);
    write_pixel(x + 4, y + 10, BLACK);
    write_pixel(x + 4, y + 11, BLACK);
    write_pixel(x + 4, y + 12, BLACK);
    write_pixel(x + 5, y + 10, BLACK);
    write_pixel(x + 5, y + 11, BLACK);
    write_pixel(x + 5, y + 12, BLACK);
    write_pixel(x + 6, y + 10, BLACK);
    write_pixel(x + 6, y + 11, BLACK);
    write_pixel(x + 6, y + 12, BLACK);
    // nose
    write_pixel(x + 10, y + 8, BLACK);
    write_pixel(x + 11, y + 8, BLACK);
    write_pixel(x + 11, y + 7, BLACK); 
    // SMILE
    write_pixel(x + 12, y + 2, BLACK);
    write_pixel(x + 13, y + 3, BLACK);
    write_pixel(x + 14, y + 4, BLACK);
    write_pixel(x + 15, y + 5, BLACK);
    write_pixel(x + 16, y + 6, BLACK);
    write_pixel(x + 16, y + 7, BLACK);
    write_pixel(x + 16, y + 8, BLACK);
    write_pixel(x + 16, y + 9, BLACK);
    write_pixel(x + 16, y + 10, BLACK);
    write_pixel(x + 12, y + 14, BLACK);
    write_pixel(x + 13, y + 13, BLACK);
    write_pixel(x + 14, y + 12, BLACK);
    write_pixel(x + 15, y + 11, BLACK);

}

void print_storage(int x, int y){
	for(l = y; l < y + 17; l++){
		for(i = 0; i < 17; i++){
			write_pixel(x+i, l, BLACK);		
		}
	}
	for(i = 0; i < 17; i++) write_pixel(x + i,y,RED); // top
	for(i = 0; i < 17; i++) write_pixel(x + i,y + 16,RED); // bottom
	for(i = 0; i < 17; i++) write_pixel(x,y + i,RED); // left
	for(i = 0; i <= 17; i++) write_pixel(x + 16,y + i,RED); // right
	// print deco
	write_pixel(x + 4, y + 4, YELLOW);
    write_pixel(x + 4, y + 5, YELLOW);
    write_pixel(x + 4, y + 6, YELLOW);
    write_pixel(x + 5, y + 4, YELLOW);
    write_pixel(x + 5, y + 5, YELLOW);
    write_pixel(x + 5, y + 6, YELLOW);
    write_pixel(x + 6, y + 4, YELLOW);
    write_pixel(x + 6, y + 5, YELLOW);
    write_pixel(x + 6, y + 6, YELLOW);
    write_pixel(x + 4, y + 10, YELLOW);
    write_pixel(x + 4, y + 11, YELLOW);
    write_pixel(x + 4, y + 12, YELLOW);
    write_pixel(x + 5, y + 10, YELLOW);
    write_pixel(x + 5, y + 11, YELLOW);
    write_pixel(x + 5, y + 12, YELLOW);
    write_pixel(x + 6, y + 10, YELLOW);
    write_pixel(x + 6, y + 11, YELLOW);
    write_pixel(x + 6, y + 12, YELLOW);

}


void check_move(int newX, int newY, int newX2, int newY2){
	if(current_level[newX][newY] == 'e'){
		current_level[newX][newY] = 'k';
		if(current_level[playerXPos][playerYPos] == 'K') current_level[playerXPos][playerYPos] = 's';
		else current_level[playerXPos][playerYPos] = 'e';
		playerXPos = newX;
		playerYPos = newY;
	}
	else if(current_level[newX][newY] == 's'){
		current_level[newX][newY] = 'K';
		if(current_level[playerXPos][playerYPos] == 'K') current_level[playerXPos][playerYPos] = 's';
		else current_level[playerXPos][playerYPos] = 'e';
		playerXPos = newX;
		playerYPos = newY;
	}
	else if(current_level[newX][newY] == 'b' || current_level[newX][newY] == 'B'){
		if(current_level[newX2][newY2] == 'e'){
			current_level[newX2][newY2] = 'b';
			if(current_level[newX][newY] == 'B') current_level[newX][newY] = 'K';
			else current_level[newX][newY] = 'k';
			if(current_level[playerXPos][playerYPos] == 'K') current_level[playerXPos][playerYPos] = 's';
			else current_level[playerXPos][playerYPos] = 'e';
			playerXPos = newX;
			playerYPos = newY;
		}else if(current_level[newX2][newY2] == 's'){
			current_level[newX2][newY2] = 'B';
			if(current_level[newX][newY] == 'B') current_level[newX][newY] = 'K';
			else current_level[newX][newY] = 'k';
			if(current_level[playerXPos][playerYPos] == 'K') current_level[playerXPos][playerYPos] = 's';
			else current_level[playerXPos][playerYPos] = 'e';
			playerXPos = newX;
			playerYPos = newY;
		}
	}
}

void print_board(char move){ // self-explanatory
	if(move == 'w') check_move(playerXPos - 1, playerYPos, playerXPos - 2, playerYPos);
	else if(move == 'a') check_move(playerXPos, playerYPos - 1, playerXPos, playerYPos - 2);
	else if(move == 's') check_move(playerXPos + 1, playerYPos, playerXPos + 2, playerYPos);
	else if(move == 'd') check_move(playerXPos, playerYPos + 1, playerXPos, playerYPos + 2);
	
	int xPos = 0;
	int yPos = 0;
	for(j = 15; j < 185; j+=17){		
		for(k = 25; k < 195; k+=17){	
			if(current_level[xPos][yPos] == 'w') print_wall(k,j);
			else if(current_level[xPos][yPos] == 'e') print_floor(k,j);
			else if(current_level[xPos][yPos] == 'b') print_box(k,j);
            else if(current_level[xPos][yPos] == 'k' || current_level[xPos][yPos] == 'K') print_character(k,j);
            else if(current_level[xPos][yPos] == 's') print_storage(k,j);
			else if(current_level[xPos][yPos] == 'B') print_box_stored(k,j);
			yPos++;
		}
		yPos = 0;
		xPos++;
	}
	char text_level[10] = {'L','E','V','E','L',':',' ', current_level_num + '0'};
	write_text("LEVEL: ", 210, 18,WHITE,current_level_num);
	write_text("Up-W",240,50,WHITE,0);
	write_text("Dn-S",240,75,WHITE,0);
	write_text("Lf-A",240,100,WHITE,0);
	write_text("Rt-D",240,125,WHITE,0);
	write_text("Menu-2",240,150,WHITE,0);
	write_text("Exit-3",240,175,WHITE,0); 
}

int main(){
	char input;

	set_graphics(VGA_320X200X256);

	do{
		erase(1,1,350,280); //clear screen
		header(8,5);

		input = (char) getch();
		if(input == start){
			erase(1,1,350,280); //clear screen
			// assign board
			for(i = 0; i < 10; i++){
				for(j = 0;j < 10;j++){
					current_level[i][j] = levels[current_level_num - 1][i][j];
					if(current_level[i][j] == 'k' || current_level[i][j] == 'K'){
						playerXPos = i; 
						playerYPos = j;
					}
				}
			}
			// start loop
			do{
				if(input == main_menu || input == quit_game) break;
				print_board(input);
				input = (char) getch();
			}while(input != quit_game || input != main_menu);		
		}
	}while(input != quit_game);	
	erase(1,1,350,280); //clear screen
	clrscr();
}