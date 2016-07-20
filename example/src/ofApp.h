#pragma once

#include "ofMain.h"
#include "ofxPSMove.h"
class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
	ofxPSMove::Receiver psMoveReceiver;
	
	
	
	  void onTrianglePressed( ofxPSMove::EventArgs & psmoveEvent );
      void onCirclePressed( ofxPSMove::EventArgs & psmoveEvent );
      void onCrossPressed( ofxPSMove::EventArgs & psmoveEvent );
	  void onSquarePressed( ofxPSMove::EventArgs & psmoveEvent );
	  void onSelectPressed( ofxPSMove::EventArgs & psmoveEvent );
	  void onStartPressed( ofxPSMove::EventArgs & psmoveEvent );
	  void onMovePressed( ofxPSMove::EventArgs & psmoveEvent );
	  void onTPressed( ofxPSMove::EventArgs & psmoveEvent );
	  void onPSPressed( ofxPSMove::EventArgs & psmoveEvent );
	
	  void onTriangleReleased( ofxPSMove::EventArgs & psmoveEvent );
      void onCircleReleased( ofxPSMove::EventArgs & psmoveEvent );
      void onCrossReleased( ofxPSMove::EventArgs & psmoveEvent );
	  void onSquareReleased( ofxPSMove::EventArgs & psmoveEvent );
	  void onSelectReleased( ofxPSMove::EventArgs & psmoveEvent );
	  void onStartReleased( ofxPSMove::EventArgs & psmoveEvent );
	  void onMoveReleased( ofxPSMove::EventArgs & psmoveEvent );
	  void onTReleased( ofxPSMove::EventArgs & psmoveEvent );
	  void onPSReleased( ofxPSMove::EventArgs & psmoveEvent );
	
	  void onTriggerUpdated( ofxPSMove::EventArgs & psmoveEvent );
	  void onBatteryUpdated( ofxPSMove::EventArgs & psmoveEvent );
	  void onTemperatureUpdated( ofxPSMove::EventArgs & psmoveEvent );
	
	void onAccelerometerUpdated( ofxPSMove::EventArgs & psmoveEvent );
	void onGyroscopeUpdated ( ofxPSMove::EventArgs & psmoveEvent );
	void onMagnetometerUpdated( ofxPSMove::EventArgs & psmoveEvent );
};
