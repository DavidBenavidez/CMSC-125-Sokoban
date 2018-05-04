#include "../../sdk/dexsdk.h"
#include "../../sdk/time.h"

int boardSize, xPos, yPos, i, j;
char **gameBoard;
char move;

header(int x, int y){ //displays header
	
	write_text("SOKOBAN",120,40,WHITE,1); //title

	//menu options
	write_text("1 - Start",40,160,WHITE,0); 
	write_text("2 - View High Scores",200,160,WHITE,0);
	write_text("2 - Quit",360,160,WHITE,0);
}

void print_box(int r, int c, int x, int y){ //print a bulb 

	//gray(x, y); // wall
	// light(r, c, x, y); // box 
	
}

void print_board(int x, int y){ //set up initial board 

	int i, j, a, b;
 	a=x;
 	b=y;
 	char str[15];

	//display level
   	write_text("Level",135,5,WHITE,0); 
	sprintf(str,"%d",level);
   	write_text(str,190,5,WHITE,0);

	//print the 25 bulbs
	/*for(i=0; i<maxrow; i++, b+=24){
		for(j=0; j<maxcol; j++, a+=31)
			print_bulb(i, j, a, b);
		a=x;
	}*/ //ilipat yung code ng backend ng pagpiprint ng board

	//prints board

	
	//display legend
	write_text("Up-W",5,35,WHITE,0);
	write_text("Dn-S",5,45,WHITE,0);
	write_text("Lf-A",5,55,WHITE,0);
	write_text("Rt-D",5,65,WHITE,0);
	
	write_text("Exit",5,75,WHITE,0);	
}

