/* ----------------------------------------------
 * Basic Calculator with + - / % *
 *
 * To Do: Create a trinity game
 * ----------------------------------------------
 */
 
#include<stdio.h>      // standard library header defines various functions for input and output

// defining function 'displayInfo' with no parameter and no return type.
// Here, we are using function 'displayInfo' to print the program header information
void displayInfo () 
{
	// printf function produces formatted output. 
	printf ("Program #2: Trinity\n");
	printf ("Author: Bushra Baqui\n");
	printf ("TA: Chenwei Zhang   Lab: Tues 9am\n");
	printf ("Date: February 2, 2016\n");
	printf ("System: DevC++ on Windows 10\n\n\n");
	printf ("Welcome to Trinity, the game where there's three ways\n"
   	        "to get three in a row, in one of three rows or columns,\n"
            "or diagonals.  Play alternates between the two players.\n"
            "On each move select any available piece and an open\n"
            "board destination location.  A winning configuration\n"
            "is three of the same set in a row (e.g. b a c, A B C\n" 
            "or 3 2 1),  all 3 from the same set position (e.g. A 1 a,\n" 
            "B 2 b or c 3 C3), or three in a row where each is a\n" 
            "different set member (1st, 2nd, 3rd) such as 2 A c,\n"
            "a B 3 or C 1 b.\n\n");
}// end displayInfo()


// defining function 'piecesToPlay' with 9 parameters and no return type. 
// This function displays the pieces available to play
void piecesToPlay(char p1, char p2, char p3, char p4, char p5, char p6, char p7, char p8, char p9) 
{
    printf ("----------------------------------\n");
	printf ("Pieces available to play:\n\n");
	printf ("   %c %c %c\n", p1, p2, p3);
	printf ("   %c %c %c\n", p4, p5, p6);
	printf ("   %c %c %c\n\n", p7, p8, p9);
}// end piecesToPlay()


// defining function 'displayBoard' with 9 parameters and no return type.
// This function displays the playing board.
void displayBoard (char b1, char b2, char b3, char b4, char b5, char b6, char b7, char b8, char b9) 
{
	printf(" -----------   Positions:\n");
		printf("| %c | %c | %c |   1  2  3\n", b1, b2, b3);
    printf(" ----------- \n");
        printf("| %c | %c | %c |   4  5  6\n", b4, b5, b6);
    printf(" ----------- \n");
        printf("| %c | %c | %c |   7  8  9\n", b7, b8, b9);
    printf(" ----------- \n"); 
}// end displayBoard()


// defining function 'updateDisplayBoard' with 11 parameters and no return type.
// This function enters the userinput piece in the board.
// Add one to the reference parameter.  In C for reference parameters we must:
//    1. Pass with an ampersand
//    2. Catch with an asterisk
//    3. Use with an asterisk
// Changes to a reference parameter are reflected back in the calling code
void updateDisplayBoard(char position, char piece, char *b1, char *b2, char *b3, char *b4, char *b5, 
                        char *b6, char *b7, char *b8, char *b9) // Here we are catching with an asterisk
{
// using switch to update the board
//when user enters the piece and the position, the piece is entered in that position
  switch(position) 
  {
    case '1': *b1 = piece;    // Using with an asterisk
            break;
    case '2': *b2 = piece;
            break;
    case '3': *b3 = piece;
            break;
    case '4': *b4 = piece;
            break;
    case '5': *b5 = piece;
            break;
    case '6': *b6 = piece;
            break;
    case '7': *b7 = piece;
            break;
    case '8': *b8 = piece;
            break;
    case '9': *b9 = piece;
            break;
    default : printf("\nError %c\n", position);  
  } // end switch
}// end updateDisplayBoard()


