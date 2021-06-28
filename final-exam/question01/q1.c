/* 
İbrahim Enes Duran | Final Exam | Q1
*/
#include <stdio.h>

int main(){
    int number = 0, target = 0, i = 0, arr[99999];

    printf("Number: ");
    scanf("%d", &number);
    printf("Digit: ");
    scanf("%d", &target);

    int temp = number;

    while (temp) {

        arr[i++] = temp % 10;
        temp /= 10;
    }

    for(int j = 0; j < i; j++){
        if(arr[j] == target){
            printf("%d contains %d.", number, target);
            return 0;
        }
    }

    printf("%d does not contain %d.", number, target);

    return 0;
}