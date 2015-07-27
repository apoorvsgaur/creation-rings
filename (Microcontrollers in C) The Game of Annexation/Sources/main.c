/*
************************************************************************
 ECE 362 - Mini-Project C Source File - Fall 2014                    
***********************************************************************
	 	   			 		  			 		  		
 Team ID: < Team 16 >

 Project Name: < The Game of Annexation >
 
 

 Team Members:

   - Team/Doc Leader: < Felise Goh >     
   - Software Leader: < Erin Rasmussen >     
   - Interface Leader: < Clayton Brandt >    
   - Peripheral Leader: < Apoorv Gaur >   
 Academic Honesty Statement:  In signing above, we hereby certify that we 
 are the individuals who created this HC(S)12 source file and that we have
 not copied the work of any other student (past or present) while completing 
 it. We understand that if we fail to honor this agreement, we will receive 
 a grade of ZERO and be subject to possible disciplinary action.

***********************************************************************

 The objective of this Mini-Project is to .... < ? >


***********************************************************************

 List of project-specific success criteria (functionality that will be
 demonstrated):

 1.

 2.

 3.

 4.

 5.

***********************************************************************

  Date code started: < ? >

  Update history (add an entry every time a significant change is made):

  Date: < ? >  Name: < ? >   Update: < ? >

  Date: < ? >  Name: < ? >   Update: < ? >

  Date: < ? >  Name: < ? >   Update: < ? >


***********************************************************************
*/

#include <hidef.h>           /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */
#include <mc9s12c32.h>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

/* All functions after main should be initialized here */
char inchar(void);
void outchar(char x);
void shiftout(char x);
void lcdwait(void);
void send_byte(char x);
void send_i(char x);
void chgline(char x);
void print_c(char x);
void pmsglcd(char[]);
void collect_score();
// ERIN IS THE BOMB.COM
int check_overlap(int*, int);
int check_flip(int, int*);
int check_valid(int, int*, int);
int flip_r(int, int*, int);
int flip_l(int, int*, int);
int flip_d(int, int*, int);
int flip_u(int, int*, int);
int flip_ur(int, int*, int);
int flip_ul(int, int*, int);
int flip_dr(int, int*, int);
int flip_dl(int, int*, int);
int poss_moves(int*, int, int);

void shiftout_cs(char x);
void shiftout_1(char x);
void shiftout_2(char x);
void cswait(void);
void send_byte_cs(char x);
void send_i_cs(char x);
void print_c_cs(char x);
//void pmsglcd(char[]);
void lcdwait();
//void shiftout(char x);
void send_byte_1(char x);
void send_i_1(char x);
void chgline_1(char x);
void print_c_1(char x);
void pmsglcd_1(char[]);
void send_byte_2(char x);
void send_i_2(char x);
void chgline_2(char x);
void print_c_2(char x);
void pmsglcd_2(char[]);
void print_matrix(int data[]);
void initial_LCD1();
void initial_LCD2();
void print_error_1();
void print_error_2();
void update_score();
void make_xmas();
void xmas_LCD1();
void xmas_LCD2();
void game_over();
void error_LCD2();
int data[64] = {
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,2,0,0,0,0,0,0,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
  //2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,2,2,2,2,2,2,2
};

int prev[64] = {
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,2,0,0,0,0,0,0,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
  //2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,2,2,2,2,2,2,2
};


/* Variable declarations */
char leftpb	= 0;  // left pushbutton flag
char rghtpb	= 0;  //right pushbutton flag
int previousr = 0;
int previousl =0;
int x = 0;
int y = 0;
int index = 56;
int flag;
int temp =0;
int player = 1;
int AN0 = 0;
int AN1 = 0;
int AN2 = 0;
int AN3 = 0;
int AN4 = 0;
int AN5 = 0;
int AN6 = 0;
int AN7 = 0;
int color = 0;
int invalid = 0;
int lcv;
int Score1 = 2;
int Score2 = 2;
int flash = 0;

   	   			 		  			 		       

/* Special ASCII characters */
#define CR 0x0D		// ASCII return 
#define LF 0x0A		// ASCII new line 

/* LCD COMMUNICATION BIT MASKS (note - different than previous labs) */
#define RS 0x10		// RS pin mask (PTT[4])
#define RW 0x20		// R/W pin mask (PTT[5])
#define LCDCLK 0x40	// LCD EN/CLK pin mask (PTT[6])

/* LCD INSTRUCTION CHARACTERS */
#define LCDON 0x0F	// LCD initialization command
#define LCDCLR 0x01	// LCD clear display command
#define TWOLINE 0x38	// LCD 2-line enable command
#define CURMOV 0xFE	// LCD cursor move instruction
#define LINE1 0x80	// LCD line 1 cursor position
#define LINE2 0xC0	// LCD line 2 cursor position

	 	   		
/*	 	   		
***********************************************************************
 Initializations
***********************************************************************
*/

