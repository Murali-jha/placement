class Solution {
public:
    
    
    void Merge(vector < int > & nums, int low, int mid, int high,int &ans) {
  int j = mid;
  for (int i = low; i < mid; i++) {
    while (j <= high && nums[i] > 2LL  * nums[j]) {
      j++;
    }
    ans += (j - (mid));
  }

  vector < int > t;
  int left = low, right = mid;
  while (left < mid && right <= high) {

    if (nums[left] <= nums[right]) {
      t.push_back(nums[left++]);
    } else {
      t.push_back(nums[right++]);
    }
  }

  while (left < mid) {
    t.push_back(nums[left++]);
  }
  while (right <= high) {
    t.push_back(nums[right++]);
  }

        int k = 0;
  for (int i = low; i <= high; i++) {
    nums[i] = t[k++];
  }
}
void MergeSort(vector < int > & nums, int low, int high,int &ans) {

  if(low<high){
      int mid = (low + high) / 2;
      MergeSort(nums, low, mid,ans);
      MergeSort(nums, mid + 1, high,ans);
      Merge(nums, low, mid+1, high,ans);
  }
}
    
    
    int reversePairs(vector<int>& nums) {
        int ans = 0;
        MergeSort(nums,0,nums.size()-1,ans);
        return ans;
    }
};
