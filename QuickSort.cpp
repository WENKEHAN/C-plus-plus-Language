#include <iostream>
#include <vector>
using namespace std;
void Mysort(vector<int>&a,int begin,int end){
    //左闭右开区间
    if(begin==end){
        return;
    }
    int left=begin;
    int right=end-1;
    int temp=a[left];
    while(left<right){
        while(left<right&&a[right]>temp){
            right--;
        }
        a[left]=a[right];
        while(left<right&&a[left]<temp){
            left++;
        }
        a[right]=a[left];
    }
    a[left]=temp;
    Mysort(a,begin,left);
    Mysort(a,left,end-1);

}
int Getleft(vector<int>&nums,const int &val){
    int left=0,right=nums.size();
    //左闭右开的原则
    while(left<right){
        int mid=left+(right-left)/2;
        if(nums[mid]==val){
            right=mid;
        }else if(nums[mid]>val){
            //大于的时候区间向左边缩
            right=mid;
        }else if(nums[mid]<val){
            left=mid+1;
        }
    }
    if(nums[left]==val){
        return left;
    }
    return -1;
}
int Getright(vector<int>&nums,const int &val){
    int left=0,right=nums.size();
    //左闭右开的原则
    while(left<right){
        int mid=left+(right-left)/2;
        if(nums[mid]==val){
            left=mid+1;
        }else if(nums[mid]>val){
            //大于的时候区间向左边缩
            right=mid;
        }else if(nums[mid]<val){
            left=mid+1;
        }
    }
    if(nums[left-1]==val){
        return left-1;
    }
    return -1;
}
int main(){
    //n几个数字，x目标值
    int n,x;
    cin>>n>>x;
    vector<int>arr;
    //用vector来保存输入的数据
    int temp;
    for(int i=0;i<n;i++){
        cin>>temp;
        arr.push_back(temp);
    }
    //Mysort(arr,0,arr.size());
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    temp= Getleft(arr,x);
    cout<<temp<<endl;
    temp= Getright(arr,x);
    cout<<temp<<endl;
    return 0;
}