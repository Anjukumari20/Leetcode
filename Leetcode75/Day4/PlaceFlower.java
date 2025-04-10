
class Solution {
    public boolean canPlaceFlowers(int[] flowerbed, int n) {
        int count=0;
        for (int i = 0; i < flowerbed.length; i++) {
            if (flowerbed[i] == 0) {
                // Check left and right plots
                boolean emptyLeft = (i == 0) || (flowerbed[i - 1] == 0);
                boolean emptyRight = (i == flowerbed.length - 1) || (flowerbed[i + 1] == 0);
                
                if (emptyLeft && emptyRight) {
                    flowerbed[i] = 1; // Plant the flower
                    count++;
                    
                    if (count >= n) {
                        return true;
                    }
                }
            }
        }
        return count >= n;
    }