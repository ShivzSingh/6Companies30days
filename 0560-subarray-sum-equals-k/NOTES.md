Solution - I (Brute force, TLE)-
​
1.Since we are very obedient person and don't want to do anything extra from our side.
2.So, we will try to generate the sum of each subarray and if matches withk , then increment our answer.
3.Like, this is the most basic thing we can do.
int subarraySum(vector<int>& arr, int k) {
int n = arr.size(); // taking the size of the array
int ans = 0; // ans variable to store our count
for(int i = 0; i < n; i++) // traverse from the array
{
int sum = arr[i]; // provide sum with arr[i]
if(sum == k) // if element itself equal to k, then also increment count
ans++;
for(int j = i + 1; j < n; j++) // now moving forward,
{
sum += arr[j]; // add elements with sum
if(sum == k) // if at any point they become equal to k
ans++; // increment answer
}
}
return ans; // and at last, return answer
}