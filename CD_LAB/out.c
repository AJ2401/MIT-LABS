#include<stdio.h>
intmain(){
 intyear;
 printf("Enterayear:");
 scanf("%d",&year);

 //leapyearifperfectlydivisibleby400
 if(year%400==0){
   printf("%disaleapyear.",year);
 }
 //notaleapyearifdivisibleby100
 //butnotdivisibleby400
 elseif(year%100==0){
   printf("%disnotaleapyear.",year);
 }
 //leapyearifnotdivisibleby100
 //butdivisibleby4
 elseif(year%4==0){
   printf("%disaleapyear.",year);
 }
 //allotheryearsarenotleapyears
 else{
   printf("%disnotaleapyear.",year);
 }

 return0;
}