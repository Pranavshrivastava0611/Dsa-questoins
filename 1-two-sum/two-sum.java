class Solution {
    public int[] twoSum(int[] nums, int target) {
        int size = nums.length;
        HashMap<Integer,Integer>map = new HashMap<>();
        for(int i=0;i<size;i++){
            if(map.containsKey(target-nums[i])){
                return new int[]{map.get(target-nums[i]),i};
            }
            map.put(nums[i],i);
        }
        return new int[]{};
    }
}