void  initializations(void) {

/* Set the PLL speed (bus clock = 24 MHz) */
  CLKSEL = CLKSEL & 0x80; //; disengage PLL from system
  PLLCTL = PLLCTL | 0x40; //; turn on PLL
  SYNR = 0x02;            //; set PLL multiplier
  REFDV = 0;              //; set PLL divider
  while (!(CRGFLG & 0x08)){  }
  CLKSEL = CLKSEL | 0x80; //; engage PLL

/* Disable watchdog timer (COPCTL register) */
  COPCTL = 0x40   ; //COP off; RTI and COP stopped in BDM-mode

/* Initialize asynchronous serial port (SCI) for 9600 baud, interrupts off initially */
  SCIBDH =  0x00; //set baud rate to 9600
  SCIBDL =  0x9C; //24,000,000 / 16 / 156 = 9600 (approx)  
  SCICR1 =  0x00; //$9C = 156
  SCICR2 =  0x0C; //initialize SCI for program-driven operation
  DDRB   =  0x10; //set PB4 for output mode
  PORTB  =  0x10; //assert DTR pin on COM port

/* Initialize peripherals */
  DDRT = 0x3F;
  ATDDIEN = 0xFF;
  DDRAD=0;          
/* Initialize interrupts */
   SPICR1 = 0x50;
   SPICR2 = 0;
   SPIBR = 0x16;
   
   RTICTL = 0x1F;
   CRGINT = 0x80;
   
 /*TSCR1 = 0x80;
   TSCR2_PR = 0x02;
   TIOS = 0x80;
   TIE = 0x80;
   TC7 = 1;
   TIE_C7I = 1;
	 TCTL1 = 0x00;
   TCTL2 = 0x80; */
   
   // ATD Controls
    ATDCTL2 = 0x80;
    ATDCTL3 = 0x10;
    ATDCTL4 =  0b00000101;
    
    //PTT = 0;
   //print_matrix(data);
    
   PTT_PTT2 = 0;    
   initial_LCD1();
   initial_LCD2();
   
}




	 		  			 		  		
/*	 		  			 		  		
***********************************************************************
Main
***********************************************************************
*/
void main(void) {
  int i = 0;
  DisableInterrupts ;
	initializations(); 		  			 		  		
	EnableInterrupts;
  
  for(;;){
    //error_LCD2();
    print_matrix(data);
    
 /*   if (leftpb){
      leftpb=0;
      Score1++;
      print_error_1();
    }
    
    if (rghtpb){
      rghtpb=0;
      Score2++;
      print_error_2();
    } */  
    
    
    //update_score();  
	  ATDCTL5 = 0b00000000;
    while((ATDSTAT0 & 0x80) != 0x80){} // Wait for conversion to finish 
    AN0 = ATDDR0H;
    
    ATDCTL5 = 0b00000001;
    while((ATDSTAT0 & 0x80) != 0x80){} // Wait for conversion to finish 
    AN1 = ATDDR1H;
    
    ATDCTL5 = 0b00000010;
    while((ATDSTAT0 & 0x80) != 0x80){} // Wait for conversion to finish 
    AN2 = ATDDR0H;
    
    ATDCTL5 = 0b00000011;
    while((ATDSTAT0 & 0x80) != 0x80){} // Wait for conversion to finish 
    AN3 = ATDDR0H;
    
    ATDCTL5 = 0b00000100;
    while((ATDSTAT0 & 0x80) != 0x80){} // Wait for conversion to finish 
    AN4 = ATDDR0H;
    
    ATDCTL5 = 0b00000101;
    while((ATDSTAT0 & 0x80) != 0x80){} // Wait for conversion to finish 
    AN5 = ATDDR0H;
    
    
    /*
    
            
    if(ATDDR1H == ATDDR0H) {
      x = 0;
      y = 0;
    } 
    */
    
    if(PTT_PTT7) {
      make_xmas();
      outchar('H');
    }
    //Reset button
    if(PTT_PTT6) {
       for(lcv = 0; lcv < 64; lcv++){
        if(lcv == 27 || lcv == 36) {
          data[lcv] = 1;
          prev[lcv] = 1;
        } else if(lcv == 28 || lcv == 35) {
          data[lcv] = 2;
          prev[lcv] = 2;
        } else{
          data[lcv] = 0;
          prev[lcv] = 0;
        }
      }
      initial_LCD1();
      initial_LCD2();
      player = 1;
      index = 7;
      temp = 0;
      color = 0;
      index = 56;
      Score1 = 2;
      Score2 = 2;
      flash=0;
      
    }
    
    ///////////////////////////////////////////////////////////////////////
    if(Score1 + Score2 == 64) {
      if(flash == 0){
        game_over();
        flash++;
      }
      player = 0;
    }else if(!poss_moves(prev, player, index)) {
      if(player == 1) {
        SPIBR = 0x10;
        for(lcv = 0; lcv< 10; lcv++){
          lcdwait();
        }
        PTT_PTT4 = 1;
        send_i_1(0x0F);
        send_i_1(0x38);
        send_i_1(0x01);
         
        pmsglcd_1("NO MOVES");
      	chgline_1(LINE2);
      	pmsglcd_1("Player 2 GO");
         
        PTT_PTT4 = 0;
        SPIBR = 0x16;
        for(lcv = 0; lcv< 10; lcv++){
          lcdwait();
        }
      }else{
        SPIBR = 0x10;
        for(lcv = 0; lcv< 10; lcv++){
          lcdwait();
        }
        PTT_PTT3 = 1;
        send_i_2(0x0F);
        send_i_2(0x38);
        send_i_2(0x01);
         
        pmsglcd_2("NO MOVES");
      	chgline_2(LINE2);
      	pmsglcd_2("Player 1 GO");
         
        PTT_PTT3 = 0;
        SPIBR = 0x16;
        for(lcv = 0; lcv< 10; lcv++){
          lcdwait();
        }
      }
      player = player % 2 + 1;
      if(!poss_moves(prev, player, index)) {
        game_over();
        //player = 0;
      }
    }
    
    if(AN2 > 0xF0 && player == 1) {
      invalid = 0;
      color = 0x01;      
      // color is TYPE
      // index
      
      invalid = check_overlap(prev, index);
      invalid = invalid + check_valid(index, prev, color);
      if(invalid) {
        player = 1;
        for(lcv = 0; lcv < 64; lcv++) {
            data[lcv] = prev[lcv];
        }
        print_error_1();
        //print invalid move to player one LCD
      }else{
        temp = prev[index];
        prev[index] = color;
        invalid = check_flip(index, prev);
        if(invalid) {
          prev[index] = 0;
          for(lcv = 0; lcv < 64; lcv++) {
            data[lcv] = prev[lcv];
          // print invalid to player one LCD
          }
          print_error_1();
          player = 1;
        }else {
          for(lcv = 0; lcv < 64; lcv++) {
            data[lcv] = prev[lcv];
          }
          player = 2;
          color = 0x02;
          index = 7;
          update_score();
          temp = data[index];
        }

      }
    }else if(AN5 > 0xF0 && player == 2) {    
      invalid = 0;
      color = 0x02;      
      // color is TYPE
      // index
      
      invalid = check_overlap(prev, index);
      invalid = invalid + check_valid(index, prev, color); // where error SHOULD occur and move on
      if(invalid) {
        player = 2;
        for(lcv = 0; lcv < 64; lcv++) {
            data[lcv] = prev[lcv];
        }
/**/    print_error_2();
        //print invalid move to player one LCD
        
      }else{
        temp = prev[index];
        prev[index] = color;
        invalid = check_flip(index, prev);
        if(invalid) {
          prev[index] = 0;
          for(lcv = 0; lcv < 64; lcv++) {
            data[lcv] = prev[lcv];
          // print invalid to player one LCD
          }
          player = 2;
/**/      print_error_2();
        }else {
          for(lcv = 0; lcv < 64; lcv++) {
            data[lcv] = prev[lcv];
          }
          player = 1;
          color = 0x01;
          index = 56;
          update_score();
          temp = data[index];
        }

      }

    }
    else{
      
      if(player == 1){
        color = 0x01;
        if(((AN0 < 0xE0) && (AN0 > 0x40)) && ((AN1 < 0xE0) && (AN1 > 0x40))) {
          x = 0;
          y = 0;
          //error_LCD2();
        } 
        
        
        else{
    	  
    	    if(AN0 > 0xE0) {
    	     // PTT_PTT5 = 1;
    	     // PTT_PTT4 = 0;
    	      y = -8;
    	      x = 0;
    	    } else if(AN0 < 0x40){
    	    //  PTT_PTT5 = 0;
    	    //  PTT_PTT4 = 1;
    	      y = 8;
    	      x = 0;
    	    } else{
    	      PTT_PTT5 = 0;
    	      PTT_PTT4 = 0;
    	      //y = 0;
    	      //x = 0;
    	    }   
    	  
    	    if(AN1 > 0xE0) {
    	    //  PTT_PTT7 = 1;
    	    //  PTT_PTT6 = 0;
    	      y = 0;
    	      x = 1;
    	    
    	    } else if(AN1 < 0x40) {
    	    //  PTT_PTT7 = 0;
    	    //  PTT_PTT6 = 1;
    	      y = 0;
    	      x = -1;
    	    } else{
    	     // PTT_PTT7 = 0;
    	    //  PTT_PTT6 = 0;
    	     // x = 0;
    	      //y = 0;
    	    }  
        }
      } else if(player == 2) {
        color = 0x02;
        if(((AN3 < 0xE0) && (AN3 > 0x40)) && ((AN4 < 0xE0) && (AN4 > 0x40))) {
          x = 0;                     
          y = 0;
          //error_LCD2();
        } 
        
        
        else{
    	  
    	    if(AN3 > 0xE0) {
    	    //  PTT_PTT5 = 1;
    	    //  PTT_PTT4 = 0;
    	      y = 8;
    	      x = 0;
    	    } else if(AN3 < 0x40){
    	    //  PTT_PTT5 = 0;
    	    //  PTT_PTT4 = 1;
    	      y = -8;
    	      x = 0;
    	    } else{
    	    //  PTT_PTT5 = 0;
    	    //  PTT_PTT4 = 0;
    	      //y = 0;
    	      //x = 0;
    	    }   
    	  
    	    if(AN4 > 0xE0) {
    	    //  PTT_PTT7 = 1;
    	    //  PTT_PTT6 = 0;
    	      y = 0;
    	      x = -1;
    	    
    	    } else if(AN4 < 0x40) {
    	    //  PTT_PTT7 = 0;
    	    //  PTT_PTT6 = 1;
    	      y = 0;
    	      x = 1;
    	    } else{
    	    //  PTT_PTT7 = 0;
    	    //  PTT_PTT6 = 0;
    	     // x = 0;
    	      //y = 0;
    	    }  
        } 
      }
    

      /*if((index % 8 != 0 && x == 1) || (index % 7 != 0 && x == -1) || (index == 0 && x != -1)) {
        data[index] = 0;
        index = x + index;
        data[index] = 3;      
      } 
      
      if((index <= 7 && y != -8) ||(y != 8 && index >= 55) ||(index > 7 && index < 55)) {
        data[index] = 0;
        index = y + index;
        data[index] = 3;      
      } */
      
      
      //temp = data[index];
      if(index > 7 && index < 56) {
        //Move y
        data[index] = temp;
        
        index = y + index;
        temp = data[index];
        data[index] = color;
        
        if(check_overlap(prev,index)) {
          data[index] = 3;
        }
      } 
      else if(index <= 7 && y == 8) {
        //Move down
        
        data[index] = temp;
        index = y + index;
        temp =data[index];
        data[index] = color;
        if(check_overlap(prev,index)) {
          data[index] = 3;
        }
            
      } 
      else if(index >= 56 && y == -8) {
        //Move up
        
        data[index] = temp;
        index = y + index;
        temp = data[index];
        data[index] = color;
        if(check_overlap(prev,index)) {
          data[index] = 3;
        }
      }
      
      if(index % 8 != 0 && (index+1) % 8 != 0) {
        
        data[index] = temp;
        index = x + index;
        temp = data[index];
        data[index] = color;
        if(check_overlap(prev,index)) {
          data[index] = 3;
        }
      } 
      else if(index % 8 == 0 && x == 1) {
        
        data[index] = temp;
        index = x+index;
        temp = data[index];
        data[index] = color;
        if(check_overlap(prev,index)) {
          data[index] = 3;
        }
      } else if((index+1) % 8 == 0 && x == -1 && index != 0) {
        
        data[index] = temp;
        index = x+index;
        temp = data[index];
        data[index] = color;
        if(check_overlap(prev,index)) {
          data[index] = 3;
        }
      }
      
     // print_matrix(data) ;
      
//      print_matrix(data);
      /*else if(index % 8 != 0 && x != -1 && y == 0) {
        //Move x in the right direction
        data[index] = 0;
        index = x + index;
        data[index] = 3;
      } 
      
      else if (index % 7 != 0 && x != 1 && y == 0) {
        //Move x in the left direction
        data[index] = 0;
        index = x + index;
        data[index] = 3;
      } 
      
      else if (((index == 0 && y == 8) || (index == 56 && y == -8)) || ((index == 0 || index == 56) && x == 1)) {
        //Move x right in spots 0 and 56
        data[index] = 0;
        index = x + y + index;
        data[index] = 3;
      }  */
    }
    ///PTT_PTT0 = 0;
    //lcdwait();
    
    //for(i = 0; i < 64; i++) {
      
    //  print_c_cs(data[i]);
    //}
    
    
    //lcdwait();
    //PTT_PTT0 = 1;
    
   i = 0;
   while(i < 7) {
      lcdwait();
      i++;
     }
    
    
  }
	  /*loop forever */
	  
}
/* do not leave main */


