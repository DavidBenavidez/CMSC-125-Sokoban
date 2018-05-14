#include "../../sdk/dexsdk.h"
#include "../../sdk/time.h"

#define GRAY 56
#define DARK_GRAY 24
#define BROWN 20
#define WHITE 63
#define YELLOW2 54
#define MAROON 32

#define LIGHT_GREEN 58
#define GREEN 2
#define DARK_GREEN 16
#define DARK_YELLOW 6
#define YELLOW 62
#define PEACH 14
#define DARK_PEACH 42
#define PANTS 48
#define RED 16

#define BLACK 0
#define start '1'
#define main_menu '2'
#define quit_game '3'
#define next_level ']'
#define prev_level '['

int i, j, k, l;
int playerXPos, playerYPos;
int current_level_num = 1;

char levels[10][10][10]  = {
{{'e','e','e','e','e','e','e','e','e','x'},{'e','b','b','w','s','w','b','b','e','x'},{'e','w','e','s','s','s','e','w','e','x'},{'e','b','e','s','e','s','e','b','e','x'},{'e','b','e','s','s','s','e','b','e','x'},{'e','b','w','w','s','w','w','b','e','x'},{'e','e','e','e','e','e','e','e','k','x'},{'x','x','x','x','x','x','x','x','x','x'},{'x','x','x','x','x','x','x','x','x','x'},{'x','x','x','x','x','x','x','x','x','x'}},
{{'w','w','w','w','w','w','w','w','w','x'},{'w','e','e','e','e','e','s','s','w','x'},{'w','e','w','w','b','e','s','s','w','x'},{'w','e','w','e','e','e','w','s','w','x'},{'w','s','b','b','b','b','w','e','w','x'},{'w','s','b','k','e','e','b','s','w','x'},{'w','e','b','b','b','b','b','s','w','x'},{'w','e','e','e','e','s','s','s','w','x'},{'w','w','w','w','w','w','w','w','w','x'},{'x','x','x','x','x','x','x','x','x','x'}},
{{'e','e','e','e','k','e','e','e','e','x'},{'e','b','e','b','e','b','e','b','e','x'},{'e','e','b','e','b','e','b','e','e','x'},{'e','w','e','b','e','b','e','w','e','x'},{'e','w','e','e','b','e','e','w','e','x'},{'e','w','w','e','s','e','w','w','e','x'},{'e','w','e','s','e','s','e','w','e','x'},{'w','w','s','e','s','e','s','w','w','x'},{'w','s','e','s','e','s','e','s','w','x'},{'w','w','w','w','w','w','w','w','w','x'}},
{{'w','w','w','w','w','x','x','x','x','x'},{'w','s','s','e','w','x','x','x','x','x'},{'w','w','s','b','w','x','x','x','x','x'},{'w','e','s','e','w','x','x','x','x','x'},{'w','s','s','e','w','w','w','w','w','x'},{'w','s','b','b','b','e','b','k','w','x'},{'w','e','e','e','b','e','b','e','w','x'},{'w','e','e','e','e','e','e','e','w','x'},{'w','w','w','w','w','w','w','w','w','x'},{'x','x','x','x','x','x','x','x','x','x'}},
{{'w','w','w','w','w','w','w','w','w','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','w','w','w','w','w','w','w','w','w'}},
{{'w','w','w','w','w','w','w','w','w','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','w','w','w','w','w','w','w','w','w'}},
{{'w','w','w','w','w','w','w','w','w','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','w','w','w','w','w','w','w','w','w'}},
{{'w','w','w','w','w','w','w','w','w','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','w','w','w','w','w','w','w','w','w'}},
{{'w','w','w','w','w','w','w','w','w','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','w','w','w','w','w','w','w','w','w'}},
{{'w','w','w','w','w','w','w','w','w','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','e','e','e','e','e','e','e','e','w'},{'w','w','w','w','w','w','w','w','w','w'}}
};
char current_level[10][10];

