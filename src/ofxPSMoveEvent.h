//
//  ofxPSMoveEvent.h
//  example
//
//  Created by james KONG on 4/2/13.
//
//

#pragma once

#include "ofEvents.h"
namespace ofxPSMove {
    class Data;

    
    class EventArgs {
    public:
        
		EventArgs(){};
		
		Data *data;
    };
    
    class CoreEvents {
    public:
        
		CoreEvents(){};
		
        ofEvent<EventArgs> buttonTrianglePressed;
		ofEvent<EventArgs> buttonCirclePressed;
		ofEvent<EventArgs> buttonCrossPressed;
		ofEvent<EventArgs> buttonSquarePressed;
		ofEvent<EventArgs> buttonSelectPressed;
		ofEvent<EventArgs> buttonStartPressed;
		ofEvent<EventArgs> buttonMovePressed;
		ofEvent<EventArgs> buttonTPressed;
		ofEvent<EventArgs> buttonPSPressed;
		
		ofEvent<EventArgs> triggerUpdated;
		ofEvent<EventArgs> batteryUpdated;
		ofEvent<EventArgs> temperatureUpdated;
		
		ofEvent<EventArgs> accelerometerUpdated;
		ofEvent<EventArgs> gyroscopeUpdated;
		ofEvent<EventArgs> magnetometerUpdated;
		
		ofEvent<EventArgs> buttonTriangleReleased;
		ofEvent<EventArgs> buttonCircleReleased;
		ofEvent<EventArgs> buttonCrossReleased;
		ofEvent<EventArgs> buttonSquareReleased;
		ofEvent<EventArgs> buttonSelectReleased;
		ofEvent<EventArgs> buttonStartReleased;
		ofEvent<EventArgs> buttonMoveReleased;
		ofEvent<EventArgs> buttonTReleased;
		ofEvent<EventArgs> buttonPSReleased;
        
    };
    
    CoreEvents & Events();
}

template<class ListenerClass>
void ofxAddPSMoveListeners( ListenerClass * listener ){
    ofAddListener(ofxPSMove::Events().buttonTrianglePressed, listener, &ListenerClass::onTrianglePressed);
    ofAddListener(ofxPSMove::Events().buttonCirclePressed, listener, &ListenerClass::onCirclePressed);
    ofAddListener(ofxPSMove::Events().buttonCrossPressed, listener, &ListenerClass::onCrossPressed);
	ofAddListener(ofxPSMove::Events().buttonSquarePressed, listener, &ListenerClass::onSquarePressed);
	ofAddListener(ofxPSMove::Events().buttonSelectPressed, listener, &ListenerClass::onSelectPressed);
	ofAddListener(ofxPSMove::Events().buttonStartPressed, listener, &ListenerClass::onStartPressed);
	ofAddListener(ofxPSMove::Events().buttonMovePressed, listener, &ListenerClass::onMovePressed);
	ofAddListener(ofxPSMove::Events().buttonTPressed, listener, &ListenerClass::onTPressed);
	ofAddListener(ofxPSMove::Events().buttonPSPressed, listener, &ListenerClass::onPSPressed);

	ofAddListener(ofxPSMove::Events().buttonTriangleReleased, listener, &ListenerClass::onTriangleReleased);
    ofAddListener(ofxPSMove::Events().buttonCircleReleased, listener, &ListenerClass::onCircleReleased);
    ofAddListener(ofxPSMove::Events().buttonCrossReleased, listener, &ListenerClass::onCrossReleased);
	ofAddListener(ofxPSMove::Events().buttonSquareReleased, listener, &ListenerClass::onSquareReleased);
	ofAddListener(ofxPSMove::Events().buttonSelectReleased, listener, &ListenerClass::onSelectReleased);
	ofAddListener(ofxPSMove::Events().buttonStartReleased, listener, &ListenerClass::onStartReleased);
	ofAddListener(ofxPSMove::Events().buttonMoveReleased, listener, &ListenerClass::onMoveReleased);
	ofAddListener(ofxPSMove::Events().buttonTReleased, listener, &ListenerClass::onTReleased);
	ofAddListener(ofxPSMove::Events().buttonPSReleased, listener, &ListenerClass::onPSReleased);

	ofAddListener(ofxPSMove::Events().triggerUpdated, listener, &ListenerClass::onTriggerUpdated);
	ofAddListener(ofxPSMove::Events().batteryUpdated, listener, &ListenerClass::onBatteryUpdated);
	ofAddListener(ofxPSMove::Events().temperatureUpdated, listener, &ListenerClass::onTemperatureUpdated);
	
	ofAddListener(ofxPSMove::Events().accelerometerUpdated, listener, &ListenerClass::onAccelerometerUpdated);
	ofAddListener(ofxPSMove::Events().gyroscopeUpdated, listener, &ListenerClass::onGyroscopeUpdated);
	ofAddListener(ofxPSMove::Events().magnetometerUpdated, listener, &ListenerClass::onMagnetometerUpdated);
}

