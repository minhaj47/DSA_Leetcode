class RandomizedSet {
private:
    unordered_set<int>us;

public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        auto p = us.find(val);
        if(p == us.end()){
            us.insert(val);
            return true;
        } return false;
    }
    
    bool remove(int val) {
        auto p = us.find(val);
        if(p != us.end()){
            us.erase(val);
            return true;
        } return false;
    }
    
    int getRandom() {
        int steps = rand() % us.size();
        auto itr = us.begin();
        advance(itr, steps);
        return *itr;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */