void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int* container = (int*)malloc(sizeof(int) * (m + n));
    int index1 = 0, index2 = 0, containerIndex = 0;
    while (index1 < m || index2 < n) {
        if (index1 >= m) {
            container[containerIndex ++] = nums2[index2 ++];
        } else if (index2 >= n) {
            container[containerIndex ++ ] = nums1[index1 ++];
        } else {
            if (nums1[index1] < nums2[index2]) {
                container[containerIndex ++ ] = nums1[index1 ++];
            } else {
                container[containerIndex ++] = nums2[index2 ++];
            }
        }
    }
    for (int i = 0; i < m + n; i ++) {
        nums1[i] = container[i];
    }
    free(container);
}
