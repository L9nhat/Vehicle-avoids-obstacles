#include <Version5.h>
#use rs232(baud=9600, xmit=pin_c6, rcv=pin_c7, bits=8, parity=N)//khong nen set_tris_c(0);
int left=74,right=85;
int8 check;
int c_b,c_b2,c_b3;
unsigned int16 i, distance;
int g,l=110;
int k;
int u=0;
int p=0;
int a=0,b=0;
void delay(unsigned int t){unsigned int x,y;for(x=0;x<t;x++){for(y=0;y<123;y++);}}
  
void led_don(){
led0(0) led1(0) led2(0) led3(1) led4(0) led5(0) led6(0) ;delay_ms(l);
led0(0) led1(0) led2(1) led3(0) led4(1) led5(0) led6(0) ;delay_ms(l);
led0(0) led1(1) led2(0) led3(0) led4(0) led5(1) led6(0) ;delay_ms(l);
led0(1) led1(0) led2(0) led3(0) led4(0) led5(0) led6(1) ;delay_ms(l);
led0(0) led1(0) led2(0) led3(0) led4(0) led5(0) led6(0) ;delay_ms(l);
}

void led_don1(){
led0(1) led1(0) led2(0) led3(0) led4(0) led5(0) led6(1) ;delay_ms(l);
led0(0) led1(1) led2(0) led3(0) led4(0) led5(1) led6(0) ;delay_ms(l);
led0(0) led1(0) led2(1) led3(0) led4(1) led5(0) led6(0) ;delay_ms(l);
led0(0) led1(0) led2(0) led3(1) led4(0) led5(0) led6(0) ;delay_ms(l);
led0(0) led1(0) led2(0) led3(0) led4(0) led5(0) led6(0) ;delay_ms(l);}

void dc_up(){k2(1);k3(1);set_pwm1_duty(left);set_pwm2_duty(right);}

void dc_right(){k1(1);k3(1);set_pwm1_duty(left);set_pwm2_duty(right);}
void dc_right2(){k1(1);k3(1);set_pwm1_duty(100);set_pwm2_duty(100);}

void dc_left(){k2(1);k4(1);set_pwm1_duty(left);set_pwm2_duty(right);}
void dc_left2(){k2(1);k4(1);set_pwm1_duty(100);set_pwm2_duty(100);}

void dc_down(){k1(1);k4(1);set_pwm1_duty(left);set_pwm2_duty(right);}

void dc_stop(){k1(0);k2(0);k3(0);k4(0);set_pwm1_duty(30);set_pwm2_duty(30);}

void ne_phai(){
delay_ms(500);
   dc_right2();delay(500);delay(500);
dc_stop();delay_ms(300);
   dc_up();delay(500);delay(500);delay(500);delay(500);
dc_stop();delay_ms(300);
   dc_left2();delay(500);delay(500);delay(20);///
dc_stop();delay_ms(300);
}

void ne_phai2(){
delay_ms(500);
   dc_right2();delay(500);delay(500);
dc_stop();delay_ms(300);
   dc_up();delay(500);delay(500);delay(500);
dc_stop();delay_ms(300);
   dc_left2();delay(500);delay(500);delay(20);///
dc_stop();delay_ms(300);
}

void ne_trai(){
delay_ms(500);
   dc_left2();delay(500);delay(500);delay(40);///   
dc_stop();delay_ms(300);
   dc_up();delay(500);delay(500);delay(400);
dc_stop();delay_ms(300);
   dc_right2();delay(500);delay(500);delay(50);
dc_stop();delay_ms(300);
}

void ne_trai2(){
delay_ms(500);
   dc_left2();delay(500);delay(500);delay(40);///   
dc_stop();delay_ms(300);
   dc_up();delay(500);delay(500);delay(350);
dc_stop();delay_ms(300);
   dc_right2();delay(500);delay(500);delay(50);
dc_stop();delay_ms(300);
}

void cb(){
      check=0;i=0;
      output_high(trig);
      delay_us(10);
      output_low(trig);
      set_timer1(0);
      while(!input(echo)&&(get_timer1()<1000));
      if(get_timer1()>900)
      check=1;
      set_timer1(0);
      while(input(echo)&&(i<25000)) 
      i=get_timer1();
      if(i>24990){
      check=2;
      }
      if(check==1){led0(1);}
      if(check==2){led1(1);}
      else{distance=i/58.82;}   
      if(distance==1||distance==2||distance==3||distance==4||distance==5||distance==6||distance==6){c_b=1;}//1<=>5cm__2<=>8cm__3<=>9cm__10.5cm__+1cm 
}

void cb2(){
      check=0;
      i=0;
      output_high(trig2);
      delay_us(10);
      output_low(trig2);
      set_timer1(0);
      while(!input(echo2)&&(get_timer1()<1000));
      if(get_timer1()>900)
      check=1;
      set_timer1(0);
      while(input(echo2)&&(i<25000)) 
      i=get_timer1();
      if(i>24990){
      check=2;
      }
      if(check==1){led0(1);}
      if(check==2){led1(1);}
      else{distance=i/58.82;}   
      if(distance==1||distance==2||distance==3||distance==4||distance==5||distance==6||distance==6){//1<=>5cm__2<=>8cm__3<=>9cm__10.5cm__+1cm
      c_b2=1;
      }
}

