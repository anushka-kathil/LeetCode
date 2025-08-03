class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int a1 = (ax2  - ax1) * (ay2 - ay1);
        int a2 = (bx2-bx1) * (by2-by1);
        int ca=0;
        int overlap_x1 = max(ax1, bx1);
        int overlap_y1 = max(ay1, by1);
        int overlap_x2 = min(ax2, bx2);
        int overlap_y2 = min(ay2, by2);
         if (overlap_x1 < overlap_x2 && overlap_y1 < overlap_y2) {
            ca = (overlap_x2 - overlap_x1) * (overlap_y2 - overlap_y1);
        }
        return a1+a2 - ca;
        
    }
};