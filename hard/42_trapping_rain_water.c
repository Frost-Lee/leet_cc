#define MIN(a,b) ((a) < (b) ? (a) : (b))

int nearest_higher_index(const int* height, int height_size, int start_index, int reference_index) {
    int max_index = start_index;
    for (int i = start_index + 1; i < height_size; i ++) {
        if (height[i] > height[max_index]) {
            if (height[max_index] > height[reference_index]) {
                break;
            }
            max_index = i;
        }
    }
    return max_index != start_index ? max_index : -1;
}

int trap(int* height, int heightSize) {
    int left_highest_index = 0;
    int right_highest_index = 0;
    int water_sum = 0;
    for (int i = 0; i < heightSize; i ++) {
        if (i >= right_highest_index) {
            if (height[i] > height[left_highest_index]) {
                left_highest_index = i;
            }
            right_highest_index = nearest_higher_index(height, heightSize, i, left_highest_index);
            if (right_highest_index == -1) {
                right_highest_index = i + 1;
                if (right_highest_index >= heightSize) {
                    return water_sum;
                }
            }
        }
        int surface_height = MIN(height[right_highest_index], height[left_highest_index]);
        if (surface_height - height[i] > 0) {
            water_sum += surface_height - height[i];
        }
    }
    return water_sum;
}
