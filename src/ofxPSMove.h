/**
 * PS Move API - An interface for the PS Move Motion Controller
 * Copyright (c) 2011 Thomas Perl <m@thp.io>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *    1. Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *
 *    2. Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 **/


#ifndef __emptyExample__ofxPSMove__
#define __emptyExample__ofxPSMove__

#include <iostream>
#include "psmove.h"
#include "psmove_tracker.h"
#include "ofMain.h"
#include "ofxOpenCv.h"
class ofxPSMoveData 
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
class ofxPSMove
{
public:
    ofxPSMove();
    ~ofxPSMove();
    void setup();
    void enable();
    void disable();
    void update(ofEventArgs & args);
    void draw();
    void setLedColor( int r , int g , int b ,int id=0 );
    ofEvent<ofxPSMoveData> PSMoveEvent;
    //    Btn_TRIANGLE = 1 << 0x04, /*!< Green triangle */
    //    Btn_CIRCLE = 1 << 0x05, /*!< Red circle */
    //    Btn_CROSS = 1 << 0x06, /*!< Blue cross */
    //    Btn_SQUARE = 1 << 0x07, /*!< Pink square */
    //
    //    Btn_SELECT = 1 << 0x08, /*!< Select button, left side */
    //    Btn_START = 1 << 0x0B, /*!< Start button, right side */
    //
    //    Btn_MOVE = 1 << 0x13, /*!< Move button, big front button */
    //    Btn_T = 1 << 0x14, /*!< Trigger, on the back */
    //    Btn_PS = 1 << 0x10, /*!< PS button, front center */
    ofEvent<bool> buttonTrianglePressed;
    ofEvent<bool> buttonCirclePressed;
    ofEvent<bool> buttonCrossPressed;
    ofEvent<bool> buttonSquarePressed;
    ofEvent<bool> buttonSelectPressed;
    ofEvent<bool> buttonStartPressed;
    ofEvent<bool> buttonMovePressed;
    ofEvent<bool> buttonTPressed;
    ofEvent<bool> buttonPSPressed;
    
    ofEvent<bool> buttonTriangleReleased;
    ofEvent<bool> buttonCircleReleased;
    ofEvent<bool> buttonCrossReleased;
    ofEvent<bool> buttonSquareReleased;
    ofEvent<bool> buttonSelectReleased;
    ofEvent<bool> buttonStartReleased;
    ofEvent<bool> buttonMoveReleased;
    ofEvent<bool> buttonTReleased;
    ofEvent<bool> buttonPSReleased;

private:
    vector<bool>bSetup;
    vector<PSMove *>move;
    int count;
    enum PSMove_Connection_Type ctype;
    vector<ofxPSMoveData> psmoveData;
    
};
#endif /* defined(__emptyExample__ofxPSMove__) */
