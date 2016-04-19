#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofEnableSmoothing();
    StartPoint.set(100,200);
    EndPoint.set(300,400);
    gui.setup();
    gui.add(gui_points.setup("NUM_POINTS",100,3,300));
    
}

//--------------------------------------------------------------
void ofApp::update(){
    num_steps = gui_points;
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(252,236,182);;
    //ofSetColor(0,220,220);
    ofSetLineWidth(1);
    for(int i=0;i<ControlPoints.size();i++){
        ofSetColor(0,220,220);
        if(i==0||i==ControlPoints.size()-1)ofSetColor(0,220,0);
        ofDrawCircle(ControlPoints[i], 7);
        
        ofSetColor(100);
        if(i>0)ofDrawLine(ControlPoints[i-1],ControlPoints[i]);
    }
    
    ofSetColor(220,0,220);
    ofPoint prev_p = P_t(0);
    ofSetLineWidth(3);
    if(ControlPoints.size()>0){
    for(float t=1.0f/num_steps; t<=1.0f;t+=1.0f/num_steps){
        ofPoint p = P_t(t);
        ofDrawLine(prev_p,p);
        prev_p=p;
    }
        ofSetColor(255);
        for(float t=1.0f/num_steps; t<=1.0f;t+=1.0f/num_steps){
            ofPoint p = P_t(t);
            ofDrawCircle(p, 1);
        }
    }
    
    ofSetColor(220,0,220);
    gui.draw();
    ofDrawBitmapString("Interactive Besier Simulator\nClick to add control points.\nDrawn by Bernstein expression : P(t) = sum(0,N-1) B_i J_N-1_i_t\nPress shift and drag to move control points.\nPress alt and click them to delete.", 20, 60);
}

//--------------------------------------------------------------

int ofApp::fact(int n){
    if(n==0) return 1;
    if (n>0) return n*fact(n-1);
}
//--------------------------------------------------------------

int ofApp::NCR(int n, int r) {
    if(r > n / 2) r = n - r; // because C(n, r) == C(n, n - r)
    long long ans = 1;
    int i;
    
    for(i = 1; i <= r; i++) {
        ans *= n - r + i;
        ans /= i;
    }
    return ans;
}
//--------------------------------------------------------------
float ofApp::Bernstein(int n,int i, float t){
    return NCR(n,i)*pow(t,i)*pow((1.0f-t),n-i);
}
//--------------------------------------------------------------
ofPoint ofApp::P_t(float t){
    ofPoint p;
    for(int i=0; i<ControlPoints.size();i++){
        p.x += ControlPoints[i].x * Bernstein(ControlPoints.size()-1,i,t);
        p.y += ControlPoints[i].y * Bernstein(ControlPoints.size()-1,i,t);
    }
    return p;
}


void ofApp::keyPressed(int key){
    if(key == OF_KEY_SHIFT){
        shift_down = true;
    }
    if(key == OF_KEY_ALT){
        cmd_down = true;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if(key == OF_KEY_SHIFT){
        shift_down = false;
        drag_index = -1;
    }
    if(key == OF_KEY_ALT){
        cmd_down = false;
    }
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    if(drag_index!=-1){
        ControlPoints[drag_index] = ofPoint(x,y);
        return;
    }
    if(shift_down){
        for(int i=0;i<ControlPoints.size();i++){
            if(ofDistSquared(x,y, ControlPoints[i].x, ControlPoints[i].y)<30){
                drag_index = i;
                ControlPoints[i] = ofPoint(x,y);
                break;
            }
        }
    }
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    if(shift_down){
    }
    else if(cmd_down){
        for(int i=0;i<ControlPoints.size();i++){
            if(ofDistSquared(x,y, ControlPoints[i].x, ControlPoints[i].y)<30){
                ControlPoints.erase(ControlPoints.begin()+i);;
                break;
            }
        }
    }
    else ControlPoints.push_back(ofPoint(x,y));
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    drag_index = -1;
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}



