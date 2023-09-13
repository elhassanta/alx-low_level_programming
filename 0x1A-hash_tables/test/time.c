#include <stdio.h>
#include <time.h>
int main() {
    // Write C code here
    int j = 1970;
    unsigned long int caldays = 0;
    unsigned long int seconds = time(NULL) % 60;
    unsigned long int minutes = (time(NULL) - seconds) % (60 * 60);
    unsigned long int hours = (((time(NULL) - seconds) - (minutes)) / 3600) % 24;
    unsigned long int days = (time(NULL) - (hours * 60 * 60 + minutes * 60 + seconds)) / (60 * 60 * 24) + 1;
    unsigned long int daysInYear = 1;
    unsigned long int daysInMonth = 1;
    int i = 1;
    minutes = minutes / 60;
    
    while (j < 2023)
    {
        if (j % 4)
        {
            caldays += 365;
        }
        else
            caldays += 366;
        j++;
    }
    daysInYear = days - caldays + 1;
    while (daysInYear >= 31)
    {
        
        if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
        {
            daysInYear -= 31;
        }
        else if (i == 2)
        {
            if (j % 4)
            {
                daysInYear -= 28;
            }
            else
                daysInYear -= 29;
        }
        else
            daysInYear -= 30;
        i++;
    }
    daysInMonth = daysInYear + 1;
    printf("time(GMT):\t%d-%d-%ld\t%ldh: %ldm: %lds\n", j, i, daysInMonth + 1, hours, minutes, seconds);
    
    

    return 0;
}
