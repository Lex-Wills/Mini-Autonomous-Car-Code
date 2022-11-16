#include "mbed.h"

PwmOut Drive_pin_A(PA_8);  //steering servo PWM output pin D7
PwmOut Drive_pin_B(PA_9);  //Not Used
PwmOut Drive_pin_C(PB_10); //Motor drive PWM output pin D6
PwmOut Drive_pin_D(PB_4);  //Motor drive PWM output pin D5 

int Turn_right=2;
int Turn_left=0;
int Speed1=10;              //Half power
int Speed2=20;              //Full power
int PW_Period=20;
 
int main(){
    
    Drive_pin_D.period_ms(PW_Period);    
    Drive_pin_D.pulsewidth_ms(0);        
    Drive_pin_C.period_ms(PW_Period);    
    Drive_pin_C.pulsewidth_ms(0);        //drive motor off
    
    wait(7);
    
    Drive_pin_A.period_ms(PW_Period);   //Steering Servo period
    Drive_pin_A.pulsewidth_us(1525);   //Steering neutral (includes a 25uS offset)
    
    wait(1);
    
    Drive_pin_D.period_ms(PW_Period);    
    Drive_pin_D.pulsewidth_ms(0);
    Drive_pin_C.period_ms(PW_Period);
    Drive_pin_C.pulsewidth_ms(Speed1);    //drive motor on forward half power
    
    wait(4);
        
    Drive_pin_A.pulsewidth_us(1775); // Half turn left

    wait(7);

    Drive_pin_A.pulsewidth_us(1275); //Half turn right

    wait(7);
  
    Drive_pin_A.pulsewidth_us(1000); // Full steering lock
    Drive_pin_C.period_ms(PW_Period);
    Drive_pin_C.pulsewidth_ms(Speed2);   // Full power
    
    wait(5);
    
    Drive_pin_A.pulsewidth_us(1525); // Neutral steering 
    
    wait(1);
    
    Drive_pin_A.pulsewidth_us(2000); // full steering opposite lock
    
    wait(5.5);
    
    Drive_pin_A.pulsewidth_us(1525); // Neutral steering 
    
    wait(1);
    
    Drive_pin_D.period_ms(PW_Period);    //drive motor reverse
    Drive_pin_D.pulsewidth_ms(Speed1);
    Drive_pin_C.period_ms(PW_Period);
    Drive_pin_C.pulsewidth_ms(0);    
    
    wait(3);
    
    Drive_pin_C.period_ms(PW_Period);    //drive motor off
    Drive_pin_C.pulsewidth_ms(0);
    Drive_pin_D.period_ms(PW_Period);
    Drive_pin_D.pulsewidth_ms(0);   
 
 }
