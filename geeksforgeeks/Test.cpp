 #include <cmath>  
 #include <cstdio>  
 #include <vector>  
 #include <iostream>  
 #include <algorithm> 
 #include <functional> 
 using namespace std;  

 int main()
{  
  vector<int> arr = {8, 8, 14, 10, 3, 5, 14, 12};
    for_each(arr.begin(), arr.end(), [](int i) {std::cout << i << "";});
  return 0;
}  