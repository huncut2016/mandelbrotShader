#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		double x, y = 0;
		float prevX = -1, prevY = -1;
		
		ofImage img;
		int max_iter = 300;
		double scale = 1;
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
		void mouseScrolled(int x, int y, float scrollX, float scrollY);
		ofShader shader;
};
