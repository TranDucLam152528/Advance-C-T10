#include <stdio.h>
#include <stdint.h>
#include <time.h>

int Checkdatemonthyear(int date, int month, int year)
{
 if(date > 31 || date <1 ){
     printf("Date of birth is not correct\n");
     printf("Please Input Your Date of Birth a gain\n");
     return 1;
 }
 else if(month > 12 || month <1){
     printf("Month of birth is not correct\n");
     printf("Please Input Your Date of Birth a gain\n");
     return 1;
 }
 else if(month == 2 && date > 29){
     printf("February has only 28 days or 29 days\n");
     printf("Please Input Your Date of Birth a gain\n");
     return 1;
 }
 else if(month == 4 ||month == 6||month == 9||month == 11 && date ==31){
     printf("Your Month Input has only 30 days\n");
     printf("Please Input Your Date of Birth a gain\n");
     return 1;
 }
 else if(year >2022 ){
     printf("Your Year Input is in future\n");
     printf("Please Input Your Date of Birth a gain\n");
     return 1;
 }
 else return 0;
}

int Programfunction(int date,int month, int year){
    time_t timen;
    struct tm *timenow;
    time (&timen);
    timenow = localtime (&timen);
    int Age = 0;
    int tm_mon_real = timenow->tm_mon +1; // cấu trúc của tm_month biểu diễn tháng bắt đầu từ 0 đến 11 -> phải + 1 */
    int tm_year_real = timenow->tm_year + 1900; // cấu trúc của tm_year biểu diễn năm, bắt đầu từ 1900 --> phải + 1900 */
    int tm_day_real = timenow->tm_mday;

    if(month < tm_mon_real || (month == tm_mon_real && date <= tm_day_real))
    {
        Age = tm_year_real - year; 
        return Age;
    }
    else{
        Age = tm_year_real - year -1; 
        return Age;
    }
}

int main(int argc, char const *argv[])
{
    int date,month,year;
    do
    {
        printf("Date of Birth: ");
        scanf("%d", &date);
        printf("Month of Birth: ");
        scanf("%d", &month);
        printf("Year of Birth: ");
        scanf("%d", &year);

    } while (Checkdatemonthyear(date,month,year));
    
    printf("Your Birthday Input is: %d/%d/%d \n",date, month, year);
    int Age = Programfunction(date,month,year);
    printf("Your Age is %d \n", Age);
}