template<class ListenerClass>
void ofxRemovePSMoveListeners( ListenerClass * listener ){
    ofRemoveListener(ofxPSMove::Events().buttonTrianglePressed, listener, &ListenerClass::onTrianglePressed);
    ofRemoveListener(ofxPSMove::Events().buttonCirclePressed, listener, &ListenerClass::onCirclePressed);
    ofRemoveListener(ofxPSMove::Events().buttonCrossPressed, listener, &ListenerClass::onCrossPressed);
	ofRemoveListener(ofxPSMove::Events().buttonSquarePressed, listener, &ListenerClass::onSquarePressed);
	ofRemoveListener(ofxPSMove::Events().buttonSelectPressed, listener, &ListenerClass::onSelectPressed);
	ofRemoveListener(ofxPSMove::Events().buttonStartPressed, listener, &ListenerClass::onStartPressed);
	ofRemoveListener(ofxPSMove::Events().buttonMovePressed, listener, &ListenerClass::onMovePressed);
	ofRemoveListener(ofxPSMove::Events().buttonTPressed, listener, &ListenerClass::onTPressed);
	ofRemoveListener(ofxPSMove::Events().buttonPSPressed, listener, &ListenerClass::onPSPressed);
	
	ofRemoveListener(ofxPSMove::Events().buttonTriangleReleased, listener, &ListenerClass::onTriangleReleased);
    ofRemoveListener(ofxPSMove::Events().buttonCircleReleased, listener, &ListenerClass::onCircleReleased);
    ofRemoveListener(ofxPSMove::Events().buttonCrossReleased, listener, &ListenerClass::onCrossReleased);
	ofRemoveListener(ofxPSMove::Events().buttonSquareReleased, listener, &ListenerClass::onSquareReleased);
	ofRemoveListener(ofxPSMove::Events().buttonSelectReleased, listener, &ListenerClass::onSelectReleased);
	ofRemoveListener(ofxPSMove::Events().buttonStartReleased, listener, &ListenerClass::onStartReleased);
	ofRemoveListener(ofxPSMove::Events().buttonMoveReleased, listener, &ListenerClass::onMoveReleased);
	ofRemoveListener(ofxPSMove::Events().buttonTReleased, listener, &ListenerClass::onTReleased);
	ofRemoveListener(ofxPSMove::Events().buttonPSReleased, listener, &ListenerClass::onPSReleased);
	
	ofRemoveListener(ofxPSMove::Events().triggerUpdated, listener, &ListenerClass::onTriggerUpdated);
	ofRemoveListener(ofxPSMove::Events().batteryUpdated, listener, &ListenerClass::onBatteryUpdated);
	ofRemoveListener(ofxPSMove::Events().temperatureUpdated, listener, &ListenerClass::onTemperatureUpdated);
	
	ofRemoveListener(ofxPSMove::Events().accelerometerUpdated, listener, &ListenerClass::onAccelerometerUpdated);
	ofRemoveListener(ofxPSMove::Events().gyroscopeUpdated, listener, &ListenerClass::onGyroscopeUpdated);
	ofRemoveListener(ofxPSMove::Events().magnetometerUpdated, listener, &ListenerClass::onMagnetometerUpdated);
	

}