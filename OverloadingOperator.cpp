#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
 
bool checkStraightLine(std::vector<std::vector<int>>& coordinates) {
        int length = coordinates.size();
        //check for x axis
        bool ans = true;
        for(int i = 0 ; i < length - 1; ++i)
        {
            if(coordinates[i][1]  != coordinates[i + 1][1])
            {
                ans = false;
                break;    
            }   
        }
        if(ans) return true;
        //check for y axis
        
        for(int i = 0 ; i < length - 1; ++i)
        {
            if(coordinates[i][0]  != coordinates[i + 1][0])
            {
                ans = false;
                break;    
            }   
        }
        if(ans) return true;
        
        // check for diagonal 
        
        float ratio = fabs(static_cast<float>(coordinates[0][0]) / static_cast<float>(coordinates[0][1]));
        for(int i = 1; i < length; ++i)
        {
            float tmp = fabs(static_cast<float>(coordinates[i][0]) / static_cast<float>(coordinates[i][1]));
            if(tmp != ratio)
            {
                ans = false;
                break;
            }
        }
        return ans;
    }
int main()
{
    std::vector<std::vector<int>> coordinates = {{1,2},{2,3},{3,4},{4,5},{5,6},{6,7}};
    std::cout << checkStraightLine(coordinates);
    //buddyStrings("aaaaaaabc","aaaaaaacb");

    return 0;
}