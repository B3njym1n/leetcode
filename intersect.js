var intersect = function(nums1, nums2) {
    let i = 0, j = 0, ret = [];
    nums1 = nums1.sort(comp);
    nums2 = nums2.sort(comp);
    while(i < nums1.length && j < nums2.length) {
        if (nums1[i] == nums2[j]) {
            ret.push(nums1[i]);
            i += 1;
            j += 1;
        } else if(nums1[i] < nums2[j]) {
            i += 1;
        } else {
            j += 1;
        }
    }
    return ret;
};

function comp(a, b) {
    return a - b;
}
