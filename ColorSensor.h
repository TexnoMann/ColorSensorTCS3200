#ifndef ColorSensor_h
#define ColorSensor_h

#include "Arduino.h"

class ColorSensor{
	public:
		ColorSensor(int s0, int s1, int s2, int s3, int out, int led);
		int colorread();
		void setUnits(int arr[6][3]);
	private:
		int i;
		int j;
		int colinstall[6][3];
		int col[3];
		int clears;
		int _s0;
		int _s1;
		int _s2;
		int _s3;
		int _out;
		int _led;
		int currentcolor;
		int b;
		
};
#endif
