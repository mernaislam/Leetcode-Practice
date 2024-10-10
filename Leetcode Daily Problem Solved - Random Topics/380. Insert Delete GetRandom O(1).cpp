/// @author Merna Islam
/// @date 16/01/2024.
/// @link https://leetcode.com/problems/insert-delete-getrandom-o1

class RandomizedSet {
public:
    vector<int> vec;
    unordered_map<int, int> mp;
    RandomizedSet() {

    }

    bool insert(int val) {
        // returns 1 if the element with key val is present in the map, else returns 0
        if(mp.count(val)) return false;

        // push item at the end of the vector    
        mp[val] = vec.size();
        vec.push_back(val);
        return true;
    }

    bool remove(int val) {
        // returns 1 if the element with key val is present in the map, else returns 0
        if(!mp.count(val)) return false;

        // get index of current item 
        int idx = mp[val];

        // remove element from vector in O(1)
        vec[idx] = vec.back();
        mp[vec.back()] = idx;
        vec.pop_back();

        // update map index value
        mp.erase(val);
        return true;
    }

    int getRandom() {
        return vec[rand() % vec.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */