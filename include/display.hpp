#ifndef DISPLAY_HPP     //headerguard
#define DISPLAY_HPP

class myDisplay {
    public:
        myDisplay();
        void begin();
        void clear();
        void drawPixel(int x, int y);
        void drawPaddle(int x, int upperY, int lowerY);
        void drawScore(int scoreL, int scoreR);
        void update();
};

#endif