#include <stdio.h>

int main()
{
    char grade;
    int points;

    for(grade = 'A'; grade < 'F'; grade++) {
        switch(grade) {
            case 'A': points = 4; break;
            case 'B': points = 3;
            case 'C': points = 2;
            case 'D': points = 1; break;
            case 'E': 
            case 'W': points = 0;
        }
        printf("points = %d\n", points);
    }

    return 0;
}