/*
***********************************************************************
  shiftout_cs: Sends the Data to the SPI data register
***********************************************************************
*/
                       
void shiftout_cs(char x)
{
 
  // read the SPTEF bit, continue if bit is 1
  // write data to SPI data register
  // wait for 30 cycles for SPI data to shift out 
  unsigned char cycle; 
  int lcv = 0;
  while (SPISR_SPTEF != 1){
  }
  
  SPIDR = x;
  while(lcv < 1000) {
    lcv++;
    }
  
 /*
asm{
  psha
  pula
  psha
  pula
  psha
  pula
  psha
  pula
  psha
  pula
  psha
  pula

}
*/
}

/*
***********************************************************************
  lcdwait: Delay for approx 2 ms
***********************************************************************
*/

void lcdwait()
{
   unsigned int delay;
   for(delay=0; delay<48000; delay++){
   }
}

void cswait()
{
   unsigned int delay;
   for(delay=0; delay<12000; delay++){
   }
}

/*
*********************************************************************** 
  send_byte: writes character x to the LCD
***********************************************************************
*/

void send_byte_cs(char x)
{
     // shift out character
     // pulse LCD clock line low->high->low
     // wait 2 ms for LCD to process data
     shiftout_cs(x);
   //  lcdwait();
     
}

/*
***********************************************************************
  send_i: Sends instruction byte x to LCD  
***********************************************************************
*/

void send_i_cs(char x)
{
        // set the register select line low (instruction data)
        // send byte
        send_byte_cs(x);
        
}

/*
***********************************************************************
  chgline: Move LCD cursor to position x
  NOTE: Cursor positions are encoded in the LINE1/LINE2 variables
***********************************************************************
*/

void chgline(char x)
{
     //send_i_cs(CURMOV);
     send_byte_cs(x);
}

/*
***********************************************************************
  print_c: Print (single) character x on LCD            
***********************************************************************
*/
 
void print_c_cs(char x)
{
   //PTT_PTT0=1;
   send_byte_cs(x);
     /* sends a character to the terminal channel */
 
}

/*
***********************************************************************
  pmsglcd: print character string str[] on LCD
***********************************************************************
*/

void pmsglcd(char str[])
{
    int temp = 0;
    while(str[temp]){      
       print_c_cs(str[temp]);
       temp++;
    }
}


/*
***********************************************************************                       
 RTI interrupt service routine: RTI_ISR
************************************************************************
*/

interrupt 7 void RTI_ISR(void)
{
  	// clear RTI interrupt flagt 
  	CRGFLG = CRGFLG | 0x80;  
  	/*
  	if(PTAD_PTAD6 < previousr){
  	  player = player %2 + 1;
  	  rghtpb = 1;
  	}
  	if(PTAD_PTAD7 < previousl){
  	  leftpb = 1;
  	  player = player %2 + 1;
  	}
  	
    previousr = PTAD_PTAD6;
  	previousl = PTAD_PTAD7;	 
      */
}

/*
***********************************************************************                       
  TIM interrupt service routine	  		
***********************************************************************
*/

interrupt 15 void TIM_ISR(void)
{
  	// clear TIM CH 7 interrupt flag 
 	TFLG1 = TFLG1 | 0x80; 
  
}

/*
***********************************************************************                       
  SCI interrupt service routine		 		  		
***********************************************************************
*/

interrupt 20 void SCI_ISR(void)
{
 


}

/*

LCD - 1 Functions

*/





/*

LCD - 2 Functions

*/


char inchar(void) {
  /* receives character from the terminal channel */
        while (!(SCISR1 & 0x20)); /* wait for input */
    return SCIDRL;
}

/*
***********************************************************************
 Name:         outchar    (use only for DEBUGGING purposes)
 Description:  outputs ASCII character x to SCI serial port
 Example:      outchar('x');
***********************************************************************
*/

void outchar(char x) {
  /* sends a character to the terminal channel */
    while (!(SCISR1 & 0x80));  /* wait for output buffer empty */
    SCIDRL = x;
}








/********************************************************************************
*  int check_overlap(int* prev, int index)
*  returns value 1 if move is invalid, 0 if it is valid
*  prev is previous configuration of array
*  index if location of move
*  --> checks if current move is in location of existing pieces
********************************************************************************/
int check_overlap(int* prev, int index)
{
  int invalid = 0;
  if(prev[index])
  {
    invalid = 1;
  }
  
  return(invalid);
}


/********************************************************************************
*  int check_valid(int index, int* prev, int type)
*  returns 0 for valid move, 1 for invalid
*  
*  checks that there is at minimum, one piece of the opponents color neighboring 
*  the piece that has been played
********************************************************************************/

int check_valid(int index, int* curr, int type)
{ 
  int invalid = 0;
  int type2;
  
  if(type == 1)
  {
    type2 = 2;
  }
  else
  {
    type2 = 1;
  }
  
  if(index == 0)
  {
    invalid = !((curr[index + 1] == type2) || (curr[index + 8] == type2) || (curr[index + 9] == type2));
  }
  else if (index == 7)
  {
    invalid = !((curr[index - 1] == type2) || (curr[index + 8] == type2) || (curr[index + 7] == type2));
  }
  else if(index == 56)
  {
    invalid = !((curr[index + 1] == type2) || (curr[index - 7] == type2) || (curr[index - 8] == type2));
  }
  else if(index == 63)
  {   
    invalid = !((curr[index - 1] == type2) || (curr[index - 9] == type2) || (curr[index - 8] == type2));
  }
  else if((index % 8) == 0)
  {
    invalid = !((curr[index + 1] == type2) || (curr[index - 8] == type2) || (curr[index - 7] == type2) || (curr[index + 9] == type2) || (curr[index + 8] == type2));
  }
  else if(((index + 1) % 8) == 0)
  {
    invalid = !((curr[index - 1] == type2) || (curr[index - 8] == type2) || (curr[index - 9] == type2) || (curr[index + 7] == type2) || (curr[index + 8] == type2));
  }
  else if(index < 7)
  {
    invalid = !((curr[index + 1] == type2) || (curr[index - 1] == type2) || (curr[index + 7] == type2) || (curr[index + 9] == type2) || (curr[index + 8] == type2));
  }
  else if(index > 56)
  {
    invalid = !((curr[index + 1] == type2) || (curr[index - 1] == type2) || (curr[index - 7] == type2) || (curr[index - 9] == type2) || (curr[index - 8] == type2));
  }
  else
  {
    invalid = (!(curr[index + 1] == type2) && !(curr[index + 8] == type2) && !(curr[index + 9] == type2) && !(curr[index - 9] == type2) && !(curr[index - 8] == type2) && !(curr[index - 1] == type2) && !(curr[index + 7] == type2) && !(curr[index - 7] == type2));
  }
  return(invalid);
}

/********************************************************************************
*  int check_flip(int index, int* curr)
*  returns 1 for invalid move
*
*  checks that at least one of the opponents pieces will be flipped by the current
*  move. If flip is possible, all flips are made
********************************************************************************/