//-----------------------------------------------------------------------------
int main() 
{
	displayInfo();  // calling function displayInfo()
	
	//Declaration of character variables. 
	char position;                  
	char returnChar = '\r'; //variable will be used later to identify user input of return key
	char moveNumber;
    char piece;
    char xyz, uvw;
	//Declaration of integer variables. 
	int playerToMove;
	int winner = 0;
    
    //Declaration and initialization of character variables for the pieces
    char p1 = 'A';
	char p2 = 'B';
	char p3 = 'C';
	char p4 = '1';
	char p5 = '2';
	char p6 = '3';
	char p7 = 'a';
	char p8 = 'b';
	char p9 = 'c';
	
	//Declaration of character variables for the board
	char b1, b2, b3, b4, b5, b6, b7, b8, b9;
	
	//Initialization of the board variables to blank space
	b1 = b2 = b3 = b4 = b5 = b6 = b7 = b8 = b9 = ' ';
	
	//Using 'for' loop to alternate turns between two players until there is a winner
	for (moveNumber = 1; moveNumber <= 9 && winner == 0; moveNumber++) 
	{
		printf ("\n");	
		
		piecesToPlay(p1, p2, p3, p4, p5, p6, p7, p8, p9);  // calling function piecesToPlay() 
		
		displayBoard(b1, b2, b3, b4, b5, b6, b7, b8, b9);  // calling function displayBoard()
		
		/*checking condition which player's turn is. 
		If move number is odd then player1 plays and if move number is even then player2 plays*/
		if (moveNumber % 2 == 0) 
		{
    	    playerToMove = 2;
	    }
	    else 
		{
		    playerToMove = 1;
	    }
    	
        printf ("%d. Player %d enter piece and position: ", moveNumber, playerToMove);
     
	    scanf ("%c%c%c", &piece, &position, &returnChar);  /*get the user input for piece, position, 
		                                                     and return key*/
	
	    //Using 'do-while' loop to check the condition for piece
	    do 
		{
		   //checking if the piece is from 'A,B,C,1,2,3,a,b,c'
		   if (piece == p1 || piece == p2 || piece == p3 || 
	           piece == p4 || piece == p5 || piece == p6 ||
	           piece == p7 || piece == p8 || piece == p9) 
	        {
	    	   //checking if the piece is available or not i.e. was the piece already taken earlier?
               if (piece==b1 ||piece==b2 ||piece==b3 ||
                   piece==b4 ||piece==b5 ||piece==b6 ||
                   piece==b7 ||piece==b8 ||piece==b9)
	            {
	               printf ("***Piece %c is not available. Please retry: ", piece);
	               scanf ("%c%c%c", &piece, &position, &returnChar); 
	        	
	       	       xyz = 'n';   //if the piece is not available
			    }
			    else 
				{
			       xyz = 'm';   //if the piece is available
			       break;      //exit the nested if loop
			    } 
			}
	        //if the piece is not from 'A,B,C,1,2,3,a,b,c' (i.e. Invalid Piece)
			else 
			{
		        printf ("***Piece %c is not available. Please retry: ", piece);
	            scanf ("%c%c%c", &piece, &position, &returnChar); 
	        
			    xyz = 'n';
            }    
        }while(xyz = 'n');     //the do while loop continues if the userinput piece is invalid or unavailable
    
    
        //checking condition for the position
        // if the userinput piece is valid and available
	    if (xyz = 'm')      
		{
		    do  
			{
			    /*checking condition if the userinput position is valid (i.e. position is 
				from '1,2,3,4,5,6,7,8,9' and position is not taken)*/
			    if((position=='1' && b1==' ')||(position=='2' && b2==' ')||(position=='3' && b3==' ')||
                   (position=='4' && b4==' ')||(position=='5' && b5==' ')||(position=='6' && b6==' ')||
                   (position=='7' && b7==' ')||(position=='8' && b8==' ')||(position=='9' && b9==' '))
	            {
	               xyz = 'm';  //if position is valid
	               break;     //exits the if loop
	            }
			    else 
				{
				   printf ("***Location %c is not available. Please retry: ", position);
	               scanf ("%c%c%c", &piece, &position, &returnChar);
	               xyz = 'n'; //if position is invalid
			    }
		    }while (xyz = 'n');  //if the userinput position is not available do-while loop continues
    	}
	
	    //calling the function updateDisplayBoard
	    //using a C reference parameter so that the change to the parameter is reflected back to the code here
	   updateDisplayBoard(position, piece, &b1, &b2, &b3, &b4, &b5, &b6, &b7, &b8, &b9);
   	
   	
	   //update piece. 
	   //if the userinput piece is in the display board, then the piece
	   if (b1==p1|| b2==p1||b3==p1||b4==p1||b5==p1||b6==p1||b7==p1||b8==p1||b9==p1) {p1 = ' ';}
       if (b1==p2|| b2==p2||b3==p2||b4==p2||b5==p2||b6==p2||b7==p2||b8==p2||b9==p2) {p2 = ' ';}
	   if (b1==p3|| b2==p3||b3==p3||b4==p3||b5==p3||b6==p3||b7==p3||b8==p3||b9==p3) {p3 = ' ';}
       if (b1==p4|| b2==p4||b3==p4||b4==p4||b5==p4||b6==p4||b7==p4||b8==p4||b9==p4) {p4 = ' ';}
       if (b1==p5|| b2==p5||b3==p5||b4==p5||b5==p5||b6==p5||b7==p5||b8==p5||b9==p5) {p5 = ' ';}
	   if (b1==p6|| b2==p6||b3==p6||b4==p6||b5==p6||b6==p6||b7==p6||b8==p6||b9==p6) {p6 = ' ';}
	   if (b1==p7|| b2==p7||b3==p7||b4==p7||b5==p7||b6==p7||b7==p7||b8==p7||b9==p7) {p7 = ' ';}
	   if (b1==p8|| b2==p8||b3==p8||b4==p8||b5==p8||b6==p8||b7==p8||b8==p8||b9==p8) {p8 = ' ';}
	   if (b1==p9|| b2==p9||b3==p9||b4==p9||b5==p9||b6==p9||b7==p9||b8==p9||b9==p9) {p9 = ' ';}
	
	
	   //converting the character value to the ASCII value and storing in variables
	   int i1=(int)b1;
	   int i2=(int)b2;
	   int i3=(int)b3;
	   int i4=(int)b4;
	   int i5=(int)b5;	
	   int i6=(int)b6;
	   int i7=(int)b7;
	   int i8=(int)b8;
	   int i9=(int)b9;
	
	   //checking winning conditions
	   /*if the sum of any pieces available to play is any of '198,150,294,214,211,217',
	   then it is a winning row, column, or diagonal.*/
	   if ((i1+i2+i3==198)||(i1+i2+i3==150)||(i1+i2+i3==294)||(i1+i2+i3==214)||(i1+i2+i3==211)||
	      (i1+i2+i3==217)) //checks top row for winner
	    {
	       printf ("Congratulations, you win with %c%c%c",b1,b2,b3); //print winning message
		   winner = 1; //assign value of variable to 1 if winning combination exists
		   break;   //if we have a winner, then exits the 'if' loop
	    }
	    else if((i4+i5+i6==150)||(i4+i5+i6==198)||(i4+i5+i6==294)||(i4+i5+i6==214)||(i4+i5+i6==211)||
	            (i4+i5+i6==217)) // checks second row for winner
	    {
	       printf ("Congratulations, you win with %c%c%c",b4,b5,b6); //print winning message
		   winner = 1; 
		   break;
	    }
	    else if((i7+i8+i9==294)||(i7+i8+i9==198)||(i7+i8+i9==150)||(i7+i8+i9==214)||(i7+i8+i9==211)||
	            (i7+i8+i9==217)) //checks third row for winner
      	{
	       printf ("Congratulations, you win with %c%c%c",b7,b8,b9);
		   winner = 1;
		   break;
	    }
	    else if((i2+i5+i8==214)||(i2+i5+i8==294)||(i2+i5+i8==198)||(i2+i5+i8==150)||(i2+i5+i8==211)||
	            (i2+i5+i8==217)) //checks second column for winner
	    {
	       printf ("Congratulations, you win with %c%c%c",b2,b5,b8);
		   winner = 1;
		   break;
	    }
	    else if((i1+i5+i9==214)||(i1+i5+i9==294)||(i1+i5+i9==198)||(i1+i5+i9==150)||(i1+i5+i9==211)||
	            (i1+i5+i9==217)) //checks top left to bottom right diagnoal for winner
	    {
	       printf ("Congratulations, you win with %c%c%c",b1,b5,b9);
		   winner = 1;
		   break;
	    }
	    else if((i7+i5+i3==214)||(i7+i5+i3==294)||(i7+i5+i3==198)||(i7+i5+i3==150)||(i7+i5+i3==211)||
	            (i7+i5+i3==217)) //checks bottom left to top right diagonal for winner
	    {
	       printf ("Congratulations, you win with %c%c%c",b7,b5,b3);
		   winner = 1;
		   break;
	    }
	    else if((i1+i4+i7==211)||(i1+i4+i7==214)||(i1+i4+i7==294)||(i1+i4+i7==198)||(i1+i4+i7==150)||
	            (i1+i4+i7==217)) // checks first column for winner
	    {   
	       printf ("Congratulations, you win with %c%c%c",b1,b4,b7);
		   winner = 1;
		   break;
	    }
	    else if((i3+i6+i9==217)||(i3+i6+i9==211)||(i3+i6+i9==214)||(i3+i6+i9==294)||(i3+i6+i9==198)||
	            (i3+i6+i9==150)) //checks third column for winner
	    {
	       printf ("Congratulations, you win with %c%c%c",b3,b6,b9);
		   winner = 1;
		   break;
	    }
	    else 
	    {
	       winner = 0; //sets variable value to 0 if there is no winner. Program re-enters for loop.
	    }
    }

	printf ("\n\n"); //new lines
	return 0;       //describes the exit status of the program
}

