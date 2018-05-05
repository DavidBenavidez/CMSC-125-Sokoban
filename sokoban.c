	#include "../../sdk/dexsdk.h"
#include "../../sdk/time.h"

#define YELLOW 54
#define PALE_YELLOW 62
#define ROYAL_BLUE 1
#define DARK_BLUE 8
#define GRAY 56
#define DARK_GREEN_BLUE 24
#define DARK_GRAY 19
#define LIGHT_GREEN 23
#define ORANGE 52
#define PINK 53
#define BROWN 20
#define LIGHT_YELLOW 55
#define WHITE 63
#define start '1'
#define view_high_scores '2'
#define quit_game '3'

int i, j, k, l;
char level0[10][10]  = {{'w','w','w','w','w','w','w','w','w','w'},{'w','e','e','e','b','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','b','e','e','e','w'},{'w','e','b','e','b','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','w','w','w','w','w','w','w','w','w'}};
// char level1[10][10]  = {{'w','w','w','w','w','w','w','w','w','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','w','w','w','w','w','w','w','w','w'}};
// char level2[10][10]  = {{'w','w','w','w','w','w','w','w','w','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','w','w','w','w','w','w','w','w','w'}};
// char level3[10][10]  = {{'w','w','w','w','w','w','w','w','w','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','w','w','w','w','w','w','w','w','w'}};
// char level4[10][10]  = {{'w','w','w','w','w','w','w','w','w','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','w','w','w','w','w','w','w','w','w'}};
// char level5[10][10]  = {{'w','w','w','w','w','w','w','w','w','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','w','w','w','w','w','w','w','w','w'}};
// char level6[10][10]  = {{'w','w','w','w','w','w','w','w','w','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','w','w','w','w','w','w','w','w','w'}};
// char level7[10][10]  = {{'w','w','w','w','w','w','w','w','w','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','w','w','w','w','w','w','w','w','w'}};
// char level8[10][10]  = {{'w','w','w','w','w','w','w','w','w','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','w','w','w','w','w','w','w','w','w'}};
// char level9[10][10]  = {{'w','w','w','w','w','w','w','w','w','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','w','w','w','w','w','w','w','w','w'}};

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
	for(i = 0; i < 17; i++) write_pixel(x + i,y,GRAY); // top		
	for(i = 0; i < 17; i++) write_pixel(x + i,y + 16,GRAY); // bottom
	for(i = 0; i < 17; i++) write_pixel(x,y + i,GRAY); // left
	for(i = 0; i < 17; i++) write_pixel(x + 16,y + i,GRAY); // right
	//print deco
	for(l = y + 3; l < y + 17; l += 3){
		for(i = 1; i < 17; i++){
			write_pixel(x + i, l, GRAY);
		}
	}
	for(l = x + 3; l < x + 16; l += 3){
		for(i = 1; i < 17; i++){
			write_pixel(l,y + i,GRAY); 
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
	for(i = 0; i < 17; i++) write_pixel(x + i,y,BROWN); // top
	for(i = 0; i < 17; i++) write_pixel(x + i,y + 16,BROWN); // bottom
	for(i = 0; i < 17; i++) write_pixel(x,y + i,BROWN); // left
	for(i = 0; i <= 17; i++) write_pixel(x + 16,y + i,BROWN); // right
	// print deco
	for(i = 0; i < 17; i++) write_pixel(x + i, y+i+1, BROWN);
	for(i = 0; i < 17; i++) write_pixel(x + 16 - i, y + i + 1, BROWN);
}

void print_board(){ // self-explanatory
	char level[10][10];
	for(i = 0; i < 10; i++){
		for(j = 0;j < 10;j++){
			level[i][j] = level0[i][j];
		}
	}
	
	int xPos = 0;
	int yPos = 0;
	for(j = 15; j < 185; j+=17){		
		for(k = 25; k < 195; k+=17){	
			if(level[xPos][yPos] == 'w') print_wall(k,j);
			else if(level[xPos][yPos] == 'e') print_floor(k,j);
			else if(level[xPos][yPos] == 'b') print_box(k,j);
			yPos++;
		}
		yPos = 0;
		xPos++;
	}

	write_text("Up-W",240,20,WHITE,0);
	write_text("Dn-S",240,60,WHITE,0);
	write_text("Lf-A",240,100,WHITE,0);
	write_text("Rt-D",240,140,WHITE,0);
	write_text("Exit-3",240,170,WHITE,0); 
}

int main(){
	char input;

	set_graphics(VGA_320X200X256);
	erase(1,1,400,220);
	header(8,5);

	input = (char) getch();
	erase(1,1,400,220);

	if(input == start){
		do{
			if(input == start){
				print_board();
			}


			input = (char) getch();
		}while(input != quit_game);		
	 }	

	return 0;
}