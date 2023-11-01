#include <16F877A.h>
#device ADC=16

#FUSES NOWDT                    //No Watch Dog Timer
#FUSES NOBROWNOUT               //No brownout reset
#FUSES NOLVP                    //No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O

#use delay(crystal=4MHz)
#define led0(x) output_bit(PIN_B0,x);
#define led1(x) output_bit(PIN_B1,x);
#define led2(x) output_bit(PIN_B2,x);
#define led3(x) output_bit(PIN_B3,x);
#define led4(x) output_bit(PIN_B4,x);
#define led5(x) output_bit(PIN_B5,x);
#define led6(x) output_bit(PIN_B6,x);
#define k1(x) output_bit(PIN_E1,x);//in1
#define k2(x) output_bit(PIN_E2,x);//in2
#define k3(x) output_bit(PIN_C0,x);//in3
#define k4(x) output_bit(PIN_C3,x);//in4
//#define led7(x) output_bit(PIN_B7,x);
#define  trig  pin_d2
#define  echo  pin_d3
#define  trig2  pin_d4
#define  echo2  pin_d5
#define  trig3  pin_d6
#define  echo3  pin_d7
