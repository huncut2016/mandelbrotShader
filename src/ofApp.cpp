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
    img.grabScreen(0, 0, ofGetWidth(), ofGetHeight());

    for (int i = 0; i < ofGetHeight(); i++){
        for (int j = 0; j < ofGetWidth(); j++){
            double a = ofMap(i, 0, ofGetHeight(), -1*scale+x, 1*scale + x);
            double b = ofMap(j, 0, ofGetWidth(), -2*scale+y , 1*scale + y);

            double ca = a, cb = b;
            
            int iter;
            bool good = true;

            for (iter = 0; iter < 200; iter++){
                double newA = 2*a*b;
                double newB = a*a - b*b;

                a = newA + ca;
                b = newB + cb;

                if (a > 100 || a < -100) {
                    good = false;
                    break;
                }
                if (b > 100 || b < -200) {
                    good = false;
                    break;
                }
            }

            ofColor col = ofColor::fromHsb(ofMap(iter, 0, 200, 0, 255), 100, 255);
            ofSetColor(col);
            int index = j * ofGetWidth() + i;
            img.setColor( j, i , col);
        }
    }

    img.update();

    img.draw(0,0);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{
    if (key == '-') {
        scale += 0.1;
    } else if (key == '+') {
        scale -= 0.1;
    } else if (key == 'w') {
        y -= 0.1;
    } else if (key == 's') {
        y += 0.1;
    } else if (key == 'a') {
        x -= 0.1;
    } else if (key == 'd') {
        x += 0.1;
    }
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int _x, int _y)
{
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
