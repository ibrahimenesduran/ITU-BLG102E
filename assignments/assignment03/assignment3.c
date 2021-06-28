/*
Ibrahim Enes Duran | ITU Computer Engineering 
Assignment 3 | Deciding the outcome of an election.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct candidate {
    char letter; 
    int votes;
    float percent;
} CANDIDATE;

typedef struct district {
    int votes_A;
    int votes_B;
    int votes_C;
    int votes_D;
} DISTRICT;

int getCountLine(char* src_text_file_name);
void read_from_text_file(char* src_text_file_name, DISTRICT* districts, int count);
void calculate_candidates(int i, DISTRICT* districts, CANDIDATE* candidate);
int compete_result(CANDIDATE* candidate);

/**
 * START OF MAIN FUNCTION
 */
int main(int argc, char* argv[]){

    CANDIDATE candidate[4];

    if(argc != 2){
        printf("Please enter the text file name !!");
        return EXIT_FAILURE;
    }
    char *src_text_file_name = argv[1];

    int count = getCountLine(src_text_file_name);

   
    DISTRICT *districts = (DISTRICT*) malloc(sizeof(DISTRICT) * count);

    read_from_text_file(src_text_file_name, districts, count);
    

    calculate_candidates(count, districts, candidate);
    free(districts);
    
    compete_result(candidate);
    
    return EXIT_SUCCESS;
}

/**
 * This function calculates the number of lines (districts) in the text file.
 * @param src_text_file_name This variable stores the name of the text file.
 * @return count of line in text (int)
 */
int getCountLine(char *src_text_file_name){
    FILE *text_file;
    
    if(!(text_file=fopen(src_text_file_name, "r"))){
        printf("Can not open %s\n", src_text_file_name);
    }
    int count = 0; char line[100];

    while(fgets(line, sizeof(line), text_file) != NULL){
            if (line[0] != '\n')
                count = count + 1;
        }
    fclose(text_file);
    return count;
}

/**
 * This function stores the votes in the text file into the districts variable.
 * @param src_text_file_name This variable stores the name of the text file.
 * @param districts This variable stores the votes cast to candidates in the districts.
 * @param count This variable stores the number of lines (districts) in the text file.
 * @return no return
 */
void read_from_text_file(char *src_text_file_name, DISTRICT *districts, int count){
    FILE *text_file;

    if(!(text_file=fopen(src_text_file_name, "r"))){
        printf("Can not open %s\n", src_text_file_name);
    }

	for(int i = 0; i < count; i++){
		fscanf(text_file, "%d %d %d %d", &districts[i].votes_A, &districts[i].votes_B, &districts[i].votes_C, &districts[i].votes_D);
        /* debug code
    printf("%d %d %d %d | %d line \n", districts[i].votes_A, districts[i].votes_B, districts[i].votes_C, districts[i].votes_D);
        */
	}

    fclose(text_file);
}

/**
 * This function calculates the total vote and overall percentage of the candidates in the districts.
 * @param i This variable stores the number of lines (districts) in the text file.
 * @param districts This variable stores the votes cast to candidates in the districts.
 * @param candidate This variable stores votes and percentages of candidates.
 * @return no return
 */
void calculate_candidates(int i, DISTRICT *districts, CANDIDATE *candidate){
    candidate[0].votes = 0; candidate[1].votes = 0; candidate[2].votes = 0; candidate[3].votes = 0;

    for(int j = 0; j < i; j++){
        candidate[0].votes = candidate[0].votes + districts[j].votes_A;
        candidate[1].votes = candidate[1].votes + districts[j].votes_B;
        candidate[2].votes = candidate[2].votes + districts[j].votes_C;
        candidate[3].votes = candidate[3].votes + districts[j].votes_D;
    }

    int total_votes = candidate[0].votes + candidate[1].votes + candidate[2].votes + candidate[3].votes;

    candidate[0].letter = 'A'; candidate[1].letter = 'B'; candidate[2].letter = 'C'; candidate[3].letter = 'D';
    candidate[0].percent = (float) candidate[0].votes / total_votes * 100; candidate[1].percent = (float) candidate[1].votes / total_votes * 100; candidate[2].percent =  (float) candidate[2].votes / total_votes * 100; candidate[3].percent = (float) candidate[3].votes / total_votes * 100;
    /* debug code
    printf("%d %d %d %d | %f %f %f %f | %c %c %c %c\n", candidate[0].votes, candidate[1].votes, candidate[2].votes, candidate[3].votes,
                                                      candidate[0].percent, candidate[1].percent, candidate[2].percent, candidate[3].percent,
                                                 candidate[0].letter, candidate[1].letter, candidate[2].letter, candidate[3].letter);
    */
}

/**
 * This function prints the candidates who are left to second round or candidate who get more than 50%  of the votes.
 * @param candidate This variable stores votes and percentages of candidates.
 * @return 0 when successful
 */
int compete_result(CANDIDATE *candidate){
        for(int j = 0; j < 4; j++){
        if(candidate[j].percent > 50.0){
            printf("Winner: %c\n", candidate[j].letter);
            return EXIT_SUCCESS;
        }
    }
    float maxPercent = 0.0;
    int maxJ = 0, maxK = 0;
    for(int j = 0; j < 4; j++){
        if(candidate[j].percent > maxPercent){
            maxPercent = candidate[j].percent;
            maxJ = j;
        }
    }

    maxPercent = 0.0;
    for(int k = 0; k < 4; k++){
        if(candidate[k].percent > maxPercent && maxJ != k){
            maxPercent = candidate[k].percent;
            maxK = k;
        }
    }

    printf("Second round: %c and %c\n", candidate[maxJ].letter, candidate[maxK].letter);
    return EXIT_SUCCESS;
}