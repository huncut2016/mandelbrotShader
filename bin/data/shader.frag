#version 150
out vec4 outputColor;
uniform vec2 WindowSize;
uniform vec4 Positions;

float map (float n, float start1,float  stop1, float start2,float  stop2) {
    return ((n-start1)/(stop1-start1))*(stop2-start2)+start2;
}

void main(){
    int WIDTH = 0;
    int HEIGHT = 1;
    int SCALE = 0;

    int X = 1;
    int Y = 2;
    int MAX_ITERATIONS = 3;

	// vec2 myCoord = gl_FragCoord.xy / 1000; // [] []
    float scale = Positions[SCALE];
    float x = Positions[X];
    float y = Positions[Y];
    int max_iter = int(Positions[MAX_ITERATIONS]);

	float a = map(gl_FragCoord.y, 0, WindowSize[HEIGHT], -1*scale+x, 1*scale + x);
    float b = map(gl_FragCoord.x, 0, WindowSize[WIDTH], -2*scale+y , 1*scale + y);

    float ca = a, cb = b;
            
    int iter;

    for (iter = 0; iter < max_iter; iter++){
        float newA = 2*a*b;
        float newB = b*b - a*a;

        a = newA + ca;
        b = newB + cb;

        if (a > 1 || a < -1) break;
        if (b > 1 || b < -2) break;
    }
    float color = map(float(iter), 0.0, float(max_iter), 0.0, 1.0);
	outputColor = vec4(1, 1, 1, color); // R G B A
	// outputColor = vec4(1, 1, 1, 1); // R G B A
}