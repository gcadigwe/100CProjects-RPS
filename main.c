#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include <stdbool.h>

char* options = "RPS";

enum Outcome {
	TIE,
	USER_WON,
	CMP_WON,
	FAILURE
};

char get_computer_choice() {
	
	srand(time(0));

	int random_number = rand() % 3;

	char choice = options[random_number];

	return choice;
}

enum Outcome compare_choices(char cmp_choice, char user_choice){
	enum Outcome outcome;
	if(user_choice == 'R'){
	
		if(cmp_choice == 'R'){
			outcome = TIE;
		}else if(cmp_choice == 'P'){
			outcome = CMP_WON;
		}else if(cmp_choice == 'S'){
			outcome = USER_WON;
		}else{
			outcome = FAILURE;
		}
		
	}else if(user_choice == 'P'){
		if(cmp_choice == 'P'){
			outcome = TIE;
		}else if(cmp_choice == 'R'){
			outcome = USER_WON;
		}else if(cmp_choice == 'S'){
			outcome = CMP_WON;
		}else {
			outcome = FAILURE;
		}
	}else if(user_choice == 'S'){
		if(cmp_choice == 'S'){
			outcome = TIE;
		}else if(cmp_choice == 'R'){
			outcome = CMP_WON;
		}else if(cmp_choice == 'P'){
			outcome = USER_WON;
		}else{
			outcome = FAILURE;
		}
	}

	return outcome;
}

void print_outcome(enum Outcome outcome){
	switch(outcome){
		case TIE: {
			printf("Tie! play again\n");
			break;

		}

		case USER_WON: {
			printf("User won 😏 \n");
			break;
		}

		case CMP_WON: {
			printf("Computer won lol 😂 \n");
			break;
		}

		case FAILURE: {
			printf("Invalid Inputs\n");
			break;
		}

		default:
			break;
	}
}



int main(){
	// bool loop = true; 
	while (true) {
	char user_choice[50];

	char cmp_choice = get_computer_choice();

	printf("Rock, Paper or Scissors?: ");
	scanf("%s", user_choice);

	enum Outcome outcome = compare_choices(cmp_choice, user_choice[0]);

	print_outcome(outcome);

	}

}
