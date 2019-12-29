double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int isOddLen = (nums1Size + nums2Size) % 2;
    double median = 0;
    int medianStartIndex = (nums1Size + nums2Size + isOddLen) / 2;
    int n1Index = 0, n2Index = 0;
    for (int i = 0; i < medianStartIndex; i ++) {
        if (n1Index < nums1Size && (n2Index >= nums2Size || nums1[n1Index] < nums2[n2Index])) {
            median = nums1[n1Index];
            n1Index += 1;
        } else {
            median = nums2[n2Index];
            n2Index += 1;
        }
    }
    if (isOddLen == 1) {
        return (double)median;
    } else {
        if (n1Index < nums1Size && (n2Index >= nums2Size || nums1[n1Index] < nums2[n2Index])) {
            median += nums1[n1Index];
        } else {
            median += nums2[n2Index];
        }
        return median / 2.0;
    }
}