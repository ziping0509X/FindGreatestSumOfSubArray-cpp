//剑指offer
//HZ偶尔会拿些专业问题来忽悠那些非计算机专业的同学。
// 今天测试组开完会后,他又发话了:在古老的一维模式识别中,常常需要计算连续子向量的最大和,当向量全为正数的时候,问题很好解决。
// 但是,如果向量中包含负数,是否应该包含某个负数,并期望旁边的正数会弥补它呢？
// 例如:{6,-3,-2,7,-15,1,2,2},连续子向量的最大和为8(从第0个开始,到第3个为止)。
// 给一个数组，返回它的最大连续子序列的和，你会不会被他忽悠住？(子向量的长度至少是1)

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int len=array.size();
        if(len==1){
            return array[0];
        }
        else{
            int flag=0;
            for(int i=0;i<len;i++){
                if(array[i]>=0)
                    flag=flag+1;
                else{
                    flag=flag-1;
                }
            }
            if(flag==len){
                int temp=0;
                for(int i=0;i<len;i++){
                    temp=temp+array[i];
                }
                return temp;
            }
            if (flag==-len){
                int temp=array[0];
                for(int i=0;i<len;i++){
                    if(temp<array[i])
                        temp=array[i];
                }
                return temp;
            }
            if(flag!=len && flag!=-len){
                int temp=0,max=0;
                for(int i=0;i<len;i++){

                    if(temp<=0){
                        temp=array[i];
                    }
                    else{
                        temp=temp+array[i];
                    }
                    if(max<temp){
                        max=temp;
                    }
                }

                return max;

            }
        }
    }
};

int main(void){
    vector<int> list;
    list.push_back(1);
    list.push_back(-2);
    list.push_back(3);
    list.push_back(10);
    list.push_back(-4);
    list.push_back(7);
    list.push_back(2);
    list.push_back(-5);
    Solution solution;
    int max=solution.FindGreatestSumOfSubArray(list);
    cout<<max<<endl;

}


//调试成功！