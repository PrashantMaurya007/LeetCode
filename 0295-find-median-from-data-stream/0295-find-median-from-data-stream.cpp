class MedianFinder {
public:
    priority_queue<int>LeftMH;
    priority_queue<int, vector<int>,greater<int>>RightMH;

    void balancing(){
        if(LeftMH.size() < RightMH.size()){
            LeftMH.push(RightMH.top());
            RightMH.pop();
        }

        else{

            if(LeftMH.size() > RightMH.size() + 1){
                RightMH.push(LeftMH.top());
                LeftMH.pop();
            }
        }


    }
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(LeftMH.empty()){
            LeftMH.push(num);
            return;
        }

        if(num > LeftMH.top()){
            RightMH.push(num);
        }
        else{
            LeftMH.push(num);
        }

        balancing();
        
    }
    
    double findMedian() {
        if(LeftMH.size()> RightMH.size()){
           return  LeftMH.top();
        }

        else{
          return ((double)LeftMH.top() + RightMH.top()) / 2;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */