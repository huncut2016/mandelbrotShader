#version 150
out vec4 outputColor;
uniform vec2 WindowSize;
uniform vec4 Positions;

float map (float n, float start1,float  stop1, float start2,float  stop2) {
    return ((n-start1)/(stop1-start1))*(stop2-start2)+start2;
}

vec4 getColor(int ite, int iterations);

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
    float bright = map(float(iter), 0.0, float(max_iter), 0.0, 1.0);
    bright = map(sqrt(bright), 0, 1.0, 0.1, 1.0);

    outputColor = getColor(iter, max_iter);
}

vec4 getColor(int ite, int iterations) {
        vec4 CalcColor = vec4(0.0, 0.0, 0.0, 1.0);

    if (ite != iterations)
	{
		int colorNr = ite % 16;

		switch (colorNr)
		{
		case 0:
		{
			CalcColor[0] = 66.0 / 255.0;
			CalcColor[1] = 30.0 / 255.0;
			CalcColor[2] = 15.0 / 255.0;

			break;
		}
		case 1:
		{
			CalcColor[0] = 25.0 / 255.0;
			CalcColor[1] = 7.0 / 255.0;
			CalcColor[2] = 26.0 / 255.0;
			break;
		}
		case 2:
		{
			CalcColor[0] = 9.0 / 255.0;
			CalcColor[1] = 1.0 / 255.0;
			CalcColor[2] = 47.0 / 255.0;
			break;
		}

		case 3:
		{
			CalcColor[0] = 4.0 / 255.0;
			CalcColor[1] = 4.0 / 255.0;
			CalcColor[2] = 73.0 / 255.0;
			break;
		}
		case 4:
		{
			CalcColor[0] = 0.0 / 255.0;
			CalcColor[1] = 7.0 / 255.0;
			CalcColor[2] = 100.0 / 255.0;
			break;
		}
		case 5:
		{
			CalcColor[0] = 12.0 / 255.0;
			CalcColor[1] = 44.0 / 255.0;
			CalcColor[2] = 138.0 / 255.0;
			break;
		}
		case 6:
		{
			CalcColor[0] = 24.0 / 255.0;
			CalcColor[1] = 82.0 / 255.0;
			CalcColor[2] = 177.0 / 255.0;
			break;
		}
		case 7:
		{
			CalcColor[0] = 57.0 / 255.0;
			CalcColor[1] = 125.0 / 255.0;
			CalcColor[2] = 209.0 / 255.0;
			break;
		}
		case 8:
		{
			CalcColor[0] = 134.0 / 255.0;
			CalcColor[1] = 181.0 / 255.0;
			CalcColor[2] = 229.0 / 255.0;
			break;
		}
		case 9:
		{
			CalcColor[0] = 211.0 / 255.0;
			CalcColor[1] = 236.0 / 255.0;
			CalcColor[2] = 248.0 / 255.0;
			break;
		}
		case 10:
		{
			CalcColor[0] = 241.0 / 255.0;
			CalcColor[1] = 233.0 / 255.0;
			CalcColor[2] = 191.0 / 255.0;
			break;
		}
		case 11:
		{
			CalcColor[0] = 248.0 / 255.0;
			CalcColor[1] = 201.0 / 255.0;
			CalcColor[2] = 95.0 / 255.0;
			break;
		}
		case 12:
		{
			CalcColor[0] = 255.0 / 255.0;
			CalcColor[1] = 170.0 / 255.0;
			CalcColor[2] = 0.0 / 255.0;
			break;
		}
		case 13:
		{
			CalcColor[0] = 204.0 / 255.0;
			CalcColor[1] = 128.0 / 255.0;
			CalcColor[2] = 0.0 / 255.0;
			break;
		}
		case 14:
		{
			CalcColor[0] = 153.0 / 255.0;
			CalcColor[1] = 87.0 / 255.0;
			CalcColor[2] = 0.0 / 255.0;
			break;
		}
		case 15:
		{
			CalcColor[0] = 106.0 / 255.0;
			CalcColor[1] = 52.0 / 255.0;
			CalcColor[2] = 3.0 / 255.0;
			break;
		}
		}
	}

    return CalcColor;
}