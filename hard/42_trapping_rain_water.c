int trap(int* height, int heightSize) {
    int left_index = 0, right_index = heightSize - 1;
    int left_max = height[0], right_max = height[heightSize - 1];
    int area = 0;
    while (left_index <= right_index) {
        if (height[left_index] < height[right_index]) {
            if (height[left_index] > left_max) {
                left_max = height[left_index];
            } else {
                area += left_max - height[left_index];
            }
            left_index += 1;
        } else {
            if (height[right_index] > right_max) {
                right_max = height[right_index];
            } else {
                area += right_max - height[right_index];
            }
            right_index -= 1;
        }
    }
    return area;
}