void header(int x, int y){ //displays header
	write_text("JACHOBAN",120,40,WHITE,1); //title

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
	for(l = y; l < y + 17; l++){
		for(i = 0; i < 17; i++){
			write_pixel(x+i, l, BLACK);		
		}
	}
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

void print_black(int x, int y){
	for(l = y; l < y + 17; l++){
		for(i = 0; i < 17; i++){
			write_pixel(x+i, l, BLACK);		
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
	write_pixel(x + 2, y + 2, BLACK);
	write_pixel(x + 7, y + 5, BLACK);
	write_pixel(x + 3, y + 6, BLACK);
	write_pixel(x + 8, y + 7, BLACK);
	write_pixel(x + 12, y + 7, BLACK);
	write_pixel(x + 6, y + 7, BLACK);
	write_pixel(x + 2, y + 9, BLACK);
	write_pixel(x + 11, y + 10, BLACK);
	write_pixel(x + 16, y + 10, BLACK);
	write_pixel(x + 9, y + 13, BLACK);
	write_pixel(x + 4, y + 15, BLACK);
	write_pixel(x + 10, y + 15, BLACK);
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
            write_pixel(x+i, l, GRAY);      
        }
    }

	// floor deco para cool
	write_pixel(x + 2, y + 2, BLACK);
	write_pixel(x + 7, y + 5, BLACK);
	write_pixel(x + 3, y + 6, BLACK);
	write_pixel(x + 8, y + 7, BLACK);
	write_pixel(x + 12, y + 7, BLACK);
	write_pixel(x + 6, y + 7, BLACK);
	write_pixel(x + 2, y + 9, BLACK);
	write_pixel(x + 11, y + 10, BLACK);
	write_pixel(x + 16, y + 10, BLACK);
	write_pixel(x + 9, y + 13, BLACK);
	write_pixel(x + 4, y + 15, BLACK);
	write_pixel(x + 10, y + 15, BLACK);

    // hoooooman
    write_pixel(x + 2 + 4, y + 2, LIGHT_GREEN);
	write_pixel(x + 2 + 5, y + 2, GREEN);
	write_pixel(x + 2 + 6, y + 2, GREEN);
	write_pixel(x + 2 + 7, y + 2, GREEN);
	write_pixel(x + 2 + 8, y + 2, DARK_GREEN);

	write_pixel(x + 2 + 3, y + 3, LIGHT_GREEN);
	write_pixel(x + 2 + 4, y + 3, GREEN);
	write_pixel(x + 2 + 5, y + 3, GREEN);
	write_pixel(x + 2 + 6, y + 3, DARK_GREEN);
	write_pixel(x + 2 + 7, y + 3, DARK_GREEN);
	write_pixel(x + 2 + 8, y + 3, GREEN);
	write_pixel(x + 2 + 9, y + 3, DARK_GREEN);

	write_pixel(x + 2 + 2, y + 4, LIGHT_GREEN);
	write_pixel(x + 2 + 3, y + 4, GREEN);
	write_pixel(x + 2 + 4, y + 4, DARK_GREEN);
	write_pixel(x + 2 + 5, y + 4, DARK_GREEN);
	write_pixel(x + 2 + 6, y + 4, DARK_YELLOW);
	write_pixel(x + 2 + 7, y + 4, DARK_YELLOW);
	write_pixel(x + 2 + 8, y + 4, DARK_GREEN);
	write_pixel(x + 2 + 9, y + 4, GREEN);
	write_pixel(x + 2 + 10, y + 4, DARK_GREEN);

	write_pixel(x + 2 + 2, y + 5, GREEN);
	write_pixel(x + 2 + 3, y + 5, DARK_GREEN);
	write_pixel(x + 2 + 4, y + 5, PEACH);
	write_pixel(x + 2 + 5, y + 5, PEACH);
	write_pixel(x + 2 + 6, y + 5, YELLOW);
	write_pixel(x + 2 + 7, y + 5, DARK_YELLOW);
	write_pixel(x + 2 + 8, y + 5, DARK_YELLOW);
	write_pixel(x + 2 + 9, y + 5, DARK_GREEN);
	write_pixel(x + 2 + 10, y + 5, GREEN);

	write_pixel(x + 2 + 2, y + 6, DARK_GREEN);
	write_pixel(x + 2 + 3, y + 6, PEACH);
	write_pixel(x + 2 + 4, y + 6, BLACK);
	write_pixel(x + 2 + 5, y + 6, PEACH);
	write_pixel(x + 2 + 6, y + 6, PEACH);
	write_pixel(x + 2 + 7, y + 6, PEACH);
	write_pixel(x + 2 + 8, y + 6, BLACK);
	write_pixel(x + 2 + 9, y + 6, DARK_YELLOW);
	write_pixel(x + 2 + 10, y + 6, DARK_GREEN);

	write_pixel(x + 2 + 2, y + 7, DARK_GREEN);
	write_pixel(x + 2 + 3, y + 7, PEACH);
	write_pixel(x + 2 + 4, y + 7, BLACK);
	write_pixel(x + 2 + 5, y + 7, PEACH);
	write_pixel(x + 2 + 6, y + 7, PEACH);
	write_pixel(x + 2 + 7, y + 7, PEACH);
	write_pixel(x + 2 + 8, y + 7, BLACK);
	write_pixel(x + 2 + 9, y + 7, DARK_PEACH);
	write_pixel(x + 2 + 10, y + 7, DARK_GREEN);    

	write_pixel(x + 2 + 2, y + 8, DARK_GREEN);
	write_pixel(x + 2 + 3, y + 8, PEACH);
	write_pixel(x + 2 + 4, y + 8, PEACH);
	write_pixel(x + 2 + 5, y + 8, PEACH);
	write_pixel(x + 2 + 6, y + 8, PEACH);
	write_pixel(x + 2 + 7, y + 8, PEACH);
	write_pixel(x + 2 + 8, y + 8, PEACH);
	write_pixel(x + 2 + 9, y + 8, DARK_PEACH);
	write_pixel(x + 2 + 10, y + 8, DARK_GREEN);

	write_pixel(x + 2 + 3, y + 9, GREEN);
	write_pixel(x + 2 + 4, y + 9, PEACH);
	write_pixel(x + 2 + 5, y + 9, PEACH);
	write_pixel(x + 2 + 6, y + 9, PEACH);
	write_pixel(x + 2 + 7, y + 9, PEACH);
	write_pixel(x + 2 + 8, y + 9, DARK_PEACH);
	write_pixel(x + 2 + 9, y + 9, GREEN);    

	write_pixel(x + 2 + 2, y + 10, GREEN);
	write_pixel(x + 2 + 3, y + 10, GREEN);
	write_pixel(x + 2 + 4, y + 10, GREEN);
	write_pixel(x + 2 + 5, y + 10, GREEN);
	write_pixel(x + 2 + 6, y + 10, DARK_GREEN);
	write_pixel(x + 2 + 7, y + 10, GREEN);
	write_pixel(x + 2 + 8, y + 10, GREEN);
	write_pixel(x + 2 + 9, y + 10, GREEN);
	write_pixel(x + 2 + 10, y + 10, DARK_GREEN);

	write_pixel(x + 2 + 2, y + 11, GREEN);
	write_pixel(x + 2 + 3, y + 11, GREEN);
	write_pixel(x + 2 + 4, y + 11, DARK_GREEN);
	write_pixel(x + 2 + 5, y + 11, GREEN);
	write_pixel(x + 2 + 6, y + 11, DARK_GREEN);
	write_pixel(x + 2 + 7, y + 11, GREEN);
	write_pixel(x + 2 + 8, y + 11, GREEN);
	write_pixel(x + 2 + 9, y + 11, GREEN);
	write_pixel(x + 2 + 10, y + 11, GREEN);

	write_pixel(x + 2 + 2, y + 12, DARK_GREEN);
	write_pixel(x + 2 + 3, y + 12, GREEN);
	write_pixel(x + 2 + 4, y + 12, GREEN);
	write_pixel(x + 2 + 5, y + 12, GREEN);
	write_pixel(x + 2 + 6, y + 12, DARK_GREEN);
	write_pixel(x + 2 + 7, y + 12, GREEN);
	write_pixel(x + 2 + 8, y + 12, GREEN);
	write_pixel(x + 2 + 9, y + 12, GREEN);
	write_pixel(x + 2 + 10, y + 12, DARK_GREEN);

	write_pixel(x + 2 + 2, y + 13, PEACH);
	write_pixel(x + 2 + 3, y + 13, DARK_GREEN);
	write_pixel(x + 2 + 4, y + 13, GREEN);
	write_pixel(x + 2 + 5, y + 13, GREEN);
	write_pixel(x + 2 + 6, y + 13, DARK_GREEN);
	write_pixel(x + 2 + 7, y + 13, GREEN);
	write_pixel(x + 2 + 8, y + 13, GREEN);
	write_pixel(x + 2 + 9, y + 13, DARK_GREEN);
	write_pixel(x + 2 + 10, y + 13, PEACH);

	write_pixel(x + 2 + 3, y + 14, DARK_GRAY);
	write_pixel(x + 2 + 4, y + 14, PANTS);
	write_pixel(x + 2 + 5, y + 14, PANTS);
	write_pixel(x + 2 + 6, y + 14, DARK_GRAY);
	write_pixel(x + 2 + 7, y + 14, PANTS);
	write_pixel(x + 2 + 8, y + 14, PANTS);
	write_pixel(x + 2 + 9, y + 14, DARK_GRAY);

	write_pixel(x + 2 + 3, y + 15, PANTS);
	write_pixel(x + 2 + 4, y + 15, PANTS);
	write_pixel(x + 2 + 5, y + 15, DARK_GRAY);
	write_pixel(x + 2 + 7, y + 15, PANTS);
	write_pixel(x + 2 + 8, y + 15, PANTS);
	write_pixel(x + 2 + 9, y + 15, DARK_GRAY);
}

void print_character_score(int x, int y){
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
	write_pixel(x + 4, y + 4, YELLOW2);
    write_pixel(x + 4, y + 5, YELLOW2);
    write_pixel(x + 4, y + 6, YELLOW2);
    write_pixel(x + 5, y + 4, YELLOW2);
    write_pixel(x + 5, y + 5, YELLOW2);
    write_pixel(x + 5, y + 6, YELLOW2);
    write_pixel(x + 6, y + 4, YELLOW2);
    write_pixel(x + 6, y + 5, YELLOW2);
    write_pixel(x + 6, y + 6, YELLOW2);
    write_pixel(x + 4, y + 10, YELLOW2);
    write_pixel(x + 4, y + 11, YELLOW2);
    write_pixel(x + 4, y + 12, YELLOW2);
    write_pixel(x + 5, y + 10, YELLOW2);
    write_pixel(x + 5, y + 11, YELLOW2);
    write_pixel(x + 5, y + 12, YELLOW2);
    write_pixel(x + 6, y + 10, YELLOW2);
    write_pixel(x + 6, y + 11, YELLOW2);
    write_pixel(x + 6, y + 12, YELLOW2);

	write_pixel(x + 2 + 4, y + 2, LIGHT_GREEN);
	write_pixel(x + 2 + 5, y + 2, GREEN);
	write_pixel(x + 2 + 6, y + 2, GREEN);
	write_pixel(x + 2 + 7, y + 2, GREEN);
	write_pixel(x + 2 + 8, y + 2, DARK_GREEN);

	write_pixel(x + 2 + 3, y + 3, LIGHT_GREEN);
	write_pixel(x + 2 + 4, y + 3, GREEN);
	write_pixel(x + 2 + 5, y + 3, GREEN);
	write_pixel(x + 2 + 6, y + 3, DARK_GREEN);
	write_pixel(x + 2 + 7, y + 3, DARK_GREEN);
	write_pixel(x + 2 + 8, y + 3, GREEN);
	write_pixel(x + 2 + 9, y + 3, DARK_GREEN);

	write_pixel(x + 2 + 2, y + 4, LIGHT_GREEN);
	write_pixel(x + 2 + 3, y + 4, GREEN);
	write_pixel(x + 2 + 4, y + 4, DARK_GREEN);
	write_pixel(x + 2 + 5, y + 4, DARK_GREEN);
	write_pixel(x + 2 + 6, y + 4, DARK_YELLOW);
	write_pixel(x + 2 + 7, y + 4, DARK_YELLOW);
	write_pixel(x + 2 + 8, y + 4, DARK_GREEN);
	write_pixel(x + 2 + 9, y + 4, GREEN);
	write_pixel(x + 2 + 10, y + 4, DARK_GREEN);

	write_pixel(x + 2 + 2, y + 5, GREEN);
	write_pixel(x + 2 + 3, y + 5, DARK_GREEN);
	write_pixel(x + 2 + 4, y + 5, PEACH);
	write_pixel(x + 2 + 5, y + 5, PEACH);
	write_pixel(x + 2 + 6, y + 5, YELLOW);
	write_pixel(x + 2 + 7, y + 5, DARK_YELLOW);
	write_pixel(x + 2 + 8, y + 5, DARK_YELLOW);
	write_pixel(x + 2 + 9, y + 5, DARK_GREEN);
	write_pixel(x + 2 + 10, y + 5, GREEN);

	write_pixel(x + 2 + 2, y + 6, DARK_GREEN);
	write_pixel(x + 2 + 3, y + 6, PEACH);
	write_pixel(x + 2 + 4, y + 6, BLACK);
	write_pixel(x + 2 + 5, y + 6, PEACH);
	write_pixel(x + 2 + 6, y + 6, PEACH);
	write_pixel(x + 2 + 7, y + 6, PEACH);
	write_pixel(x + 2 + 8, y + 6, BLACK);
	write_pixel(x + 2 + 9, y + 6, DARK_YELLOW);
	write_pixel(x + 2 + 10, y + 6, DARK_GREEN);

	write_pixel(x + 2 + 2, y + 7, DARK_GREEN);
	write_pixel(x + 2 + 3, y + 7, PEACH);
	write_pixel(x + 2 + 4, y + 7, BLACK);
	write_pixel(x + 2 + 5, y + 7, PEACH);
	write_pixel(x + 2 + 6, y + 7, PEACH);
	write_pixel(x + 2 + 7, y + 7, PEACH);
	write_pixel(x + 2 + 8, y + 7, BLACK);
	write_pixel(x + 2 + 9, y + 7, DARK_PEACH);
	write_pixel(x + 2 + 10, y + 7, DARK_GREEN);    

	write_pixel(x + 2 + 2, y + 8, DARK_GREEN);
	write_pixel(x + 2 + 3, y + 8, PEACH);
	write_pixel(x + 2 + 4, y + 8, PEACH);
	write_pixel(x + 2 + 5, y + 8, PEACH);
	write_pixel(x + 2 + 6, y + 8, PEACH);
	write_pixel(x + 2 + 7, y + 8, PEACH);
	write_pixel(x + 2 + 8, y + 8, PEACH);
	write_pixel(x + 2 + 9, y + 8, DARK_PEACH);
	write_pixel(x + 2 + 10, y + 8, DARK_GREEN);

	write_pixel(x + 2 + 3, y + 9, GREEN);
	write_pixel(x + 2 + 4, y + 9, PEACH);
	write_pixel(x + 2 + 5, y + 9, PEACH);
	write_pixel(x + 2 + 6, y + 9, PEACH);
	write_pixel(x + 2 + 7, y + 9, PEACH);
	write_pixel(x + 2 + 8, y + 9, DARK_PEACH);
	write_pixel(x + 2 + 9, y + 9, GREEN);    

	write_pixel(x + 2 + 2, y + 10, GREEN);
	write_pixel(x + 2 + 3, y + 10, GREEN);
	write_pixel(x + 2 + 4, y + 10, GREEN);
	write_pixel(x + 2 + 5, y + 10, GREEN);
	write_pixel(x + 2 + 6, y + 10, DARK_GREEN);
	write_pixel(x + 2 + 7, y + 10, GREEN);
	write_pixel(x + 2 + 8, y + 10, GREEN);
	write_pixel(x + 2 + 9, y + 10, GREEN);
	write_pixel(x + 2 + 10, y + 10, DARK_GREEN);

	write_pixel(x + 2 + 2, y + 11, GREEN);
	write_pixel(x + 2 + 3, y + 11, GREEN);
	write_pixel(x + 2 + 4, y + 11, DARK_GREEN);
	write_pixel(x + 2 + 5, y + 11, GREEN);
	write_pixel(x + 2 + 6, y + 11, DARK_GREEN);
	write_pixel(x + 2 + 7, y + 11, GREEN);
	write_pixel(x + 2 + 8, y + 11, GREEN);
	write_pixel(x + 2 + 9, y + 11, GREEN);
	write_pixel(x + 2 + 10, y + 11, GREEN);

	write_pixel(x + 2 + 2, y + 12, DARK_GREEN);
	write_pixel(x + 2 + 3, y + 12, GREEN);
	write_pixel(x + 2 + 4, y + 12, GREEN);
	write_pixel(x + 2 + 5, y + 12, GREEN);
	write_pixel(x + 2 + 6, y + 12, DARK_GREEN);
	write_pixel(x + 2 + 7, y + 12, GREEN);
	write_pixel(x + 2 + 8, y + 12, GREEN);
	write_pixel(x + 2 + 9, y + 12, GREEN);
	write_pixel(x + 2 + 10, y + 12, DARK_GREEN);

	write_pixel(x + 2 + 2, y + 13, PEACH);
	write_pixel(x + 2 + 3, y + 13, DARK_GREEN);
	write_pixel(x + 2 + 4, y + 13, GREEN);
	write_pixel(x + 2 + 5, y + 13, GREEN);
	write_pixel(x + 2 + 6, y + 13, DARK_GREEN);
	write_pixel(x + 2 + 7, y + 13, GREEN);
	write_pixel(x + 2 + 8, y + 13, GREEN);
	write_pixel(x + 2 + 9, y + 13, DARK_GREEN);
	write_pixel(x + 2 + 10, y + 13, PEACH);

	write_pixel(x + 2 + 3, y + 14, DARK_GRAY);
	write_pixel(x + 2 + 4, y + 14, PANTS);
	write_pixel(x + 2 + 5, y + 14, PANTS);
	write_pixel(x + 2 + 6, y + 14, DARK_GRAY);
	write_pixel(x + 2 + 7, y + 14, PANTS);
	write_pixel(x + 2 + 8, y + 14, PANTS);
	write_pixel(x + 2 + 9, y + 14, DARK_GRAY);

	write_pixel(x + 2 + 3, y + 15, PANTS);
	write_pixel(x + 2 + 4, y + 15, PANTS);
	write_pixel(x + 2 + 5, y + 15, DARK_GRAY);
	write_pixel(x + 2 + 7, y + 15, PANTS);
	write_pixel(x + 2 + 8, y + 15, PANTS);
	write_pixel(x + 2 + 9, y + 15, DARK_GRAY);
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
	write_pixel(x + 4, y + 4, YELLOW2);
    write_pixel(x + 4, y + 5, YELLOW2);
    write_pixel(x + 4, y + 6, YELLOW2);
    write_pixel(x + 5, y + 4, YELLOW2);
    write_pixel(x + 5, y + 5, YELLOW2);
    write_pixel(x + 5, y + 6, YELLOW2);
    write_pixel(x + 6, y + 4, YELLOW2);
    write_pixel(x + 6, y + 5, YELLOW2);
    write_pixel(x + 6, y + 6, YELLOW2);
    write_pixel(x + 4, y + 10, YELLOW2);
    write_pixel(x + 4, y + 11, YELLOW2);
    write_pixel(x + 4, y + 12, YELLOW2);
    write_pixel(x + 5, y + 10, YELLOW2);
    write_pixel(x + 5, y + 11, YELLOW2);
    write_pixel(x + 5, y + 12, YELLOW2);
    write_pixel(x + 6, y + 10, YELLOW2);
    write_pixel(x + 6, y + 11, YELLOW2);
    write_pixel(x + 6, y + 12, YELLOW2);
}

void print_character_score_right(int x, int y){
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
	write_pixel(x + 4, y + 4, YELLOW2);
    write_pixel(x + 4, y + 5, YELLOW2);
    write_pixel(x + 4, y + 6, YELLOW2);
    write_pixel(x + 5, y + 4, YELLOW2);
    write_pixel(x + 5, y + 5, YELLOW2);
    write_pixel(x + 5, y + 6, YELLOW2);
    write_pixel(x + 6, y + 4, YELLOW2);
    write_pixel(x + 6, y + 5, YELLOW2);
    write_pixel(x + 6, y + 6, YELLOW2);
    write_pixel(x + 4, y + 10, YELLOW2);
    write_pixel(x + 4, y + 11, YELLOW2);
    write_pixel(x + 4, y + 12, YELLOW2);
    write_pixel(x + 5, y + 10, YELLOW2);
    write_pixel(x + 5, y + 11, YELLOW2);
    write_pixel(x + 5, y + 12, YELLOW2);
    write_pixel(x + 6, y + 10, YELLOW2);
    write_pixel(x + 6, y + 11, YELLOW2);
    write_pixel(x + 6, y + 12, YELLOW2);


    // hoooooman
    write_pixel(x + 2 + 4, y + 2, LIGHT_GREEN);
	write_pixel(x + 2 + 5, y + 2, GREEN);
	write_pixel(x + 2 + 6, y + 2, GREEN);
	write_pixel(x + 2 + 7, y + 2, GREEN);
	write_pixel(x + 2 + 8, y + 2, DARK_GREEN);

	write_pixel(x + 2 + 1, y + 3, LIGHT_GREEN);
	write_pixel(x + 2 + 2, y + 3, LIGHT_GREEN);
	write_pixel(x + 2 + 3, y + 3, LIGHT_GREEN);
	write_pixel(x + 2 + 4, y + 3, GREEN);
	write_pixel(x + 2 + 5, y + 3, GREEN);
	write_pixel(x + 2 + 6, y + 3, GREEN);
	write_pixel(x + 2 + 7, y + 3, GREEN);
	write_pixel(x + 2 + 8, y + 3, GREEN);
	write_pixel(x + 2 + 9, y + 3, DARK_GREEN);

	write_pixel(x + 2 + 2, y + 4, LIGHT_GREEN);
	write_pixel(x + 2 + 3, y + 4, GREEN);
	write_pixel(x + 2 + 4, y + 4, GREEN);
	write_pixel(x + 2 + 5, y + 4, GREEN);
	write_pixel(x + 2 + 6, y + 4, GREEN);
	write_pixel(x + 2 + 7, y + 4, GREEN);
	write_pixel(x + 2 + 8, y + 4, DARK_GREEN);
	write_pixel(x + 2 + 9, y + 4, DARK_GREEN);
	write_pixel(x + 2 + 10, y + 4, DARK_YELLOW);

	write_pixel(x + 2 + 2, y + 5, GREEN);
	write_pixel(x + 2 + 3, y + 5, GREEN);
	write_pixel(x + 2 + 4, y + 5, GREEN);
	write_pixel(x + 2 + 5, y + 5, GREEN);
	write_pixel(x + 2 + 6, y + 5, DARK_GREEN);
	write_pixel(x + 2 + 7, y + 5, DARK_GREEN);
	write_pixel(x + 2 + 8, y + 5, DARK_PEACH);
	write_pixel(x + 2 + 9, y + 5, PEACH);
	write_pixel(x + 2 + 10, y + 5, YELLOW);

	write_pixel(x + 2 + 2, y + 6, GREEN);
	write_pixel(x + 2 + 3, y + 6, GREEN);
	write_pixel(x + 2 + 4, y + 6, GREEN);
	write_pixel(x + 2 + 5, y + 6, DARK_GREEN);
	write_pixel(x + 2 + 6, y + 6, PEACH);
	write_pixel(x + 2 + 7, y + 6, PEACH);
	write_pixel(x + 2 + 8, y + 6, PEACH);
	write_pixel(x + 2 + 9, y + 6, BLACK);
	write_pixel(x + 2 + 10, y + 6, DARK_PEACH);

	write_pixel(x + 2 + 2, y + 7, GREEN);
	write_pixel(x + 2 + 3, y + 7, GREEN);
	write_pixel(x + 2 + 4, y + 7, DARK_GREEN);
	write_pixel(x + 2 + 5, y + 7, PEACH);
	write_pixel(x + 2 + 6, y + 7, PEACH);
	write_pixel(x + 2 + 7, y + 7, PEACH);
	write_pixel(x + 2 + 8, y + 7, PEACH);
	write_pixel(x + 2 + 9, y + 7, BLACK);
	write_pixel(x + 2 + 10, y + 7, DARK_PEACH);    

	write_pixel(x + 2 + 2, y + 8, DARK_GREEN);
	write_pixel(x + 2 + 3, y + 8, GREEN);
	write_pixel(x + 2 + 4, y + 8, DARK_GREEN);
	write_pixel(x + 2 + 5, y + 8, DARK_PEACH);
	write_pixel(x + 2 + 6, y + 8, PEACH);
	write_pixel(x + 2 + 7, y + 8, PEACH);
	write_pixel(x + 2 + 8, y + 8, PEACH);
	write_pixel(x + 2 + 9, y + 8, PEACH);
	write_pixel(x + 2 + 10, y + 8, DARK_PEACH);

	write_pixel(x + 2 + 2, y + 9, DARK_GREEN);
	write_pixel(x + 2 + 3, y + 9, GREEN);
	write_pixel(x + 2 + 4, y + 9, GREEN);
	write_pixel(x + 2 + 5, y + 9, DARK_GREEN);
	write_pixel(x + 2 + 6, y + 9, PEACH);
	write_pixel(x + 2 + 7, y + 9, PEACH);
	write_pixel(x + 2 + 8, y + 9, PEACH);
	write_pixel(x + 2 + 9, y + 9, DARK_PEACH);
	write_pixel(x + 2 + 10, y + 9, DARK_PEACH);

	write_pixel(x + 2 + 3, y + 10, DARK_GREEN);
	write_pixel(x + 2 + 4, y + 10, GREEN);
	write_pixel(x + 2 + 5, y + 10, GREEN);
	write_pixel(x + 2 + 6, y + 10, GREEN);
	write_pixel(x + 2 + 7, y + 10, GREEN);
	write_pixel(x + 2 + 8, y + 10, GREEN);
	write_pixel(x + 2 + 9, y + 10, GREEN);
	write_pixel(x + 2 + 10, y + 10, DARK_GREEN);

	write_pixel(x + 2 + 3, y + 11, DARK_GREEN);
	write_pixel(x + 2 + 4, y + 11, GREEN);
	write_pixel(x + 2 + 5, y + 11, DARK_GREEN);
	write_pixel(x + 2 + 6, y + 11, GREEN);
	write_pixel(x + 2 + 7, y + 11, GREEN);
	write_pixel(x + 2 + 8, y + 11, DARK_GREEN);
	write_pixel(x + 2 + 9, y + 11, GREEN);
	
	write_pixel(x + 2 + 4, y + 12, GREEN);
	write_pixel(x + 2 + 5, y + 12, DARK_GREEN);
	write_pixel(x + 2 + 6, y + 12, GREEN);
	write_pixel(x + 2 + 7, y + 12, GREEN);
	write_pixel(x + 2 + 8, y + 12, DARK_GREEN);
	write_pixel(x + 2 + 9, y + 12, GREEN);

	write_pixel(x + 2 + 4, y + 13, DARK_GREEN);
	write_pixel(x + 2 + 5, y + 13, DARK_GREEN);
	write_pixel(x + 2 + 6, y + 13, PEACH);
	write_pixel(x + 2 + 7, y + 13, DARK_PEACH);
	write_pixel(x + 2 + 8, y + 13, DARK_GREEN);

	write_pixel(x + 2 + 4, y + 14, DARK_GRAY);
	write_pixel(x + 2 + 5, y + 14, PANTS);
	write_pixel(x + 2 + 6, y + 14, PANTS);
	write_pixel(x + 2 + 7, y + 14, PANTS);
	write_pixel(x + 2 + 8, y + 14, DARK_GRAY);

	write_pixel(x + 2 + 5, y + 15, PANTS);
	write_pixel(x + 2 + 6, y + 15, PANTS);
	write_pixel(x + 2 + 7, y + 15, PANTS);
	
}

void print_character_score_up(int x, int y){
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
	write_pixel(x + 4, y + 4, YELLOW2);
    write_pixel(x + 4, y + 5, YELLOW2);
    write_pixel(x + 4, y + 6, YELLOW2);
    write_pixel(x + 5, y + 4, YELLOW2);
    write_pixel(x + 5, y + 5, YELLOW2);
    write_pixel(x + 5, y + 6, YELLOW2);
    write_pixel(x + 6, y + 4, YELLOW2);
    write_pixel(x + 6, y + 5, YELLOW2);
    write_pixel(x + 6, y + 6, YELLOW2);
    write_pixel(x + 4, y + 10, YELLOW2);
    write_pixel(x + 4, y + 11, YELLOW2);
    write_pixel(x + 4, y + 12, YELLOW2);
    write_pixel(x + 5, y + 10, YELLOW2);
    write_pixel(x + 5, y + 11, YELLOW2);
    write_pixel(x + 5, y + 12, YELLOW2);
    write_pixel(x + 6, y + 10, YELLOW2);
    write_pixel(x + 6, y + 11, YELLOW2);
    write_pixel(x + 6, y + 12, YELLOW2);

	write_pixel(x + 2 + 4, y + 2, LIGHT_GREEN);
	write_pixel(x + 2 + 5, y + 2, GREEN);
	write_pixel(x + 2 + 6, y + 2, GREEN);
	write_pixel(x + 2 + 7, y + 2, GREEN);
	write_pixel(x + 2 + 8, y + 2, DARK_GREEN);

	write_pixel(x + 2 + 3, y + 3, LIGHT_GREEN);
	write_pixel(x + 2 + 4, y + 3, GREEN);
	write_pixel(x + 2 + 5, y + 3, GREEN);
	write_pixel(x + 2 + 6, y + 3, LIGHT_GREEN);
	write_pixel(x + 2 + 7, y + 3, DARK_GREEN);
	write_pixel(x + 2 + 8, y + 3, GREEN);
	write_pixel(x + 2 + 9, y + 3, DARK_GREEN);

	write_pixel(x + 2 + 2, y + 4, LIGHT_GREEN);
	write_pixel(x + 2 + 3, y + 4, GREEN);
	write_pixel(x + 2 + 4, y + 4, GREEN);
	write_pixel(x + 2 + 5, y + 4, GREEN);
	write_pixel(x + 2 + 6, y + 4, DARK_GREEN);
	write_pixel(x + 2 + 7, y + 4, GREEN);
	write_pixel(x + 2 + 8, y + 4, GREEN);
	write_pixel(x + 2 + 9, y + 4, GREEN);
	write_pixel(x + 2 + 10, y + 4, DARK_GREEN);

	write_pixel(x + 2 + 2, y + 5, GREEN);
	write_pixel(x + 2 + 3, y + 5, GREEN);
	write_pixel(x + 2 + 4, y + 5, GREEN);
	write_pixel(x + 2 + 5, y + 5, GREEN);
	write_pixel(x + 2 + 6, y + 5, GREEN);
	write_pixel(x + 2 + 7, y + 5, GREEN);
	write_pixel(x + 2 + 8, y + 5, GREEN);
	write_pixel(x + 2 + 9, y + 5, GREEN);
	write_pixel(x + 2 + 10, y + 5, GREEN);

	write_pixel(x + 2 + 2, y + 6, DARK_GREEN);
	write_pixel(x + 2 + 3, y + 6, GREEN);
	write_pixel(x + 2 + 4, y + 6, GREEN);
	write_pixel(x + 2 + 5, y + 6, GREEN);
	write_pixel(x + 2 + 6, y + 6, GREEN);
	write_pixel(x + 2 + 7, y + 6, GREEN);
	write_pixel(x + 2 + 8, y + 6, GREEN);
	write_pixel(x + 2 + 9, y + 6, GREEN);
	write_pixel(x + 2 + 10, y + 6, DARK_GREEN);

	write_pixel(x + 2 + 2, y + 7, DARK_GREEN);
	write_pixel(x + 2 + 3, y + 7, GREEN);
	write_pixel(x + 2 + 4, y + 7, GREEN);
	write_pixel(x + 2 + 5, y + 7, GREEN);
	write_pixel(x + 2 + 6, y + 7, GREEN);
	write_pixel(x + 2 + 7, y + 7, GREEN);
	write_pixel(x + 2 + 8, y + 7, GREEN);
	write_pixel(x + 2 + 9, y + 7, GREEN);
	write_pixel(x + 2 + 10, y + 7, DARK_GREEN);    

	write_pixel(x + 2 + 2, y + 8, DARK_GREEN);
	write_pixel(x + 2 + 3, y + 8, DARK_GREEN);
	write_pixel(x + 2 + 4, y + 8, GREEN);
	write_pixel(x + 2 + 5, y + 8, GREEN);
	write_pixel(x + 2 + 6, y + 8, GREEN);
	write_pixel(x + 2 + 7, y + 8, GREEN);
	write_pixel(x + 2 + 8, y + 8, GREEN);
	write_pixel(x + 2 + 9, y + 8, DARK_GREEN);
	write_pixel(x + 2 + 10, y + 8, DARK_GREEN);

	write_pixel(x + 2 + 3, y + 9, DARK_GREEN);
	write_pixel(x + 2 + 4, y + 9, DARK_GREEN);
	write_pixel(x + 2 + 5, y + 9, DARK_GREEN);
	write_pixel(x + 2 + 6, y + 9, GREEN);
	write_pixel(x + 2 + 7, y + 9, GREEN);
	write_pixel(x + 2 + 8, y + 9, DARK_GREEN);
	write_pixel(x + 2 + 9, y + 9, DARK_GREEN);    

	write_pixel(x + 2 + 2, y + 10, LIGHT_GREEN);
	write_pixel(x + 2 + 3, y + 10, GREEN);
	write_pixel(x + 2 + 4, y + 10, GREEN);
	write_pixel(x + 2 + 5, y + 10, GREEN);
	write_pixel(x + 2 + 6, y + 10, GREEN);
	write_pixel(x + 2 + 7, y + 10, GREEN);
	write_pixel(x + 2 + 8, y + 10, GREEN);
	write_pixel(x + 2 + 9, y + 10, GREEN);
	write_pixel(x + 2 + 10, y + 10, DARK_GREEN);

	write_pixel(x + 2 + 2, y + 11, DARK_GREEN);
	write_pixel(x + 2 + 3, y + 11, GREEN);
	write_pixel(x + 2 + 4, y + 11, GREEN);
	write_pixel(x + 2 + 5, y + 11, GREEN);
	write_pixel(x + 2 + 6, y + 11, GREEN);
	write_pixel(x + 2 + 7, y + 11, GREEN);
	write_pixel(x + 2 + 8, y + 11, GREEN);
	write_pixel(x + 2 + 9, y + 11, GREEN);
	write_pixel(x + 2 + 10, y + 11, DARK_GREEN);

	write_pixel(x + 2 + 2, y + 12, DARK_GREEN);
	write_pixel(x + 2 + 3, y + 12, GREEN);
	write_pixel(x + 2 + 4, y + 12, GREEN);
	write_pixel(x + 2 + 5, y + 12, GREEN);
	write_pixel(x + 2 + 6, y + 12, GREEN);
	write_pixel(x + 2 + 7, y + 12, GREEN);
	write_pixel(x + 2 + 8, y + 12, GREEN);
	write_pixel(x + 2 + 9, y + 12, DARK_GREEN);
	write_pixel(x + 2 + 10, y + 12, DARK_GREEN);

	write_pixel(x + 2 + 2, y + 13, PEACH);
	write_pixel(x + 2 + 3, y + 13, DARK_GREEN);
	write_pixel(x + 2 + 4, y + 13, GREEN);
	write_pixel(x + 2 + 5, y + 13, GREEN);
	write_pixel(x + 2 + 6, y + 13, GREEN);
	write_pixel(x + 2 + 7, y + 13, GREEN);
	write_pixel(x + 2 + 8, y + 13, GREEN);
	write_pixel(x + 2 + 9, y + 13, DARK_GREEN);
	write_pixel(x + 2 + 10, y + 13, PEACH);

	write_pixel(x + 2 + 3, y + 14, DARK_GRAY);
	write_pixel(x + 2 + 4, y + 14, PANTS);
	write_pixel(x + 2 + 5, y + 14, PANTS);
	write_pixel(x + 2 + 6, y + 14, DARK_GRAY);
	write_pixel(x + 2 + 7, y + 14, PANTS);
	write_pixel(x + 2 + 8, y + 14, PANTS);
	write_pixel(x + 2 + 9, y + 14, DARK_GRAY);

	write_pixel(x + 2 + 3, y + 15, PANTS);
	write_pixel(x + 2 + 4, y + 15, PANTS);
	write_pixel(x + 2 + 5, y + 15, DARK_GRAY);
	write_pixel(x + 2 + 7, y + 15, PANTS);
	write_pixel(x + 2 + 8, y + 15, PANTS);
	write_pixel(x + 2 + 9, y + 15, DARK_GRAY);
}

void print_character_score_left(int x, int y){
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
	write_pixel(x + 4, y + 4, YELLOW2);
    write_pixel(x + 4, y + 5, YELLOW2);
    write_pixel(x + 4, y + 6, YELLOW2);
    write_pixel(x + 5, y + 4, YELLOW2);
    write_pixel(x + 5, y + 5, YELLOW2);
    write_pixel(x + 5, y + 6, YELLOW2);
    write_pixel(x + 6, y + 4, YELLOW2);
    write_pixel(x + 6, y + 5, YELLOW2);
    write_pixel(x + 6, y + 6, YELLOW2);
    write_pixel(x + 4, y + 10, YELLOW2);
    write_pixel(x + 4, y + 11, YELLOW2);
    write_pixel(x + 4, y + 12, YELLOW2);
    write_pixel(x + 5, y + 10, YELLOW2);
    write_pixel(x + 5, y + 11, YELLOW2);
    write_pixel(x + 5, y + 12, YELLOW2);
    write_pixel(x + 6, y + 10, YELLOW2);
    write_pixel(x + 6, y + 11, YELLOW2);
    write_pixel(x + 6, y + 12, YELLOW2);


    // hoooooman
    write_pixel(x + 2 + 4, y + 2, LIGHT_GREEN);
	write_pixel(x + 2 + 5, y + 2, GREEN);
	write_pixel(x + 2 + 6, y + 2, GREEN);
	write_pixel(x + 2 + 7, y + 2, GREEN);
	write_pixel(x + 2 + 8, y + 2, DARK_GREEN);

	write_pixel(x + 2 + 3, y + 3, LIGHT_GREEN);
	write_pixel(x + 2 + 4, y + 3, GREEN);
	write_pixel(x + 2 + 5, y + 3, GREEN);
	write_pixel(x + 2 + 6, y + 3, GREEN);
	write_pixel(x + 2 + 7, y + 3, GREEN);
	write_pixel(x + 2 + 8, y + 3, GREEN);
	write_pixel(x + 2 + 9, y + 3, DARK_GREEN);
	write_pixel(x + 2 + 10, y + 3, DARK_GREEN);
	write_pixel(x + 2 + 11, y + 3, DARK_GREEN);

	write_pixel(x + 2 + 2, y + 4, DARK_YELLOW);
	write_pixel(x + 2 + 3, y + 4, DARK_GREEN);
	write_pixel(x + 2 + 4, y + 4, DARK_GREEN);
	write_pixel(x + 2 + 5, y + 4, DARK_GREEN);
	write_pixel(x + 2 + 6, y + 4, GREEN);
	write_pixel(x + 2 + 7, y + 4, GREEN);
	write_pixel(x + 2 + 8, y + 4, GREEN);
	write_pixel(x + 2 + 9, y + 4, GREEN);
	write_pixel(x + 2 + 10, y + 4, DARK_GREEN);

	write_pixel(x + 2 + 2, y + 5, YELLOW);
	write_pixel(x + 2 + 3, y + 5, YELLOW);
	write_pixel(x + 2 + 4, y + 5, DARK_YELLOW);
	write_pixel(x + 2 + 5, y + 5, DARK_YELLOW);
	write_pixel(x + 2 + 6, y + 5, DARK_GREEN);
	write_pixel(x + 2 + 7, y + 5, GREEN);
	write_pixel(x + 2 + 8, y + 5, GREEN);
	write_pixel(x + 2 + 9, y + 5, GREEN);
	write_pixel(x + 2 + 10, y + 5, DARK_GREEN);

	write_pixel(x + 2 + 2, y + 6, PEACH);
	write_pixel(x + 2 + 3, y + 6, BLACK);
	write_pixel(x + 2 + 4, y + 6, DARK_PEACH);
	write_pixel(x + 2 + 5, y + 6, YELLOW);
	write_pixel(x + 2 + 6, y + 6, DARK_YELLOW);
	write_pixel(x + 2 + 7, y + 6, DARK_GREEN);
	write_pixel(x + 2 + 8, y + 6, GREEN);
	write_pixel(x + 2 + 9, y + 6, GREEN);
	write_pixel(x + 2 + 10, y + 6, GREEN);

	write_pixel(x + 2 + 2, y + 7, DARK_PEACH);
	write_pixel(x + 2 + 3, y + 7, BLACK);
	write_pixel(x + 2 + 4, y + 7, PEACH);
	write_pixel(x + 2 + 5, y + 7, PEACH);
	write_pixel(x + 2 + 6, y + 7, PEACH);
	write_pixel(x + 2 + 7, y + 7, PEACH);
	write_pixel(x + 2 + 8, y + 7, PEACH);
	write_pixel(x + 2 + 9, y + 7, GREEN);
	write_pixel(x + 2 + 10, y + 7, GREEN);    

	write_pixel(x + 2 + 2, y + 8, PEACH);
	write_pixel(x + 2 + 3, y + 8, PEACH);
	write_pixel(x + 2 + 4, y + 8, PEACH);
	write_pixel(x + 2 + 5, y + 8, PEACH);
	write_pixel(x + 2 + 6, y + 8, PEACH);
	write_pixel(x + 2 + 7, y + 8, PEACH);
	write_pixel(x + 2 + 8, y + 8, DARK_GREEN);
	write_pixel(x + 2 + 9, y + 8, GREEN);
	write_pixel(x + 2 + 10, y + 8, GREEN);

	write_pixel(x + 2 + 2, y + 9, PEACH);
	write_pixel(x + 2 + 3, y + 9, PEACH);
	write_pixel(x + 2 + 4, y + 9, PEACH);
	write_pixel(x + 2 + 5, y + 9, PEACH);
	write_pixel(x + 2 + 6, y + 9, PEACH);
	write_pixel(x + 2 + 7, y + 9, DARK_GREEN);
	write_pixel(x + 2 + 8, y + 9, GREEN);
	write_pixel(x + 2 + 9, y + 9, GREEN);
	write_pixel(x + 2 + 10, y + 9, DARK_GREEN);

	write_pixel(x + 2 + 2, y + 10, DARK_GREEN);
	write_pixel(x + 2 + 3, y + 10, GREEN);
	write_pixel(x + 2 + 4, y + 10, GREEN);
	write_pixel(x + 2 + 5, y + 10, GREEN);
	write_pixel(x + 2 + 6, y + 10, GREEN);
	write_pixel(x + 2 + 7, y + 10, GREEN);
	write_pixel(x + 2 + 8, y + 10, GREEN);
	write_pixel(x + 2 + 9, y + 10, DARK_GREEN);

	write_pixel(x + 2 + 3, y + 11, DARK_GREEN);
	write_pixel(x + 2 + 4, y + 11, GREEN);
	write_pixel(x + 2 + 5, y + 11, GREEN);
	write_pixel(x + 2 + 6, y + 11, DARK_GREEN);
	write_pixel(x + 2 + 7, y + 11, GREEN);
	write_pixel(x + 2 + 8, y + 11, GREEN);
	write_pixel(x + 2 + 9, y + 11, GREEN);
	
	write_pixel(x + 2 + 3, y + 12, GREEN);
	write_pixel(x + 2 + 4, y + 12, DARK_GREEN);
	write_pixel(x + 2 + 5, y + 12, GREEN);
	write_pixel(x + 2 + 6, y + 12, GREEN);
	write_pixel(x + 2 + 7, y + 12, DARK_GREEN);
	write_pixel(x + 2 + 8, y + 12, GREEN);

	write_pixel(x + 2 + 4, y + 13, DARK_GREEN);
	write_pixel(x + 2 + 5, y + 13, PEACH);
	write_pixel(x + 2 + 6, y + 13, DARK_PEACH);
	write_pixel(x + 2 + 7, y + 13, DARK_GREEN);
	write_pixel(x + 2 + 8, y + 13, DARK_GREEN);

	write_pixel(x + 2 + 4, y + 14, DARK_GRAY);
	write_pixel(x + 2 + 5, y + 14, PANTS);
	write_pixel(x + 2 + 6, y + 14, PANTS);
	write_pixel(x + 2 + 7, y + 14, PANTS);
	write_pixel(x + 2 + 8, y + 14, DARK_GRAY);

	write_pixel(x + 2 + 5, y + 15, PANTS);
	write_pixel(x + 2 + 6, y + 15, PANTS);
	write_pixel(x + 2 + 7, y + 15, PANTS);
	
}

void print_character_up(int x, int y){
	for(l = y; l < y + 17; l++){
        for(i = 0; i < 17; i++){
            write_pixel(x+i, l, GRAY);      
        }
    }

	// floor deco para cool
	write_pixel(x + 2, y + 2, BLACK);
	write_pixel(x + 7, y + 5, BLACK);
	write_pixel(x + 3, y + 6, BLACK);
	write_pixel(x + 8, y + 7, BLACK);
	write_pixel(x + 12, y + 7, BLACK);
	write_pixel(x + 6, y + 7, BLACK);
	write_pixel(x + 2, y + 9, BLACK);
	write_pixel(x + 11, y + 10, BLACK);
	write_pixel(x + 16, y + 10, BLACK);
	write_pixel(x + 9, y + 13, BLACK);
	write_pixel(x + 4, y + 15, BLACK);
	write_pixel(x + 10, y + 15, BLACK);

	write_pixel(x + 2 + 4, y + 2, LIGHT_GREEN);
	write_pixel(x + 2 + 5, y + 2, GREEN);
	write_pixel(x + 2 + 6, y + 2, GREEN);
	write_pixel(x + 2 + 7, y + 2, GREEN);
	write_pixel(x + 2 + 8, y + 2, DARK_GREEN);

	write_pixel(x + 2 + 3, y + 3, LIGHT_GREEN);
	write_pixel(x + 2 + 4, y + 3, GREEN);
	write_pixel(x + 2 + 5, y + 3, GREEN);
	write_pixel(x + 2 + 6, y + 3, LIGHT_GREEN);
	write_pixel(x + 2 + 7, y + 3, DARK_GREEN);
	write_pixel(x + 2 + 8, y + 3, GREEN);
	write_pixel(x + 2 + 9, y + 3, DARK_GREEN);

	write_pixel(x + 2 + 2, y + 4, LIGHT_GREEN);
	write_pixel(x + 2 + 3, y + 4, GREEN);
	write_pixel(x + 2 + 4, y + 4, GREEN);
	write_pixel(x + 2 + 5, y + 4, GREEN);
	write_pixel(x + 2 + 6, y + 4, DARK_GREEN);
	write_pixel(x + 2 + 7, y + 4, GREEN);
	write_pixel(x + 2 + 8, y + 4, GREEN);
	write_pixel(x + 2 + 9, y + 4, GREEN);
	write_pixel(x + 2 + 10, y + 4, DARK_GREEN);

	write_pixel(x + 2 + 2, y + 5, GREEN);
	write_pixel(x + 2 + 3, y + 5, GREEN);
	write_pixel(x + 2 + 4, y + 5, GREEN);
	write_pixel(x + 2 + 5, y + 5, GREEN);
	write_pixel(x + 2 + 6, y + 5, GREEN);
	write_pixel(x + 2 + 7, y + 5, GREEN);
	write_pixel(x + 2 + 8, y + 5, GREEN);
	write_pixel(x + 2 + 9, y + 5, GREEN);
	write_pixel(x + 2 + 10, y + 5, GREEN);

	write_pixel(x + 2 + 2, y + 6, DARK_GREEN);
	write_pixel(x + 2 + 3, y + 6, GREEN);
	write_pixel(x + 2 + 4, y + 6, GREEN);
	write_pixel(x + 2 + 5, y + 6, GREEN);
	write_pixel(x + 2 + 6, y + 6, GREEN);
	write_pixel(x + 2 + 7, y + 6, GREEN);
	write_pixel(x + 2 + 8, y + 6, GREEN);
	write_pixel(x + 2 + 9, y + 6, GREEN);
	write_pixel(x + 2 + 10, y + 6, DARK_GREEN);

	write_pixel(x + 2 + 2, y + 7, DARK_GREEN);
	write_pixel(x + 2 + 3, y + 7, GREEN);
	write_pixel(x + 2 + 4, y + 7, GREEN);
	write_pixel(x + 2 + 5, y + 7, GREEN);
	write_pixel(x + 2 + 6, y + 7, GREEN);
	write_pixel(x + 2 + 7, y + 7, GREEN);
	write_pixel(x + 2 + 8, y + 7, GREEN);
	write_pixel(x + 2 + 9, y + 7, GREEN);
	write_pixel(x + 2 + 10, y + 7, DARK_GREEN);    

	write_pixel(x + 2 + 2, y + 8, DARK_GREEN);
	write_pixel(x + 2 + 3, y + 8, DARK_GREEN);
	write_pixel(x + 2 + 4, y + 8, GREEN);
	write_pixel(x + 2 + 5, y + 8, GREEN);
	write_pixel(x + 2 + 6, y + 8, GREEN);
	write_pixel(x + 2 + 7, y + 8, GREEN);
	write_pixel(x + 2 + 8, y + 8, GREEN);
	write_pixel(x + 2 + 9, y + 8, DARK_GREEN);
	write_pixel(x + 2 + 10, y + 8, DARK_GREEN);

	write_pixel(x + 2 + 3, y + 9, DARK_GREEN);
	write_pixel(x + 2 + 4, y + 9, DARK_GREEN);
	write_pixel(x + 2 + 5, y + 9, DARK_GREEN);
	write_pixel(x + 2 + 6, y + 9, GREEN);
	write_pixel(x + 2 + 7, y + 9, GREEN);
	write_pixel(x + 2 + 8, y + 9, DARK_GREEN);
	write_pixel(x + 2 + 9, y + 9, DARK_GREEN);    

	write_pixel(x + 2 + 2, y + 10, LIGHT_GREEN);
	write_pixel(x + 2 + 3, y + 10, GREEN);
	write_pixel(x + 2 + 4, y + 10, GREEN);
	write_pixel(x + 2 + 5, y + 10, GREEN);
	write_pixel(x + 2 + 6, y + 10, GREEN);
	write_pixel(x + 2 + 7, y + 10, GREEN);
	write_pixel(x + 2 + 8, y + 10, GREEN);
	write_pixel(x + 2 + 9, y + 10, GREEN);
	write_pixel(x + 2 + 10, y + 10, DARK_GREEN);

	write_pixel(x + 2 + 2, y + 11, DARK_GREEN);
	write_pixel(x + 2 + 3, y + 11, GREEN);
	write_pixel(x + 2 + 4, y + 11, GREEN);
	write_pixel(x + 2 + 5, y + 11, GREEN);
	write_pixel(x + 2 + 6, y + 11, GREEN);
	write_pixel(x + 2 + 7, y + 11, GREEN);
	write_pixel(x + 2 + 8, y + 11, GREEN);
	write_pixel(x + 2 + 9, y + 11, GREEN);
	write_pixel(x + 2 + 10, y + 11, DARK_GREEN);

	write_pixel(x + 2 + 2, y + 12, DARK_GREEN);
	write_pixel(x + 2 + 3, y + 12, GREEN);
	write_pixel(x + 2 + 4, y + 12, GREEN);
	write_pixel(x + 2 + 5, y + 12, GREEN);
	write_pixel(x + 2 + 6, y + 12, GREEN);
	write_pixel(x + 2 + 7, y + 12, GREEN);
	write_pixel(x + 2 + 8, y + 12, GREEN);
	write_pixel(x + 2 + 9, y + 12, DARK_GREEN);
	write_pixel(x + 2 + 10, y + 12, DARK_GREEN);

	write_pixel(x + 2 + 2, y + 13, PEACH);
	write_pixel(x + 2 + 3, y + 13, DARK_GREEN);
	write_pixel(x + 2 + 4, y + 13, GREEN);
	write_pixel(x + 2 + 5, y + 13, GREEN);
	write_pixel(x + 2 + 6, y + 13, GREEN);
	write_pixel(x + 2 + 7, y + 13, GREEN);
	write_pixel(x + 2 + 8, y + 13, GREEN);
	write_pixel(x + 2 + 9, y + 13, DARK_GREEN);
	write_pixel(x + 2 + 10, y + 13, PEACH);

	write_pixel(x + 2 + 3, y + 14, DARK_GRAY);
	write_pixel(x + 2 + 4, y + 14, PANTS);
	write_pixel(x + 2 + 5, y + 14, PANTS);
	write_pixel(x + 2 + 6, y + 14, DARK_GRAY);
	write_pixel(x + 2 + 7, y + 14, PANTS);
	write_pixel(x + 2 + 8, y + 14, PANTS);
	write_pixel(x + 2 + 9, y + 14, DARK_GRAY);

	write_pixel(x + 2 + 3, y + 15, PANTS);
	write_pixel(x + 2 + 4, y + 15, PANTS);
	write_pixel(x + 2 + 5, y + 15, DARK_GRAY);
	write_pixel(x + 2 + 7, y + 15, PANTS);
	write_pixel(x + 2 + 8, y + 15, PANTS);
	write_pixel(x + 2 + 9, y + 15, DARK_GRAY);
}

void print_character_left(int x, int y){
	for(l = y; l < y + 17; l++){
        for(i = 0; i < 17; i++){
            write_pixel(x+i, l, GRAY);      
        }
    }

	// floor deco para cool
	write_pixel(x + 2, y + 2, BLACK);
	write_pixel(x + 7, y + 5, BLACK);
	write_pixel(x + 3, y + 6, BLACK);
	write_pixel(x + 8, y + 7, BLACK);
	write_pixel(x + 12, y + 7, BLACK);
	write_pixel(x + 6, y + 7, BLACK);
	write_pixel(x + 2, y + 9, BLACK);
	write_pixel(x + 11, y + 10, BLACK);
	write_pixel(x + 16, y + 10, BLACK);
	write_pixel(x + 9, y + 13, BLACK);
	write_pixel(x + 4, y + 15, BLACK);
	write_pixel(x + 10, y + 15, BLACK);


    // hoooooman
    write_pixel(x + 2 + 4, y + 2, LIGHT_GREEN);
	write_pixel(x + 2 + 5, y + 2, GREEN);
	write_pixel(x + 2 + 6, y + 2, GREEN);
	write_pixel(x + 2 + 7, y + 2, GREEN);
	write_pixel(x + 2 + 8, y + 2, DARK_GREEN);

	write_pixel(x + 2 + 3, y + 3, LIGHT_GREEN);
	write_pixel(x + 2 + 4, y + 3, GREEN);
	write_pixel(x + 2 + 5, y + 3, GREEN);
	write_pixel(x + 2 + 6, y + 3, GREEN);
	write_pixel(x + 2 + 7, y + 3, GREEN);
	write_pixel(x + 2 + 8, y + 3, GREEN);
	write_pixel(x + 2 + 9, y + 3, DARK_GREEN);
	write_pixel(x + 2 + 10, y + 3, DARK_GREEN);
	write_pixel(x + 2 + 11, y + 3, DARK_GREEN);

	write_pixel(x + 2 + 2, y + 4, DARK_YELLOW);
	write_pixel(x + 2 + 3, y + 4, DARK_GREEN);
	write_pixel(x + 2 + 4, y + 4, DARK_GREEN);
	write_pixel(x + 2 + 5, y + 4, DARK_GREEN);
	write_pixel(x + 2 + 6, y + 4, GREEN);
	write_pixel(x + 2 + 7, y + 4, GREEN);
	write_pixel(x + 2 + 8, y + 4, GREEN);
	write_pixel(x + 2 + 9, y + 4, GREEN);
	write_pixel(x + 2 + 10, y + 4, DARK_GREEN);

	write_pixel(x + 2 + 2, y + 5, YELLOW);
	write_pixel(x + 2 + 3, y + 5, YELLOW);
	write_pixel(x + 2 + 4, y + 5, DARK_YELLOW);
	write_pixel(x + 2 + 5, y + 5, DARK_YELLOW);
	write_pixel(x + 2 + 6, y + 5, DARK_GREEN);
	write_pixel(x + 2 + 7, y + 5, GREEN);
	write_pixel(x + 2 + 8, y + 5, GREEN);
	write_pixel(x + 2 + 9, y + 5, GREEN);
	write_pixel(x + 2 + 10, y + 5, DARK_GREEN);

	write_pixel(x + 2 + 2, y + 6, PEACH);
	write_pixel(x + 2 + 3, y + 6, BLACK);
	write_pixel(x + 2 + 4, y + 6, DARK_PEACH);
	write_pixel(x + 2 + 5, y + 6, YELLOW);
	write_pixel(x + 2 + 6, y + 6, DARK_YELLOW);
	write_pixel(x + 2 + 7, y + 6, DARK_GREEN);
	write_pixel(x + 2 + 8, y + 6, GREEN);
	write_pixel(x + 2 + 9, y + 6, GREEN);
	write_pixel(x + 2 + 10, y + 6, GREEN);

	write_pixel(x + 2 + 2, y + 7, DARK_PEACH);
	write_pixel(x + 2 + 3, y + 7, BLACK);
	write_pixel(x + 2 + 4, y + 7, PEACH);
	write_pixel(x + 2 + 5, y + 7, PEACH);
	write_pixel(x + 2 + 6, y + 7, PEACH);
	write_pixel(x + 2 + 7, y + 7, PEACH);
	write_pixel(x + 2 + 8, y + 7, PEACH);
	write_pixel(x + 2 + 9, y + 7, GREEN);
	write_pixel(x + 2 + 10, y + 7, GREEN);    

	write_pixel(x + 2 + 2, y + 8, PEACH);
	write_pixel(x + 2 + 3, y + 8, PEACH);
	write_pixel(x + 2 + 4, y + 8, PEACH);
	write_pixel(x + 2 + 5, y + 8, PEACH);
	write_pixel(x + 2 + 6, y + 8, PEACH);
	write_pixel(x + 2 + 7, y + 8, PEACH);
	write_pixel(x + 2 + 8, y + 8, DARK_GREEN);
	write_pixel(x + 2 + 9, y + 8, GREEN);
	write_pixel(x + 2 + 10, y + 8, GREEN);

	write_pixel(x + 2 + 2, y + 9, PEACH);
	write_pixel(x + 2 + 3, y + 9, PEACH);
	write_pixel(x + 2 + 4, y + 9, PEACH);
	write_pixel(x + 2 + 5, y + 9, PEACH);
	write_pixel(x + 2 + 6, y + 9, PEACH);
	write_pixel(x + 2 + 7, y + 9, DARK_GREEN);
	write_pixel(x + 2 + 8, y + 9, GREEN);
	write_pixel(x + 2 + 9, y + 9, GREEN);
	write_pixel(x + 2 + 10, y + 9, DARK_GREEN);

	write_pixel(x + 2 + 2, y + 10, DARK_GREEN);
	write_pixel(x + 2 + 3, y + 10, GREEN);
	write_pixel(x + 2 + 4, y + 10, GREEN);
	write_pixel(x + 2 + 5, y + 10, GREEN);
	write_pixel(x + 2 + 6, y + 10, GREEN);
	write_pixel(x + 2 + 7, y + 10, GREEN);
	write_pixel(x + 2 + 8, y + 10, GREEN);
	write_pixel(x + 2 + 9, y + 10, DARK_GREEN);

	write_pixel(x + 2 + 3, y + 11, DARK_GREEN);
	write_pixel(x + 2 + 4, y + 11, GREEN);
	write_pixel(x + 2 + 5, y + 11, GREEN);
	write_pixel(x + 2 + 6, y + 11, DARK_GREEN);
	write_pixel(x + 2 + 7, y + 11, GREEN);
	write_pixel(x + 2 + 8, y + 11, GREEN);
	write_pixel(x + 2 + 9, y + 11, GREEN);
	
	write_pixel(x + 2 + 3, y + 12, GREEN);
	write_pixel(x + 2 + 4, y + 12, DARK_GREEN);
	write_pixel(x + 2 + 5, y + 12, GREEN);
	write_pixel(x + 2 + 6, y + 12, GREEN);
	write_pixel(x + 2 + 7, y + 12, DARK_GREEN);
	write_pixel(x + 2 + 8, y + 12, GREEN);

	write_pixel(x + 2 + 4, y + 13, DARK_GREEN);
	write_pixel(x + 2 + 5, y + 13, PEACH);
	write_pixel(x + 2 + 6, y + 13, DARK_PEACH);
	write_pixel(x + 2 + 7, y + 13, DARK_GREEN);
	write_pixel(x + 2 + 8, y + 13, DARK_GREEN);

	write_pixel(x + 2 + 4, y + 14, DARK_GRAY);
	write_pixel(x + 2 + 5, y + 14, PANTS);
	write_pixel(x + 2 + 6, y + 14, PANTS);
	write_pixel(x + 2 + 7, y + 14, PANTS);
	write_pixel(x + 2 + 8, y + 14, DARK_GRAY);

	write_pixel(x + 2 + 5, y + 15, PANTS);
	write_pixel(x + 2 + 6, y + 15, PANTS);
	write_pixel(x + 2 + 7, y + 15, PANTS);
	
}

void print_character_right(int x, int y){
	for(l = y; l < y + 17; l++){
        for(i = 0; i < 17; i++){
            write_pixel(x+i, l, GRAY);      
        }
    }

	// floor deco para cool
	write_pixel(x + 2, y + 2, BLACK);
	write_pixel(x + 7, y + 5, BLACK);
	write_pixel(x + 3, y + 6, BLACK);
	write_pixel(x + 8, y + 7, BLACK);
	write_pixel(x + 12, y + 7, BLACK);
	write_pixel(x + 6, y + 7, BLACK);
	write_pixel(x + 2, y + 9, BLACK);
	write_pixel(x + 11, y + 10, BLACK);
	write_pixel(x + 16, y + 10, BLACK);
	write_pixel(x + 9, y + 13, BLACK);
	write_pixel(x + 4, y + 15, BLACK);
	write_pixel(x + 10, y + 15, BLACK);


    // hoooooman
    write_pixel(x + 2 + 4, y + 2, LIGHT_GREEN);
	write_pixel(x + 2 + 5, y + 2, GREEN);
	write_pixel(x + 2 + 6, y + 2, GREEN);
	write_pixel(x + 2 + 7, y + 2, GREEN);
	write_pixel(x + 2 + 8, y + 2, DARK_GREEN);

	write_pixel(x + 2 + 1, y + 3, LIGHT_GREEN);
	write_pixel(x + 2 + 2, y + 3, LIGHT_GREEN);
	write_pixel(x + 2 + 3, y + 3, LIGHT_GREEN);
	write_pixel(x + 2 + 4, y + 3, GREEN);
	write_pixel(x + 2 + 5, y + 3, GREEN);
	write_pixel(x + 2 + 6, y + 3, GREEN);
	write_pixel(x + 2 + 7, y + 3, GREEN);
	write_pixel(x + 2 + 8, y + 3, GREEN);
	write_pixel(x + 2 + 9, y + 3, DARK_GREEN);

	write_pixel(x + 2 + 2, y + 4, LIGHT_GREEN);
	write_pixel(x + 2 + 3, y + 4, GREEN);
	write_pixel(x + 2 + 4, y + 4, GREEN);
	write_pixel(x + 2 + 5, y + 4, GREEN);
	write_pixel(x + 2 + 6, y + 4, GREEN);
	write_pixel(x + 2 + 7, y + 4, GREEN);
	write_pixel(x + 2 + 8, y + 4, DARK_GREEN);
	write_pixel(x + 2 + 9, y + 4, DARK_GREEN);
	write_pixel(x + 2 + 10, y + 4, DARK_YELLOW);

	write_pixel(x + 2 + 2, y + 5, GREEN);
	write_pixel(x + 2 + 3, y + 5, GREEN);
	write_pixel(x + 2 + 4, y + 5, GREEN);
	write_pixel(x + 2 + 5, y + 5, GREEN);
	write_pixel(x + 2 + 6, y + 5, DARK_GREEN);
	write_pixel(x + 2 + 7, y + 5, DARK_GREEN);
	write_pixel(x + 2 + 8, y + 5, DARK_PEACH);
	write_pixel(x + 2 + 9, y + 5, PEACH);
	write_pixel(x + 2 + 10, y + 5, YELLOW);

	write_pixel(x + 2 + 2, y + 6, GREEN);
	write_pixel(x + 2 + 3, y + 6, GREEN);
	write_pixel(x + 2 + 4, y + 6, GREEN);
	write_pixel(x + 2 + 5, y + 6, DARK_GREEN);
	write_pixel(x + 2 + 6, y + 6, PEACH);
	write_pixel(x + 2 + 7, y + 6, PEACH);
	write_pixel(x + 2 + 8, y + 6, PEACH);
	write_pixel(x + 2 + 9, y + 6, BLACK);
	write_pixel(x + 2 + 10, y + 6, DARK_PEACH);

	write_pixel(x + 2 + 2, y + 7, GREEN);
	write_pixel(x + 2 + 3, y + 7, GREEN);
	write_pixel(x + 2 + 4, y + 7, DARK_GREEN);
	write_pixel(x + 2 + 5, y + 7, PEACH);
	write_pixel(x + 2 + 6, y + 7, PEACH);
	write_pixel(x + 2 + 7, y + 7, PEACH);
	write_pixel(x + 2 + 8, y + 7, PEACH);
	write_pixel(x + 2 + 9, y + 7, BLACK);
	write_pixel(x + 2 + 10, y + 7, DARK_PEACH);    

	write_pixel(x + 2 + 2, y + 8, DARK_GREEN);
	write_pixel(x + 2 + 3, y + 8, GREEN);
	write_pixel(x + 2 + 4, y + 8, DARK_GREEN);
	write_pixel(x + 2 + 5, y + 8, DARK_PEACH);
	write_pixel(x + 2 + 6, y + 8, PEACH);
	write_pixel(x + 2 + 7, y + 8, PEACH);
	write_pixel(x + 2 + 8, y + 8, PEACH);
	write_pixel(x + 2 + 9, y + 8, PEACH);
	write_pixel(x + 2 + 10, y + 8, DARK_PEACH);

	write_pixel(x + 2 + 2, y + 9, DARK_GREEN);
	write_pixel(x + 2 + 3, y + 9, GREEN);
	write_pixel(x + 2 + 4, y + 9, GREEN);
	write_pixel(x + 2 + 5, y + 9, DARK_GREEN);
	write_pixel(x + 2 + 6, y + 9, PEACH);
	write_pixel(x + 2 + 7, y + 9, PEACH);
	write_pixel(x + 2 + 8, y + 9, PEACH);
	write_pixel(x + 2 + 9, y + 9, DARK_PEACH);
	write_pixel(x + 2 + 10, y + 9, DARK_PEACH);

	write_pixel(x + 2 + 3, y + 10, DARK_GREEN);
	write_pixel(x + 2 + 4, y + 10, GREEN);
	write_pixel(x + 2 + 5, y + 10, GREEN);
	write_pixel(x + 2 + 6, y + 10, GREEN);
	write_pixel(x + 2 + 7, y + 10, GREEN);
	write_pixel(x + 2 + 8, y + 10, GREEN);
	write_pixel(x + 2 + 9, y + 10, GREEN);
	write_pixel(x + 2 + 10, y + 10, DARK_GREEN);

	write_pixel(x + 2 + 3, y + 11, DARK_GREEN);
	write_pixel(x + 2 + 4, y + 11, GREEN);
	write_pixel(x + 2 + 5, y + 11, DARK_GREEN);
	write_pixel(x + 2 + 6, y + 11, GREEN);
	write_pixel(x + 2 + 7, y + 11, GREEN);
	write_pixel(x + 2 + 8, y + 11, DARK_GREEN);
	write_pixel(x + 2 + 9, y + 11, GREEN);
	
	write_pixel(x + 2 + 4, y + 12, GREEN);
	write_pixel(x + 2 + 5, y + 12, DARK_GREEN);
	write_pixel(x + 2 + 6, y + 12, GREEN);
	write_pixel(x + 2 + 7, y + 12, GREEN);
	write_pixel(x + 2 + 8, y + 12, DARK_GREEN);
	write_pixel(x + 2 + 9, y + 12, GREEN);

	write_pixel(x + 2 + 4, y + 13, DARK_GREEN);
	write_pixel(x + 2 + 5, y + 13, DARK_GREEN);
	write_pixel(x + 2 + 6, y + 13, PEACH);
	write_pixel(x + 2 + 7, y + 13, DARK_PEACH);
	write_pixel(x + 2 + 8, y + 13, DARK_GREEN);

	write_pixel(x + 2 + 4, y + 14, DARK_GRAY);
	write_pixel(x + 2 + 5, y + 14, PANTS);
	write_pixel(x + 2 + 6, y + 14, PANTS);
	write_pixel(x + 2 + 7, y + 14, PANTS);
	write_pixel(x + 2 + 8, y + 14, DARK_GRAY);

	write_pixel(x + 2 + 5, y + 15, PANTS);
	write_pixel(x + 2 + 6, y + 15, PANTS);
	write_pixel(x + 2 + 7, y + 15, PANTS);
	
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
            else if(current_level[xPos][yPos] == 'k') {
				// if char down
				if(move == 's') print_character(k,j);
				// if char left
				else if(move == 'a') print_character_left(k,j);
				// if char right
				else if(move == 'd') print_character_right(k,j);
				// if char up
				else if(move == 'w') print_character_up(k,j);
				else print_character(k,j);
			}else if(current_level[xPos][yPos] == 'K'){
				// if char down
				if(move == 's') print_character_score(k,j);
				// if char left
				else if(move == 'a') print_character_score_left(k,j);
				// if char right
				else if(move == 'd') print_character_score_right(k,j);
				// if char up
				else if(move == 'w') print_character_score_up(k,j);
				else print_character_score(k,j);
			}else if(current_level[xPos][yPos] == 's') print_storage(k,j);
			else if(current_level[xPos][yPos] == 'B') print_box_stored(k,j);
			else print_black(k,j);
			yPos++;
		}
		yPos = 0;
		xPos++;
	}
	char text_level[10] = {'L','E','V','E','L',':',' ', current_level_num + '0'};
	write_text(text_level, 225, 18,WHITE,0);
	write_text("Up-W",240,50,WHITE,0);
	write_text("Dn-S",240,75,WHITE,0);
	write_text("Lf-A",240,100,WHITE,0);
	write_text("Rt-D",240,125,WHITE,0);
	write_text("Menu-2",240,150,WHITE,0);
	write_text("Exit-3",240,175,WHITE,0); 
}

void go_next_level(){
	current_level_num++;
	for(i = 0; i < 10; i++){
		for(j = 0;j < 10;j++){
			current_level[i][j] = levels[current_level_num - 1][i][j];
			if(current_level[i][j] == 'k' || current_level[i][j] == 'K'){
				playerXPos = i; 
				playerYPos = j;
			}
		}
	}
	erase(1,1,350,280); //clear screen
}

void go_prev_level(){
	current_level_num--;
	for(i = 0; i < 10; i++){
		for(j = 0;j < 10;j++){
			current_level[i][j] = levels[current_level_num - 1][i][j];
			if(current_level[i][j] == 'k' || current_level[i][j] == 'K'){
				playerXPos = i; 
				playerYPos = j;
			}
		}
	}
	erase(1,1,350,280); //clear screen
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
				if(input == next_level){
					go_next_level();		
				}
				else if(input == prev_level){
					go_prev_level();		
				}
				print_board(input);
				input = (char) getch();
			}while(input != quit_game || input != main_menu);		
		}
	}while(input != quit_game);	
	set_graphics(VGA_TEXT80X25X16);
	clrscr();
}