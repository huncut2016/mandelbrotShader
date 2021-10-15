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
        #define WIDTH 0
        #define HEIGHT 1

        float winSize[2] = {ofGetWidth(), ofGetHeight()};
        float Positions[4] = {scale, x, y, max_iter};

        shader.setUniform2f("WindowSize", winSize[WIDTH], winSize[HEIGHT]);
        shader.setUniform4f("Positions", scale, x, y, max_iter);

        ofDrawRectangle(0, 0, winSize[WIDTH], winSize[HEIGHT]);

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
        scale *= 1.07;
        break;
    
    case '+':
        scale /= 1.07;
        break;
    
    case 'a':
         y -= 0.1 * scale;
        break;
    
    case 'd':
        y += 0.1 * scale ;
        break;

    case 'w':
        x += 0.1 *scale;
        break;

    case 's':
        x -= 0.1 *scale;
        break;

    case 'm':
        max_iter += 100; // increase max iteration
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
    x += (yy-prevY) / 300 * scale;
    y -= (xx-prevX) / 300 * scale;
    

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
