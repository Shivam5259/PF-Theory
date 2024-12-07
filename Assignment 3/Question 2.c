#include <stdio.h>
#include <windows.h>

struct Player{
	char PlayerName[100];
	int ballScore[12];
	int score;
};

int playGame(struct Player player);
int ValidateScore(int score);
int findWinner(struct Player player1, struct Player  player2);
void displayMatchScoreBoard(struct Player player1,struct Player player2 );

int main(){
	system("cls");
	struct Player player1, player2; 
	player1.score=0;
	player2.score=0;

	printf("Enter the name of player 1: ");
	scanf(" %[^\n]",&player1.PlayerName);

	printf("Enter the name of player 2: ");
	scanf(" %[^\n]",&player2.PlayerName);

	for(int i=0;i<12;i++){
		printf("\nEnter score of %s for %d ball: ", player1.PlayerName, i+1);
		player1.ballScore[i]=playGame(player1);
		player1.score+=player1.ballScore[i];

		printf("Enter score of %s for %d ball: ", player2.PlayerName, i+1);
		player2.ballScore[i]=playGame(player2);
		player2.score+=player2.ballScore[i];
	}

	if(findWinner(player1,player2)==1) printf("\n%s won against %s\n",player1.PlayerName,player2.PlayerName);
	else if(findWinner(player1,player2)==0) printf("\n%s won against %s\n",player2.PlayerName,player1.PlayerName);
	else printf("\nDraw\n");

	printf("\nPress Enter to display the Score Board......");
	getchar();
	getchar();
	displayMatchScoreBoard(player1,player2);
}

int playGame(struct Player player){

	scanf("%d",&player.ballScore[0]);
	if(ValidateScore(player.ballScore[0])==0)
		return 0;
	else
		return  player.ballScore[0];
		
}

int ValidateScore(int score){
	if(score>=0 && score<=6) return 1;
	else return 0;
}

int findWinner(struct Player player1, struct Player  player2){
	if(player1.score>player2.score) return 1;
	else if(player1.score==player2.score) return -1;
	else return 0;
}

void displayMatchScoreBoard(struct Player player1, struct Player player2 ){
	system("cls");
	
	printf("\n==== Match Score Board ====\n\n");

	printf("\n%s performence in match is:\n",player1.PlayerName);

   	for(int i=0;i<12;i++){
   		printf("ball %d = %d\n", i+1, player1.ballScore[i]);
    }

    printf("\nAverage score: %d\n",player1.score/12);
    printf("Total score: %d\n",player1.score);
    printf("========================================");
	printf("\n%s performence in match is: \n", player2.PlayerName);

    for(int i=0; i<12; i++){
   		printf("ball %d = %d\n",i+1,player2.ballScore[i]);
    }

    printf("\nAverage score: %d\n", player2.score/12);
    printf("Total score: %d\n", player2.score);
}


