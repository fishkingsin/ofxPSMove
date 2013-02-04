//
//  ofxPSMoveEvent.cpp
//  example
//
//  Created by james KONG on 4/2/13.
//
//

#include "ofxPSMoveEvent.h"
namespace ofxPSMove {
    CoreEvents & Events(){
        static CoreEvents * events = new CoreEvents;
        return *events;
    }
}