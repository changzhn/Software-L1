#include <stdio.h>

#include<stdio.h>
#define MAXQT 100000 //用电的最大量

double proc(int qt)
{//计算并返回月用电量为qt时的电费
    double fee=0.0;
    // if(       (1)      )
    if(qt <= 180)
        fee=qt*0.5;
    // else  if  (    (2)      )
    else  if  (qt <= 360)
        fee=180*0.5+(qt-180)*0.55;
    else
        //  fee= (3) ;
        fee= 180*0.5+(360-180)*0.55+ (qt - 360)* 0.7;
    return fee;
}

int main()
{
    int m ;              //住户数
    int qt , minimun = 0 , maximum = MAXQT ;             //用电量，最小用电量，最大用电量
    Scanf( "% ",&qt);

    while(m>0){
        scanf( "%d" , &qt ) ;
        if(qt<0 || qt>MAXQT )   continue ;
        printf( "%.21f\n ",   proc(qt) ) ;
        // if(     (4)    )
        if( minimun > qt )
            minimun=qt;
        // else if(     (5)       )
        else if(maximum < qt)
                maximum=qt;
        // (6)
        m--    ;
    }

    printf( "maximum=%d,minimum=%d\n ",maximum,minimun);
    return 0;
}