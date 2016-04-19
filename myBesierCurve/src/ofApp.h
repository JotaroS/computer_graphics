#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "vector"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    int num_steps = 200;
    
    int fact(int n);
    int NCR(int n, int r);
    float Bernstein(int n,int i, float t);
    bool shift_down;
    bool cmd_down;
    int drag_index= -1;
    ofPoint P_t(float t);
    ofPoint StartPoint;
    ofPoint EndPoint;
    vector<ofPoint> Points;
    vector<ofPoint> ControlPoints;
    ofxPanel gui;
    ofxIntSlider gui_points;
    
		
};
