class LFUCache {
public:
int cap;
unordered_map<int,int> keyvalue;
map<int,queue<int>> freqToKey;
unordered_map<int,int> keyToFreq;
    LFUCache(int capacity) {

         cap=capacity;
    }
    
    int get(int key) {
        if(keyvalue.find(key)!= keyvalue.end()){
            keyToFreq[key]++;
            freqToKey[keyToFreq[key]].push(key);
            return keyvalue[key];
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(keyvalue.size() == cap && keyvalue.find(key) == keyvalue.end()){
            int lowestFreq= freqToKey.begin()->first;

            while(true){
                while(!freqToKey[lowestFreq].empty() && keyToFreq[freqToKey[lowestFreq].front()] !=lowestFreq){
                    freqToKey[lowestFreq].pop();
                }
                        
            if(!freqToKey[lowestFreq].empty()){
                int key=freqToKey[lowestFreq].front();
                freqToKey[lowestFreq].pop();
                keyvalue.erase(key);
                keyToFreq.erase(key);
                break;
            }
            else{
                freqToKey.erase(lowestFreq);
                lowestFreq++;
            }

        }
    }
    keyvalue[key]=value;
    keyToFreq[key]++;
    freqToKey[keyToFreq[key]].push(key);
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */