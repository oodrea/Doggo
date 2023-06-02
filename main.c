/* 
TABADERO, Audrea Arjaemi T.
CCPROG1 S11A
Machine Project
Last Modified: 12 September 2021
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#define N 18
void getGender( char *gender ); 
void displayName( char gender );
int roll_die( void );
int doggoAction( int doggoaction );
int doggoBeg( int doggoaction, int doggobeg, int 
parentgrillingcount, int *meatTemp, int *meat, int *stars, int 
*treat1, int *treat2 );
int hoomanReaction( int doggoaction, int reaction, int beg, int 
*meat, int *stars, int *hearts, int parentgrillingcount, int 
*meatTemp );
int treatPicker( int doggoaction, int treat, int *stars, int 
*hearts, int *meatTemp, int *meat, int parentgrillingcount, int 
*treat1, int *treat2, int *treat3, int *treat4, int *treat5, int 
*treat6 );
int playGarden( int doggoPlay );
void displayPlay( int doggoPlay, int mins );
void playTracker( int doggoPlay, int mins, int *play1, int 
*play2, int *play3, int *play4, int *play5, int *play6 );
void treatDisplay( void );
void endPlayDisplay( int play, int play1, int play2, int play3, 
int play4, int play5, int play6 );
void endTreatoDisplay( int treat, int treat1, int treat2, int 
treat3, int treat4, int treat5, int treat6 );
void getReplay( char *ans );
int main() {
 char gender='y', //sets gender to invalid as default to take 
in user input
 ans;
 int doggoaction,
 doggobeg,
 meat=0,
 stars=0,
 begCount=0,
 reaction,
 hearts=0,
 treat,
 parentgrillingcount=0,
 ignorecount=0,
 doggoPlay,
 endCheck=0,
 meatTemp=0,
 x,
 demerit=0,
 reacts,
 treatcheck;
 int play1=0,
 play2=0,
 play3=0,
 play4=0,
 play5=0,
 play6=0,
 treat1=0,
 treat2=0,
 treat3=0,
 treat4=0,
 treat5=0,
 treat6=0;
 time_t t;
 
 srand( time( &t ) );
 getGender( &gender );
 
 while (gender!= 'm' && gender!= 'M' && gender!='f' && gender!
='F' ){
 printf("Don't mean to be a killjoy but sadly that's an 
invalid input :( But fret not! Let's try again :D \n");
 getGender( &gender );
 }
 printf("\nHello ");
 displayName( gender ); //male = 1 ; female = 0;
 printf("!");
 printf("\nLet's start! "); 
 do{
 doggoaction = roll_die();
 doggoAction( doggoaction );
 if( doggoaction == 5 ){
 parentgrillingcount++;
 }
 
 if( doggoaction!= 6 ){ //doggo action is not sa garden
 begCount=0;
 ignorecount=0;
 meatTemp=0;
 while( begCount < 3 ){
 printf("\nHow do you want to beg for treatos?\n");
 doggobeg = roll_die();
 int begcheck = doggoBeg( doggoaction, doggobeg, 
parentgrillingcount, &meatTemp, &meat, &stars, &treat1, 
&treat2 );
 
 while( begcheck == 7 ){ //parent grilling special 
moves
 doggobeg = roll_die();
 ignorecount--;
 begcheck = doggoBeg( doggoaction, doggobeg, 
parentgrillingcount, &meatTemp, &meat, &stars, &treat1, 
&treat2 );
 }
 if( begcheck == 8 || begcheck == 6 ){ //doggo does 
hooman's fav move and skips roll die for reaction
 treat = roll_die();
 treatcheck = treatPicker( doggoaction, treat, 
&stars, &hearts, &meatTemp, &meat, parentgrillingcount, &treat1, 
&treat2, &treat3, &treat4, &treat5, &treat6 );
 while( treatcheck == 9 ){ //interference with 
parent grilling
 treat = roll_die();
 treatcheck = treatPicker( doggoaction, treat, 
&stars, &hearts, &meatTemp, &meat, parentgrillingcount, &treat1, 
&treat2, &treat3, &treat4, &treat5, &treat6 );
 }
 
 }
 else{
 if( begcheck != 5 ){
 reaction = roll_die();
 if( reaction == 6 ){ //if doggo ignored
 ignorecount++;
 }
 reacts = hoomanReaction( doggoaction, reaction, 
doggobeg, &meat, &stars, &hearts, parentgrillingcount, 
&meatTemp );
 if( reacts==6 ){ //doggo is given treat
 treat = roll_die();
 treatcheck = treatPicker( doggoaction, treat, 
&stars, &hearts, &meatTemp, &meat, parentgrillingcount, &treat1, 
&treat2, &treat3, &treat4, &treat5, &treat6 );
 while( treatcheck == 9 ){ //interference with 
parent grilling
 treat = roll_die();
 treatcheck = treatPicker( doggoaction, treat, 
&stars, &hearts, &meatTemp, &meat, parentgrillingcount, &treat1, 
&treat2, &treat3, &treat4, &treat5, &treat6 );
 }
 }
 }
 }
 if( ignorecount == 3 ){ //demerit sequence
 printf("\nHooman ignored you 3x in a row :(\n");
 displayName( gender );
 printf(" steals a piece of hotdog from the picnic 
table.\n");
 stars-=2;
 demerit+=1;
 }
 begCount++;
 // printf("Beg count = %d\nMeat Temp = %d\nMeat Count = 
%d", begCount, meatTemp, meat); //beg, meat check
 if( begCount == 2 ){
 printf("\nYou can beg for another treato one more 
time.\n");
 }
 else if ( begCount < 2 ){
 printf("\nYou can beg for another treato.\n");
 }
 else{
 printf("\nWhat is ");
 displayName( gender );
 printf("'s next move?\n");
 }
 }// closing brack of while loop
 
 if( meat == 3 ){
 endCheck++; //triggers end of game
 }
 }else{ //garden 
 printf("\nHow long do you want to play in the garden?\n");
 int mins = roll_die();
 if ( mins == 6 ){
 printf("Have fun playing in the garden!\n");
 printf("See you when I see you, ");
 displayName( gender );
 printf("\n");
 endCheck+=2; //so it doesn't interfere with hooman end
check
 }
 else{
 mins*=3;
 printf("You will be playing for %d minutes.\n", mins);
 printf("\nHow do you want to play in the garden?\n");
 doggoPlay = roll_die();
 playGarden( doggoPlay );
 playTracker( doggoPlay, mins, &play1, &play2, &play3, 
&play4, &play5, &play6 );
 displayPlay( doggoPlay, mins );
 printf("\nWhat is ");
 displayName( gender );
 printf("'s next move?\n");
 }
 
 }
 } while( endCheck == 0 );
 if( endCheck == 1 ){
 printf("\n*Beep-Boop*\nHold on what's this? A message from
Head Doggo? Let's see what it says hmm\n");
 printf("\nCongratulations! ");
 displayName( gender );
 printf(" has already attained their goal of getting 3 
pieces of meat!");
 }
 printf("\nYou've reached the end of the game!");
 if( demerit == 0 ){
 printf("\n\nGood Dog, ");
 displayName( gender );
 printf("!\n");
 }
 
 int totalTreato = treat1+treat2+treat3+treat4+treat5+treat6;
 if( totalTreato == 0 ){
 printf("\nUnfortunately you didn't get any treatos this 
game :( ");
 }
 else{
 printf("\nYou received a total of %d treato(s)! ", 
totalTreato );
 for( int y=1; y<=6; y++ ){ //goes through 1 - 6 for the 
treats
 endTreatoDisplay( y, treat1, treat2, treat3, treat4, 
treat5, treat6 );
 }
 }
 
 printf("\n\n");
 displayName( gender );
 printf(" got %d piece(s) of meat!\n\nAlong with %d stars, 
including %d heart(s)!\n", meat, stars, hearts);
 int totalGarden = play1+play2+play3+play4+play5+play6;
 if( totalGarden !=0 ){
 printf("Hope you enjoyed the %d minutes spent playing in the 
garden. ", totalGarden );
 
 for( int i=1; i<=6; i++ ){ //goes through 1 - 6 for the plays 
in garden
 endPlayDisplay( i, play1, play2, play3, play4, play5, 
play6 );
 }
 printf("Sounds like heaps of fun!\n");
 }
 else{
 printf("Sounds like a lot of fun! Hope you enjoyed your 
time ");
 displayName( gender );
 printf("!");
 }
 
 getReplay( &ans ); //gets input if user wants to play again
 while (ans!= 'y' && ans!= 'Y' && ans!='n' && ans!='N' ){
 printf("That's an invalid input. Maybe you mispressed? 
Worry not! Let's try again :D \n");
 getReplay( &ans );
 }
 
 if( ans == 'y' || ans == 'Y' ){
 printf("\nAight let's take it back from the top! :D\n\n");
 main();
 }
 else{
 printf("\nThanks for playing! Come back soon :D ");
 }
return 0;
}
//functions
void getGender( char *gender ){
 printf("Is doggo male or female? (M/F) : ");
 *gender = getchar();
 getchar();
}
void displayName( char gender ){ 
 if ( gender == 'm' || gender == 'M'){
 printf("Bailey");
 }
 else if ( gender == 'f' || gender == 'F' ){
 printf("Kahlua");
 }
}
int roll_die( void ){
 char check;
 printf("Press Enter to roll the die!\n");
 do{
 check = getchar();
 }
 while( check!= '\n' );
 int x = rand()%6+1;
 printf("Die is rolling! What will it land on?\n");
 sleep( 1 ); 
 printf("\nYou rolled a %d!\n\n", x);
 return( x );
}
int doggoAction( int doggoaction ){
 switch ( doggoaction ) {
 case 1 : 
 printf("You ran to Kid #1.\n");
 return 1;
 break;
 case 2 : 
 printf("You ran to Kid #2.\n");
 return 2;
 break;
 case 3 : 
 printf("You ran to Kid #3.\n");
 return 3;
 break;
 case 4 : 
 printf("You ran to the Parent near the picnic table.\n");
 return 4;
 break;
 case 5 : 
 printf("You ran to the Parent grilling hotdogs and burgers.\
n");
 return 5;
 break;
 case 6 : 
 printf("You decided to play in the garden.\n");
 return 6;
 break;
 }
 return 0;
}
int doggoBeg( int doggoaction, int doggobeg, int 
parentgrillingcount, int *meatTemp, int *meat, int *stars, int 
*treat1, int *treat2 ){
 switch( doggobeg ){
 case 1:
 printf("You nudge hooman with snout.\n");
 break;
 case 2:
 printf("You poke hooman with paw.\n");
 break;
 case 3:
 printf("You place paw on hooman's lap.\n");
 break;
 case 4:
 printf("You place head on hooman's lap.\n");
 break;
 case 5:
 printf("You climb on hooman's lap.\n");
 break;
 case 6:
 printf("You sit and show hooman you're a good dog!\n");
 break;
 }
 printf("\nLet's see how hooman reacts!\n");
 if( doggoaction == 5 && ( doggobeg == 3 || doggobeg == 4 || 
doggobeg == 5 ) && parentgrillingcount<3 ){ //doggo beg moves 
that are not allowed with parent grilling
 printf("\nOh no! Parent is busy grilling! Let's try that 
again!\n");
 printf("\nHow do you want to beg for treatos?\n");
 return 7;
 }
 if( doggoaction==1 && doggobeg==4 ){ //fav moves
 if( *meatTemp<=0 ){
 printf("Score! Kid #1 gives you a piece of burger!
Nom! Nom!\n");
 *meat+=1;
 *stars+=5;
 *meatTemp+=1;
 *treat2+=1;
 return 5;
 }
 else{
 printf("You did hooman's favorite move but you 
already got meat. Let's settle for other treatos for now yeah?\
n");
 return 6;
 }
 
 }
 else if( doggoaction==2 && doggobeg==3 ){
 if( *meatTemp<=0 ){
 printf("Jackpot! Kid #2 gives you a piece of hotdog! 
Chomp! Chomp!\n");
 *meat+=1;
 *stars+=5;
 *meatTemp+=1;
 *treat1+=1;
 return 5;
 }
 else{
 printf("You did hooman's favorite move but you already
got meat. Let's settle for other treatos for now yeah?\n");
 return 6;
 }
 
 }
 else if( doggoaction==3 && doggobeg==5 ){
 if ( *meatTemp<=0 ){
 printf("Nice! Kid #3 gives you a piece of hotdog! 
Yum!\n");
 *meat+=1;
 *stars+=5;
 *meatTemp+=1;
 *treat1+=1;
 return 5;
 }
 else{
 printf("You did hooman's favorite move but you 
already got meat. Let's settle for other treatos for now yeah?\
n");
 return 6;
 }
 
 }
 else if( doggoaction==4 && doggobeg==6 ){ 
 if( *meatTemp<=0 ){
 printf("Alrighty! Parent gives you a piece of 
burger! Yummerz!\n");
 *meat+=1;
 *stars+=5;
 *meatTemp+=1;
 *treat2+=1;
 return 5;
 }
 else{
 printf("You did hooman's favorite move but you 
already got meat. Let's settle for other treatos for now yeah?\
n");
 return 6;
 }
 
 }
 else if( doggoaction==5 && doggobeg==6 ){ //parent 
grilling
 if( parentgrillingcount >= 3 ){ //parent can give meat
na
 if( *meatTemp<0 ){
 printf("Okay! Parent gives you a piece of burger! 
Nyum!\n");
 *meat+=1;
 *stars+=5;
 *meatTemp+=1;
 *treat2+=1;
 return 5;
 }
 else{
 printf("You did hooman's favorite move but you 
already got meat. Let's settle for other treatos for now yeah?\
n");
 return 6;
 }
 }
 else{ 
 printf("\nWell done! But unfortunately Parent is 
grilling. They wouldn't want you to burn your tongue! Don't 
worry! Hooman will give you treato!\nWhat treato will you get?\
n");
 return 8; 
 }
 
 }
 
 return 0;
}
int hoomanReaction( int doggoaction, int reaction, int beg, int 
*meat, int *stars, int *hearts, int parentgrillingcount, int 
*meatTemp ){ //if returns 1 == treat
 switch( reaction ){
 case 4:
 printf("Hooman pets you on the head.\n");
 *stars+=3;
 *hearts+=1;
 break;
 case 5:
 printf("Hooman plays with you for 2 minutes.\n");
 *stars+=3;
 *hearts+=1;
 break;
 case 6:
 printf("Hooman ignores you :(\n");
 break;
 default:
 printf("Hooman gives you a treato!\n");
 printf("\nWhat treato will you get?\n");
 return 6;
 break;
 }
 
 return 0;
}
int treatPicker( int doggoaction, int treat, int *stars, int 
*hearts, int *meatTemp, int *meat, int parentgrillingcount, int 
*treat1, int *treat2, int *treat3, int *treat4, int *treat5, int 
*treat6 ){
 switch( doggoaction ){ //which hooman
 case 1:
 printf("Kid #1");
 break;
 case 2:
 printf("Kid #2");
 break;
 case 3:
 printf("Kid #3");
 break;
 case 4:
 printf("Parent");
 break;
 case 5:
 printf("Parent");
 break;
 }
 switch( treat ){
 case 1: //hotdog or burger
 if( doggoaction == 1 || doggoaction == 4 ){ //kid #1 and 
parent at the table
 printf(" gives you a piece of burger!");
 if( *meatTemp>0 ){
 printf(" But unfortunately you already got meat :
(\n");
 }
 else{
 *stars+=5;
 *meat+=1;
 *meatTemp+=1;
 *treat2+=1;
 }
 
 }
 else if( doggoaction == 5 ){
 if( parentgrillingcount < 3 ){
 printf(" wants to give you a piece of burger but 
they don't want you to burn your tongue. Let's settle for other 
treatos for now yeah?\n");
 return 9;
 }
 }
 else { //kids 1,3
 printf(" gives you a piece of hotdog!"); 
 if( *meatTemp>0 ){
 printf(" But unfortunately you already got meat :
(\n");
 }
 else{
 *stars+=5;
 *meat+=1;
 *meatTemp+=1;
 *treat1+=1;
 }
 }
 break;
 case 2: //hotdog or burger
 if( doggoaction == 1 || doggoaction == 4 ){ //kid #1 and 
parent at the table
 printf(" gives you a piece of burger!");
 if( *meatTemp>0 ){
 printf(" But unfortunately you already got meat :
(\n");
 }
 else{
 *stars+=5;
 *meat+=1;
 *meatTemp+=1;
 *treat2+=1;
 }
 }
 else if( doggoaction == 5 ){
 if( parentgrillingcount < 3 ){
 printf(" wants to give you a piece of burger but 
they don't want you to burn your tongue. Let's settle for other 
treatos for now yeah?\n");
 return 9;
 }
 }
 else { //kids 1,3
 printf(" gives you a piece of hotdog!"); 
 if( *meatTemp>0 ){
 printf(" But unfortunately you already got meat :
(\n");
 }
 else{
 *stars+=5;
 *meat+=1;
 *meatTemp+=1;
 *treat1+=1;
 }
 }
 break;
 case 3: //doggo biscuit
 printf(" gives you doggo biscuit!\n");
 *stars+=3;
 *treat3+=1;
 break;
 case 4:
 printf(" gives you french fries!\n");
 *stars+=2;
 *treat4+=1;
 break;
 case 5:
 printf(" gives you cheese!\n");
 *stars+=2;
 *treat5+=1;
 break;
 case 6:
 printf(" gives you pickle :(\n");
 *stars+=1;
 *treat6+=1;
 break;
 }
 return 0;
}
int playGarden( int doggoPlay ){
 switch( doggoPlay ){
 case 1:
 printf("You decided to chase your tail.\n");
 break;
 case 2:
 printf("You decided to do zoomies! Nyoom!\n");
 break;
 case 3:
 printf("You decided to roll over and show some tricks.\
n");
 break;
 case 4:
 printf("You decided to check out the neighbour's dog.\n");
 break;
 case 5:
 printf("You decided to check out the neighbour's cat.\n");
 break;
 case 6:
 printf("You decided to bathe in the sun.\n");
 break;
 }
 return 0;
}
void displayPlay( int doggoPlay, int mins ){
 printf("\nYou spent %d minutes ", mins);
 switch( doggoPlay ){
 case 1:
 printf("chasing your tail!\n");
 break;
 case 2:
 printf("doing zoomies!\n");
 break;
 case 3:
 printf("rolling over and showing tricks!\n");
 break;
 case 4:
 printf("checking out the neighbour's dog!\n");
 break;
 case 5:
 printf("checking out the neighbour's cat!\n");
 break;
 case 6:
 printf("bathing in the sun!\n");
 break;
 }
}
void playTracker( int doggoPlay, int mins, int *play1, int 
*play2, int *play3, int *play4, int *play5, int *play6 ){
 switch( doggoPlay ){
 case 1:
 *play1+=mins;
 break;
 case 2:
 *play2+=mins;
 break;
 case 3:
 *play3+=mins;
 break;
 case 4:
 *play4+=mins;
 break;
 case 5:
 *play5+=mins;
 break;
 case 6:
 *play6+=mins;
 break;
 }
}
void endPlayDisplay( int play, int play1, int play2, int play3, 
int play4, int play5, int play6 ){ 
 switch( play ){
 case 1:
 if( play1 == 0 ){
 printf("\n\nYou didn't spend any time rolling over and
showing tricks, ");
 }
 else{
 printf("\n\nYou spent %d minutes chasing your tail, ",
play1);
 }
 break;
 case 2:
 if( play2 == 0 ){
 printf("you didn't spend any time doing zoomies. ");
 }
 else{
 printf("%d mintues doing zoomies, ", play2);
 }
 break;
 case 3:
 if( play3 == 0 ){
 printf("you didn't spend any time rolling over and 
showing tricks, ");
 }
 else{
 printf("%d minutes rolling over and showing tricks, ",
play3);
 }
 break;
 case 4:
 if( play4 == 0 ){
 printf("you didn't spend any time checking out the 
neighbour's dog, ");
 }
 else{
 printf("%d mintues checking out the neighbour's dog, 
", play4);
 }
 break;
 case 5:
 if( play5 == 0){
 printf("you didn't spend any time checking out the 
neighbour's cat, ");
 }
 else{
 printf("%d mintues checking out the neighbour's cat, 
", play5);
 }
 break;
 case 6:
 if( play6 == 0 ){
 printf("and you didn't spend any time bathing in the 
sun. ");
 }
 else{
 printf("and %d mintues bathing in the sun! ", play6);
 }
 break; 
 }
 
}
void endTreatoDisplay( int treat, int treat1, int treat2, int 
treat3, int treat4, int treat5, int treat6 ){
 switch( treat ){
 case 1:
 if( treat1 == 0 ){
 printf("\nYou didn't get any hotdogs, ");
 }
 else{
 printf("\nYou got %d pieces of hotdog, ", 
treat1 );
 }
 break;
 case 2:
 if( treat2 == 0 ){
 printf("you didn't get any burgers, ");
 }
 else{
 printf("you got %d pieces of burger, ", treat2 );
 }
 break;
 case 3:
 if( treat3 == 0 ){
 printf("you didn't get any doggo biscuits, ");
 }
 else{
 printf("you got %d doggo biscuits, ", treat3 );
 }
 break;
 case 4:
 if( treat4 == 0 ){
 printf("you didn't get any french fries, ");
 }
 else{
 printf("you got french fries %d times, ", 
treat4 );
 }
 break;
 case 5:
 if( treat5 == 0 ){
 printf("you didn't get any cheese, ");
 }
 else{
 printf("you got %d pieces of cheese, ", treat5 );
 }
 break;
 case 6:
 if( treat6 == 0 ){
 printf("and you didn't get any pickles. ");
 }
 else{
 printf("and you got %d pickles! ", treat6 );
 }
 break;
 }
 
 
}
void getReplay( char *ans ){
 printf("\n\nDo you want to play again? (Y/N): "); 
 *ans = getchar();
 getchar();
}