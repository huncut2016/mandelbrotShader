#include "./ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    shader.load("shader");
}

//--------------------------------------------------------------
void ofApp::update()
{
}

//--------------------------------------------------------------
void ofApp::draw()
{
    shader.begin();

        shader.setUniform2f("WindowSize", ofGetWidth(), ofGetHeight());
        shader.setUniform2f("Positions", x, y);
        
        shader.setUniform1f("Scale", scale);
        shader.setUniform1f("Max_iter", max_iter);

        ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());

    shader.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{
    switch (key)
    {
    case '-':
        max_iter -= 10;
        break;
    
    case '+':
        max_iter += 100;
        break;
    
    default:
        break;
    }
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int _x, int _y)
{
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int xx, int yy, int button)
{   
    x -= (xx-prevX) / 300 * scale;
    y += (yy-prevY) / 300 * scale;
    

    prevX = xx;
    prevY = yy;
}

//--------------------------------------------------------------
void ofApp::mousePressed(int xx, int yy, int button)
{
    prevX = xx;
    prevY = yy;
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

void ofApp::mouseScrolled(int xx, int yy, float scrollX, float scrollY) {
    if (scrollY == -1) {
        scale *= 1.07;
    } else {
        scale /= 1.07;
    }
}