void cb3(){
      check=0;
      i=0;
      output_high(trig3);
      delay_us(10);
      output_low(trig3);
      set_timer1(0);
      while(!input(echo3)&&(get_timer1()<1000));
      if(get_timer1()>900)
      check=1;
      set_timer1(0);
      while(input(echo3)&&(i<25000)) 
      i=get_timer1();
      if(i>24990){
      check=2;
      }
      if(check==1){
      output_low(pin_b0);
      }
      if(check==2){
      output_low(pin_b3);
      }
      else{
      distance=i/58.82;
      }   
      if(distance==1||distance==2||distance==3||distance==4||distance==5||distance==6||distance==7){//1<=>5cm__2<=>8cm__3<=>9cm__10.5cm__+1cm
      c_b3=1;
      }
}

void vat_can(){
      if(c_b==1){
      k=250;
      g=1;
      dc_stop();
      led2(1);delay_ms(50);led2(0);
      }
}

void vat_can2(){
      if(c_b2==1){
      k=250;
      delay_ms(170);
      dc_stop();
      led3(1);delay_ms(50);led3(0);
      }
}

void vat_can3(){
      if(c_b3==1){
      k=250;
      delay_ms(170);
      dc_stop();
      led4(1);delay_ms(50);led4(0);
      }
}

void so_sanh(){
if(c_b3==1 && c_b==0 && c_b2==0){
ne_trai2();a=1;b=0;
}
else if(c_b3==0 && c_b==1 && c_b2==0){
ne_trai();a=1;b=0;
}
else if(c_b3==1 && c_b==1 && c_b2==0){
ne_trai();a=1;b=0;
}
else if(c_b3==0 && c_b==0 && c_b2==1){
ne_phai2();a=0;b=1;
}
else if(c_b3==0 && c_b==1 && c_b2==1){
ne_phai();a=0;b=1;
}
else if(c_b3==1 && c_b==1 && c_b2==1){
p=1;u=15;
}
else if(c_b3==1 && c_b==0 && c_b2==1){
p=1;u=15;
}
}

void tim_duong(){
  if(g==3){
   for(k=0;k<250;k++){
         dc_up();
         cb();delay_ms(5);cb2();delay_ms(5);cb3();delay_ms(5);
         vat_can();vat_can2();vat_can3();
         }         
         k=0;
         for(k=0;k<250;k++){
         cb();delay_ms(5);cb2();delay_ms(5);cb3();delay_ms(5);
         vat_can();vat_can2();vat_can3();
         }
         k=0;
         so_sanh();
         c_b=0;c_b2=0;c_b3=0;u=0;
         delay_ms(20);
         }
         else{
         for(k=0;k<250;k++){
         dc_up();
         cb();delay_ms(5);cb2();delay_ms(5);cb3();delay_ms(5);
         vat_can();vat_can2();vat_can3();
         }                  
         k=0;
         so_sanh();
         c_b=0;c_b2=0;c_b3=0;u=0;g++;
         delay_ms(20);
         }
}
void doichieu(){
if(a==1&&b==0){
a=0;b=0;
dc_right2();delay(500);delay(500);delay(100);
}
else if(a==0&&b==1){
a=0;b=0;
dc_left2();delay(500);delay(500);
}
}

void main()
{
   set_tris_b(0);output_b(0);
   set_tris_e(0);output_e(0);
   a=0;b=0;k=0;g=0;u=0;p=0;c_b=0;c_b2=0;c_b3=0;dc_stop();led_don();
   setup_timer_1(T1_INTERNAL|T1_DIV_BY_2);
   setup_timer_2(T2_DIV_BY_1,255,1);
   setup_ccp2(CCP_PWM);
   setup_ccp1(CCP_PWM);
   output_low(pin_e1);
   output_low(pin_e2);
   set_pwm1_duty(0);//LEFT
   set_pwm2_duty(0);//RIGHT
   //
   dc_stop();
   delay_ms(500);
   led_don1();
///
   while(TRUE)
   {
   if(p==1){dc_stop();
   led3(1);delay(500);delay(500);led3(0);delay(500);delay(500);led3(1);delay(500);delay(500);led3(0);delay(500);delay(500);
   led3(1);delay(500);delay(500);led3(0);delay(500);delay(500);led3(1);delay(500);delay(500);led3(0);delay(500);delay(500);
   led3(1);delay(500);delay(500);led3(0);delay(500);delay(500);led3(1);delay(500);delay(500);led3(0);delay(500);delay(500);
   led3(1);delay(500);delay(500);led3(0);delay(500);delay(500);led3(1);delay(500);delay(500);led3(0);delay(500);delay(500);
   led3(1);delay(500);delay(500);led3(0);delay(500);delay(500);led3(1);delay(500);delay(500);led3(0);delay(500);delay(500);
   led3(1);delay(500);delay(500);led3(0);delay(500);delay(500);led3(1);delay(500);delay(500);led3(0);delay(500);delay(500);
   dc_down();delay(500);delay(500);delay(500);delay(500);
   dc_stop();delay(500);
   doichieu();
   dc_stop();delay(500);
   }//p=0;a
   else{tim_duong();}
   }
}
