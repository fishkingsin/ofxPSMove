
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

#include "ofxPSMove.h"
#include "psmove.h"
namespace ofxPSMove {
	Receiver::Receiver()
	{
		//bSetup = false;
		//    psmoveData.accelerometer.set(0);
		//    psmoveData.gyroscope.set(0);
		//    psmoveData.magnetometer.set(0);
	}
	Receiver::~Receiver()
	{
		for (int id=0; id<count; id++) {
			bSetup[id] = false;
			if(move[id]!=NULL)
			{
				psmove_set_leds(move[id], 0,0,0);
				psmove_update_leds(move[id]);
				psmove_disconnect(move[id]);
			}
		}
		ofLog(OF_LOG_VERBOSE,"PSMove Disconnected\n");
	}
	void Receiver::enable(){
		ofAddListener(ofEvents().update, this, &Receiver::update);
	}
	
	void Receiver::disable(){
		ofRemoveListener(ofEvents().update, this, &Receiver::update);
	}
	
	void Receiver::setup()
	{
		
		count = psmove_count_connected();
		bSetup.resize(count);
		move.resize(count);
		psmoveData.resize(count);
		//    ofLog(OF_LOG_VERBOSE,"Connected controllers: %d\n", psmoveData.id);
		
		for (int id=0; id<count; id++) {
			move[id] = psmove_connect_by_id(id);
			
			if (move[id] == NULL) {
				ofLog(OF_LOG_ERROR,"Could not connect to default Move controller.\n"
					  "Please connect one via USB or Bluetooth.\n");
				
				bSetup[id] = false;
			}
			else
			{
				bSetup[id] = true;
			}
			if(bSetup[id])
			{
				
				char *serial = psmove_get_serial(move[id]);
				ofLog(OF_LOG_VERBOSE,"Serial: %s\n", serial);
				free(serial);
				
				ctype = psmove_connection_type(move[id]);
				switch (ctype) {
					case Conn_USB:
						ofLog(OF_LOG_NOTICE,"Connected via USB.\n");
						break;
					case Conn_Bluetooth:
						ofLog(OF_LOG_NOTICE,"Connected via Bluetooth.\n");
						break;
					case Conn_Unknown:
						ofLog(OF_LOG_WARNING,"Unknown connection type.\n");
						break;
				}
				
				for (int i=0; i<10; i++) {
					psmove_set_leds(move[id], 0, 255*(i%3==0), 0);
					psmove_set_rumble(move[id], 255*(i%2));
					psmove_update_leds(move[id]);
					usleep(10000*(i%10));
				}
				
				for (int i=250; i>=0; i-=5) {
					psmove_set_leds(move[id], i, i, 0);
					psmove_set_rumble(move[id], 0);
					psmove_update_leds(move[id]);
				}
				
				/* Enable rate limiting for LED updates */
				//psmove_set_rate_limiting(move, 1);
				
				psmove_set_leds(move[id], 0, 0, 0);
				psmove_set_rumble(move[id], 0);
				psmove_update_leds(move[id]);
			}
		}
	}
	void Receiver::update(ofEventArgs & args)
	{
		for (int id=0; id<count; id++) {
			if(bSetup[id])
			{
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
				int btn = psmove_get_buttons(move[id]);
				EventArgs args;
				psmoveData[id].id = id;
				args.data = &psmoveData[id];
				//			args.person = person;
				//			args.scene = &scene;
				
				//			if (m.getAddress() == "/TSPS/personEntered/" || personIsNew){
				//				ofNotifyEvent(Events().personEntered, args, this);
				if((psmove_get_buttons(move[id]) & Btn_TRIANGLE) && !psmoveData[id].BTN_TRIANGLE)
				{
					psmoveData[id].BTN_TRIANGLE = true;
					ofNotifyEvent(Events().buttonTrianglePressed,args,this);
				}
				else
				{
					psmoveData[id].BTN_TRIANGLE = false;
					ofNotifyEvent(Events().buttonTriangleReleased,args,this);
				}
                if(psmove_get_buttons(move[id]) & Btn_CIRCLE&& !psmoveData[id].BTN_CIRCLE)
				{
					
                    psmoveData[id].BTN_CIRCLE = true;
                    ofNotifyEvent( Events().buttonCirclePressed,args,this);
				}else
				{
					psmoveData[id].BTN_CIRCLE = false;
					ofNotifyEvent( Events().buttonCirclePressed,args,this);
				}
				if(psmove_get_buttons(move[id]) & Btn_CROSS && !psmoveData[id].BTN_CROSS)
                {    psmoveData[id].BTN_CROSS = true;
                    ofNotifyEvent( Events().buttonCrossPressed,args,this);
                }
                else
                {
                    psmoveData[id].BTN_CROSS = false;
                    ofNotifyEvent( Events().buttonCirclePressed,args,this);
                }
                if(psmove_get_buttons(move[id]) & Btn_SQUARE)
                {   psmoveData[id].BTN_TRIANGLE = true;
                    ofNotifyEvent( Events().buttonSquarePressed,args,this);
                }
                else
                {
                    psmoveData[id].BTN_TRIANGLE = false;
                    ofNotifyEvent( Events().buttonCirclePressed,args,this);
                }
                if(psmove_get_buttons(move[id]) & Btn_SELECT)
                {   psmoveData[id].BTN_TRIANGLE = true;
                    ofNotifyEvent( Events().buttonSelectPressed,args,this);
                }else
                {
                    psmoveData[id].BTN_TRIANGLE = false;
                    ofNotifyEvent( Events().buttonCirclePressed,args,this);
                }
                if(psmove_get_buttons(move[id]) & Btn_START)
                {   psmoveData[id].BTN_TRIANGLE = true;
                    ofNotifyEvent( Events().buttonStartPressed,args,this);
                }else
                {
                    psmoveData[id].BTN_TRIANGLE = false;
                    ofNotifyEvent( Events().buttonCirclePressed,args,this);
                }
                if(psmove_get_buttons(move[id]) & Btn_MOVE)
                {   psmoveData[id].BTN_MOVE = true;
                    ofNotifyEvent( Events().buttonMovePressed,args,this);
                }else
                {
                    psmoveData[id].BTN_MOVE = false;
                    ofNotifyEvent( Events().buttonCirclePressed,args,this);
                }
                if(psmove_get_buttons(move[id]) & Btn_T)
                {   psmoveData[id].BTN_T = true;
                    ofNotifyEvent( Events().buttonTPressed,args,this);
                }else
                {
                    psmoveData[id].BTN_T = false;
                    ofNotifyEvent( Events().buttonCirclePressed,args,this);
                }
                if(psmove_get_buttons(move[id]) & Btn_PS)
                {   psmoveData[id].BTN_PS = true;
                    ofNotifyEvent( Events().buttonPSPressed,args,this);
                }else
                {
                    psmoveData[id].BTN_PS = false;
                    ofNotifyEvent( Events().buttonCirclePressed,args,this);
                }
				
				int _x, _y, _z;
				psmove_get_accelerometer(move[id], &_x, &_y, &_z);
				psmoveData[id].accelerometer.set(_x,_y,_z);
				
				psmove_get_gyroscope(move[id], &_x, &_y, &_z);
				psmoveData[id].gyroscope.set(_x,_y,_z);
				
				psmove_get_magnetometer(move[id], &_x, &_y, &_z);
				psmoveData[id].magnetometer.set(_x,_y,_z);
				
				uint trigger = psmove_get_trigger(move[id]);
				if(psmoveData[id].TRIGGER != trigger)
				{
					psmoveData[id].TRIGGER = trigger;
                    ofNotifyEvent( Events().triggerUpdated,args,this);
				}
				
				int battery = psmove_get_battery(move[id]);

				if(psmoveData[id].battery != battery)
				{
					psmoveData[id].battery = battery;
                    ofNotifyEvent( Events().batteryUpdated,args,this);
				}
				
				int temperature = psmove_get_temperature(move[id]);
				
				if(psmoveData[id].temperature != temperature)
				{
					psmoveData[id].temperature = psmove_get_temperature(move[id]);
                    ofNotifyEvent( Events().temperatureUpdated,args,this);
				}

				
				
				/*if (ctype != Conn_USB && !(psmove_get_buttons(move) & Btn_PS)) {
				 int res = psmove_poll(move);
				 if (res) {
				 if (psmove_get_buttons(move) & Btn_TRIANGLE) {
				 ofLog(OF_LOG_VERBOSE,"Triangle pressed, with trigger value: %d\n",
				 psmove_get_trigger(move));
				 psmove_set_rumble(move, psmove_get_trigger(move));
				 } else {
				 psmove_set_rumble(move, 0x00);
				 }
				 
				 psmove_set_leds(move, sin(ofGetFrameNum()/30.0f)*255,cos(ofGetFrameNum()/60.0f)*255, psmove_get_trigger(move));
				 
				 //int x, y, z;
				 
				 ofLog(OF_LOG_VERBOSE,"buttons: %x\n", psmove_get_buttons(move));
				 
				 battery = psmove_get_battery(move);
				 
				 if (battery == Batt_CHARGING) {
				 ofLog(OF_LOG_VERBOSE,"battery charging\n");
				 } else if (battery == Batt_CHARGING_DONE) {
				 ofLog(OF_LOG_VERBOSE,"battery fully charged (on charger)\n");
				 } else if (battery >= Batt_MIN && battery <= Batt_MAX) {
				 ofLog(OF_LOG_VERBOSE,"battery level: %d / %d\n", battery, Batt_MAX);
				 } else {
				 ofLog(OF_LOG_VERBOSE,"battery level: unknown (%x)\n", battery);
				 }
				 
				 ofLog(OF_LOG_VERBOSE,"temperature: %d\n", psmove_get_temperature(move));
				 
				 psmove_update_leds(move);
				 }
				 }*/
//				ofNotifyEvent( Event().PSMoveEvent,psmoveData[id],this);
			}
		}
		
	}
	void Receiver::draw()
	{
		
	}
	void Receiver::setLedColor(int _id, int r , int g , int b)
	{
		if(_id < count)
		{
			if(move[_id]!=NULL)
			{
				psmove_set_leds(move[_id], r, g, b);
				psmove_update_leds(move[_id]);
			}
		}
	}
}