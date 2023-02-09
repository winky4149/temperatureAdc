/*
 * filter.c
 *
 *  Created on: Feb 6, 2023
 *      Author: npedu030
 */

#include "filter.h"

uint16_t AvgFilter(uint16_t inData)
{
	static uint16_t filterBuffer[100];
	static uint16_t sumvalue=0;
	static uint8_t bufPos=0;
	//합계에서 현재 위치의 버퍼값을 빼기
	sumvalue-=filterBuffer[bufPos];
	//현재위치의 버퍼값 갱신
	filterBuffer[bufPos]=inData;
	//합계에서 현재 위치의 버퍼값을 더하기
	sumvalue+=filterBuffer[bufPos];
	bufPos++;
	bufPos%=100;
	return sumvalue/100;
	// -
}

double Kalman(double measurement) {
    // Kalman filter setup
    static double P = 1.0;
    static double varP = 0.0001;  // pow(0.01, 2)
    static double R = 0.25;//pow(0.5, 2);
    static double K = 1.0;
    static double X = 20.0;

    // Kalman Simple Filter
    P = P + varP;
    K = P / (P + R);
    X = (K * measurement) + (1 - K) * X;
    P = (1 - K) * P;

    return X;
}
