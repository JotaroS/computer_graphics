#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    for(int i=0; i < 10;i++){
        links.push_back(Link());
        links[i].theta = 0+ofRandom(0,10)
        ; //ofRandom(-1,1);
        links[i].length = 50;//+ofRandom(0,50);
    }
}
float x_goal =10;
float y_goal =10;
//--------------------------------------------------------------
void ofApp::update(){
    for(int i=links.size()-1; i>=0; i--){
        ofPoint e = FK(0,links.size());
        ofPoint l = FK(0,i);
        ofPoint e_l = e-l;
        ofPoint g_l = ofPoint(x_goal,y_goal)-l;
        float theta = atan2(e_l.y,e_l.x)-atan2(g_l.y,g_l.x);
        links[i].theta-=theta*0.8;

    }
}


ofPoint ofApp::FK(int m,int n){
    ofPoint p;
    for(int i=m; i< n; i++){
        p.x+=links[i].length*cos(links[i].theta);
        p.y+=links[i].length*sin(links[i].theta);
    }
    return p;
}

//--------------------------------------------------------------
void ofApp::draw(){
    float end_x=0,end_y=0;
    ofBackground(200);
    ofPushMatrix();{
        ofTranslate(ofGetWidth()/2,ofGetHeight()/2);

        ofPushMatrix();
        {
            for(int i=0; i < links.size(); i++){
                ofSetColor(200,0,200);
                ofDrawCircle(0, 0, 10);
                ofSetColor(0,200,200);
                ofSetLineWidth(3);
                ofDrawLine(0,0,links[i].length*cos(links[i].theta),links[i].length*sin(links[i].theta));
                ofTranslate(links[i].length*cos(links[i].theta),links[i].length*sin(links[i].theta));
                end_x+=links[i].length*cos(links[i].theta);
                end_y+=links[i].length*sin(links[i].theta);
            }
            ofSetColor(100,200,100);
            ofDrawCircle(0, 0, 10);
        }ofPopMatrix();
        
    }ofPopMatrix();
    
    ofDrawBitmapString("end_x="+ofToString(end_x), 20, 20);
    ofDrawBitmapString("end_y="+ofToString(end_y), 20, 40);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    x_goal = x - ofGetWidth()/2;
    y_goal = y- ofGetHeight()/2;

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

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