int check_flip(int index, int* curr)
{
  int invalid = 0;
  int type = curr[index]; // current player piece placed
  int type2; // opponents piece to be flipped
  int no_match; // if a given direction does not produce a flip
  int total; // result of whether any directions produce flips
  int lcv;
  
  if(type == 1)
  {
    type2 = 2;
  }
  else
  {
    type2 = 1;
  }
  if(index == 0)
  {
    if(curr[index + 1] == type2)
    {
      invalid = flip_r(index, curr, type);
    }
    if(curr[index + 8] == type2)
    {
      invalid = invalid + flip_d(index, curr, type);
    }
    if(curr[index + 9] == type2)
    {
      invalid = invalid + flip_dr(index, curr, type);
    }
  }
  else if(index == 7)
  {
    if(curr[index - 1] == type2)
    {
      invalid = flip_l(index, curr, type); 
    }
    if(curr[index + 8] == type2)
    {
      invalid += flip_d(index, curr, type);
    }
    if(curr[index + 7] == type2)
    {
      invalid += flip_dl(index, curr, type);
    }
  }
  else if(index == 56)
  {
    if(curr[index + 1] == type2)
    {
      invalid = flip_r(index, curr, type);
    }
    if(curr[index - 7] == type2)
    {
      invalid += flip_ur(index, curr, type);
    }
    if(curr[index - 8] == type2)
    {
      invalid += flip_u(index, curr, type);
    }
  }
  else if(index == 63)
  {   
    if(curr[index - 1] == type2)
    {
      invalid = flip_l(index, curr, type);
    }
    if(curr[index - 9] == type2)
    {
      invalid += flip_ul(index, curr, type);
    }
    if(curr[index - 8] == type2)
    {
      invalid += flip_u(index, curr, type);
    }
  }                                                               // flip tight dnw
  else if((index % 8) == 0)    /////////////////////////// -9? something going left does NOT stop at the edge check all flip left finctions. Stop BEFORE %8 == 0
  {
    if(curr[index + 1] == type2)
    {
      invalid = flip_r(index, curr, type);
    }
    if(curr[index - 7] == type2)    // did not flip?? invalid move
    {
      invalid += flip_ur(index, curr, type);
    }
    if(curr[index - 8] == type2)
    {
      invalid += flip_u(index, curr, type);
    }
    if(curr[index + 8] == type2)
    {
      invalid += flip_d(index, curr, type);
    }
    if(curr[index + 9] == type2)
    {
      invalid += flip_dr(index, curr, type);
    }
  }
  else if(((index + 1) % 8) == 0)
  {
    if(curr[index - 1] == type2)
    {
      invalid = flip_l(index, curr, type);
    }
    if(curr[index - 9] == type2)
    {
      invalid += flip_ul(index, curr, type);
    }
    if(curr[index - 8] == type2)
    {
      invalid += flip_u(index, curr, type);
    }
    if(curr[index + 7] == type2)
    {
      invalid += flip_dl(index, curr, type);
    }
    if(curr[index + 8] == type2)
    {
      invalid += flip_d(index, curr, type);
    }
  }
  else if(index < 7)
  {
    if(curr[index + 1] == type2)
    {
      invalid = flip_r(index, curr, type);
    }
    if(curr[index + 7] == type2)
    {
      invalid += flip_dl(index, curr, type);
    }
    if(curr[index + 8] == type2)
    {
      invalid += flip_d(index, curr, type);
    }
    if(curr[index + 9] == type2)
    {
      invalid += flip_dr(index, curr, type);
    }
    if(curr[index - 1] == type2)
    {
      invalid += flip_l(index, curr, type);
    }
  }
  else if(index > 56)
  {
    if(curr[index + 1] == type2)
    {
      invalid = flip_r(index, curr, type);
    }
    if(curr[index - 7] == type2)
    {
      invalid += flip_ur(index, curr, type);
    }
    if(curr[index - 8] == type2)
    {
      invalid += flip_u(index, curr, type);
    }
    if(curr[index - 9] == type2)
    {
      invalid += flip_ul(index, curr, type);
    }
    if(curr[index - 1] == type2)
    {
      invalid += flip_l(index, curr, type);
    }
  }
  else
  {
    if(curr[index + 1] == type2)
    {
      invalid = flip_r(index, curr, type);
    }
    if(curr[index - 1] == type2)
    {
      invalid += flip_l(index, curr, type);
    }
    if(curr[index + 8] == type2)
    {
      invalid += flip_d(index, curr, type);
    }
    if(curr[index - 8] == type2)
    {
      invalid += flip_u(index, curr, type);
    }
    if(curr[index - 7] == type2)
    {
      invalid += flip_ur(index, curr, type);
    }
    if(curr[index - 9] == type2)
    {
      invalid += flip_ul(index, curr, type);
    }
    if(curr[index + 9] == type2)
    {
      invalid += flip_dr(index, curr, type);
    }
    if(curr[index + 7] == type2)
    {
      invalid += flip_dl(index, curr, type);
    }
  }
  return(!invalid);
}

/********************************************************************************
*  int flip_r(int index, int* curr, int type, int*new)
*  returns a 1 if flips can be made
*  
*  checks and flips all pieces to the right of the current move
*
********************************************************************************/

int flip_r(int index, int* curr, int type)
{
  int type2 = (type % 2) + 1;
  int temp = index + 1;
  int lcv;
  int flip = 0;
  
  while((curr[temp] == type2) && ((temp+1) % 8 != 0)) {
    temp++;
  }
  if(curr[temp] == type) {
    for(lcv = index; lcv <= temp; lcv++) {
      curr[lcv] = type;
    }
    flip = 1;
  }
  return(flip);
}

/********************************************************************************
*  int flip_l(int index, int* curr, int type, int*new)
*  returns a 1 if flips can be made
*  
*  checks and flips all pieces to the left of the current move
*
********************************************************************************/

int flip_l(int index, int* curr, int type)
{
  int type2 = (type % 2) + 1;
  int temp = index - 1;
  int lcv;
  int flip = 0;
  
  while((curr[temp] == type2) && ((temp) % 8 != 0)) {
    temp--;
  }
  if(curr[temp] == type) {
    for(lcv = index; lcv >= temp; lcv--) {
      curr[lcv] = type;
    }
    flip = 1;
  }
  return(flip);
}

/********************************************************************************
*  int flip_u(int index, int* curr, int type, int*new)
*  returns a 1 if flips can be made
*  
*  checks and flips all pieces above the current move
*
********************************************************************************/

int flip_u(int index, int* curr, int type)
{
  int type2 = (type % 2) + 1;
  int temp = index - 8;
  int lcv;
  int flip = 0;
  
  while((curr[temp] == type2) && (temp >= 0)){
    temp-=8;
  }
  if(temp < 0) {
    temp+=8;
  }
  if(curr[temp] == type) {
    for(lcv = index; lcv >= temp; lcv-=8) {
      curr[lcv] = type;
    }
    flip = 1;
  }
  return(flip);
}

/********************************************************************************
*  int flip_d(int index, int* curr, int type, int*new)
*  returns a 1 if flips can be made
*  
*  checks and flips all pieces below the current move
*
********************************************************************************/

int flip_d(int index, int* curr, int type)
{
  int type2 = (type % 2) + 1;
  int temp = index + 8;
  int lcv;
  int flip = 0;
  
  while((curr[temp] == type2) && (temp < 64)){
    temp+=8;
  }
  if(temp > 63) {
    temp -=8;
  }
  
  if(curr[temp] == type) {
    for(lcv = index; lcv <= temp; lcv+=8) {
      curr[lcv] = type;
    }
    flip = 1;
  }
  return(flip);
}

/********************************************************************************
* 
*  flip up left
*  
*  
*
********************************************************************************/

int flip_ul(int index, int* curr, int type)
{
  int type2 = (type % 2) + 1;
  int temp = index - 9;
  int lcv;
  int flip = 0;
  
  while((curr[temp] == type2) && ((temp) % 8 != 0) && (temp >= 0)) {
    temp-=9;
  }
  if(temp < 0) {
    temp+=9;
  }
  if(curr[temp] == type) {
    for(lcv = index; lcv >= temp; lcv-=9) {
      curr[lcv] = type;
    }
    flip = 1;
  }
  return(flip);
}

/********************************************************************************
* 
*  flip up right
*  
*  
*
********************************************************************************/

int flip_ur(int index, int* curr, int type)
{
  int type2 = (type % 2) + 1;
  int temp = index - 7;
  int lcv;
  int flip = 0;
  
  while((curr[temp] == type2) && ((temp+1) % 8 != 0) && (temp >= 0)) {
    temp-=7;
  }
  if(temp < 0) {
    temp +=7;
  }
  if(curr[temp] == type) {
    for(lcv = index; lcv >= temp; lcv-=7) {
      curr[lcv] = type;
    }
    flip = 1;
  }
  return(flip);
}

/********************************************************************************
* 
*  flip down left
*  
*  
*
********************************************************************************/

int flip_dl(int index, int* curr, int type)
{
  int type2 = (type % 2) + 1;
  int temp = index + 7;
  int lcv;
  int flip = 0;
  
  while((curr[temp] == type2) && ((temp) % 8 != 0) && (temp < 64)) {
    temp+=7;
  }
  if(temp > 63) {
    temp -=7;
  }
  if(curr[temp] == type) {
    for(lcv = index; lcv <= temp; lcv+=7) {
      curr[lcv] = type;
    }
    flip = 1;
  }
  return(flip);
}

/********************************************************************************
* 
*  flip down right
*  
*  
*
********************************************************************************/

int flip_dr(int index, int* curr, int type)
{
  int type2 = (type % 2) + 1;
  int temp = index + 9;
  int lcv;
  int flip = 0;
  
  while((curr[temp] == type2) && ((temp+1) % 8 != 0) && (temp < 64)) {
    temp+=9;
  }
  if(temp > 63){
    temp -=9;
  }
  if(curr[temp] == type) {
    for(lcv = index; lcv <= temp; lcv+=9) {
      curr[lcv] = type;
    }
    flip = 1;
  }
  return(flip);
}

/********************************************************************************
* 
*  Check valid move exists
*  
*  
*
********************************************************************************/

int poss_moves(int* curr, int type, int index) {
  int valid = 0;
  int lcv;
  int lcv2;
  int temp = prev[index];
  
  for(lcv = 0; lcv < 64; lcv++) {
    if(prev[lcv] == 0) {
      prev[lcv] = type;
      valid += !check_flip(lcv, curr); // check flip actually flips the array
      for(lcv2 = 0; lcv2 < 64; lcv2++){
        prev[lcv2] = data[lcv2];
        if(lcv2 == index) {
          prev[lcv2] = temp;
        }
      }
      prev[lcv] = 0;
    }
  }
    
  return(valid);
}








/* 

   LCD Functions - 1

*/

void shiftout_1(char x)
{
 
  // read the SPTEF bit, continue if bit is 1
  // write data to SPI data register
  // wait for 30 cycles for SPI data to shift out 
  unsigned char cycle; 
  while (SPISR_SPTEF != 1){
  }
  
  SPIDR = x;
 
asm{
  psha
  pula
  psha
  pula
  psha
  pula
  psha
  pula
  psha
  pula
  psha
  pula

}
}

void send_byte_1(char x)
{
     // shift out character
     // pulse LCD clock line low->high->low
     // wait 2 ms for LCD to process data
     shiftout_1(x);
     PTT_PTT4=1;
     PTT_PTT4=0;
     PTT_PTT4=1;
     lcdwait();
     
}

/*
***********************************************************************
  send_i: Sends instruction byte x to LCD  
***********************************************************************
*/

void send_i_1(char x)
{
        // set the register select line low (instruction data)
        // send byte
        PTT_PTT1 = 0;
        send_byte_1(x);
        
}

/*
***********************************************************************
  chgline: Move LCD cursor to position x
  NOTE: Cursor positions are encoded in the LINE1/LINE2 variables
***********************************************************************
*/

void chgline_1(char x)
{
     send_i_1(CURMOV);
     send_byte_1(x);
}

/*
***********************************************************************
  print_c: Print (single) character x on LCD            
***********************************************************************
*/
 
void print_c_1(char x)
{
   PTT_PTT1=1;
   send_byte_1(x);
     /* sends a character to the terminal channel */
 
}

/*
***********************************************************************
  pmsglcd: print character string str[] on LCD
***********************************************************************
*/

void pmsglcd_1(char str[])
{
    int temp = 0;
    while(str[temp]){      
       print_c_1(str[temp]);
       temp++;
    }
}

/* 

   LCD Functions - 2

*/

void shiftout_2(char x)
{
 
  // read the SPTEF bit, continue if bit is 1
  // write data to SPI data register
  // wait for 30 cycles for SPI data to shift out 
  unsigned char cycle; 
  while (SPISR_SPTEF != 1){
  }
  
  SPIDR = x;
 
asm{
  psha
  pula
  psha
  pula
  psha
  pula
  psha
  pula
  psha
  pula
  psha
  pula

}
}

void send_byte_2(char x)
{
     // shift out character
     // pulse LCD clock line low->high->low
     // wait 2 ms for LCD to process data
     shiftout_2(x);
     PTT_PTT3=1;
     PTT_PTT3=0;
     PTT_PTT3=1;
     lcdwait();
     
}

/*
***********************************************************************
  send_i: Sends instruction byte x to LCD  
***********************************************************************
*/

