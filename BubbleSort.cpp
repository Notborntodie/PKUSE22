#include<iostream>
#include <vector>
using namespace std;
vector<int> bubblesort(vector<int> &nums) {
	bool Noswap = true;		//标志位判断是否有过交换
	int temp,times=nums.size()-1;
	for (int k = 0; k < nums.size()-1; k++) {
		for (int j = 0; j < times; j++) {		//初始时内循环大小和数组大小相当，每趟排序会减少1
			if (nums[j] > nums[j + 1]) {
				temp = nums[j];
				nums[j] = nums[j+1];
				nums[j+1] = temp;
				Noswap = false;			
			}
		}
		if (Noswap)
			return nums;
		times--;		//每次排序最大的数字总会排在最后面，因此不需要遍历整个数组
		Noswap = true;	//每次内循环结束将标志位置为true
	}
	return nums;
}
int main() {
	vector<int> v;
	int n;
	cout << "请输入数组大小" << endl;
	cin >> n;
	int temp = -1;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		v.push_back(temp);
	}
	bubblesort(v);
}