#include<iostream>
using namespace std;

int main(){

    int number;
    int result = 0;
    int counter = 0;
    cin >> number;

    while(number < counter){

        if(counter < 10){
            int temp = counter+counter;
            if(temp == number){
                if(result == 0 || result > temp){
                    result = temp;
                }
            }
        }

        else if(counter < 100){
            int temp = counter + counter/10 + counter%10;
            if(temp == number){
                if(result == 0 || result > temp){
                    result = temp;
                }
            }
        }

        else if(counter < 1000){
            int temp = counter + counter/100 + counter%100/10 + counter%10;
            if(temp == number){
                if(result == 0 || result > temp){
                    result = temp;
                }
            }
        }
        
        else if(counter < 10000){
            int temp = counter + counter/1000 + counter%1000/100 + counter%1000%100/10 + counter%10;
            if(temp == number){
                if(result == 0 || result > temp){
                    result = temp;
                }
            }
        }
        
        else if(counter < 100000){
            int temp = counter + counter/10000 + counter%10000/1000 + counter%10000%1000%100/10 + counter%10000%1000%100/10 + counter%10;
            if(temp == number){
                if(result == 0 || result > temp){
                    result = temp;
                }
            }
        }
        
        else if(counter < 1000000){
            int temp = counter + counter/100 + counter%100/10 + counter%10;
            if(temp == number){
                if(result == 0 || result > temp){
                    result = temp;
                }
            }
        }

        counter++;
    }

    return 0;
}