void send_i_2(char x)
{
        // set the register select line low (instruction data)
        // send byte
        PTT_PTT1 = 0;
        send_byte_2(x);
        
}

/*
***********************************************************************
  chgline: Move LCD cursor to position x
  NOTE: Cursor positions are encoded in the LINE1/LINE2 variables
***********************************************************************
*/

void chgline_2(char x)
{
     send_i_2(CURMOV);
     send_byte_2(x);
}

/*
***********************************************************************
  print_c: Print (single) character x on LCD            
***********************************************************************
*/
 
void print_c_2(char x)
{
   PTT_PTT1=1;
   send_byte_2(x);
     /* sends a character to the terminal channel */
 
}

/*
***********************************************************************
  pmsglcd: print character string str[] on LCD
***********************************************************************
*/

void pmsglcd_2(char str[])
{
    int temp = 0;
    while(str[temp]){      
       print_c_2(str[temp]);
       temp++;
    }
}

/*
***********************************************************************
  print_matrix: prints matrix
***********************************************************************
*/

void print_matrix(int data[]) {
  int i = 0;
  int j = 0;
  PTT_PTT0 = 0;
  cswait();
	for (i=0; i<64;i++){
	    print_c_cs(data[i]);
	}
	cswait();
	PTT_PTT0 = 1;	
}


void initial_LCD1()
{
   SPIBR = 0x10;
   lcdwait();
	 lcdwait();
	 lcdwait();
	 lcdwait();
	 lcdwait();
	 lcdwait();
	 lcdwait();
	 lcdwait(); 
	 lcdwait();
	 lcdwait();
	 lcdwait();
	 lcdwait();     
	 lcdwait();
   PTT_PTT4 = 1;
   send_i_1(0x0F);
   send_i_1(0x38);
   send_i_1(0x01);
   
   pmsglcd_1("Player 1: 2");
	 chgline_1(LINE2);
	 pmsglcd_1("Player 1: 2    ");
   
   PTT_PTT4 = 0;
}

void initial_LCD2()
{
   PTT_PTT3 = 1;
   send_i_2(0x0F);
   send_i_2(0x38);
   send_i_2(0x01);
   
   pmsglcd_2("Player 1: 2");
	 chgline_2(LINE2);
	 pmsglcd_2("Player 2: 2    ");
   
   PTT_PTT3 = 0;
   SPIBR = 0x16;
   lcdwait();
	 lcdwait();
	 lcdwait();
	 lcdwait();
	 lcdwait();
	 lcdwait();
	 lcdwait();
	 lcdwait(); 
	 lcdwait();
	 lcdwait();
	 lcdwait();
	 lcdwait();     
	 lcdwait();
   
}

void print_error_1() {
   int i = 0;
   SPIBR = 0x10;
   lcdwait();
	 lcdwait();
	 lcdwait();
	 lcdwait();
	 lcdwait();
	 lcdwait();
	 lcdwait();
	 lcdwait(); 
	 lcdwait();
	 lcdwait();
	 lcdwait();
	 lcdwait();     
	 lcdwait();
	 send_i_1(LCDCLR);
	 pmsglcd_1("Invalid move..");
	 for(i=0; i<100; i++)
	    lcdwait();
	 update_score();
}

void print_error_2() {
   int i = 0;
   SPIBR = 0x10;
   lcdwait();
	 lcdwait();
	 lcdwait();
	 lcdwait();
	 lcdwait();
	 lcdwait();
	 lcdwait();
	 lcdwait(); 
	 lcdwait();
	 lcdwait();
	 lcdwait();
	 lcdwait();     
	 lcdwait();
	 send_i_2(LCDCLR);
	 pmsglcd_2("Invalid move..");
	 for(i=0; i<100; i++)
	    lcdwait();
	 update_score();
}  

void update_score(){
   int Digit_1_1;
   int Digit_1_2;
   int Digit_2_1;
   int Digit_2_2;
   SPIBR = 0x10;
   lcdwait();
	 lcdwait();
	 lcdwait();
	 lcdwait();
	 lcdwait();
	 lcdwait();
	 lcdwait();
	 lcdwait(); 
	 lcdwait();
	 lcdwait();
	 lcdwait();
	 lcdwait();     
	 lcdwait();
	 collect_score();
   PTT_PTT4 = 1;
   
   send_i_1(0x0F);
   send_i_1(0x38);
   send_i_1(0x01);   
   pmsglcd_1("Player 1: ");
	 //chgline_1(LINE2);
	 //pmsglcd_1("Score: ");
	 Digit_1_1 = ((Score1%100)/10)+48;
   print_c_1(Digit_1_1);
   Digit_1_2 = ((Score1%100)%10)+48;
   print_c_1(Digit_1_2);
   print_c_2(0x20);
   //PTT_PTT4 = 0;
   chgline_1(LINE2);
   pmsglcd_1("Player 2: ");
   Digit_1_1 = ((Score2%100)/10)+48;
   print_c_1(Digit_1_1);
   Digit_1_2 = ((Score2%100)%10)+48;
   print_c_1(Digit_1_2);
   print_c_1(0x20);
   print_c_1(0x20);
   print_c_1(0x20);
   print_c_1(0x20);
   PTT_PTT4 = 0;
   
   
   PTT_PTT3 = 1;
   send_i_2(0x0F);
   send_i_2(0x38);
   send_i_2(0x01);
   
   pmsglcd_2("Player 1: ");
	 //chgline_2(LINE2);
	 //pmsglcd_2("Score: ");
	 Digit_1_1 = ((Score1%100)/10)+48;
   print_c_2(Digit_1_1);
   Digit_1_2 = ((Score1%100)%10)+48;
   print_c_2(Digit_1_2);
   print_c_2(0x20);
   //PTT_PTT4 = 0;
   chgline_2(LINE2);
   pmsglcd_2("Player 2: ");
   Digit_1_1 = ((Score2%100)/10)+48;
   print_c_2(Digit_1_1);
   Digit_1_2 = ((Score2%100)%10)+48;
   print_c_2(Digit_1_2);
   print_c_2(0x20);
   print_c_2(0x20);
   print_c_2(0x20);
   print_c_2(0x20);
   PTT_PTT4 = 0;
   
   
   
   SPIBR = 0x16;
   lcdwait();
	 lcdwait();
	 lcdwait();
	 lcdwait();
	 lcdwait();
	 lcdwait();
	 lcdwait();
	 lcdwait(); 
	 lcdwait();
	 lcdwait();
	 lcdwait();
	 lcdwait();     
	 lcdwait();
}
   
   
/*
***********************************************************************
  Collect_score: Updates the score based on the peices of the board
***********************************************************************
*/  
  
