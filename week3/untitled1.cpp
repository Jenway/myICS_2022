#include <raylib.h>

int main() {
	InitWindow(800,600,"test");
	SetTraceLogLevel(LOG_WARNING);
	SetTargetFPS(24);
	//读入图片文件
	Image imgBackground=LoadImage(""C:\\Users\\Jenway\\Desktop\\123.jpg"");
	Image imgRacoon[12];
	for (int i=0;i<12;i++) {
		const char* filename=TextFormat(""C:\\Users\\Jenway\\Desktop\\123.jpg"");
		imgRacoon[i]=LoadImage(filename);
	}
	
	int stepX=1;
	int racoonX=0;
	int racoonY=300;
	int racoonFrame=0;
	int racoonTotalFrame=0;
	while(!WindowShouldClose()) {
		if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
			if (racoonFrame==0)
				racoonTotalFrame+=12;
			else
				racoonTotalFrame++;
		} 
		if (racoonFrame<racoonTotalFrame) {
			racoonFrame++;
			if (racoonFrame>=racoonTotalFrame) {
				racoonFrame=0;
				racoonTotalFrame=0;
			}
			racoonX+=stepX;
		} 
		Texture tBackground = LoadTextureFromImage(imgBackground);
		Texture tRacoon = LoadTextureFromImage(imgRacoon[racoonFrame%12]);
		BeginDrawing();
		//叠加显示图层。注意显示的顺序
		DrawTexture(tBackground,0,0,WHITE);
		DrawTexture(tRacoon,racoonX,racoonY,WHITE);
		EndDrawing();
		UnloadTexture(tRacoon);
		UnloadTexture(tBackground);
	}
	for (int i=0;i<12;i++) {
		UnloadImage(imgRacoon[i]);
	}
	UnloadImage(imgBackground);
	CloseWindow();
}
