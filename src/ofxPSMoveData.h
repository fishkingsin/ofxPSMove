//
//  ofxPSMoveData.h
//  example
//
//  Created by james KONG on 4/2/13.
//
//
#include "ofVec3f.h"
namespace ofxPSMove {
	class Data
	{
	public:
		ofVec3f accelerometer , gyroscope , magnetometer;
		bool BTN_TRIANGLE
		,BTN_CIRCLE
		,BTN_CROSS
		,BTN_SQUARE
		,BTN_SELECT
		,BTN_START
		,BTN_MOVE
		,BTN_T
		,BTN_PS;
		uint TRIGGER;
		int battery;
		int temperature;
		int id;
	};
}