#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
}

//--------------------------------------------------------------
void ofApp::update()
{
}

//--------------------------------------------------------------
void ofApp::draw()
{
    for (int i = 0; i < ofGetHeight(); i++){
        for (int j = 0; j < ofGetWidth(); j++){
            double a = ofMap(i, 0, ofGetHeight(), -1, 1);
            double b = ofMap(j, 0, ofGetWidth(), -2 , 1);
            
            int iter;
            bool good = true;

            for (iter = 0; iter < 200; iter++){
                double newA = 2*a*b;
                double newB = a*a + b*b;

                a = newA;
                b = newB;

                if (a > 1 || a < -1) {
                    good = false;
                    break;
                }
                if (b > 1 || b < -2) {
                    good = false;
                    break;
                }
            }

            ofColor col = ofColor::fromHsb(ofMap(iter, 0, 200, 0, 255), 255, 255);
            ofSetColor(col);
            ofDrawCircle(i, j, 1);

        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int _x, int _y)
{
    x = (float)_x;
    y = (float)_y;
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h)
{
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg)
{
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo)
{
}
