class Robot {
public:
    int w, h;
    int x = 0, y = 0;
    int dir = 0;
    vector<string> dirs = {"East", "North", "West", "South"};

    Robot(int width, int height) {
        w = width;
        h = height;
    }

    void step(int num) {
        int perimeter = 2 * (w + h) - 4;
        num %= perimeter;
        if (num == 0) num = perimeter;

        while (num > 0) {
            if (dir == 0) {
                int move = min(num, w - 1 - x);
                x += move;
                num -= move;
            } 
            else if (dir == 1) {
                int move = min(num, h - 1 - y);
                y += move;
                num -= move;
            } 
            else if (dir == 2) {
                int move = min(num, x);
                x -= move;
                num -= move;
            } 
            else {
                int move = min(num, y);
                y -= move;
                num -= move;
            }

            if (num > 0) dir = (dir + 1) % 4;
        }
    }

    vector<int> getPos() {
        return {x, y};
    }

    string getDir() {
        return dirs[dir];
    }
};