void collect_score() {
  int lcv = 0;
  
  Score1 = 0;
  Score2 = 0;
  while(lcv < 64) {
    if(prev[lcv] == 1){
      Score1 = Score1+ 1;
    } else if(prev[lcv] == 2) {
      Score2= Score2 + 1;
    }
    lcv++;
  }
}
  
/*
***********************************************************************
  Makes The Board light up for Xmas!
***********************************************************************
*/   
void make_xmas(){
 
 int lcv = 0;
 int key = 0;
 int i = 0;
 
 /*
 for(lcv = 0; lcv < 64; lcv++) {
   if(lcv < 8){
    data[lcv] = 1;
   } else if(lcv >= 8 && lcv < 16) {
    data[lcv] = 2;
   } else if(lcv >= 16 && lcv < 24) {
    data[lcv] = 1;
   } else if(lcv >= 24 && lcv < 32) {
    data[lcv] = 2;
   } else if(lcv >= 32 && lcv < 40){
    data[lcv] = 1;
   } else if(lcv >= 40 && lcv < 48){
    data[lcv] = 2;
   }else if(lcv >= 48 && lcv < 56){
    data[lcv] = 1;
   } else {
    data[lcv] = 2;
   }
     
 }
 
 for(lcv = 0; lcv < 64; lcv++) {
   if(lcv < 8){
    prev[lcv] = 2;
   } else if(lcv >= 8 && lcv < 16) {
    prev[lcv] = 1;
   } else if(lcv >= 16 && lcv < 24) {
    prev[lcv] = 2;
   } else if(lcv >= 24 && lcv < 32) {
    prev[lcv] = 1;
   } else if(lcv >= 32 && lcv < 40){
    prev[lcv] = 2;
   } else if(lcv >= 40 && lcv < 48){
    prev[lcv] = 1;
   }else if(lcv >= 48 && lcv < 56){
    prev[lcv] = 2;
   } else {
    prev[lcv] = 1;
   }
     
 }
 */
 xmas_LCD1();
 xmas_LCD2();
 for(lcv = 0; lcv < 64; lcv++){
  if(lcv % 2 == 0) {
    data[lcv] = 1;
  }else{
    data[lcv] = 2;
  }
 }
 for(lcv = 0; lcv < 64; lcv++){
  if(lcv % 2 == 0) {
    prev[lcv] = 2;
  }else{
    prev[lcv] = 1;
  }
 }
 lcv = 0;
 
 while(!lcv){
 i = 0; 
 if(key == 0) {
    print_matrix(data);
    key = 1;
 }else{
  print_matrix(prev);
  key = 0;
 }
 while(i < 13) {
  lcdwait();
  i++;
 
 }
 
 if(PTT_PTT6){
  lcv = 1;
 }
 }
  
}


void xmas_LCD1()
{
   SPIBR = 0x10;
   lcdwait();
	 lcdwait();
	 lcdwait();
	 lcdwait();
	 lcdwait();
	 lcdwait();
	 lcdwait();
	 lcdwait(); 
	 lcdwait();
	 lcdwait();
	 lcdwait();
	 lcdwait();     
	 lcdwait();
   PTT_PTT4 = 1;
   send_i_1(0x0F);
   send_i_1(0x38);
   send_i_1(0x01);
   
   pmsglcd_1("Merry Christmas!");
	 chgline_1(LINE2);
	 pmsglcd_1("Happy Holidays!");
   
   PTT_PTT4 = 0;
}

void xmas_LCD2()
{
   PTT_PTT3 = 1;
   send_i_2(0x0F);
   send_i_2(0x38);
   send_i_2(0x01);
   
   pmsglcd_2("Merry Christmas!");
	 chgline_2(LINE2);
	 pmsglcd_2("Happy Holidays!");
   
   PTT_PTT3 = 0;
   SPIBR = 0x16;
   lcdwait();
	 lcdwait();
	 lcdwait();
	 lcdwait();
	 lcdwait();
	 lcdwait();
	 lcdwait();
	 lcdwait(); 
	 lcdwait();
	 lcdwait();
	 lcdwait();
	 lcdwait();     
	 lcdwait();
   
}

void game_over() {
   SPIBR = 0x10;
   lcdwait();
	 lcdwait();
	 lcdwait();
	 lcdwait();
	 lcdwait();
	 lcdwait();
	 lcdwait();
	 lcdwait(); 
	 lcdwait();
	 lcdwait();
	 lcdwait();
	 lcdwait();     
	 lcdwait();
    PTT_PTT3 = 1;
    PTT_PTT4 = 1;
   send_i_1(0x0F);
   send_i_1(0x38);
   send_i_1(0x01);
   
   send_i_2(0x0F);
   send_i_2(0x38);
   send_i_2(0x01);
   
   pmsglcd_1("Game Over!");
   pmsglcd_2("Game Over!");
	 chgline_1(LINE2);
	 chgline_2(LINE2);
	 if(Score1 > Score2) {
	  pmsglcd_1("WINNER!!!!");
	  pmsglcd_2("Loser....");
	 }else{
	  pmsglcd_1("Loser....");
	  pmsglcd_2("WINNER!!!!");
	 }
	 
	   
   PTT_PTT3 = 0;
   PTT_PTT4 = 0;
   SPIBR = 0x16;
   lcdwait();
	 lcdwait();
	 lcdwait();
	 lcdwait();
	 lcdwait();
	 lcdwait();
	 lcdwait();
	 lcdwait(); 
	 lcdwait();
	 lcdwait();
	 lcdwait();
	 lcdwait();     
	 lcdwait();
}

void error_LCD2()
{
   SPIBR = 0x10;
   lcdwait();
	 lcdwait();
	 lcdwait();
	 lcdwait();
	 lcdwait();
	 lcdwait();
	 lcdwait();
	 lcdwait(); 
	 lcdwait();
	 lcdwait();
	 lcdwait();
	 lcdwait();     
	 lcdwait();
   PTT_PTT3 = 1;
   send_i_2(0x0F);
   send_i_2(0x38);
   send_i_2(0x01);
   
   pmsglcd_2("Error");
	
   PTT_PTT3 = 0;
   SPIBR = 0x16;
   lcdwait();
	 lcdwait();
	 lcdwait();
	 lcdwait();
	 lcdwait();
	 lcdwait();
	 lcdwait();
	 lcdwait(); 
	 lcdwait();
	 lcdwait();
	 lcdwait();
	 lcdwait();     
	 lcdwait();
}
